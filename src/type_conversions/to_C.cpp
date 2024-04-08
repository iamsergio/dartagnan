/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "to_C.h"
#include "to_CppWrapper.h"

#include <QDebug>

using namespace Dartagnan;

namespace ToCConversions {

QString type(const AbstractMetaType type)
{
    if (!hasType(type) || type.isVoid())
        return "void";

    if (type.isObject() || type.isValuePointer() || type.isValue()) {
        return "void*";
    }

    if (type.isEnum() || type.isFlags()) {
        // TODO: Support enum class with different storage
        return "int";
    }

    if (typeIsPrimitiveConst(type)) {
        // "const int &" and "const int" are returned as int, etc.
        return type.name();
    }

    return type.cppSignature();
}

QString functionReturnType(const AbstractMetaFunction *func,
                           const AbstractMetaType templateInstantiation)
{
    if (func->isConstructor())
        return "void *";

    if (func->isDestructor())
        return "void";

    const AbstractMetaType t = func->type();

    if (hasType(t) && t.typeUsagePattern() == AbstractMetaType::TemplateArgument) {
        // A method can return T, for example T QVector<T>::at(int index).
        // We now need to replace T with the instantiated type

        const AbstractMetaType actualType =
            Dartagnan::instantiationForTemplateArgument(templateInstantiation, t);

        QString result = type(actualType);

        // Furthermore, a method can return "const T *", for example: const T
        // *QVector<T>::constData() So we need to add const and *

        if (t.isConstant())
            result = QString("const %1").arg(result);

        if (templateArgumentIsPointer(t)) {
            // TODO: support **
            result = QString("%1 *").arg(result);
        }

        return result;
    }

    return type(t);
}

QString functionSignature(const AbstractMetaFunction *func, FunctionFormatOptions opts,
                          AbstractMetaType instantiation)
{
    const QString exportMacro = (opts & FunctionFormatOption::ExportMacro)
        ? QString("%1 ").arg(Dartagnan::exportMacroName())
        : QString();
    return QString("%1%2 %3(%4)")
        .arg(exportMacro, functionReturnType(func, instantiation),
             functionName(func, instantiation, opts),
             membersText(func,
                         opts | FunctionFormatOption::ImplicitThisAs1stParams
                             | FunctionFormatOption::StringInsteadOfQString,
                         instantiation));
}

QString functionName(const AbstractMetaFunction *func, const AbstractMetaType instantiation,
                     FunctionFormatOptions opts)
{
    auto record = func->ownerClass();

    const QString qualifiedClassCppName = ToCConversions::qualifiedClassName(record, instantiation);
    QString cname;

    QString argumentsText = argumentTypesForSignature(func, instantiation);
    if (!argumentsText.isEmpty())
        argumentsText = "_" + argumentsText;

    QString funcName = func->name();
    if (opts & FunctionFormatOption::ForSignalHandler) {
        funcName[0] = funcName[0].toUpper();
        funcName = QString("on%1").arg(funcName);
    }

    if (func->isConstructor()) {
        cname = QStringLiteral("c_%1__constructor%2").arg(qualifiedClassCppName, argumentsText);
    } else if (func->isDestructor()) {
        cname = dtorFunctionName(record, instantiation);
    } else {
        // Normal, non-static method
        // getter/setter prefix
        const QString prefix = func->functionType() == AbstractMetaFunction::GetAttroFunction
            ? QString("_get_")
            : func->functionType() == AbstractMetaFunction::SetAttroFunction ? QString("_set_")
                                                                             : QString();

        if (func->isStatic()) {
            cname = QStringLiteral("c_static_%1__%2%3%4")
                        .arg(qualifiedClassCppName, prefix, funcName, argumentsText);
        } else {
            cname = QStringLiteral("c_%1__%2%3%4")
                        .arg(qualifiedClassCppName, prefix, funcName, argumentsText);
        }
    }

    cname = cname.replace("::", "__");
    return cname;
}

QString registerCallbackFunctionsName(const AbstractMetaClass *metaClass)
{
    const QString qualifiedClassCppName = metaClass ? metaClass->qualifiedCppName() : QString();
    QString name = QString("c_%1__registerVirtualMethodCallback").arg(qualifiedClassCppName);
    return name.replace("::", "__");
}

QString registerCallbackFunctionSignature(const AbstractMetaClass *metaClass,
                                          FunctionFormatOptions opts)
{
    const QString exportMacro = (opts & FunctionFormatOption::ExportMacro)
        ? QString("%1 ").arg(Dartagnan::exportMacroName())
        : QString();
    const QString qualifiedClassCppName = metaClass ? metaClass->qualifiedCppName() : QString();
    return QString("%1void %2(void *ptr, void *callback, int methodId)")
        .arg(exportMacro, registerCallbackFunctionsName(metaClass));
}

static const AbstractMetaType templateParamForArgument(const AbstractMetaFunction *func,
                                                       AbstractMetaArgument argument,
                                                       const AbstractMetaType instantiation)
{
    if (argument.type().typeUsagePattern() != AbstractMetaType::TemplateArgument) {
        // Not a template argument, nothing to do
        return argument.type();
    }

    if (!hasType(instantiation)) {
        qWarning() << Q_FUNC_INFO << "Expected template instantiation when dealing with func"
                   << func->signature();
        return {};
    }

    const QString templateArg = argument.type().name();
    auto result = Dartagnan::instantiationForTemplateArgument(instantiation, argument.type());
    return hasType(result) ? result : argument.type();
}

QString membersText(const AbstractMetaFunction *func, FunctionFormatOptions formatOpts,
                    const AbstractMetaType instantiation)
{
    if (func->isDestructor())
        return "void *thisObj";

    if (formatOpts & FunctionFormatOption::ForSignalHandler) {
        return "void *thisObj, void *contextQObject, void *callback";
    }

    QStringList members;
    if ((formatOpts & FunctionFormatOption::ImplicitThisAs1stParams) && !func->isStatic()
        && !func->isConstructor() && func->ownerClass())
        members << "void *thisObj";

    const auto arguments = func->arguments();
    for (AbstractMetaArgument argument : arguments) {
        QString argName = argument.name();

        const AbstractMetaType actualType = Dartagnan::actualType(argument.type(), instantiation);
        if ((formatOpts & FunctionFormatOption::StringInsteadOfQString)
            && actualType.name() == "QString") {
            members << QString("const char *%1_").arg(argName);
            continue;
        }

        if (actualType.isObject() || actualType.isValue() || actualType.isValuePointer()
            || actualType.isFlags()) {
            // These are not supported by C, so will need to be cast before calling the C++ func.
            argName += "_";
        }

        members << QStringLiteral("%1 %2").arg(
            type(templateParamForArgument(func, argument, instantiation)), argName);
    }

    return members.join(",");
}

QString membersTextEscaped(const AbstractMetaFunction *func)
{
    QString text = membersText(func);
    return text;
}

QString argumentTypesForSignature(const AbstractMetaFunction *func,
                                  const AbstractMetaType instantiation)
{
    if (func->isDestructor())
        return {};

    QStringList result;
    const auto args = func->arguments();
    for (AbstractMetaArgument arg : args) {
        const AbstractMetaType actualType = Dartagnan::actualType(arg.type(), instantiation);
        Q_ASSERT(hasType(actualType));
        result << actualType.name().replace(" ", "_");

        // @param instantiation is about the class having a template, but arg.type() might be a
        // template too, so append its arguments
        if (actualType.hasInstantiations()) {
            for (auto i : actualType.instantiations()) {
                result << i.name();
            }
        }
    }

    return result.join('_');
}

QString dtorFunctionName(const AbstractMetaClass *record, const AbstractMetaType instantiation)
{
    QString cname =
        QStringLiteral("c_%1__destructor").arg(qualifiedClassName(record, instantiation));
    cname = cname.replace("::", "__");
    return cname;
}

QString argumentCasts(const AbstractMetaFunction *func, FunctionFormatOptions options,
                      AbstractMetaType instantiation)
{
    QString result;
    const AbstractMetaArgumentList args = func->arguments();
    for (AbstractMetaArgument arg : args) {
        const QString name = arg.name();
        const AbstractMetaType actualType = Dartagnan::actualType(arg.type(), instantiation);
        QString typeName = actualType.typeEntry()->qualifiedCppName();

        if ((options & FunctionFormatOption::StringInsteadOfQString)
            && actualType.name() == "QString") {
            result += QString("const auto %1 = QString::fromUtf8(%2_);").arg(name, name);
        } else if (actualType.isObject() || actualType.isValue() || actualType.isValuePointer()) {

            if (arg.type().typeUsagePattern() != AbstractMetaType::TemplateArgument) {
                QString params = ToCppWrapperConversions::templateParams(instantiation);
                if (params.isEmpty())
                    params += ToCppWrapperConversions::templateParams(arg.type());

                typeName += params;
            }

            const bool isPointer =
                actualType.cppSignature().endsWith("*"); // TODO: Improve this. Quick hack for now.
            const QString maybeDeref = isPointer ? QString() : "*";
            const QString ampersand = isPointer ? QString() : "&";

            if (!isPointer) {
                // Assert soon, as these bugs are difficult to debug
                result += QString("assert(%1_);\n").arg(name);
            }

            result += QString("auto %1%2 = %3reinterpret_cast<%4 *>(%5_);")
                          .arg(ampersand, name, maybeDeref, typeName, name);
        } else if (actualType.isFlags()) {
            // QFlags need to be cast to int, as C doesn't support QFlags
            result += QString("auto %1 = static_cast<%2>(%3_);").arg(name, typeName, name);
        }
    }

    return result;
}

bool typeIsPrimitiveConst(const AbstractMetaType type)
{
    return type.isPrimitive() && type.isConstant();
}

QString finalizerName(const AbstractMetaClass *metaClass, const AbstractMetaType instantiation)
{
    return QString("c_%1_Finalizer")
        .arg(qualifiedClassName(metaClass, instantiation).replace(":", "_"));
}

QString finalizerSignature(const AbstractMetaClass *metaClass, FunctionFormatOptions opts,
                           const AbstractMetaType instantiation)
{
    const QString exportMacro = (opts & FunctionFormatOption::ExportMacro)
        ? QString("%1 ").arg(Dartagnan::exportMacroName())
        : QString();

    return QString("%1 void %2(void *cppObj)")
        .arg(exportMacro, finalizerName(metaClass, instantiation));
}

QString templateArgs(AbstractMetaType type)
{
    if (!hasType(type))
        return {};

    QStringList args;
    if (type.instantiations().isEmpty())
        return QString();

    for (auto t : type.instantiations()) {
        args << t.name().replace(" ", "_");
    }

    QString result = args.join("_");
    if (!result.isEmpty())
        result = QString("_T_%1_T_").arg(result);

    return result;
}

QString qualifiedClassName(const AbstractMetaClass *metaClass,
                           const AbstractMetaType templateInstantiation)
{
    if (!metaClass)
        return {};

    QString name = metaClass->qualifiedCppName();
    if (hasType(templateInstantiation))
        name += templateArgs(templateInstantiation);

    return name;
}

bool templateArgumentIsPointer(const AbstractMetaType type)
{
    return type.cppSignature().contains("*");
}

bool methodReturnsBool(const AbstractMetaFunction *method, AbstractMetaType templateInstantiation)
{
    if (!hasType(templateInstantiation))
        return method->returnsBool();

    const AbstractMetaType type = method->type();
    if (hasType(type) && type.typeUsagePattern() == AbstractMetaType::TemplateArgument) {
        const AbstractMetaType actualType =
            Dartagnan::instantiationForTemplateArgument(templateInstantiation, type);
        return hasType(actualType) && isBool(actualType);
    } else {
        return method->returnsBool();
    }
}

} // namespace ToCConversions

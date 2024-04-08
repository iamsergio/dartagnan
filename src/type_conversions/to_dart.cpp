/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "to_dart.h"
#include "dartagnan.h"
#include "generator_dart.h"
#include "to_C.h"
#include "to_CppWrapper.h"

#include <QDebug>

using namespace Dartagnan;

QString ToDartConversions::type(AbstractMetaType t, Options options)
{
    const bool isForTypedef = options & Option::ForTypedef;
    const bool isForTypedefName = options & Option::ForTypedefName;

    if (hasType(t) && t.isFlags())
        return "int";

    if (isForTypedef) {
        if (!hasType(t))
            return "void";

        if (t.name() == "char" && t.isPrimitive())
            return isForTypedefName ? "char" : "int";

        if (type(t) == "String")
            return "ffi.Pointer<Utf8>";

        if (t.isObject() || t.isValue() || t.isValuePointer()) {
            // classes are passed as void* in the ffi interface
            return "ffi.Pointer<void>";
        }

        if (t.name() == "bool")
            return isForTypedefName ? "bool" : "int";
    }

    if (!hasType(t))
        return QString();

    if (t.isEnum()) {
        // TODO: Support enum class with other types of storage
        return "int";
    }

    QString scopePrefix;
    if (const AbstractMetaClass *metaClass = Dartagnan::classForType(t)) {
        const QString scope = DartagnanGeneratorBase::m_optionsFromJson.scopeForType(metaClass);
        if (!scope.isEmpty())
            scopePrefix = scope + ".";
    }


    const QString name = scopePrefix + t.name();
    if (name == "int")
        return name;

    if (name == "qreal" || name == "float")
        return "double";

    if (name == "qsizetype" || name == "unsigned int" || name == "signed int")
        return "int";

    if (name == "qsizetype" || name == "qint64")
        return "int";

    if ((options & Option::StringInsteadOfQString) && name == "QString") {
        // It's nicer to use Dart's String in user code instead of QString
        return "String";
    }

    if (name == "char") {
        const QString sig = t.cppSignature().replace("const ", "").replace("volatile ", "");
        if (t.isPrimitive()) {
            return "String";
        } else if (sig == "char *") {
            return "String";
        } else if (sig == "char **") {
            return "List<String>";
        } else {
            return QString("TODO-MAKE-GENERIC-%1").arg(t.minimalSignature());
        }
    }

    // if (t->typeUsagePattern() == AbstractMetaType::TemplateArgument)
    // return QString("%1?").arg(name);

    return name;
}

QString ToDartConversions::typeForFFI(AbstractMetaType t, AbstractMetaType templateInstantiation)
{
    if (t.typeUsagePattern() == AbstractMetaType::TemplateArgument
        && hasType(templateInstantiation)) {
        // Use the instantiation instead
        t = Dartagnan::instantiationForTemplateArgument(templateInstantiation, t);
        if (!hasType(t)) {
            qWarning() << Q_FUNC_INFO << "Failed to get instantiation type"
                       << "class instantiation=" << templateInstantiation.cppSignature();
            return {};
        }
    }

    const QString dartType = type(t);

    if (t.name() == "char" && t.isPrimitive())
        return "ffi.Int8";

    if (dartType == "String")
        return "ffi.Pointer<Utf8>";

    if (t.isObject() || t.isValue() || t.isValuePointer())
        return "ffi.Pointer<void>";

    const QString name = t.name();

    if (name == "void" || name.isEmpty())
        return "ffi.Void";

    if (name == "voidstar")
        return "ffi.Pointer<void>";

    if (name == "bool")
        return "ffi.Int8";

    if (dartType == "double")
        return "ffi.Double";

    if (dartType == "int" || t.isEnum())
        return "ffi.Int32";

    return dartType;
}

QString ToDartConversions::typeForFFI(const AbstractMetaFunction *func,
                                      AbstractMetaType templateInstantiation)
{
    if (func->isConstructor())
        return "ffi.Pointer<void>";

    if (hasType(func->type()))
        return typeForFFI(func->type(), templateInstantiation);

    return "ffi.Void";
}

QString ToDartConversions::mangle(const QString &type)
{
    QString mangled = type;
    return mangled.replace("ffi.Pointer<void>", "voidstar")
        .replace("ffi.Pointer<Utf8>", "string")
        .replace('<', '_')
        .replace('>', '_')
        .replace('.', '_');
}

QString ToDartConversions::type(const AbstractMetaFunction *func, Options options,
                                AbstractMetaType templateInstantiation)
{
    if (func->isConstructor())
        return "ffi.Pointer<void>";

    AbstractMetaType t = func->type();
    if (hasType(t) && t.typeUsagePattern() == AbstractMetaType::TemplateArgument) {
        AbstractMetaType actuaType =
            Dartagnan::instantiationForTemplateArgument(templateInstantiation, t);
        return type(actuaType, options);
    } else {
        return type(func->type(), options);
    }
}

QString ToDartConversions::value(AbstractMetaArgument arg, const QString &value)
{
    if (value == "nullptr")
        return "null";

    if (value == "{}") {
        if (arg.type().isEnum() || arg.type().isFlags())
            return "0";
        return "null";
    }

    return value;
}

QString ToDartConversions::defaultValueExpression(AbstractMetaArgument arg,
                                                  const AbstractMetaClass *context)
{
    if (!arg.hasDefaultValueExpression())
        return QString();

    // For example: { "Qt::UserRole + 1" }
    QStringList tokens = arg.defaultValueExpression().split(" ");

    for (QString &token : tokens) {
        const QString dartEnumeratorName =
            EnumRegistry::instance().dartNameForCppEnumerator(token, context);
        if (!dartEnumeratorName.isEmpty())
            token = dartEnumeratorName;
    }

    // For example: { "Qt_ItemDataRole.UserRole + 1" }
    return tokens.join(" ");
}

QString ToDartConversions::functionArguments(const AbstractMetaFunction *func,
                                             bool includeDefaultArgumentExpr, Options options)
{
    QStringList arguments;
    const AbstractMetaArgumentList args = func->arguments();
    int argsWithDefaultArgumentsCount = 0;
    for (AbstractMetaArgument arg : args) {
        QString defaultArgumentExpression;
        QString required;
        QString nullable;
        if (includeDefaultArgumentExpr && arg.hasDefaultValueExpression()) {
            argsWithDefaultArgumentsCount++;

            const QString defaultExpression = defaultValueExpression(arg, func->ownerClass());

            if (arg.type().isPrimitive() || arg.type().isEnum() || arg.type().isFlags()) {
                defaultArgumentExpression =
                    QString(" = %1").arg(ToDartConversions::value(arg, defaultExpression));
            } else if (arg.type().isValue()
                       || arg.type().typeUsagePattern() == AbstractMetaType::TemplateArgument
                       || arg.type().typeUsagePattern() == AbstractMetaType::ObjectPattern) {
                // func(QSize sz = {})
                // Dart doesn't accept default constructible default arguments, so user needs to
                // pass it, for now A workaround will be to make it nullable and optional {QSize?
                // sz} and in our generated code, assign a default constructed value if null
                required = "required ";
            }
        }

        if (typeIsNullable(arg))
            nullable = "?";

        QString openBraces;
        if (argsWithDefaultArgumentsCount == 1)
            openBraces = '{';

        const QString argName = (options & Option::ReplaceReservedDartKeyword)
            ? cleanReservedKeywords(arg.name())
            : arg.name();

        arguments << QStringLiteral("%1%2%3%4 %5%6")
                         .arg(openBraces, required, type(arg.type(), options), nullable, argName,
                              defaultArgumentExpression);
    }

    if (argsWithDefaultArgumentsCount > 0) {
        // Close brace of optional arguments list
        arguments.last() += '}';
    }

    return arguments.join(',');
}

QString ToDartConversions::scopedNameForType(const AbstractMetaClass *metaClass)
{
    const QString scope = DartagnanGeneratorBase::m_optionsFromJson.scopeForType(metaClass);
    if (scope.isEmpty())
        return metaClass->name();
    return QStringLiteral("%1.%2").arg(scope, metaClass->name());
}

QString ToDartConversions::directCallArguments(const AbstractMetaFunction *func)
{
    QStringList arguments;

    const AbstractMetaArgumentList args = func->arguments();
    for (int i = 0; i < args.size(); ++i) {
        AbstractMetaArgument arg = args[i];
        QString argumentStr;
        if (type(arg.type(), Option::ForTypedef) == "ffi.Pointer<void>") {
            if (auto metaClass = Dartagnan::classForType(arg.type())) {
                if (metaClass->name() == "QString") {
                    argumentStr = QString("%1.fromCppPointer(%2).toDartString()")
                                      .arg(scopedNameForType(metaClass), arg.name());
                } else if (arg.type().isValue()) {
                    argumentStr = QString("%1.fromCppPointer(%2)")
                                      .arg(scopedNameForType(metaClass), arg.name());
                } else {
                    argumentStr =
                        QString("(%1 == null || %1.address == 0) ? null : %2.fromCppPointer(%3)")
                            .arg(arg.name(), scopedNameForType(metaClass), arg.name());
                }
            } else {
                argumentStr = QString("ERROR, no class found for type %1").arg(arg.type().name());
            }

        } else if (isBool(arg.type())) {
            argumentStr = QString("%1 != 0").arg(arg.name());
        } else if (arg.type().name() == "char") {
            argumentStr = arg.name() + ".toString()";
        } else {
            argumentStr = arg.name();
        }

        if (arg.hasDefaultValueExpression()) {
            // Argument is optional, we used the named syntax, which is nicer for the user

            QString argName = arg.name();


            if (func->isVirtual()) {

                /// Take care of virtual functions in the base class having different argument names
                /// than the derived In dart we need to use the argument names of the base method,
                /// as we don't overload on the derived dart class

                auto func_ = Dartagnan::baseMethodForFunction(func);
                auto arg_ = func_->arguments()[i];
                argName = arg_.name();
            }

            argumentStr = QString("%1 : %2").arg(argName, argumentStr);
        }

        arguments << argumentStr;
    }

    return arguments.join(',');
}

QString ToDartConversions::callArguments(const AbstractMetaFunction *func,
                                         AbstractMetaType templateInstantiation)
{
    QStringList arguments;

    if (!func->isStatic() && !func->isConstructor() && func->ownerClass())
        arguments << "thisCpp";

    const AbstractMetaArgumentList args = func->arguments();
    for (AbstractMetaArgument arg : args) {
        arguments << callArgument(arg, templateInstantiation);
    }

    return arguments.join(',');
}

QString ToDartConversions::callArgument(AbstractMetaArgument arg,
                                        AbstractMetaType templateInstantiation)
{
    AbstractMetaType actualType = Dartagnan::actualType(arg.type(), templateInstantiation);
    const QString dartType = ToDartConversions::type(actualType, Option::StringInsteadOfQString);

    QString argName = cleanReservedKeywords(arg.name());
    if (arg.type().typeUsagePattern() == AbstractMetaType::TemplateArgument) {
        const QString typeName =
            ToDartConversions::type(actualType, ToDartConversions::Option::StringInsteadOfQString);
        argName = QString("(%1 as %2)").arg(argName, typeName);
    }

    if (isBool(arg.type())) {
        return QString("%1 ? 1 : 0").arg(argName);
    } else if (dartType == "String") {
        // If it's "const char*" in C++ but String in Dart.
        // So can be nullptr.
        return typeIsNullable(arg) ? QString("%1?.toNativeUtf8() ?? ffi.nullptr").arg(argName)
                                   : QString("%1.toNativeUtf8()").arg(argName);
    } else if (actualType.isObject() || actualType.isValuePointer()) {
        return QString("%1 == null ? ffi.nullptr : %2.thisCpp").arg(argName, argName);
    } else if (actualType.isValue()) {
        return QString("%1 == null ? ffi.nullptr : %2.thisCpp").arg(argName, argName);
    }

    return argName;
}

QString ToDartConversions::enumeratorName(AbstractMetaEnum metaEnum,
                                          const AbstractMetaEnumValue *enumerator)
{
    const AbstractMetaClass *metaClass = metaEnum.enclosingClass();
    if (metaEnum.isAnonymous()) {
        if (metaClass) {
            return QString("%1.%2").arg(metaClass->name().replace(":", "_"), enumerator->name());
        } else {
            return enumerator->name();
        }
    } else {
        return QString("%1.%2").arg(enumName(metaEnum), enumerator->name());
    }
}

QString ToDartConversions::enumName(AbstractMetaEnum metaEnum)
{
    if (metaEnum.isAnonymous())
        return QString();

    const AbstractMetaClass *metaClass = metaEnum.enclosingClass();
    const QString classPrefix =
        (metaClass ? (metaClass->name().replace(":", "_") + "_") : QString());

    return QString("%1%2").arg(classPrefix, metaEnum.name());
}

QString ToDartConversions::defaultValueForType(AbstractMetaType t)
{
    const QString dartTypeName = ToDartConversions::type(t);
    if (t.isEnum() || dartTypeName == "int" || isBool(t)
        || t.typeUsagePattern() == AbstractMetaType::FlagsPattern)
        return "0";

    return "TODO";
}

QString ToDartConversions::templateArgs(const AbstractMetaClass *metaClass)
{
    // Impl is the same as the C++ one, so reuse
    return ToCppWrapperConversions::templateArgs(metaClass);
}

QString ToDartConversions::templateParams(AbstractMetaType type)
{
    if (!hasType(type) || type.instantiations().isEmpty())
        return {};

    QStringList args;
    for (AbstractMetaType instantiation : type.instantiations()) {
        args << ToDartConversions::type(instantiation);
    }

    return QString("<%1>").arg(args.join(","));
}

QString ToDartConversions::className(const AbstractMetaClass *metaClass,
                                     AbstractMetaType templateInstantiation,
                                     FunctionFormatOptions opts)
{
    if (!metaClass)
        return {};

    QString name = metaClass->name();
    if (opts & FunctionFormatOption::TemplateArgs) {
        name = name += templateArgs(metaClass);
    } else if (opts & FunctionFormatOption::TemplateParams) {
        name = name += templateParams(templateInstantiation);
    }

    if (opts & FunctionFormatOption::QualifiedWithScope) {
        const QString scope = DartagnanGeneratorBase::m_optionsFromJson.scopeForType(metaClass);
        if (!scope.isEmpty())
            name = QStringLiteral("%1.%2").arg(scope, name);
    }

    return name;
}

QString ToDartConversions::className(AbstractMetaType type, FunctionFormatOptions opts)
{
    const AbstractMetaClass *metaClass = Dartagnan::classForType(type);
    if (!metaClass) {
        qWarning() << "No class found for type" << type.name() << "Maybe not in bindings_global.h";
        qFatal("Aborting...");
    }

    return className(metaClass, type, opts);
}

QString ToDartConversions::cFunctionNameText(const AbstractMetaFunction *method)
{
    auto metaClass = method->ownerClass();

    const QHash<const AbstractMetaClass *, QVector<AbstractMetaType>> templateHash =
        DartGenerator::instance()->templateHash();


    const auto list = templateHash.value(metaClass);
    if (list.isEmpty() || !metaClass)
        return ToCConversions::functionName(method);

    return QString("${getCFunctionName(%1)}").arg(Dartagnan::idForFunction(method));
}

QString ToDartConversions::finalizerMemberVariableName(AbstractMetaType templateInstantiation)
{
    return QString("_finalizer%1").arg(ToCConversions::templateArgs(templateInstantiation));
}

QString ToDartConversions::returnType(const AbstractMetaFunction *func,
                                      FunctionFormatOptions formatOpts)
{
    AbstractMetaType type = func->type();
    if (type.typeUsagePattern() == AbstractMetaType::TemplateArgument) {
        // It's an argument like T. We need to find it's actual instantiation

        return type.name();
        /*const AbstractMetaClass *metaClass = func->ownerClass();
        if (!metaClass || metaClass->isNamespace()) {
            qWarning() << Q_FUNC_INFO << "Only class templates supported";
            return {};
        }*/

    } else {
        return className(type, formatOpts);
    }
}

QString ToDartConversions::cleanReservedKeywords(const QString &name)
{
    if (name == QLatin1String("var")) {
        return QString("%1_dart").arg(name);
    }

    return name;
}

bool ToDartConversions::typeIsNullable(AbstractMetaArgument arg)
{
    if (arg.defaultValueExpression() == "nullptr")
        return true;

    auto type = arg.type();
    if (type.isValuePointer() || type.isNativePointer() || type.isObject())
        return true;



    return false;
}

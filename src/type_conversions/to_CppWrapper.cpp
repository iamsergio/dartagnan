/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "to_CppWrapper.h"
#include "generator_base.h"
#include "typedatabase.h"

#include <QDebug>

using namespace Dartagnan;

namespace ToCppWrapperConversions {

QString type(const AbstractMetaFunction *func)
{
    if (hasType(func->type())) {
        return type(func->type());
    }

    if (func->isConstructor() || func->isDestructor())
        return {};

    return "void";
}

bool isValueClass(AbstractMetaType type)
{
    if (!hasType(type))
        return false;

    if (type.isValue()) {
        return true;
    }

    return false;
}

QString type(AbstractMetaType t, AbstractMetaType templateInstantiation,
             const AbstractMetaClass *protecedEnumWorkaroundFor, Options options)
{
    if (protecedEnumWorkaroundFor && hasType(t) && t.isEnum()) {
        AbstractMetaEnum metaEnum = enumForType(t);
        if (metaEnum.typeEntry() && metaEnum.isProtected()) {
            // For the C function to access a protected enum, we need to qualify it with
            // the wrapper's name, as there we redeclared it as public
            return QString("%1::%2").arg(
                ToCppWrapperConversions::wrapperClassName(protecedEnumWorkaroundFor),
                metaEnum.name());
        }
    }

    QString star;
    if ((options & Option::ForVirtualCallbackReturnType) && isValueClass(t)
        && !t.cppSignature().contains("&")) {
        // Our virtual callbacks return ffi.Pointer<void> for value types, so suffix our
        // function typedef return type with *
        star = "*";
    };

    if (!hasType(templateInstantiation))
        return t.cppSignature() + star;

    if (t.typeUsagePattern() == AbstractMetaType::TemplateArgument) {
        // Means the function returns for example T

        AbstractMetaType actualtype = instantiationForTemplateArgument(templateInstantiation, t);

        return type(actualtype);

    } else if (t.hasInstantiations() && t.hasTemplateChildren()) {
        // This means it's return Foo<T>, we need to replace T with the actual instantiated type

        // Get the class, for example MyTemplate<T>
        return instantiationsTextForTemplateArguments(templateInstantiation, t,
                                                      TemplateFormatOption::IncludeClassName);
    }

    return t.cppSignature();
}

QString returnType(const AbstractMetaFunction *func, AbstractMetaType templateInstantiation,
                   ToCppWrapperConversions::Options options)
{
    if (func->isConstructor() || func->isDestructor())
        return {};

    auto t = func->type();
    if (hasType(t))
        return type(t, templateInstantiation, nullptr, options);

    return "void";
}

QString arguments(const AbstractMetaFunction *func, FunctionFormatOptions formatOpts,
                  Options options)
{
    QStringList result;

    const auto arguments = func->arguments();
    for (AbstractMetaArgument argument : arguments) {
        QString defaultArgumentExpression;
        if ((formatOpts & FunctionFormatOption::DefaultArgumentExpr)
            && argument.hasDefaultValueExpression())
            defaultArgumentExpression = QString(" = %1").arg(argument.defaultValueExpression());

        result << QStringLiteral("%1 %2%3").arg(type(argument.type(), {}, {}, options),
                                                argument.name(), defaultArgumentExpression);
    }

    return result.join(',');
}

QString callArguments(const AbstractMetaFunction *func, Dartagnan::GeneratedCodeType loc,
                      AbstractMetaType instantiation)
{
    QStringList result;
    if (loc == Dartagnan::GeneratedCodeType_CppwrapperVirtualCallback) {
        result << "const_cast<void *>(thisPtr)";
    }

    for (AbstractMetaArgument arg : func->arguments()) {
        QString argText;
        if (arg.type().isEnum() && (loc & Dartagnan::GeneratedCodeType_FFI_C)) {
            argText = QStringLiteral("static_cast<%1>(%2)")
                          .arg(type(arg.type(), instantiation, func->ownerClass()), arg.name());
        } else if (loc == Dartagnan::GeneratedCodeType_CppwrapperVirtualCallback
                   && arg.type().isValue() && !arg.type().cppSignature().contains("&")) {
            argText = QString("&%1").arg(arg.name());
        } else {
            argText = arg.name();
        }

        result << argText;
    }

    return result.join(',');
}

QString qualifiedWrapperMethodName(const AbstractMetaFunction *func,
                                   Dartagnan::FunctionFormatOptions formatOpts,
                                   AbstractMetaType instantiation)
{
    Q_ASSERT(func);
    return QString("%1::%2")
        .arg(wrapperClassName(func->ownerClass(), formatOpts, instantiation))
        .arg(func->originalName());
}

QString wrappersNamespace()
{
    return TypeDatabase::instance()->defaultPackageName() + "_wrappersNS";
}

QString wrapperClassName(const AbstractMetaClass *metaClass,
                         Dartagnan::FunctionFormatOptions formatOpts,
                         AbstractMetaType instantiation)
{
    if (!metaClass)
        return QString();

    if (metaClass->isNamespace()) {
        // For global functions, our C wrappers call the target functions directly, without
        // wrapper C++ classes.
        return metaClass->name();
    } else {

        const QString scope = DartagnanGeneratorBase::m_optionsFromJson.scopeForType(metaClass);

        QString name = scope.isEmpty()
            ? QStringLiteral("%1::%2").arg(wrappersNamespace(), wrapperName(metaClass))
            : QStringLiteral("%1::%2::%3").arg(wrappersNamespace(), scope, wrapperName(metaClass));

        if (formatOpts & FunctionFormatOption::TemplateArgs) {
            name = name + templateArgs(metaClass);
        } else if (hasType(instantiation) && (formatOpts & FunctionFormatOption::TemplateParams)) {
            name = name + templateParams(instantiation);
        }

        return name;
    }
}

QString wrapperName(const AbstractMetaClass *metaClass, Dartagnan::FunctionFormatOptions formatOpts)
{
    QString name = metaClass->name() + "_wrapper";

    if (formatOpts & FunctionFormatOption::TemplateArgs)
        name = name + templateArgs(metaClass);

    return name;
}

QString wrapperMethodName(const AbstractMetaFunction *func)
{
    if (func->isConstructor() | func->isDestructor())
        return wrapperName(func->ownerClass());

    return func->originalName();
}

QString virtualCallbackFunctionPointer(const AbstractMetaFunction *func, const QString &name)
{
    QString args =
        ToCppWrapperConversions::arguments(func, {}, Option::ForVirtualCallbackReturnType);
    if (args.isEmpty())
        args = "void *";
    else
        args.prepend("void *,");

    return QString("%1 (*%2)(%3)")
        .arg(ToCppWrapperConversions::returnType(func, {}, Option::ForVirtualCallbackReturnType),
             name, args);
}

QString virtualCallbackMemberName(const AbstractMetaFunction *func)
{
    return QString("m_%1Callback").arg(DartOverloadRegistry::instance().nameForMethod(func));
}

QString virtualCallbackTypedefName(const AbstractMetaFunction *func)
{
    return QString("Callback_%1").arg(DartOverloadRegistry::instance().nameForMethod(func));
}

QString templateString(const AbstractMetaClass *metaClass)
{
    const int numTemplateArgs = metaClass->templateArguments().size();
    if (numTemplateArgs == 0)
        return {};

    QStringList args;
    for (auto templateArg : metaClass->templateArguments())
        args << QString("typename %1").arg(templateArg->name());

    return QString("template <%1>").arg(args.join(","));
}

QString templateArgs(const AbstractMetaClass *metaClass)
{
    const int numTemplateArgs = metaClass->templateArguments().size();
    if (numTemplateArgs == 0)
        return {};

    QStringList args;
    for (auto templateArg : metaClass->templateArguments()) {
        args << templateArg->name();
    }

    return QString("<%1>").arg(args.join(","));
}

QString templateParams(AbstractMetaType type)
{
    if (!hasType(type) || type.instantiations().isEmpty())
        return {};

    QStringList args;
    for (AbstractMetaType instantiation : type.instantiations()) {
        args << instantiation.cppSignature();
    }

    return QString("<%1>").arg(args.join(","));
}

QString qualifiedClassName(const AbstractMetaClass *metaClass, FunctionFormatOptions formatOpts)
{
    QString name = metaClass->qualifiedCppName();
    if (formatOpts & FunctionFormatOption::TemplateArgs)
        name = name + templateArgs(metaClass);

    return name;
}

} // namespace ToCppWrapperConversions

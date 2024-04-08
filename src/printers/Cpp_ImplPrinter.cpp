/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "Cpp_ImplPrinter.h"
#include "type_conversions/to_CppWrapper.h"

using namespace Dartagnan;

MethodImplPrinterBase::MethodImplPrinterBase(TextStream &s, const AbstractMetaFunction *func,
                                             AbstractMetaType instantiation)
    : Printer(s)
    , m_metaClass(func->ownerClass())
    , m_method(func)
    , m_instantiation(instantiation)
{
}

MethodImplPrinterBase::~MethodImplPrinterBase()
{
    s << "}\n";
}

bool MethodImplPrinterBase::needsReturn() const
{
    return hasType(m_method->type());
}

MethodImplPrinter::MethodImplPrinter(TextStream &s, const AbstractMetaFunction *func)
    : MethodImplPrinterBase(s, func)
{
    const QString className = m_metaClass->name();
    const QString qualifiedClassName = ToCppWrapperConversions::qualifiedClassName(
        m_metaClass, FunctionFormatOption::TemplateArgs);
    const QString arguments = ToCppWrapperConversions::arguments(func);

    s << ToCppWrapperConversions::templateString(m_metaClass);
    s << QString("%1 %2::%3(%4)%5")
             .arg(ToCppWrapperConversions::returnType(m_method),
                  ToCppWrapperConversions::wrapperName(m_metaClass,
                                                       FunctionFormatOption::TemplateArgs),
                  m_method->originalName(), arguments,
                  (m_method->isConstant() ? QString("const") : QString()));
    s << "{";
    ADD_READBILITY_TAG(1000);

    const QString returnText = needsReturn() ? QString("return ") : QString();
    const QString callArguments = ToCppWrapperConversions::callArguments(
        m_method, Dartagnan::GeneratedCodeType_Cppwrapper, {});
    const QString targetMethodCall =
        QString("::%1::%2(%3);").arg(qualifiedClassName, m_method->originalName(), callArguments);

    if (func->isVirtual()) {
        // If the method is virtual, C++ must ask Dart if it was overridden by the user.
        const QString callbackName = ToCppWrapperConversions::virtualCallbackMemberName(func);
        s << QString("if (%1) {").arg(callbackName);
        ADD_READBILITY_TAG(1001);

        if (generatesQDebugStatements())
            s << QString("qDebug() << \"Debug:\" << Q_FUNC_INFO << this;\n");

        s << "const void* thisPtr = this;\n";
        s << returnText;
        const QString dereference = ToCppWrapperConversions::isValueClass(func->type()) ? "*" : "";
        const QString expression =
            QString("%1%2(%3);")
                .arg(dereference, callbackName,
                     ToCppWrapperConversions::callArguments(
                         m_method, Dartagnan::GeneratedCodeType_CppwrapperVirtualCallback, {}));

        s << expression;

        s << "} else {";
        if (func->isAbstract()) { // don't call base class if it's pure virtual
            ADD_READBILITY_TAG(1015);
            s << Dartagnan::emptyReturnStatementFor(func);
        } else {
            ADD_READBILITY_TAG(1002);
            s << returnText << targetMethodCall;
        }

        s << "}";
        s << "}";

        // C can't call protected C++ methods, so we need an overload (here suffixed with
        // _nocallback) to call the base method directly, bypassing protected. Also, since this is
        // called by dart, we don't call into dart (hence nocallback)
        ADD_READBILITY_TAG(1009)
        s << QString("%1 %2::%3_nocallback(%4)%5")
                 .arg(ToCppWrapperConversions::returnType(m_method),
                      ToCppWrapperConversions::wrapperName(m_metaClass), m_method->originalName(),
                      arguments, (m_method->isConstant() ? QString("const") : QString()));
        s << "{";
        ADD_READBILITY_TAG(1003);

        if (func->isAbstract()) {
            ADD_READBILITY_TAG(1007);
            s << Dartagnan::emptyReturnStatementFor(func);
        } else {
            s << returnText << targetMethodCall;
        }
    } else {
        ADD_READBILITY_TAG(1004);
        s << returnText << targetMethodCall;
    }
}

DtorImplPrinter::DtorImplPrinter(TextStream &s, const AbstractMetaFunction *func)
    : MethodImplPrinterBase(s, func)
{
    const QString className =
        ToCppWrapperConversions::wrapperName(m_metaClass, FunctionFormatOption::TemplateArgs);
    const QString dtorName = ToCppWrapperConversions::wrapperName(m_metaClass);
    ADD_READBILITY_TAG(1005);
    s << ToCppWrapperConversions::templateString(m_metaClass);
    s << QString("%1::~%2() {").arg(className, dtorName);
}

CtorImplPrinter::CtorImplPrinter(TextStream &s, const AbstractMetaFunction *func)
    : MethodImplPrinterBase(s, func)
{
    const QString className =
        ToCppWrapperConversions::wrapperName(m_metaClass, FunctionFormatOption::TemplateArgs);
    const QString ctorName = ToCppWrapperConversions::wrapperName(m_metaClass);
    ADD_READBILITY_TAG(1006);
    s << ToCppWrapperConversions::templateString(m_metaClass);
    s << QString("%1::%2(%3) : ::%4(%5) {")
             .arg(className)
             .arg(ctorName)
             .arg(ToCppWrapperConversions::arguments(func))
             .arg(ToCppWrapperConversions::qualifiedClassName(m_metaClass,
                                                              FunctionFormatOption::TemplateArgs))
             .arg(ToCppWrapperConversions::callArguments(
                 func, Dartagnan::GeneratedCodeType_Cppwrapper, {}));
}

std::unique_ptr<MethodImplPrinterBase> createMethodPrinter(TextStream &s,
                                                           const AbstractMetaFunction *func)
{
    if (!Dartagnan::acceptsMethod(func))
        return {};

    if (func->hasInjectedCode()) {
        const CodeSnipList snips = func->injectedCodeSnips();
        for (const CodeSnip &snip : snips) {
            s << "\n" << snip.code() << "\n";
            return {};
        }
    }

    const bool isFinal = func->attributes() & AbstractMetaFunction::FinalCppMethod;
    if (isFinal)
        return {};

    MethodImplPrinterBase *printer = nullptr;
    if (func->isConstructor())
        printer = new CtorImplPrinter(s, func);
    else if (func->isDestructor())
        printer = new DtorImplPrinter(s, func);
    else {
        printer = new MethodImplPrinter(s, func);
    }

    return std::unique_ptr<MethodImplPrinterBase>(printer);
}

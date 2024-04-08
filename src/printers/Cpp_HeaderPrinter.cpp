/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "Cpp_HeaderPrinter.h"
#include "type_conversions/to_CppWrapper.h"

#include <QDebug>

using namespace Dartagnan;

ClassPrinter::ClassPrinter(TextStream &s, const AbstractMetaClass *metaClass)
    : s(s)
    , m_metaClass(metaClass)
    , m_className(metaClass->name())
    , m_wrapperClassName(ToCppWrapperConversions::wrapperName(metaClass))
{
}

ClassPrinter::~ClassPrinter()
{
    s << "};\n";
}

void ClassPrinter::printMembers()
{
}

void ClassPrinter::printMethods()
{
    const auto methods = m_metaClass->functions();
    for (auto m : methods) {
        const AbstractMetaFunction *method = m.get();
        if (!Dartagnan::acceptsMethod(method))
            continue;

        if (m_seenFunctions.functionWasSeen(method))
            continue;

        m_seenFunctions.markAsSeen(method);

        const bool isFinal = m->attributes() & AbstractMetaFunction::FinalCppMethod;
        if (isFinal)
            continue;

        ADD_READBILITY_TAG(1041) if (method->isStatic()) s << "static ";

        const QString constStr = method->isConstant() ? "const" : QString();
        const QString argumentsStr =
            ToCppWrapperConversions::arguments(method, FunctionFormatOption::DefaultArgumentExpr);

        if (method->isVirtual())
            s << "virtual ";

        s << QString("%1 %2(%3)%4;")
                 .arg(ToCppWrapperConversions::returnType(method),
                      ToCppWrapperConversions::wrapperMethodName(method), argumentsStr, constStr);


        if (method->isVirtual()) {
            ADD_READBILITY_TAG(1008)
            s << QString("virtual %1 %2_nocallback(%3)%4;")
                     .arg(ToCppWrapperConversions::returnType(method),
                          ToCppWrapperConversions::wrapperMethodName(method), argumentsStr,
                          constStr);
        }
    }
}

void ClassPrinter::printVirtualCallbacks()
{
    const auto methods = m_metaClass->functions();
    for (auto m : methods) {
        const AbstractMetaFunction *method = m.get();
        if (!Dartagnan::acceptsMethod(method) || !method->isVirtual())
            continue;

        const QString functionTypedefName =
            ToCppWrapperConversions::virtualCallbackTypedefName(method);
        ADD_READBILITY_TAG(1042)
        s << QString("typedef %1;")
                 .arg(ToCppWrapperConversions::virtualCallbackFunctionPointer(method,
                                                                              functionTypedefName));
        s << QString("%1 %2 = nullptr;")
                 .arg(functionTypedefName,
                      ToCppWrapperConversions::virtualCallbackMemberName(method));
    }
}

static void printProtectedEnumsWorkaround(TextStream &s, const AbstractMetaClass *metaClass)
{
    if (!metaClass)
        return;

    for (auto baseClass : metaClass->baseClasses())
        printProtectedEnumsWorkaround(s, baseClass);

    const QString baseClassName = QString("::%1%2").arg(
        metaClass->qualifiedCppName(), ToCppWrapperConversions::templateArgs(metaClass));
    for (auto metaEnum : metaClass->enums()) {
        if (metaEnum.isProtected()) {
            s << QString("using %1::%2;\n").arg(baseClassName, metaEnum.name());
        }
    }
}

PolymorphicClassPrinter::PolymorphicClassPrinter(TextStream &s, const AbstractMetaClass *metaClass)
    : ClassPrinter(s, metaClass)
{
    ADD_READBILITY_TAG(1017)
    s << ToCppWrapperConversions::templateString(metaClass);
    const QString baseClassName = QString("::%1%2").arg(
        metaClass->qualifiedCppName(), ToCppWrapperConversions::templateArgs(metaClass));
    s << QString("class %1 : public %2 {").arg(m_wrapperClassName, baseClassName);
    s << "public:\n";
    s << QString("~%1();").arg(m_wrapperClassName); // Our polymorphic wrappers always have dtor

    // The C functions can static cast to protected enums, so print a workaround
    printProtectedEnumsWorkaround(s, metaClass);
}

NonPolymorphicClassPrinter::NonPolymorphicClassPrinter(TextStream &s,
                                                       const AbstractMetaClass *metaClass)
    : ClassPrinter(s, metaClass)
{
    ADD_READBILITY_TAG(1043)
    s << ToCppWrapperConversions::templateString(metaClass);
    s << QString("class %1 : public ::%2%3 {")
             .arg(m_wrapperClassName, metaClass->qualifiedCppName(),
                  ToCppWrapperConversions::templateArgs(metaClass));
    s << "public:\n";
    s << QString("~%1();").arg(m_wrapperClassName); // TODO
}

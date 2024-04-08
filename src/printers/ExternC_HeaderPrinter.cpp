/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "ExternC_HeaderPrinter.h"
#include "generator_dart.h"
#include "typedatabase.h"

#include <QDebug>

using namespace Dartagnan;

ExternCHeaderPrinter::ExternCHeaderPrinter(TextStream &s, const AbstractMetaClass *metaClass,
                                           AbstractMetaType instantiation, bool pureCOnly)
    : ExternCPrinterBase(s, metaClass, instantiation, pureCOnly)
{

    const FunctionFormatOptions opt =
        pureCOnly ? FunctionFormatOption::Default : FunctionFormatOption::ExportMacro;
    const auto methods = metaClass->functions();
    bool seenDtor = false;
    for (auto method : methods) {
        if (!Dartagnan::acceptsMethod(method.get(), RejectedMethod::RejectedMethod_Default)
            || m_seenFunctions.functionWasSeen(method.get()))
            continue;

        m_seenFunctions.markAsSeen(method.get());

        ADD_READBILITY_TAG(1067)
        s << QString("// %1::%2\n").arg(metaClass->qualifiedCppName(), method->signature());
        s << ToCConversions::functionSignature(method.get(), opt, instantiation) << ";\n";
        if (method->isDestructor())
            seenDtor = true;

        if (method->isSignal() && DartGenerator::instance()->m_optionsFromJson.supportsQtSignals) {
            ADD_READBILITY_TAG(1078)
            s << ToCConversions::functionSignature(
                method.get(), FunctionFormatOptions(opt | FunctionFormatOption::ForSignalHandler),
                instantiation)
              << ";";
        }
    }

    if (!seenDtor && !metaClass->isNamespace()) {
        ADD_READBILITY_TAG(1066)
        auto dtor = Dartagnan::createDestructor(metaClass);
        s << ToCConversions::functionSignature(dtor.get(), opt, instantiation) << ";\n";
    }

    // Also print the C getters/setters for members:

    auto getters =
        Dartagnan::syntheticGetters(metaClass, Dartagnan::GeneratedCodeType_Cppwrapper_header);
    auto setters =
        Dartagnan::syntheticSetters(metaClass, Dartagnan::GeneratedCodeType_Cppwrapper_header);

    for (const auto &func : getters) {
        ADD_READBILITY_TAG(1044)
        s << ToCConversions::functionSignature(func.get(), opt, instantiation) << ";\n";
    }

    for (const auto &func : setters) {
        ADD_READBILITY_TAG(1045)
        s << ToCConversions::functionSignature(func.get(), opt, instantiation) << ";\n";
    }

    if (m_metaClass->isPolymorphic()) {
        ADD_READBILITY_TAG(1046)
        s << ToCConversions::registerCallbackFunctionSignature(metaClass, opt) << ";";
    }
    ADD_READBILITY_TAG(1047)
    s << ToCConversions::finalizerSignature(metaClass, opt, instantiation) << ";";
}

/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#include "printers.h"

/**
 * @brief Prints the C functions that Dart ffi will call.
 * These extern "C" functions will then call the normal C++ methods.
 *
 * This only prints the declarations (in the headers) see also ExternCImplPrinter which prints
 * the implementation
 */
class ExternCHeaderPrinter : public ExternCPrinterBase
{
public:
    explicit ExternCHeaderPrinter(TextStream &s, const AbstractMetaClass *metaClass,
                                  AbstractMetaType instantiation = {}, bool pureCOnly = false);

private:
    Dartagnan::SeenFunctions m_seenFunctions;
};

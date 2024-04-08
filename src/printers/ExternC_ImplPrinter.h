/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#include "Cpp_ImplPrinter.h"
#include "printers.h"

class MethodImplPrinterBase;

std::unique_ptr<MethodImplPrinterBase> createExternCMethodPrinter(TextStream &s,
                                                                  const AbstractMetaFunction *func,
                                                                  AbstractMetaType instantiation);

/// @brief Iterates the class and creates impl for all methods and members
class ExternCImplPrinter : public ExternCPrinterBase
{
public:
    explicit ExternCImplPrinter(TextStream &s, const AbstractMetaClass *metaClass,
                                AbstractMetaType instantiation = {});

private:
    Dartagnan::SeenFunctions m_seenFunctions;
};

/// @brief Prints an extern "C" method body
class ExternCMethodImplPrinter : public MethodImplPrinterBase
{
public:
    explicit ExternCMethodImplPrinter(TextStream &s, const AbstractMetaFunction *func,
                                      AbstractMetaType instantiation);
};

/// @brief Prints an extern "C" CTOR body
class ExternCCtorImplPrinter : public MethodImplPrinterBase
{
public:
    explicit ExternCCtorImplPrinter(TextStream &s, const AbstractMetaFunction *func,
                                    AbstractMetaType instantiation);
};

/// @brief Prints an extern "C" DTOR body
class ExternCDtorImplPrinter : public MethodImplPrinterBase
{
public:
    explicit ExternCDtorImplPrinter(TextStream &s, const AbstractMetaFunction *func,
                                    AbstractMetaType instantiation);
};

/// @brief Prints an extern "C" member variable getter
class ExternCGetterImplPrinter : public MethodImplPrinterBase
{
public:
    explicit ExternCGetterImplPrinter(TextStream &s, const AbstractMetaFunction *func,
                                      AbstractMetaType instantiation);
};

/// @brief Prints an extern "C" member variable setter
class ExternCSetterImplPrinter : public MethodImplPrinterBase
{
public:
    explicit ExternCSetterImplPrinter(TextStream &s, const AbstractMetaFunction *func,
                                      AbstractMetaType instantiation);
};

/// @brief Prints the signal handler
class ExternCSignalHandlerPrinter : public MethodImplPrinterBase
{
public:
    explicit ExternCSignalHandlerPrinter(TextStream &s, const AbstractMetaFunction *);
};

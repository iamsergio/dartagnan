/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#include "printers.h"

class MethodImplPrinterBase;
std::unique_ptr<MethodImplPrinterBase> createMethodPrinter(TextStream &s,
                                                           const AbstractMetaFunction *func);

class MethodImplPrinterBase : public Printer
{
public:
    explicit MethodImplPrinterBase(TextStream &s, const AbstractMetaFunction *func,
                                   AbstractMetaType instantiation = {});
    ~MethodImplPrinterBase();

    ///@brief Returns whether we need a 'return' statement. False if it's a void method.
    bool needsReturn() const;

protected:
    const AbstractMetaClass *m_metaClass;
    const AbstractMetaFunction *m_method;
    const AbstractMetaType m_instantiation;
};

class MethodImplPrinter : public MethodImplPrinterBase
{
public:
    explicit MethodImplPrinter(TextStream &s, const AbstractMetaFunction *);
};

class DtorImplPrinter : public MethodImplPrinterBase
{
public:
    explicit DtorImplPrinter(TextStream &s, const AbstractMetaFunction *func);
};

class CtorImplPrinter : public MethodImplPrinterBase
{
public:
    explicit CtorImplPrinter(TextStream &s, const AbstractMetaFunction *func = nullptr);
};

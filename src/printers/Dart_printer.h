/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#include "printers.h"

class DartFunctionPrinterBase;

std::unique_ptr<DartFunctionPrinterBase>
createDartFunctionPrinter(TextStream &s, const AbstractMetaFunction *func);

class DartClassPrinter : public Printer
{
public:
    explicit DartClassPrinter(TextStream &s, const AbstractMetaClass *metaClass);
    ~DartClassPrinter();

private:
    void printGetterText(AbstractMetaField field);
    void printSetterText(AbstractMetaField field);
    void printOverriddenMethodHelpers(TextStream &s, const AbstractMetaClass *metaclass);

    Dartagnan::SeenFunctions m_seenFunctions;
};

class DartNamespacePrinter : public Printer
{
public:
    explicit DartNamespacePrinter(TextStream &s, const AbstractMetaClass *metaClass);
};

class DartFunctionPrinterBase : public Printer
{
public:
    explicit DartFunctionPrinterBase(TextStream &s, const AbstractMetaFunction *func);
    ~DartFunctionPrinterBase();

protected:
    const AbstractMetaFunction *m_func;
};

class DartDtorPrinter : public DartFunctionPrinterBase
{
public:
    explicit DartDtorPrinter(TextStream &s, const AbstractMetaFunction *func);
};

class DartCtorPrinter : public DartFunctionPrinterBase
{
public:
    explicit DartCtorPrinter(TextStream &s, const AbstractMetaFunction *func);
};

class DartGlobalFuncPrinter : public DartFunctionPrinterBase
{
public:
    explicit DartGlobalFuncPrinter(TextStream &s, const AbstractMetaFunction *func);
};

class DartMethodPrinter : public DartFunctionPrinterBase
{
public:
    explicit DartMethodPrinter(TextStream &s, const AbstractMetaFunction *func);
};

class DartSignalHandlerPrinter : public DartFunctionPrinterBase
{
public:
    explicit DartSignalHandlerPrinter(TextStream &s, const AbstractMetaFunction *func);
};

class DartEnumPrinter : public Printer
{
public:
    explicit DartEnumPrinter(TextStream &s, AbstractMetaEnum, const AbstractMetaClass *context);
};

/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#include "dartagnan.h"
#include "generator_base.h"
#include "type_conversions/to_C.h"

#include <QString>
#include <QTextStream>

/// RAII style printer
class Printer
{
public:
    explicit Printer(TextStream &s)
        : s(s)
    {
    }

    virtual ~Printer();

protected:
    TextStream &s;

private:
    Q_DISABLE_COPY(Printer);
};

class NamespacePrinter : public Printer
{
public:
    explicit NamespacePrinter(TextStream &s, const QString nsName);
    ~NamespacePrinter();
};

class ExternCPrinterBase : public Printer
{
public:
    explicit ExternCPrinterBase(TextStream &s, const AbstractMetaClass *metaClass,
                                AbstractMetaType instantiation = {}, bool pureCOnly = false);
    ~ExternCPrinterBase();

protected:
    const AbstractMetaClass *const m_metaClass;
    const AbstractMetaType m_instantiation;
    const bool m_pureCOnly;
};

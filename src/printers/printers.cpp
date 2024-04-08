/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "printers.h"

#include <QDebug>

Printer::~Printer()
{
}

NamespacePrinter::NamespacePrinter(TextStream &s, const QString nsName)
    : Printer(s)
{
    s << QString("namespace %1 {").arg(nsName);
}

NamespacePrinter::~NamespacePrinter()
{
    s << QString("}");
}

ExternCPrinterBase::ExternCPrinterBase(TextStream &s, const AbstractMetaClass *metaClass,
                                       AbstractMetaType instantiation, bool pureCOnly)
    : Printer(s)
    , m_metaClass(metaClass)
    , m_instantiation(instantiation)
    , m_pureCOnly(pureCOnly)
{
    if (!pureCOnly)
        s << "extern \"C\" {\n";
}

ExternCPrinterBase::~ExternCPrinterBase()
{
    if (!m_pureCOnly)
        s << "}\n";
}

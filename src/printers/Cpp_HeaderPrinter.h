/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#include "printers.h"

// RAII style printers
class ClassPrinter
{
public:
    explicit ClassPrinter(TextStream &s, const AbstractMetaClass *metaClass);
    ~ClassPrinter();

    void printMembers();
    void printMethods();
    void printVirtualCallbacks();

protected:
    TextStream &s;
    const AbstractMetaClass *const m_metaClass;
    const QString m_className;
    const QString m_wrapperClassName;

private:
    Dartagnan::SeenFunctions m_seenFunctions;
    Q_DISABLE_COPY(ClassPrinter);
};

class PolymorphicClassPrinter : public ClassPrinter
{
public:
    explicit PolymorphicClassPrinter(TextStream &s, const AbstractMetaClass *metaClass);
};

class NonPolymorphicClassPrinter : public ClassPrinter
{
public:
    explicit NonPolymorphicClassPrinter(TextStream &s, const AbstractMetaClass *metaClass);
};

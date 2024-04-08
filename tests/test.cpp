/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "test.h"

#include <QDebug>

using namespace TestTargetNS;

int MyBaseClass::s_staticMember = 1;
const int MyBaseClass::s_staticConstMember = 1;

int DestructorCounter::s_instanceCount = 0;
int MyBaseClass::s_instanceCount = 0;
int MyDerivedClass::s_instanceCount = 0;
int PureAbstract::s_instanceCount = 0;

TEST_EXPORT int s_myTemplateInstanceCount = 0;

int MyBaseClass::foo() const
{
    return 42;
}

int MyBaseClass::bar() const
{
    return 42;
}

int MyDerivedClass::bar() const
{
    return 43;
}

int POD::calculateStatic()
{
    qDebug() << Q_FUNC_INFO;
    return 42;
}

int POD::doStuffOnMyClass(MyBaseClass *)
{
    return 42;
}

struct MemoryLeakChecker
{
    // Since there's no easy way to force GC in Dart, we run this at static-dtors time
    // and make sure that there are 0 DestructorCounter instances
    ~MemoryLeakChecker()
    {

        if (TestTargetNS::DestructorCounter::s_instanceCount != 0
            || TestTargetNS::MyDerivedClass::s_instanceCount != 0
            || TestTargetNS::MyBaseClass::s_instanceCount != 0
            || TestTargetNS::PureAbstract::s_instanceCount != 0 || s_myTemplateInstanceCount != 0) {
            qWarning() << "Memory leaks found." << TestTargetNS::DestructorCounter::s_instanceCount
                       << TestTargetNS::MyDerivedClass::s_instanceCount
                       << TestTargetNS::MyBaseClass::s_instanceCount
                       << TestTargetNS::PureAbstract::s_instanceCount << s_myTemplateInstanceCount;
            abort();
        }
    }
};

MyObject::MyObject(QObject *parent)
    : QObject(parent)
{
}

MyObject::~MyObject() {};

int MyObject::virtualFunc()
{
    return 42;
}

void MyObject::virtualReceivingQString(const QString &)
{
}

static MemoryLeakChecker s_memoryLeakChecker;

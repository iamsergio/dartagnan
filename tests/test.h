/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#include "test_exports.h"

#include <QDebug>
#include <QList>
#include <QObject>
#include <QString>

#include <string>
#include <type_traits>

extern TEST_EXPORT int s_myTemplateInstanceCount;

inline void globalReceivingStringView(std::string_view)
{
}

enum class MyEnumClass {
    Value = 1,
    ValueFoo
};

struct EmptyStruct
{
};

struct SimpleStruct
{
    int value = 1;
};

struct SimpleObjectStruct
{
    void receivesStructWithDefaultArg(SimpleObjectStruct = {})
    {
    }

    void receivesStringView(std::string_view)
    {
    }

    void receivesString(std::string)
    {
    }

    std::string returnsString() const
    {
        return {};
    }
};

struct NonCopiable
{
    int count() const
    {
        return 1000;
    }

    NonCopiable() = default;
    Q_DISABLE_COPY(NonCopiable)
};

namespace AnotherNamespace {
// Tests that the wrapper includes <QString.h>
static QString size(QString s)
{
    return s;
}
enum NamespaceLevelEnum {
    NamespaceLevelEnum_value1 = 1,
    NamespaceLevelEnum_value2 = 2
};
Q_DECLARE_FLAGS(NamespaceLevelEnums, NamespaceLevelEnum)

struct AnotherNamespaceStruct
{
    void receivesEnumerator(NamespaceLevelEnum = NamespaceLevelEnum_value2)
    {
    }
};

enum class MyNamespacedEnumClass {
    ValueFoo1
};


}

template<typename T>
struct MyTemplate
{
    T value;
    int returnInt() const
    {
        return 1;
    }

    MyTemplate()
    {
        s_myTemplateInstanceCount++;
    }

    MyTemplate returnsTemplate()
    {
        return {};
    }

    T returnsT()
    {
        return {};
    }

    MyTemplate<EmptyStruct> returnTemplate2()
    {
        return {};
    }

    MyTemplate<EmptyStruct *> returnTemplate3()
    {
        return {};
    }

    MyTemplate<const EmptyStruct *> returnTemplate4()
    {
        return {};
    }

    MyTemplate(const MyTemplate<T> &other)
    {
        s_myTemplateInstanceCount++;
    }

    ~MyTemplate()
    {
        s_myTemplateInstanceCount--;
    }

    int receivesTemplate(MyTemplate<T>)
    {
        return 30;
    }

    int receivesT(T)
    {
        return 31;
    }

    static void staticInTemplateClass()
    {
    }
};

template<typename T0, typename T1>
struct MyTemplateWithTwoArgs
{
    T0 value0;
    T1 value1;

    int returnInt() const
    {
        return 1;
    }

    MyTemplateWithTwoArgs()
    {
        s_myTemplateInstanceCount++;
    }

    ~MyTemplateWithTwoArgs()
    {
        s_myTemplateInstanceCount--;
    }
};

template<typename T>
struct MyTemplate2
{
    MyTemplate2<NonCopiable *> returnTemplate1()
    {
        return {};
    }

    int count() const
    {
        return 1000;
    }

    void receivesT(T)
    {
    }

    void assignsT()
    {
        T a;
        T b;
        a = b;
    }

    T m_value = {};
};

template<typename T>
struct UnusedTemplate
{
    // For testing that we don't generate these methods, as we don't have any instantiations
    bool receivesT(T) const
    {
        return false;
    }
    T returnsT()
    {
        return {};
    }
};

/**
 * Contains simple C++ function that we call from Dart, for demo/testing purposes.
 * This is built as libTestTarget.so.
 * The generated bindings for this class are in libMyBindings.so
 **/
namespace TestTargetNS {


class TEST_EXPORT PureAbstract
{
public:
    virtual int foo() = 0;
    virtual void voidPureAbstract() = 0;
    virtual void renamedPureVirtual() = 0;
    static void renamedStatic()
    {
    }

    static int s_instanceCount;
    PureAbstract()
    {
        s_instanceCount++;
    }

    virtual ~PureAbstract()
    {
        s_instanceCount--;
    }

    int callVirtualReceivingPointer(SimpleStruct *s)
    {
        return virtualReceivingPointer(s);
    }

    virtual int virtualReceivingPointer(SimpleStruct *s)
    {
        return 42;
    }

    int returnsInt() const
    {
        return 5;
    }

    void flagsWithDefaultArgs(AnotherNamespace::NamespaceLevelEnums options = {})
    {
    }

    /// For testing when the derived class overrides without a name ("int = 0")
    virtual void unnamedOverriddenDefaultArgCase(int myarg = 0)
    {
    }
};

class TEST_EXPORT DerivedFromPureAbstract : public PureAbstract
{
public:
    DerivedFromPureAbstract()
    {
    }

    DerivedFromPureAbstract(int)
    {
    }

    int foo() override
    {
        return 42;
    }

    int nonVirtualCallsVirtual()
    {
        return foo();
    }

    void voidPureAbstract() override
    {
    }

    void renamedPureVirtual() override
    {
    }

    void unnamedOverriddenDefaultArgCase(int = 0) override
    {
    }

    int indirectionCallsVirtualReceivingStruct(SimpleStruct s)
    {
        return receivesValueStruct(s);
    }

    virtual int receivesValueStruct(SimpleStruct)
    {
        qDebug() << Q_FUNC_INFO << "receivesValueStruct() C++";
        return 1;
    }
};

class TEST_EXPORT Derived2FromPureAbstract : public PureAbstract
{
public:
    // Tests that a pure abstract derived from pure abstract still compiles
};

struct TEST_EXPORT DestructorCounter
{
    DestructorCounter()
    {
        s_instanceCount++;
    }

    ~DestructorCounter()
    {
        s_instanceCount--;
    }

    static int instanceCount()
    {
        return s_instanceCount;
    }

    static DestructorCounter *newOnTheHeap()
    {
        return new DestructorCounter();
    }

    static DestructorCounter newOnTheStack()
    {
        return DestructorCounter();
    }

    static int s_instanceCount;
};

class TEST_EXPORT MyBaseClass
{
public:
    enum MyEnum {
        MyEnumerator0,
        MyEnumerator1 = 1,
        MyEnumerator3 = 3
    };

    enum {
        AnonymousEnumerator1 = 1,
        AnonymousEnumerator2 = 2,
        AnonymousEnumerator3
    };

    static int s_instanceCount;
    MyBaseClass()
    {
        s_instanceCount++;
    }

    explicit MyBaseClass(MyBaseClass *mybaseclassptr)
    {
        s_instanceCount++;
    }

    virtual ~MyBaseClass()
    {
        s_instanceCount--;
    }

    int foo() const;
    virtual int bar() const;
    virtual int bar2() const
    {
        return 1;
    }
    virtual int virtualReceivingInt(int)
    {
        return 1;
    }
    bool getBoolFalse() const
    {
        return false;
    }
    bool getBoolTrue() const
    {
        return true;
    }
    bool getBool(int) const
    {
        return false;
    }
    bool setBool(bool b)
    {
        return b;
    }
    void hello()
    {
    }
    int sum(int a, int b)
    {
        return a + b;
    }

    int receivesEnum(MyEnum e)
    {
        return e * 10;
    }

    void receivesEnumWithDefaultArg(MyEnum = MyEnumerator0)
    {
    }

    void receivesintWithDefaultEnumArg(int = MyEnumerator0)
    {
    }

    void receivesintWithDefaultEnumArg2(int = AnonymousEnumerator1)
    {
    }

    void receivesintWithDefaultEnumArg3(int = MyBaseClass::MyEnumerator0)
    {
    }

    void receivesEnumWithDefaultArgNull(MyEnum = {})
    {
        // Tests that {} is converted into 0, not to null in dart.
    }

    void receivesCharStarStar(const char **)
    {
    }

    void receivesCharStarStar2(char **)
    {
    }

    void receivesIntStarStar(int **)
    {
    }

    void receivesPtr(void *ptr)
    {
        Q_UNUSED(ptr);
    }

    void receivesCharStarStar2(const char *[])
    {
    }

    void addQObjects(const QList<QObject *> &)
    {
    }

    void addReals(QList<qreal>)
    {
    }
    void addInts(QList<int>)
    {
    }

    QList<qreal> returnsReals() const
    {
        return {};
    }

    qint64 returnsInt64() const
    {
        return 1; // TODO test a big number
    }

    const char **returnsCharStarStar()
    {
        return nullptr;
    }

    int callsVirtual() const
    {
        return bar();
    }

    int receivesCallback(int (*callback)(int))
    {
        return callback(42);
    }

    virtual int virtualReceivingBool(bool b)
    {
        return b ? 10 : 5;
    }

    virtual MyTemplate<int> virtualReturnsIntTemplate()
    {
        return {};
    }
    MyTemplate<int> methodReturnsIntTemplate()
    {
        return {};
    }

    virtual bool virtualReturningBool(bool b)
    {
        return b;
    }

    SimpleStruct nonVirtualReturningStruct() const
    {
        return virtualReturningStruct();
    }

    virtual SimpleStruct virtualReturningStruct() const
    {
        return {};
    }

    static void print(const char *msg)
    {
        qDebug() << msg;
    }
    static const char *returnsConstChar()
    {
        return "Hello";
    }
    static QString returnsQString()
    {
        return QString("hello");
    }

    QString receivesAndReturnsQString(const QString &s)
    {
        return s;
    }

    void receivesFloat(float)
    {
    }

    static MyTemplate<int> returnsIntTemplate()
    {
        return {};
    }
    static MyTemplate<double> returnsDoubleTemplate()
    {
        return {};
    }
    static MyTemplateWithTwoArgs<int, double> returnsTemplateWithTwoArgs()
    {
        return {};
    }

    static QList<SimpleStruct *> returnsListOfStructPtr()
    {
        QList<SimpleStruct *> list;
        list << new SimpleStruct();
        return list;
    }

    QList<int> returnsVector()
    {
        return { 1, 2, 3 };
    }

    void renamedMethod1()
    {
    }

    virtual void renamedVirtual1()
    {
    }

    virtual int virtualReceivingOptionalArgument(int optional = 1)
    {
        return optional;
    }

    virtual void virtualWithNoDefaultArgumentInDerived(int optional = 1)
    {
        Q_UNUSED(optional);
    }

    int nonVirtualButOverridden() const
    {
        // Tests that shadowing works
        return 1;
    }

    void receivesQFlags(AnotherNamespace::NamespaceLevelEnums)
    {
    }

    AnotherNamespace::NamespaceLevelEnums returnsQFlags() const
    {
        return AnotherNamespace::NamespaceLevelEnum_value1;
    }

    virtual int nonVirtualInBaseButVirtualInDerived(int i, int j) const
    {
        return i * j;
    }


    int nonVirtualInBaseButVirtualInDerived(int i) const
    {
        return 10 * i;
    }

    virtual void virtualWithOverload(int i) const
    {
    }
    virtual void virtualWithOverload(int i, int j) const
    {
    }

    virtual void virtualReceivingCharPtr(char *)
    {
        // TODO call this in the test. For now it validates that it builds
    }

    static void overloadedStatic()
    {
    }
    static void overloadedStatic(int)
    {
    }
    static void overloadedStatic(int, int)
    {
    }

    static SimpleStruct returnsSimpleStruct(int value)
    {
        return { value };
    }

    static int s_staticMember;
    static const int s_staticConstMember;

    virtual qint64 virtualReturningQint64()
    {
        // Tests that the virtual callback in dart compiles
        return 0;
    }

    static int anotherOverloadedStatic(int)
    {
        // Tests that overloaded and overriden statics with different
        // return type compile in dart
        return 0;
    }

    static inline QString fromStdString(const std::string &)
    {
        return {};
    }

    void testUnsignedInt(unsigned int)
    {
    }
    unsigned int testUnsignedIntReturn()
    {
        return 0;
    }

    void push(char)
    {
    }
    void push(const char *)
    {
    }

protected:
    enum ProtectedEnum {
        ProtectedEnum_V1 = 1
    };

    int m_protectedValue = 1;
};

class TEST_EXPORT MyDerivedClass : public MyBaseClass
{
public:
    static int s_instanceCount;
    MyDerivedClass()
    {
        s_instanceCount++;
    }

    virtual ~MyDerivedClass()
    {
        s_instanceCount--;
    }

    int bar() const override;
    int virtual virtualNotInBase() const
    {
        return 40;
    }

    void show()
    {
        setVisible(true);
        paintEvent();
    }
    virtual void setVisible(bool b)
    {
    }

    virtual int receivesDerivedPolymorphic(MyDerivedClass *der)
    {
        delete der;
        return 10;
    }

    int alsoCallsVirtual()
    {
        // Tests that passing a class created in C++ runs the correct dart fromCache() method.
        return receivesDerivedPolymorphic(new MyDerivedClass());
    }

    const MyDerivedClass *returnsConstPointer()
    {
        return this;
    }

    MyTemplate2<NonCopiable *> returnTemplate1()
    {
        return {};
    }

    const MyTemplate2<NonCopiable *> &returnTemplate2()
    {
        static const MyTemplate2<NonCopiable *> s_foo;
        return s_foo;
    }

    void virtualWithNoDefaultArgumentInDerived(int optional) override
    {
        Q_UNUSED(optional);
    }

    int nonVirtualButOverridden() const
    {
        // Tests that shadowing works
        return 2;
    }

    int receivesProtectedEnum(ProtectedEnum p)
    {
        return p;
    }

    void receivesEnumFromBaseClassWithDefaultValue(int a = MyEnumerator0)
    {
    }

    static const MyDerivedClass *anotherOverloadedStatic(int)
    {
        return nullptr;
    }
    static const MyDerivedClass *anotherOverloadedStatic(int, int)
    {
        return nullptr;
    }

    static AnotherNamespace::NamespaceLevelEnum returnsAnotherNamespaceEnum()
    {
        return {};
    }

    static AnotherNamespace::AnotherNamespaceStruct returnsAnotherNamespaceStruct()
    {
        return {};
    }

    static std::vector<int> returnsStdVector()
    {
        return {};
    }

protected:
    virtual void paintEvent()
    {
        // Tests an infinit loop when calling a protected method
    }
};

struct TEST_EXPORT POD
{
    int v1 = 1;
    int v2 = 2;
    int v3 = 3;
    const int v4_const = 4;

    POD() // TODO remove this ctor
    {
    }
    POD(int a, int b, int c, int d) // TODO remove this ctor
        : v1(a)
        , v2(b)
        , v3(c)
        , v4_const(d)
    {
    }

    int calculate() const
    {
        return v1 * v2 * v3;
    }

    void withDefaultAarg(int v = 2)
    {
        Q_UNUSED(v);
    }

    void receivesReservedDartKeyword(int var)
    {
        Q_UNUSED(var);
    }

    static int calculateStatic();
    static int doStuffOnMyClass(MyBaseClass *myarg);

    static POD returnsPOD()
    {
        return { 10, 20, 30, 40 };
    }

    static POD &returnsReferenceToPOD()
    {
        static POD s_pod;
        return s_pod;
    }

    static const POD &returnsConstReferenceToPOD()
    {
        static const POD s_pod;
        return s_pod;
    }

    static POD *returnsPointerToPOD()
    {
        return new POD();
    }
    static MyBaseClass *returnsPointerToPolymorphic()
    {
        return new MyBaseClass();
    }

    static int receivesPODs(POD pod1, POD pod2)
    {
        return pod1.v1 + pod2.v2;
    }

    static int receivesRefPODs(POD &pod1, POD &pod2)
    {
        pod1.v1 = 10;
        pod2.v2 = 10;
        return pod1.v1 + pod2.v2;
    }

    static int receivesConstRefPODs(const POD &pod1, const POD &pod2)
    {
        return pod1.v1 + pod2.v2;
    }

    static int receivesPointerToPODs(POD *ptrPod1, POD *ptrPod2)
    {
        return ptrPod1->v1 + ptrPod2->v2;
    }

    static int receivesConstPointerToPODs(const POD *ptrPod1, const POD *ptrPod2)
    {
        return ptrPod1->v1 + ptrPod2->v2;
    }

    static char returnsChar()
    {
        return 'c';
    }

    static const char returnsConstChar()
    {
        return 'a';
    }

    const int &intByConstRef() const
    {
        return v1;
    }

    int &intRef()
    {
        return v1;
    }

    void receivesNamespaceEnum(int v = AnotherNamespace::NamespaceLevelEnum_value1 + 1)
    {
    }

    void receivesNamespaceEnum1(
        AnotherNamespace::NamespaceLevelEnum = AnotherNamespace::NamespaceLevelEnum_value1)
    {
    }
};

struct StructWithStructAsMember
{
    POD m_pod;
};

inline int namespaceLevelGlobalFunction()
{
    return 41;
}

enum NameSpaceLevelEnum {
    NameSpaceLevelEnum_Value = 41
};

inline NameSpaceLevelEnum namespaceFunctionReturningNamespaceEnum()
{
    return NameSpaceLevelEnum_Value;
}

} // namespace

namespace EmptyNameSpace {
}

enum GlobalEnum {
    GlobalEnum_Value = 30
};

inline int globalFunction()
{
    return 42;
}

static TestTargetNS::PureAbstract *returnsPureAbstract()
{
    return new TestTargetNS::DerivedFromPureAbstract();
}

static int receivingPureAbstract(TestTargetNS::PureAbstract *a)
{
    return a->foo();
}

inline int receivesStructAsOptionalArgument(EmptyStruct arg1 = EmptyStruct())
{
    return 10;
}

inline int receivesStructAsOptionalArgument2(EmptyStruct = {})
{
    return 11;
}

class TEST_EXPORT MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = nullptr);
    ~MyObject() override;

    virtual int virtualFunc();
    virtual void virtualReceivingQString(const QString &str);
    virtual int virtualReturningInt() const
    {
        return 42;
    }
    virtual void pureVirtual() = 0;

    virtual const char *virtualMethodReturningConstChar() const
    {
        return "dartagnan";
    }


    MyEnumClass returnsEnumClass()
    {
        return {};
    }

    void receivesEnumClassWithDefaultArg(MyEnumClass foo = MyEnumClass::ValueFoo)
    {
    }

    void receivesEnumClassWithDefaultArg(AnotherNamespace::MyNamespacedEnumClass foo =
                                             AnotherNamespace::MyNamespacedEnumClass::ValueFoo1)
    {
    }

Q_SIGNALS:
    void valueChanged(int);
};

class DoubleInheritance : public SimpleStruct, public MyObject
{
public:
    int nonVirtualCallsVirtualFrom2ndBase() const
    {
        // We don't support virtuals in 2nd base class yet
        return virtualReturningInt();
    }
};

class Virtual1
{
public:
    virtual void virtualMethod1()
    {
    }
};

class Virtual2
{
public:
    virtual void virtualMethod2()
    {
    }
};

class DoubleInheritanceFromVirtuals : public Virtual1, public Virtual2
{
public:
    // Tests that we can inherit from two virtuals
};

struct Cyclic2;
struct Cyclic1
{
    Cyclic1(Cyclic2 *)
    {
    }

    Cyclic2 *getCyclic2() const
    {
        return nullptr;
    }
};

struct Cyclic2 : Cyclic1
{
    Cyclic1 *getCyclic1() const
    {
        return nullptr;
    }
};


/// A type that's not in typesystem.xml:
struct UnknownType
{
};

class PureAbstractWithUnknownType
{
public:
    // Method that we won't generate bindings for
    virtual UnknownType unknownmethod() = 0;

    int getValue() const
    {
        return 1;
    }
};

/// Tests two classes with the same name but on different namespaces
/// Uses dartagnan.json to split them into two scopes
namespace NameClashingNS1 {
struct SimpleClash
{
    SimpleClash(int)
    {
    }

    static int getValueStatic()
    {
        return 1;
    }

    int getValue()
    {
        return 1;
    }
};
}

namespace NameClashingNS2 {
struct SimpleClash
{
    SimpleClash(int)
    {
    }

    static int getValueStatic()
    {
        return 2;
    }

    int getFoo()
    {
        return 2;
    }

    static NameClashingNS1::SimpleClash returnsFromOtherScope()
    {
        return NameClashingNS1::SimpleClash(1);
    }

    static NameClashingNS1::SimpleClash
    returnsAndReceivesFromOtherScope(NameClashingNS1::SimpleClash s)
    {
        return s;
    }
};

inline SimpleStruct operator+(SimpleStruct one, SimpleStruct)
{
    return one;
}

}

class BaseClassWithFinalMethod
{
public:
    virtual void finalMethod() final
    {
    }
};

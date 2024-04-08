#include "MyBaseClass_c.h"


#include <iostream>

#include <cassert>


namespace Dartagnan {

typedef int (*CleanupCallback)(void *thisPtr);
static CleanupCallback s_cleanupCallback = nullptr;

template<typename T>
struct ValueWrapper
{
    T value;
};

}
namespace TestBindings_wrappersNS {
MyBaseClass_wrapper::MyBaseClass_wrapper()
    : ::TestTargetNS::MyBaseClass()
{
}
MyBaseClass_wrapper::MyBaseClass_wrapper(TestTargetNS::MyBaseClass *mybaseclassptr)
    : ::TestTargetNS::MyBaseClass(mybaseclassptr)
{
}
void MyBaseClass_wrapper::addInts(QList<int> arg__1)
{
    ::TestTargetNS::MyBaseClass::addInts(arg__1);
}
void MyBaseClass_wrapper::addQObjects(const QList<QObject *> &arg__1)
{
    ::TestTargetNS::MyBaseClass::addQObjects(arg__1);
}
void MyBaseClass_wrapper::addReals(QList<qreal> arg__1)
{
    ::TestTargetNS::MyBaseClass::addReals(arg__1);
}
int MyBaseClass_wrapper::anotherOverloadedStatic(int arg__1)
{
    return ::TestTargetNS::MyBaseClass::anotherOverloadedStatic(arg__1);
}
int MyBaseClass_wrapper::bar() const
{
    if (m_barCallback) {
        const void *thisPtr = this;
        return m_barCallback(const_cast<void *>(thisPtr));
    } else {
        return ::TestTargetNS::MyBaseClass::bar();
    }
}
int MyBaseClass_wrapper::bar_nocallback() const
{
    return ::TestTargetNS::MyBaseClass::bar();
}
int MyBaseClass_wrapper::bar2() const
{
    if (m_bar2Callback) {
        const void *thisPtr = this;
        return m_bar2Callback(const_cast<void *>(thisPtr));
    } else {
        return ::TestTargetNS::MyBaseClass::bar2();
    }
}
int MyBaseClass_wrapper::bar2_nocallback() const
{
    return ::TestTargetNS::MyBaseClass::bar2();
}
int MyBaseClass_wrapper::callsVirtual() const
{
    return ::TestTargetNS::MyBaseClass::callsVirtual();
}
int MyBaseClass_wrapper::foo() const
{
    return ::TestTargetNS::MyBaseClass::foo();
}
bool MyBaseClass_wrapper::getBool(int arg__1) const
{
    return ::TestTargetNS::MyBaseClass::getBool(arg__1);
}
bool MyBaseClass_wrapper::getBoolFalse() const
{
    return ::TestTargetNS::MyBaseClass::getBoolFalse();
}
bool MyBaseClass_wrapper::getBoolTrue() const
{
    return ::TestTargetNS::MyBaseClass::getBoolTrue();
}
void MyBaseClass_wrapper::hello()
{
    ::TestTargetNS::MyBaseClass::hello();
}
MyTemplate<int> MyBaseClass_wrapper::methodReturnsIntTemplate()
{
    return ::TestTargetNS::MyBaseClass::methodReturnsIntTemplate();
}
int MyBaseClass_wrapper::nonVirtualButOverridden() const
{
    return ::TestTargetNS::MyBaseClass::nonVirtualButOverridden();
}
int MyBaseClass_wrapper::nonVirtualInBaseButVirtualInDerived(int i) const
{
    return ::TestTargetNS::MyBaseClass::nonVirtualInBaseButVirtualInDerived(i);
}
int MyBaseClass_wrapper::nonVirtualInBaseButVirtualInDerived(int i, int j) const
{
    if (m_nonVirtualInBaseButVirtualInDerived_2Callback) {
        const void *thisPtr = this;
        return m_nonVirtualInBaseButVirtualInDerived_2Callback(const_cast<void *>(thisPtr), i, j);
    } else {
        return ::TestTargetNS::MyBaseClass::nonVirtualInBaseButVirtualInDerived(i, j);
    }
}
int MyBaseClass_wrapper::nonVirtualInBaseButVirtualInDerived_nocallback(int i, int j) const
{
    return ::TestTargetNS::MyBaseClass::nonVirtualInBaseButVirtualInDerived(i, j);
}
SimpleStruct MyBaseClass_wrapper::nonVirtualReturningStruct() const
{
    return ::TestTargetNS::MyBaseClass::nonVirtualReturningStruct();
}
void MyBaseClass_wrapper::overloadedStatic()
{
    ::TestTargetNS::MyBaseClass::overloadedStatic();
}
void MyBaseClass_wrapper::overloadedStatic(int arg__1)
{
    ::TestTargetNS::MyBaseClass::overloadedStatic(arg__1);
}
void MyBaseClass_wrapper::overloadedStatic(int arg__1, int arg__2)
{
    ::TestTargetNS::MyBaseClass::overloadedStatic(arg__1, arg__2);
}
void MyBaseClass_wrapper::print(const char *msg)
{
    ::TestTargetNS::MyBaseClass::print(msg);
}
void MyBaseClass_wrapper::push(const char *arg__1)
{
    ::TestTargetNS::MyBaseClass::push(arg__1);
}
QString MyBaseClass_wrapper::receivesAndReturnsQString(const QString &s)
{
    return ::TestTargetNS::MyBaseClass::receivesAndReturnsQString(s);
}
int MyBaseClass_wrapper::receivesEnum(TestTargetNS::MyBaseClass::MyEnum e)
{
    return ::TestTargetNS::MyBaseClass::receivesEnum(e);
}
void MyBaseClass_wrapper::receivesEnumWithDefaultArg(TestTargetNS::MyBaseClass::MyEnum arg__1)
{
    ::TestTargetNS::MyBaseClass::receivesEnumWithDefaultArg(arg__1);
}
void MyBaseClass_wrapper::receivesEnumWithDefaultArgNull(TestTargetNS::MyBaseClass::MyEnum arg__1)
{
    ::TestTargetNS::MyBaseClass::receivesEnumWithDefaultArgNull(arg__1);
}
void MyBaseClass_wrapper::receivesFloat(float arg__1)
{
    ::TestTargetNS::MyBaseClass::receivesFloat(arg__1);
}
void MyBaseClass_wrapper::receivesQFlags(QFlags<AnotherNamespace::NamespaceLevelEnum> arg__1)
{
    ::TestTargetNS::MyBaseClass::receivesQFlags(arg__1);
}
void MyBaseClass_wrapper::receivesintWithDefaultEnumArg(int arg__1)
{
    ::TestTargetNS::MyBaseClass::receivesintWithDefaultEnumArg(arg__1);
}
void MyBaseClass_wrapper::receivesintWithDefaultEnumArg2(int arg__1)
{
    ::TestTargetNS::MyBaseClass::receivesintWithDefaultEnumArg2(arg__1);
}
void MyBaseClass_wrapper::receivesintWithDefaultEnumArg3(int arg__1)
{
    ::TestTargetNS::MyBaseClass::receivesintWithDefaultEnumArg3(arg__1);
}
void MyBaseClass_wrapper::renamedMethod1()
{
    ::TestTargetNS::MyBaseClass::renamedMethod1();
}
void MyBaseClass_wrapper::renamedVirtual1()
{
    if (m_renamedVirtual2Callback) {
        const void *thisPtr = this;
        m_renamedVirtual2Callback(const_cast<void *>(thisPtr));
    } else {
        ::TestTargetNS::MyBaseClass::renamedVirtual1();
    }
}
void MyBaseClass_wrapper::renamedVirtual1_nocallback()
{
    ::TestTargetNS::MyBaseClass::renamedVirtual1();
}
const char *MyBaseClass_wrapper::returnsConstChar()
{
    return ::TestTargetNS::MyBaseClass::returnsConstChar();
}
MyTemplate<double> MyBaseClass_wrapper::returnsDoubleTemplate()
{
    return ::TestTargetNS::MyBaseClass::returnsDoubleTemplate();
}
qint64 MyBaseClass_wrapper::returnsInt64() const
{
    return ::TestTargetNS::MyBaseClass::returnsInt64();
}
MyTemplate<int> MyBaseClass_wrapper::returnsIntTemplate()
{
    return ::TestTargetNS::MyBaseClass::returnsIntTemplate();
}
QList<SimpleStruct *> MyBaseClass_wrapper::returnsListOfStructPtr()
{
    return ::TestTargetNS::MyBaseClass::returnsListOfStructPtr();
}
QFlags<AnotherNamespace::NamespaceLevelEnum> MyBaseClass_wrapper::returnsQFlags() const
{
    return ::TestTargetNS::MyBaseClass::returnsQFlags();
}
QString MyBaseClass_wrapper::returnsQString()
{
    return ::TestTargetNS::MyBaseClass::returnsQString();
}
QList<qreal> MyBaseClass_wrapper::returnsReals() const
{
    return ::TestTargetNS::MyBaseClass::returnsReals();
}
SimpleStruct MyBaseClass_wrapper::returnsSimpleStruct(int value)
{
    return ::TestTargetNS::MyBaseClass::returnsSimpleStruct(value);
}
MyTemplateWithTwoArgs<int, double> MyBaseClass_wrapper::returnsTemplateWithTwoArgs()
{
    return ::TestTargetNS::MyBaseClass::returnsTemplateWithTwoArgs();
}
QList<int> MyBaseClass_wrapper::returnsVector()
{
    return ::TestTargetNS::MyBaseClass::returnsVector();
}
bool MyBaseClass_wrapper::setBool(bool b)
{
    return ::TestTargetNS::MyBaseClass::setBool(b);
}
int MyBaseClass_wrapper::sum(int a, int b)
{
    return ::TestTargetNS::MyBaseClass::sum(a, b);
}
int MyBaseClass_wrapper::virtualReceivingBool(bool b)
{
    if (m_virtualReceivingBoolCallback) {
        const void *thisPtr = this;
        return m_virtualReceivingBoolCallback(const_cast<void *>(thisPtr), b);
    } else {
        return ::TestTargetNS::MyBaseClass::virtualReceivingBool(b);
    }
}
int MyBaseClass_wrapper::virtualReceivingBool_nocallback(bool b)
{
    return ::TestTargetNS::MyBaseClass::virtualReceivingBool(b);
}
void MyBaseClass_wrapper::virtualReceivingCharPtr(char *arg__1)
{
    if (m_virtualReceivingCharPtrCallback) {
        const void *thisPtr = this;
        m_virtualReceivingCharPtrCallback(const_cast<void *>(thisPtr), arg__1);
    } else {
        ::TestTargetNS::MyBaseClass::virtualReceivingCharPtr(arg__1);
    }
}
void MyBaseClass_wrapper::virtualReceivingCharPtr_nocallback(char *arg__1)
{
    ::TestTargetNS::MyBaseClass::virtualReceivingCharPtr(arg__1);
}
int MyBaseClass_wrapper::virtualReceivingInt(int arg__1)
{
    if (m_virtualReceivingIntCallback) {
        const void *thisPtr = this;
        return m_virtualReceivingIntCallback(const_cast<void *>(thisPtr), arg__1);
    } else {
        return ::TestTargetNS::MyBaseClass::virtualReceivingInt(arg__1);
    }
}
int MyBaseClass_wrapper::virtualReceivingInt_nocallback(int arg__1)
{
    return ::TestTargetNS::MyBaseClass::virtualReceivingInt(arg__1);
}
int MyBaseClass_wrapper::virtualReceivingOptionalArgument(int optional)
{
    if (m_virtualReceivingOptionalArgumentCallback) {
        const void *thisPtr = this;
        return m_virtualReceivingOptionalArgumentCallback(const_cast<void *>(thisPtr), optional);
    } else {
        return ::TestTargetNS::MyBaseClass::virtualReceivingOptionalArgument(optional);
    }
}
int MyBaseClass_wrapper::virtualReceivingOptionalArgument_nocallback(int optional)
{
    return ::TestTargetNS::MyBaseClass::virtualReceivingOptionalArgument(optional);
}
bool MyBaseClass_wrapper::virtualReturningBool(bool b)
{
    if (m_virtualReturningBoolCallback) {
        const void *thisPtr = this;
        return m_virtualReturningBoolCallback(const_cast<void *>(thisPtr), b);
    } else {
        return ::TestTargetNS::MyBaseClass::virtualReturningBool(b);
    }
}
bool MyBaseClass_wrapper::virtualReturningBool_nocallback(bool b)
{
    return ::TestTargetNS::MyBaseClass::virtualReturningBool(b);
}
qint64 MyBaseClass_wrapper::virtualReturningQint64()
{
    if (m_virtualReturningQint64Callback) {
        const void *thisPtr = this;
        return m_virtualReturningQint64Callback(const_cast<void *>(thisPtr));
    } else {
        return ::TestTargetNS::MyBaseClass::virtualReturningQint64();
    }
}
qint64 MyBaseClass_wrapper::virtualReturningQint64_nocallback()
{
    return ::TestTargetNS::MyBaseClass::virtualReturningQint64();
}
SimpleStruct MyBaseClass_wrapper::virtualReturningStruct() const
{
    if (m_virtualReturningStructCallback) {
        const void *thisPtr = this;
        return *m_virtualReturningStructCallback(const_cast<void *>(thisPtr));
    } else {
        return ::TestTargetNS::MyBaseClass::virtualReturningStruct();
    }
}
SimpleStruct MyBaseClass_wrapper::virtualReturningStruct_nocallback() const
{
    return ::TestTargetNS::MyBaseClass::virtualReturningStruct();
}
MyTemplate<int> MyBaseClass_wrapper::virtualReturnsIntTemplate()
{
    if (m_virtualReturnsIntTemplateCallback) {
        const void *thisPtr = this;
        return *m_virtualReturnsIntTemplateCallback(const_cast<void *>(thisPtr));
    } else {
        return ::TestTargetNS::MyBaseClass::virtualReturnsIntTemplate();
    }
}
MyTemplate<int> MyBaseClass_wrapper::virtualReturnsIntTemplate_nocallback()
{
    return ::TestTargetNS::MyBaseClass::virtualReturnsIntTemplate();
}
void MyBaseClass_wrapper::virtualWithNoDefaultArgumentInDerived(int optional)
{
    if (m_virtualWithNoDefaultArgumentInDerivedCallback) {
        const void *thisPtr = this;
        m_virtualWithNoDefaultArgumentInDerivedCallback(const_cast<void *>(thisPtr), optional);
    } else {
        ::TestTargetNS::MyBaseClass::virtualWithNoDefaultArgumentInDerived(optional);
    }
}
void MyBaseClass_wrapper::virtualWithNoDefaultArgumentInDerived_nocallback(int optional)
{
    ::TestTargetNS::MyBaseClass::virtualWithNoDefaultArgumentInDerived(optional);
}
void MyBaseClass_wrapper::virtualWithOverload(int i) const
{
    if (m_virtualWithOverloadCallback) {
        const void *thisPtr = this;
        m_virtualWithOverloadCallback(const_cast<void *>(thisPtr), i);
    } else {
        ::TestTargetNS::MyBaseClass::virtualWithOverload(i);
    }
}
void MyBaseClass_wrapper::virtualWithOverload_nocallback(int i) const
{
    ::TestTargetNS::MyBaseClass::virtualWithOverload(i);
}
void MyBaseClass_wrapper::virtualWithOverload(int i, int j) const
{
    if (m_virtualWithOverload_2Callback) {
        const void *thisPtr = this;
        m_virtualWithOverload_2Callback(const_cast<void *>(thisPtr), i, j);
    } else {
        ::TestTargetNS::MyBaseClass::virtualWithOverload(i, j);
    }
}
void MyBaseClass_wrapper::virtualWithOverload_nocallback(int i, int j) const
{
    ::TestTargetNS::MyBaseClass::virtualWithOverload(i, j);
}
MyBaseClass_wrapper::~MyBaseClass_wrapper()
{
}

}
static TestTargetNS::MyBaseClass *fromPtr(void *ptr)
{
    return reinterpret_cast<TestTargetNS::MyBaseClass *>(ptr);
}
static TestBindings_wrappersNS::MyBaseClass_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(ptr);
}
extern "C" {
void c_TestTargetNS__MyBaseClass_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(cppObj);
}
void *c_TestTargetNS__MyBaseClass__constructor()
{
    auto ptr = new TestBindings_wrappersNS::MyBaseClass_wrapper();
    return reinterpret_cast<void *>(ptr);
}
void *c_TestTargetNS__MyBaseClass__constructor_MyBaseClass(void *mybaseclassptr_)
{
    auto mybaseclassptr = reinterpret_cast<TestTargetNS::MyBaseClass *>(mybaseclassptr_);
    auto ptr = new TestBindings_wrappersNS::MyBaseClass_wrapper(mybaseclassptr);
    return reinterpret_cast<void *>(ptr);
}
// addInts(QList<int > arg__1)
void c_TestTargetNS__MyBaseClass__addInts_QList_int(void *thisObj, void *arg__1_)
{
    assert(arg__1_);
    auto &arg__1 = *reinterpret_cast<QList<int> *>(arg__1_);
    fromPtr(thisObj)->addInts(arg__1);
}
// addQObjects(const QList<QObject* > & arg__1)
void c_TestTargetNS__MyBaseClass__addQObjects_QList_QObject(void *thisObj, void *arg__1_)
{
    assert(arg__1_);
    auto &arg__1 = *reinterpret_cast<QList<QObject *> *>(arg__1_);
    fromPtr(thisObj)->addQObjects(arg__1);
}
// addReals(QList<qreal > arg__1)
void c_TestTargetNS__MyBaseClass__addReals_QList_qreal(void *thisObj, void *arg__1_)
{
    assert(arg__1_);
    auto &arg__1 = *reinterpret_cast<QList<qreal> *>(arg__1_);
    fromPtr(thisObj)->addReals(arg__1);
}
// anotherOverloadedStatic(int arg__1)
int c_static_TestTargetNS__MyBaseClass__anotherOverloadedStatic_int(int arg__1)
{
    const auto &result =
        TestBindings_wrappersNS::MyBaseClass_wrapper::anotherOverloadedStatic(arg__1);
    return result;
}
// bar() const
int c_TestTargetNS__MyBaseClass__bar(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->bar_nocallback();
        } else {
            return targetPtr->bar();
        }
    }();
    return result;
}
// bar2() const
int c_TestTargetNS__MyBaseClass__bar2(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->bar2_nocallback();
        } else {
            return targetPtr->bar2();
        }
    }();
    return result;
}
// callsVirtual() const
int c_TestTargetNS__MyBaseClass__callsVirtual(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->callsVirtual();
    return result;
}
// foo() const
int c_TestTargetNS__MyBaseClass__foo(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->foo();
    return result;
}
// getBool(int arg__1) const
bool c_TestTargetNS__MyBaseClass__getBool_int(void *thisObj, int arg__1)
{
    const auto &result = fromPtr(thisObj)->getBool(arg__1);
    return result;
}
// getBoolFalse() const
bool c_TestTargetNS__MyBaseClass__getBoolFalse(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->getBoolFalse();
    return result;
}
// getBoolTrue() const
bool c_TestTargetNS__MyBaseClass__getBoolTrue(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->getBoolTrue();
    return result;
}
// hello()
void c_TestTargetNS__MyBaseClass__hello(void *thisObj)
{
    fromPtr(thisObj)->hello();
}
// methodReturnsIntTemplate()
void *c_TestTargetNS__MyBaseClass__methodReturnsIntTemplate(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<int>> {
        fromPtr(thisObj)->methodReturnsIntTemplate()
    };
    return result;
}
// nonVirtualButOverridden() const
int c_TestTargetNS__MyBaseClass__nonVirtualButOverridden(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->nonVirtualButOverridden();
    return result;
}
// nonVirtualInBaseButVirtualInDerived(int i) const
int c_TestTargetNS__MyBaseClass__nonVirtualInBaseButVirtualInDerived_int(void *thisObj, int i)
{
    const auto &result = fromPtr(thisObj)->nonVirtualInBaseButVirtualInDerived(i);
    return result;
}
// nonVirtualInBaseButVirtualInDerived(int i, int j) const
int c_TestTargetNS__MyBaseClass__nonVirtualInBaseButVirtualInDerived_int_int(void *thisObj, int i,
                                                                             int j)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->nonVirtualInBaseButVirtualInDerived_nocallback(i, j);
        } else {
            return targetPtr->nonVirtualInBaseButVirtualInDerived(i, j);
        }
    }();
    return result;
}
// nonVirtualReturningStruct() const
void *c_TestTargetNS__MyBaseClass__nonVirtualReturningStruct(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<SimpleStruct> { fromPtr(thisObj)->nonVirtualReturningStruct() };
    return result;
}
// overloadedStatic()
void c_static_TestTargetNS__MyBaseClass__overloadedStatic()
{
    TestBindings_wrappersNS::MyBaseClass_wrapper::overloadedStatic();
}
// overloadedStatic(int arg__1)
void c_static_TestTargetNS__MyBaseClass__overloadedStatic_int(int arg__1)
{
    TestBindings_wrappersNS::MyBaseClass_wrapper::overloadedStatic(arg__1);
}
// overloadedStatic(int arg__1, int arg__2)
void c_static_TestTargetNS__MyBaseClass__overloadedStatic_int_int(int arg__1, int arg__2)
{
    TestBindings_wrappersNS::MyBaseClass_wrapper::overloadedStatic(arg__1, arg__2);
}
// print(const char * msg)
void c_static_TestTargetNS__MyBaseClass__print_char(const char *msg)
{
    TestBindings_wrappersNS::MyBaseClass_wrapper::print(msg);
    free(( char * )msg);
}
// push(const char * arg__1)
void c_TestTargetNS__MyBaseClass__push_char(void *thisObj, const char *arg__1)
{
    fromPtr(thisObj)->push(arg__1);
    free(( char * )arg__1);
}
// receivesAndReturnsQString(const QString & s)
void *c_TestTargetNS__MyBaseClass__receivesAndReturnsQString_QString(void *thisObj, const char *s_)
{
    const auto s = QString::fromUtf8(s_);
    const auto &result =
        new Dartagnan::ValueWrapper<QString> { fromPtr(thisObj)->receivesAndReturnsQString(s) };
    free(( char * )s_);
    return result;
}
// receivesEnum(TestTargetNS::MyBaseClass::MyEnum e)
int c_TestTargetNS__MyBaseClass__receivesEnum_MyEnum(void *thisObj, int e)
{
    const auto &result =
        fromPtr(thisObj)->receivesEnum(static_cast<TestTargetNS::MyBaseClass::MyEnum>(e));
    return result;
}
// receivesEnumWithDefaultArg(TestTargetNS::MyBaseClass::MyEnum arg__1)
void c_TestTargetNS__MyBaseClass__receivesEnumWithDefaultArg_MyEnum(void *thisObj, int arg__1)
{
    fromPtr(thisObj)->receivesEnumWithDefaultArg(
        static_cast<TestTargetNS::MyBaseClass::MyEnum>(arg__1));
}
// receivesEnumWithDefaultArgNull(TestTargetNS::MyBaseClass::MyEnum arg__1)
void c_TestTargetNS__MyBaseClass__receivesEnumWithDefaultArgNull_MyEnum(void *thisObj, int arg__1)
{
    fromPtr(thisObj)->receivesEnumWithDefaultArgNull(
        static_cast<TestTargetNS::MyBaseClass::MyEnum>(arg__1));
}
// receivesFloat(float arg__1)
void c_TestTargetNS__MyBaseClass__receivesFloat_float(void *thisObj, float arg__1)
{
    fromPtr(thisObj)->receivesFloat(arg__1);
}
// receivesQFlags(QFlags<AnotherNamespace::NamespaceLevelEnum> arg__1)
void c_TestTargetNS__MyBaseClass__receivesQFlags_NamespaceLevelEnums(void *thisObj, int arg__1_)
{
    auto arg__1 = static_cast<QFlags<AnotherNamespace::NamespaceLevelEnum>>(arg__1_);
    fromPtr(thisObj)->receivesQFlags(arg__1);
}
// receivesintWithDefaultEnumArg(int arg__1)
void c_TestTargetNS__MyBaseClass__receivesintWithDefaultEnumArg_int(void *thisObj, int arg__1)
{
    fromPtr(thisObj)->receivesintWithDefaultEnumArg(arg__1);
}
// receivesintWithDefaultEnumArg2(int arg__1)
void c_TestTargetNS__MyBaseClass__receivesintWithDefaultEnumArg2_int(void *thisObj, int arg__1)
{
    fromPtr(thisObj)->receivesintWithDefaultEnumArg2(arg__1);
}
// receivesintWithDefaultEnumArg3(int arg__1)
void c_TestTargetNS__MyBaseClass__receivesintWithDefaultEnumArg3_int(void *thisObj, int arg__1)
{
    fromPtr(thisObj)->receivesintWithDefaultEnumArg3(arg__1);
}
// renamedMethod1()
void c_TestTargetNS__MyBaseClass__renamedMethod2(void *thisObj)
{
    fromPtr(thisObj)->renamedMethod1();
}
// renamedVirtual1()
void c_TestTargetNS__MyBaseClass__renamedVirtual2(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->renamedVirtual1_nocallback();
        } else {
            return targetPtr->renamedVirtual1();
        }
    }();
}
// returnsConstChar()
const char *c_static_TestTargetNS__MyBaseClass__returnsConstChar()
{
    const auto &result = TestBindings_wrappersNS::MyBaseClass_wrapper::returnsConstChar();
    return result;
}
// returnsDoubleTemplate()
void *c_static_TestTargetNS__MyBaseClass__returnsDoubleTemplate()
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<double>> {
        TestBindings_wrappersNS::MyBaseClass_wrapper::returnsDoubleTemplate()
    };
    return result;
}
// returnsInt64() const
qint64 c_TestTargetNS__MyBaseClass__returnsInt64(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->returnsInt64();
    return result;
}
// returnsIntTemplate()
void *c_static_TestTargetNS__MyBaseClass__returnsIntTemplate()
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<int>> {
        TestBindings_wrappersNS::MyBaseClass_wrapper::returnsIntTemplate()
    };
    return result;
}
// returnsListOfStructPtr()
void *c_static_TestTargetNS__MyBaseClass__returnsListOfStructPtr()
{
    const auto &result = new Dartagnan::ValueWrapper<QList<SimpleStruct *>> {
        TestBindings_wrappersNS::MyBaseClass_wrapper::returnsListOfStructPtr()
    };
    return result;
}
// returnsQFlags() const
int c_TestTargetNS__MyBaseClass__returnsQFlags(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->returnsQFlags();
    return result;
}
// returnsQString()
void *c_static_TestTargetNS__MyBaseClass__returnsQString()
{
    const auto &result = new Dartagnan::ValueWrapper<QString> {
        TestBindings_wrappersNS::MyBaseClass_wrapper::returnsQString()
    };
    return result;
}
// returnsReals() const
void *c_TestTargetNS__MyBaseClass__returnsReals(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<qreal>> { fromPtr(thisObj)->returnsReals() };
    return result;
}
// returnsSimpleStruct(int value)
void *c_static_TestTargetNS__MyBaseClass__returnsSimpleStruct_int(int value)
{
    const auto &result = new Dartagnan::ValueWrapper<SimpleStruct> {
        TestBindings_wrappersNS::MyBaseClass_wrapper::returnsSimpleStruct(value)
    };
    return result;
}
// returnsTemplateWithTwoArgs()
void *c_static_TestTargetNS__MyBaseClass__returnsTemplateWithTwoArgs()
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplateWithTwoArgs<int, double>> {
        TestBindings_wrappersNS::MyBaseClass_wrapper::returnsTemplateWithTwoArgs()
    };
    return result;
}
// returnsVector()
void *c_TestTargetNS__MyBaseClass__returnsVector(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<int>> { fromPtr(thisObj)->returnsVector() };
    return result;
}
// setBool(bool b)
bool c_TestTargetNS__MyBaseClass__setBool_bool(void *thisObj, bool b)
{
    const auto &result = fromPtr(thisObj)->setBool(b);
    return result;
}
// sum(int a, int b)
int c_TestTargetNS__MyBaseClass__sum_int_int(void *thisObj, int a, int b)
{
    const auto &result = fromPtr(thisObj)->sum(a, b);
    return result;
}
// virtualReceivingBool(bool b)
int c_TestTargetNS__MyBaseClass__virtualReceivingBool_bool(void *thisObj, bool b)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReceivingBool_nocallback(b);
        } else {
            return targetPtr->virtualReceivingBool(b);
        }
    }();
    return result;
}
// virtualReceivingCharPtr(char * arg__1)
void c_TestTargetNS__MyBaseClass__virtualReceivingCharPtr_char(void *thisObj, char *arg__1)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReceivingCharPtr_nocallback(arg__1);
        } else {
            return targetPtr->virtualReceivingCharPtr(arg__1);
        }
    }();
    free(( char * )arg__1);
}
// virtualReceivingInt(int arg__1)
int c_TestTargetNS__MyBaseClass__virtualReceivingInt_int(void *thisObj, int arg__1)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReceivingInt_nocallback(arg__1);
        } else {
            return targetPtr->virtualReceivingInt(arg__1);
        }
    }();
    return result;
}
// virtualReceivingOptionalArgument(int optional)
int c_TestTargetNS__MyBaseClass__virtualReceivingOptionalArgument_int(void *thisObj, int optional)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReceivingOptionalArgument_nocallback(optional);
        } else {
            return targetPtr->virtualReceivingOptionalArgument(optional);
        }
    }();
    return result;
}
// virtualReturningBool(bool b)
bool c_TestTargetNS__MyBaseClass__virtualReturningBool_bool(void *thisObj, bool b)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReturningBool_nocallback(b);
        } else {
            return targetPtr->virtualReturningBool(b);
        }
    }();
    return result;
}
// virtualReturningQint64()
qint64 c_TestTargetNS__MyBaseClass__virtualReturningQint64(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReturningQint64_nocallback();
        } else {
            return targetPtr->virtualReturningQint64();
        }
    }();
    return result;
}
// virtualReturningStruct() const
void *c_TestTargetNS__MyBaseClass__virtualReturningStruct(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<SimpleStruct> { [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReturningStruct_nocallback();
        } else {
            return targetPtr->virtualReturningStruct();
        }
    }() };
    return result;
}
// virtualReturnsIntTemplate()
void *c_TestTargetNS__MyBaseClass__virtualReturnsIntTemplate(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<int>> { [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReturnsIntTemplate_nocallback();
        } else {
            return targetPtr->virtualReturnsIntTemplate();
        }
    }() };
    return result;
}
// virtualWithNoDefaultArgumentInDerived(int optional)
void c_TestTargetNS__MyBaseClass__virtualWithNoDefaultArgumentInDerived_int(void *thisObj,
                                                                            int optional)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualWithNoDefaultArgumentInDerived_nocallback(optional);
        } else {
            return targetPtr->virtualWithNoDefaultArgumentInDerived(optional);
        }
    }();
}
// virtualWithOverload(int i) const
void c_TestTargetNS__MyBaseClass__virtualWithOverload_int(void *thisObj, int i)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualWithOverload_nocallback(i);
        } else {
            return targetPtr->virtualWithOverload(i);
        }
    }();
}
// virtualWithOverload(int i, int j) const
void c_TestTargetNS__MyBaseClass__virtualWithOverload_int_int(void *thisObj, int i, int j)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyBaseClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualWithOverload_nocallback(i, j);
        } else {
            return targetPtr->virtualWithOverload(i, j);
        }
    }();
}
void c_TestTargetNS__MyBaseClass__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
int c_static_TestTargetNS__MyBaseClass___get_s_instanceCount()
{
    return TestBindings_wrappersNS::MyBaseClass_wrapper::s_instanceCount;
}
int c_static_TestTargetNS__MyBaseClass___get_s_staticMember()
{
    return TestBindings_wrappersNS::MyBaseClass_wrapper::s_staticMember;
}
int c_static_TestTargetNS__MyBaseClass___get_s_staticConstMember()
{
    return TestBindings_wrappersNS::MyBaseClass_wrapper::s_staticConstMember;
}
void c_static_TestTargetNS__MyBaseClass___set_s_instanceCount_int(int s_instanceCount_)
{
    TestBindings_wrappersNS::MyBaseClass_wrapper::s_instanceCount = s_instanceCount_;
}
void c_static_TestTargetNS__MyBaseClass___set_s_staticMember_int(int s_staticMember_)
{
    TestBindings_wrappersNS::MyBaseClass_wrapper::s_staticMember = s_staticMember_;
}
void c_TestTargetNS__MyBaseClass__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 51:
        wrapper->m_barCallback =
            reinterpret_cast<TestBindings_wrappersNS::MyBaseClass_wrapper::Callback_bar>(callback);
        break;
    case 52:
        wrapper->m_bar2Callback =
            reinterpret_cast<TestBindings_wrappersNS::MyBaseClass_wrapper::Callback_bar2>(callback);
        break;
    case 63:
        wrapper->m_nonVirtualInBaseButVirtualInDerived_2Callback =
            reinterpret_cast<TestBindings_wrappersNS::MyBaseClass_wrapper::
                                 Callback_nonVirtualInBaseButVirtualInDerived_2>(callback);
        break;
    case 86:
        wrapper->m_renamedVirtual2Callback = reinterpret_cast<
            TestBindings_wrappersNS::MyBaseClass_wrapper::Callback_renamedVirtual2>(callback);
        break;
    case 103:
        wrapper->m_virtualReceivingBoolCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyBaseClass_wrapper::Callback_virtualReceivingBool>(callback);
        break;
    case 104:
        wrapper->m_virtualReceivingCharPtrCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyBaseClass_wrapper::Callback_virtualReceivingCharPtr>(
            callback);
        break;
    case 105:
        wrapper->m_virtualReceivingIntCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyBaseClass_wrapper::Callback_virtualReceivingInt>(callback);
        break;
    case 106:
        wrapper->m_virtualReceivingOptionalArgumentCallback =
            reinterpret_cast<TestBindings_wrappersNS::MyBaseClass_wrapper::
                                 Callback_virtualReceivingOptionalArgument>(callback);
        break;
    case 107:
        wrapper->m_virtualReturningBoolCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyBaseClass_wrapper::Callback_virtualReturningBool>(callback);
        break;
    case 108:
        wrapper->m_virtualReturningQint64Callback = reinterpret_cast<
            TestBindings_wrappersNS::MyBaseClass_wrapper::Callback_virtualReturningQint64>(
            callback);
        break;
    case 109:
        wrapper->m_virtualReturningStructCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyBaseClass_wrapper::Callback_virtualReturningStruct>(
            callback);
        break;
    case 110:
        wrapper->m_virtualReturnsIntTemplateCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyBaseClass_wrapper::Callback_virtualReturnsIntTemplate>(
            callback);
        break;
    case 111:
        wrapper->m_virtualWithNoDefaultArgumentInDerivedCallback =
            reinterpret_cast<TestBindings_wrappersNS::MyBaseClass_wrapper::
                                 Callback_virtualWithNoDefaultArgumentInDerived>(callback);
        break;
    case 112:
        wrapper->m_virtualWithOverloadCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyBaseClass_wrapper::Callback_virtualWithOverload>(callback);
        break;
    case 113:
        wrapper->m_virtualWithOverload_2Callback = reinterpret_cast<
            TestBindings_wrappersNS::MyBaseClass_wrapper::Callback_virtualWithOverload_2>(callback);
        break;
    }
}
}

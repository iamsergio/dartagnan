#include "MyDerivedClass_c.h"


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
MyDerivedClass_wrapper::MyDerivedClass_wrapper()
    : ::TestTargetNS::MyDerivedClass()
{
}
int MyDerivedClass_wrapper::alsoCallsVirtual()
{
    return ::TestTargetNS::MyDerivedClass::alsoCallsVirtual();
}
const TestTargetNS::MyDerivedClass *MyDerivedClass_wrapper::anotherOverloadedStatic(int arg__1)
{
    return ::TestTargetNS::MyDerivedClass::anotherOverloadedStatic(arg__1);
}
const TestTargetNS::MyDerivedClass *MyDerivedClass_wrapper::anotherOverloadedStatic(int arg__1,
                                                                                    int arg__2)
{
    return ::TestTargetNS::MyDerivedClass::anotherOverloadedStatic(arg__1, arg__2);
}
int MyDerivedClass_wrapper::bar() const
{
    if (m_barCallback) {
        const void *thisPtr = this;
        return m_barCallback(const_cast<void *>(thisPtr));
    } else {
        return ::TestTargetNS::MyDerivedClass::bar();
    }
}
int MyDerivedClass_wrapper::bar_nocallback() const
{
    return ::TestTargetNS::MyDerivedClass::bar();
}
int MyDerivedClass_wrapper::bar2() const
{
    if (m_bar2Callback) {
        const void *thisPtr = this;
        return m_bar2Callback(const_cast<void *>(thisPtr));
    } else {
        return ::TestTargetNS::MyDerivedClass::bar2();
    }
}
int MyDerivedClass_wrapper::bar2_nocallback() const
{
    return ::TestTargetNS::MyDerivedClass::bar2();
}
int MyDerivedClass_wrapper::nonVirtualButOverridden() const
{
    return ::TestTargetNS::MyDerivedClass::nonVirtualButOverridden();
}
int MyDerivedClass_wrapper::nonVirtualInBaseButVirtualInDerived(int i, int j) const
{
    if (m_nonVirtualInBaseButVirtualInDerived_2Callback) {
        const void *thisPtr = this;
        return m_nonVirtualInBaseButVirtualInDerived_2Callback(const_cast<void *>(thisPtr), i, j);
    } else {
        return ::TestTargetNS::MyDerivedClass::nonVirtualInBaseButVirtualInDerived(i, j);
    }
}
int MyDerivedClass_wrapper::nonVirtualInBaseButVirtualInDerived_nocallback(int i, int j) const
{
    return ::TestTargetNS::MyDerivedClass::nonVirtualInBaseButVirtualInDerived(i, j);
}
void MyDerivedClass_wrapper::paintEvent()
{
    if (m_paintEventCallback) {
        const void *thisPtr = this;
        m_paintEventCallback(const_cast<void *>(thisPtr));
    } else {
        ::TestTargetNS::MyDerivedClass::paintEvent();
    }
}
void MyDerivedClass_wrapper::paintEvent_nocallback()
{
    ::TestTargetNS::MyDerivedClass::paintEvent();
}
int MyDerivedClass_wrapper::receivesDerivedPolymorphic(TestTargetNS::MyDerivedClass *der)
{
    if (m_receivesDerivedPolymorphicCallback) {
        const void *thisPtr = this;
        return m_receivesDerivedPolymorphicCallback(const_cast<void *>(thisPtr), der);
    } else {
        return ::TestTargetNS::MyDerivedClass::receivesDerivedPolymorphic(der);
    }
}
int MyDerivedClass_wrapper::receivesDerivedPolymorphic_nocallback(TestTargetNS::MyDerivedClass *der)
{
    return ::TestTargetNS::MyDerivedClass::receivesDerivedPolymorphic(der);
}
void MyDerivedClass_wrapper::receivesEnumFromBaseClassWithDefaultValue(int a)
{
    ::TestTargetNS::MyDerivedClass::receivesEnumFromBaseClassWithDefaultValue(a);
}
int MyDerivedClass_wrapper::receivesProtectedEnum(TestTargetNS::MyBaseClass::ProtectedEnum p)
{
    return ::TestTargetNS::MyDerivedClass::receivesProtectedEnum(p);
}
void MyDerivedClass_wrapper::renamedVirtual1()
{
    if (m_renamedVirtual2Callback) {
        const void *thisPtr = this;
        m_renamedVirtual2Callback(const_cast<void *>(thisPtr));
    } else {
        ::TestTargetNS::MyDerivedClass::renamedVirtual1();
    }
}
void MyDerivedClass_wrapper::renamedVirtual1_nocallback()
{
    ::TestTargetNS::MyDerivedClass::renamedVirtual1();
}
MyTemplate2<NonCopiable *> MyDerivedClass_wrapper::returnTemplate1()
{
    return ::TestTargetNS::MyDerivedClass::returnTemplate1();
}
const MyTemplate2<NonCopiable *> &MyDerivedClass_wrapper::returnTemplate2()
{
    return ::TestTargetNS::MyDerivedClass::returnTemplate2();
}
AnotherNamespace::NamespaceLevelEnum MyDerivedClass_wrapper::returnsAnotherNamespaceEnum()
{
    return ::TestTargetNS::MyDerivedClass::returnsAnotherNamespaceEnum();
}
AnotherNamespace::AnotherNamespaceStruct MyDerivedClass_wrapper::returnsAnotherNamespaceStruct()
{
    return ::TestTargetNS::MyDerivedClass::returnsAnotherNamespaceStruct();
}
const TestTargetNS::MyDerivedClass *MyDerivedClass_wrapper::returnsConstPointer()
{
    return ::TestTargetNS::MyDerivedClass::returnsConstPointer();
}
void MyDerivedClass_wrapper::setVisible(bool b)
{
    if (m_setVisibleCallback) {
        const void *thisPtr = this;
        m_setVisibleCallback(const_cast<void *>(thisPtr), b);
    } else {
        ::TestTargetNS::MyDerivedClass::setVisible(b);
    }
}
void MyDerivedClass_wrapper::setVisible_nocallback(bool b)
{
    ::TestTargetNS::MyDerivedClass::setVisible(b);
}
void MyDerivedClass_wrapper::show()
{
    ::TestTargetNS::MyDerivedClass::show();
}
int MyDerivedClass_wrapper::virtualNotInBase() const
{
    if (m_virtualNotInBaseCallback) {
        const void *thisPtr = this;
        return m_virtualNotInBaseCallback(const_cast<void *>(thisPtr));
    } else {
        return ::TestTargetNS::MyDerivedClass::virtualNotInBase();
    }
}
int MyDerivedClass_wrapper::virtualNotInBase_nocallback() const
{
    return ::TestTargetNS::MyDerivedClass::virtualNotInBase();
}
int MyDerivedClass_wrapper::virtualReceivingBool(bool b)
{
    if (m_virtualReceivingBoolCallback) {
        const void *thisPtr = this;
        return m_virtualReceivingBoolCallback(const_cast<void *>(thisPtr), b);
    } else {
        return ::TestTargetNS::MyDerivedClass::virtualReceivingBool(b);
    }
}
int MyDerivedClass_wrapper::virtualReceivingBool_nocallback(bool b)
{
    return ::TestTargetNS::MyDerivedClass::virtualReceivingBool(b);
}
void MyDerivedClass_wrapper::virtualReceivingCharPtr(char *arg__1)
{
    if (m_virtualReceivingCharPtrCallback) {
        const void *thisPtr = this;
        m_virtualReceivingCharPtrCallback(const_cast<void *>(thisPtr), arg__1);
    } else {
        ::TestTargetNS::MyDerivedClass::virtualReceivingCharPtr(arg__1);
    }
}
void MyDerivedClass_wrapper::virtualReceivingCharPtr_nocallback(char *arg__1)
{
    ::TestTargetNS::MyDerivedClass::virtualReceivingCharPtr(arg__1);
}
int MyDerivedClass_wrapper::virtualReceivingInt(int arg__1)
{
    if (m_virtualReceivingIntCallback) {
        const void *thisPtr = this;
        return m_virtualReceivingIntCallback(const_cast<void *>(thisPtr), arg__1);
    } else {
        return ::TestTargetNS::MyDerivedClass::virtualReceivingInt(arg__1);
    }
}
int MyDerivedClass_wrapper::virtualReceivingInt_nocallback(int arg__1)
{
    return ::TestTargetNS::MyDerivedClass::virtualReceivingInt(arg__1);
}
int MyDerivedClass_wrapper::virtualReceivingOptionalArgument(int optional)
{
    if (m_virtualReceivingOptionalArgumentCallback) {
        const void *thisPtr = this;
        return m_virtualReceivingOptionalArgumentCallback(const_cast<void *>(thisPtr), optional);
    } else {
        return ::TestTargetNS::MyDerivedClass::virtualReceivingOptionalArgument(optional);
    }
}
int MyDerivedClass_wrapper::virtualReceivingOptionalArgument_nocallback(int optional)
{
    return ::TestTargetNS::MyDerivedClass::virtualReceivingOptionalArgument(optional);
}
bool MyDerivedClass_wrapper::virtualReturningBool(bool b)
{
    if (m_virtualReturningBoolCallback) {
        const void *thisPtr = this;
        return m_virtualReturningBoolCallback(const_cast<void *>(thisPtr), b);
    } else {
        return ::TestTargetNS::MyDerivedClass::virtualReturningBool(b);
    }
}
bool MyDerivedClass_wrapper::virtualReturningBool_nocallback(bool b)
{
    return ::TestTargetNS::MyDerivedClass::virtualReturningBool(b);
}
qint64 MyDerivedClass_wrapper::virtualReturningQint64()
{
    if (m_virtualReturningQint64Callback) {
        const void *thisPtr = this;
        return m_virtualReturningQint64Callback(const_cast<void *>(thisPtr));
    } else {
        return ::TestTargetNS::MyDerivedClass::virtualReturningQint64();
    }
}
qint64 MyDerivedClass_wrapper::virtualReturningQint64_nocallback()
{
    return ::TestTargetNS::MyDerivedClass::virtualReturningQint64();
}
SimpleStruct MyDerivedClass_wrapper::virtualReturningStruct() const
{
    if (m_virtualReturningStructCallback) {
        const void *thisPtr = this;
        return *m_virtualReturningStructCallback(const_cast<void *>(thisPtr));
    } else {
        return ::TestTargetNS::MyDerivedClass::virtualReturningStruct();
    }
}
SimpleStruct MyDerivedClass_wrapper::virtualReturningStruct_nocallback() const
{
    return ::TestTargetNS::MyDerivedClass::virtualReturningStruct();
}
MyTemplate<int> MyDerivedClass_wrapper::virtualReturnsIntTemplate()
{
    if (m_virtualReturnsIntTemplateCallback) {
        const void *thisPtr = this;
        return *m_virtualReturnsIntTemplateCallback(const_cast<void *>(thisPtr));
    } else {
        return ::TestTargetNS::MyDerivedClass::virtualReturnsIntTemplate();
    }
}
MyTemplate<int> MyDerivedClass_wrapper::virtualReturnsIntTemplate_nocallback()
{
    return ::TestTargetNS::MyDerivedClass::virtualReturnsIntTemplate();
}
void MyDerivedClass_wrapper::virtualWithOverload(int i) const
{
    if (m_virtualWithOverloadCallback) {
        const void *thisPtr = this;
        m_virtualWithOverloadCallback(const_cast<void *>(thisPtr), i);
    } else {
        ::TestTargetNS::MyDerivedClass::virtualWithOverload(i);
    }
}
void MyDerivedClass_wrapper::virtualWithOverload_nocallback(int i) const
{
    ::TestTargetNS::MyDerivedClass::virtualWithOverload(i);
}
void MyDerivedClass_wrapper::virtualWithOverload(int i, int j) const
{
    if (m_virtualWithOverload_2Callback) {
        const void *thisPtr = this;
        m_virtualWithOverload_2Callback(const_cast<void *>(thisPtr), i, j);
    } else {
        ::TestTargetNS::MyDerivedClass::virtualWithOverload(i, j);
    }
}
void MyDerivedClass_wrapper::virtualWithOverload_nocallback(int i, int j) const
{
    ::TestTargetNS::MyDerivedClass::virtualWithOverload(i, j);
}
MyDerivedClass_wrapper::~MyDerivedClass_wrapper()
{
}

}
static TestTargetNS::MyDerivedClass *fromPtr(void *ptr)
{
    return reinterpret_cast<TestTargetNS::MyDerivedClass *>(ptr);
}
static TestBindings_wrappersNS::MyDerivedClass_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(ptr);
}
extern "C" {
void c_TestTargetNS__MyDerivedClass_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(cppObj);
}
void *c_TestTargetNS__MyDerivedClass__constructor()
{
    auto ptr = new TestBindings_wrappersNS::MyDerivedClass_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// alsoCallsVirtual()
int c_TestTargetNS__MyDerivedClass__alsoCallsVirtual(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->alsoCallsVirtual();
    return result;
}
// anotherOverloadedStatic(int arg__1)
void *c_static_TestTargetNS__MyDerivedClass__anotherOverloadedStatic_int(int arg__1)
{
    const auto &result = const_cast<void *>(static_cast<const void *>(
        TestBindings_wrappersNS::MyDerivedClass_wrapper::anotherOverloadedStatic(arg__1)));
    return result;
}
// anotherOverloadedStatic(int arg__1, int arg__2)
void *c_static_TestTargetNS__MyDerivedClass__anotherOverloadedStatic_int_int(int arg__1, int arg__2)
{
    const auto &result = const_cast<void *>(static_cast<const void *>(
        TestBindings_wrappersNS::MyDerivedClass_wrapper::anotherOverloadedStatic(arg__1, arg__2)));
    return result;
}
// bar() const
int c_TestTargetNS__MyDerivedClass__bar(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->bar_nocallback();
        } else {
            return targetPtr->bar();
        }
    }();
    return result;
}
// bar2() const
int c_TestTargetNS__MyDerivedClass__bar2(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->bar2_nocallback();
        } else {
            return targetPtr->bar2();
        }
    }();
    return result;
}
// nonVirtualButOverridden() const
int c_TestTargetNS__MyDerivedClass__nonVirtualButOverridden(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->nonVirtualButOverridden();
    return result;
}
// nonVirtualInBaseButVirtualInDerived(int i, int j) const
int c_TestTargetNS__MyDerivedClass__nonVirtualInBaseButVirtualInDerived_int_int(void *thisObj,
                                                                                int i, int j)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->nonVirtualInBaseButVirtualInDerived_nocallback(i, j);
        } else {
            return targetPtr->nonVirtualInBaseButVirtualInDerived(i, j);
        }
    }();
    return result;
}
// paintEvent()
void c_TestTargetNS__MyDerivedClass__paintEvent(void *thisObj)
{
    fromWrapperPtr(thisObj)->paintEvent_nocallback();
}
// receivesDerivedPolymorphic(TestTargetNS::MyDerivedClass * der)
int c_TestTargetNS__MyDerivedClass__receivesDerivedPolymorphic_MyDerivedClass(void *thisObj,
                                                                              void *der_)
{
    auto der = reinterpret_cast<TestTargetNS::MyDerivedClass *>(der_);
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->receivesDerivedPolymorphic_nocallback(der);
        } else {
            return targetPtr->receivesDerivedPolymorphic(der);
        }
    }();
    return result;
}
// receivesEnumFromBaseClassWithDefaultValue(int a)
void c_TestTargetNS__MyDerivedClass__receivesEnumFromBaseClassWithDefaultValue_int(void *thisObj,
                                                                                   int a)
{
    fromPtr(thisObj)->receivesEnumFromBaseClassWithDefaultValue(a);
}
// receivesProtectedEnum(TestTargetNS::MyBaseClass::ProtectedEnum p)
int c_TestTargetNS__MyDerivedClass__receivesProtectedEnum_ProtectedEnum(void *thisObj, int p)
{
    const auto &result = fromPtr(thisObj)->receivesProtectedEnum(
        static_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper::ProtectedEnum>(p));
    return result;
}
// renamedVirtual1()
void c_TestTargetNS__MyDerivedClass__renamedVirtual2(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->renamedVirtual1_nocallback();
        } else {
            return targetPtr->renamedVirtual1();
        }
    }();
}
// returnTemplate1()
void *c_TestTargetNS__MyDerivedClass__returnTemplate1(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate2<NonCopiable *>> {
        fromPtr(thisObj)->returnTemplate1()
    };
    return result;
}
// returnTemplate2()
void *c_TestTargetNS__MyDerivedClass__returnTemplate2(void *thisObj)
{
    const auto &result =
        const_cast<void *>(static_cast<const void *>(&fromPtr(thisObj)->returnTemplate2()));
    return result;
}
// returnsAnotherNamespaceEnum()
int c_static_TestTargetNS__MyDerivedClass__returnsAnotherNamespaceEnum()
{
    const auto &result =
        TestBindings_wrappersNS::MyDerivedClass_wrapper::returnsAnotherNamespaceEnum();
    return result;
}
// returnsAnotherNamespaceStruct()
void *c_static_TestTargetNS__MyDerivedClass__returnsAnotherNamespaceStruct()
{
    const auto &result = new Dartagnan::ValueWrapper<AnotherNamespace::AnotherNamespaceStruct> {
        TestBindings_wrappersNS::MyDerivedClass_wrapper::returnsAnotherNamespaceStruct()
    };
    return result;
}
// returnsConstPointer()
void *c_TestTargetNS__MyDerivedClass__returnsConstPointer(void *thisObj)
{
    const auto &result =
        const_cast<void *>(static_cast<const void *>(fromPtr(thisObj)->returnsConstPointer()));
    return result;
}
// setVisible(bool b)
void c_TestTargetNS__MyDerivedClass__setVisible_bool(void *thisObj, bool b)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->setVisible_nocallback(b);
        } else {
            return targetPtr->setVisible(b);
        }
    }();
}
// show()
void c_TestTargetNS__MyDerivedClass__show(void *thisObj)
{
    fromPtr(thisObj)->show();
}
// virtualNotInBase() const
int c_TestTargetNS__MyDerivedClass__virtualNotInBase(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualNotInBase_nocallback();
        } else {
            return targetPtr->virtualNotInBase();
        }
    }();
    return result;
}
// virtualReceivingBool(bool b)
int c_TestTargetNS__MyDerivedClass__virtualReceivingBool_bool(void *thisObj, bool b)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReceivingBool_nocallback(b);
        } else {
            return targetPtr->virtualReceivingBool(b);
        }
    }();
    return result;
}
// virtualReceivingCharPtr(char * arg__1)
void c_TestTargetNS__MyDerivedClass__virtualReceivingCharPtr_char(void *thisObj, char *arg__1)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReceivingCharPtr_nocallback(arg__1);
        } else {
            return targetPtr->virtualReceivingCharPtr(arg__1);
        }
    }();
    free(( char * )arg__1);
}
// virtualReceivingInt(int arg__1)
int c_TestTargetNS__MyDerivedClass__virtualReceivingInt_int(void *thisObj, int arg__1)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReceivingInt_nocallback(arg__1);
        } else {
            return targetPtr->virtualReceivingInt(arg__1);
        }
    }();
    return result;
}
// virtualReceivingOptionalArgument(int optional)
int c_TestTargetNS__MyDerivedClass__virtualReceivingOptionalArgument_int(void *thisObj,
                                                                         int optional)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReceivingOptionalArgument_nocallback(optional);
        } else {
            return targetPtr->virtualReceivingOptionalArgument(optional);
        }
    }();
    return result;
}
// virtualReturningBool(bool b)
bool c_TestTargetNS__MyDerivedClass__virtualReturningBool_bool(void *thisObj, bool b)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReturningBool_nocallback(b);
        } else {
            return targetPtr->virtualReturningBool(b);
        }
    }();
    return result;
}
// virtualReturningQint64()
qint64 c_TestTargetNS__MyDerivedClass__virtualReturningQint64(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReturningQint64_nocallback();
        } else {
            return targetPtr->virtualReturningQint64();
        }
    }();
    return result;
}
// virtualReturningStruct() const
void *c_TestTargetNS__MyDerivedClass__virtualReturningStruct(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<SimpleStruct> { [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReturningStruct_nocallback();
        } else {
            return targetPtr->virtualReturningStruct();
        }
    }() };
    return result;
}
// virtualReturnsIntTemplate()
void *c_TestTargetNS__MyDerivedClass__virtualReturnsIntTemplate(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<int>> { [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReturnsIntTemplate_nocallback();
        } else {
            return targetPtr->virtualReturnsIntTemplate();
        }
    }() };
    return result;
}
// virtualWithOverload(int i) const
void c_TestTargetNS__MyDerivedClass__virtualWithOverload_int(void *thisObj, int i)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualWithOverload_nocallback(i);
        } else {
            return targetPtr->virtualWithOverload(i);
        }
    }();
}
// virtualWithOverload(int i, int j) const
void c_TestTargetNS__MyDerivedClass__virtualWithOverload_int_int(void *thisObj, int i, int j)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualWithOverload_nocallback(i, j);
        } else {
            return targetPtr->virtualWithOverload(i, j);
        }
    }();
}
void c_TestTargetNS__MyDerivedClass__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
int c_static_TestTargetNS__MyDerivedClass___get_s_instanceCount()
{
    return TestBindings_wrappersNS::MyDerivedClass_wrapper::s_instanceCount;
}
void c_static_TestTargetNS__MyDerivedClass___set_s_instanceCount_int(int s_instanceCount_)
{
    TestBindings_wrappersNS::MyDerivedClass_wrapper::s_instanceCount = s_instanceCount_;
}
void c_TestTargetNS__MyDerivedClass__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                   int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 51:
        wrapper->m_barCallback =
            reinterpret_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_bar>(
                callback);
        break;
    case 52:
        wrapper->m_bar2Callback =
            reinterpret_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_bar2>(
                callback);
        break;
    case 63:
        wrapper->m_nonVirtualInBaseButVirtualInDerived_2Callback =
            reinterpret_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper::
                                 Callback_nonVirtualInBaseButVirtualInDerived_2>(callback);
        break;
    case 135:
        wrapper->m_paintEventCallback =
            reinterpret_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_paintEvent>(
                callback);
        break;
    case 143:
        wrapper->m_receivesDerivedPolymorphicCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_receivesDerivedPolymorphic>(
            callback);
        break;
    case 86:
        wrapper->m_renamedVirtual2Callback = reinterpret_cast<
            TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_renamedVirtual2>(callback);
        break;
    case 176:
        wrapper->m_setVisibleCallback =
            reinterpret_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_setVisible>(
                callback);
        break;
    case 181:
        wrapper->m_virtualNotInBaseCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_virtualNotInBase>(callback);
        break;
    case 103:
        wrapper->m_virtualReceivingBoolCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_virtualReceivingBool>(
            callback);
        break;
    case 104:
        wrapper->m_virtualReceivingCharPtrCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_virtualReceivingCharPtr>(
            callback);
        break;
    case 105:
        wrapper->m_virtualReceivingIntCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_virtualReceivingInt>(
            callback);
        break;
    case 106:
        wrapper->m_virtualReceivingOptionalArgumentCallback =
            reinterpret_cast<TestBindings_wrappersNS::MyDerivedClass_wrapper::
                                 Callback_virtualReceivingOptionalArgument>(callback);
        break;
    case 107:
        wrapper->m_virtualReturningBoolCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_virtualReturningBool>(
            callback);
        break;
    case 108:
        wrapper->m_virtualReturningQint64Callback = reinterpret_cast<
            TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_virtualReturningQint64>(
            callback);
        break;
    case 109:
        wrapper->m_virtualReturningStructCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_virtualReturningStruct>(
            callback);
        break;
    case 110:
        wrapper->m_virtualReturnsIntTemplateCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_virtualReturnsIntTemplate>(
            callback);
        break;
    case 112:
        wrapper->m_virtualWithOverloadCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_virtualWithOverload>(
            callback);
        break;
    case 113:
        wrapper->m_virtualWithOverload_2Callback = reinterpret_cast<
            TestBindings_wrappersNS::MyDerivedClass_wrapper::Callback_virtualWithOverload_2>(
            callback);
        break;
    }
}
}

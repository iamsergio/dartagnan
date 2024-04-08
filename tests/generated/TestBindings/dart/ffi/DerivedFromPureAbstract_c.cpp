#include "DerivedFromPureAbstract_c.h"


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
DerivedFromPureAbstract_wrapper::DerivedFromPureAbstract_wrapper()
    : ::TestTargetNS::DerivedFromPureAbstract()
{
}
DerivedFromPureAbstract_wrapper::DerivedFromPureAbstract_wrapper(int arg__1)
    : ::TestTargetNS::DerivedFromPureAbstract(arg__1)
{
}
int DerivedFromPureAbstract_wrapper::foo()
{
    if (m_fooCallback) {
        const void *thisPtr = this;
        return m_fooCallback(const_cast<void *>(thisPtr));
    } else {
        return ::TestTargetNS::DerivedFromPureAbstract::foo();
    }
}
int DerivedFromPureAbstract_wrapper::foo_nocallback()
{
    return ::TestTargetNS::DerivedFromPureAbstract::foo();
}
int DerivedFromPureAbstract_wrapper::indirectionCallsVirtualReceivingStruct(SimpleStruct s)
{
    return ::TestTargetNS::DerivedFromPureAbstract::indirectionCallsVirtualReceivingStruct(s);
}
int DerivedFromPureAbstract_wrapper::nonVirtualCallsVirtual()
{
    return ::TestTargetNS::DerivedFromPureAbstract::nonVirtualCallsVirtual();
}
int DerivedFromPureAbstract_wrapper::receivesValueStruct(SimpleStruct arg__1)
{
    if (m_receivesValueStructCallback) {
        const void *thisPtr = this;
        return m_receivesValueStructCallback(const_cast<void *>(thisPtr), &arg__1);
    } else {
        return ::TestTargetNS::DerivedFromPureAbstract::receivesValueStruct(arg__1);
    }
}
int DerivedFromPureAbstract_wrapper::receivesValueStruct_nocallback(SimpleStruct arg__1)
{
    return ::TestTargetNS::DerivedFromPureAbstract::receivesValueStruct(arg__1);
}
void DerivedFromPureAbstract_wrapper::renamedPureVirtual()
{
    if (m_renamedPureVirtual1Callback) {
        const void *thisPtr = this;
        m_renamedPureVirtual1Callback(const_cast<void *>(thisPtr));
    } else {
        ::TestTargetNS::DerivedFromPureAbstract::renamedPureVirtual();
    }
}
void DerivedFromPureAbstract_wrapper::renamedPureVirtual_nocallback()
{
    ::TestTargetNS::DerivedFromPureAbstract::renamedPureVirtual();
}
void DerivedFromPureAbstract_wrapper::unnamedOverriddenDefaultArgCase(int arg__1)
{
    if (m_unnamedOverriddenDefaultArgCaseCallback) {
        const void *thisPtr = this;
        m_unnamedOverriddenDefaultArgCaseCallback(const_cast<void *>(thisPtr), arg__1);
    } else {
        ::TestTargetNS::DerivedFromPureAbstract::unnamedOverriddenDefaultArgCase(arg__1);
    }
}
void DerivedFromPureAbstract_wrapper::unnamedOverriddenDefaultArgCase_nocallback(int arg__1)
{
    ::TestTargetNS::DerivedFromPureAbstract::unnamedOverriddenDefaultArgCase(arg__1);
}
int DerivedFromPureAbstract_wrapper::virtualReceivingPointer(SimpleStruct *s)
{
    if (m_virtualReceivingPointerCallback) {
        const void *thisPtr = this;
        return m_virtualReceivingPointerCallback(const_cast<void *>(thisPtr), s);
    } else {
        return ::TestTargetNS::DerivedFromPureAbstract::virtualReceivingPointer(s);
    }
}
int DerivedFromPureAbstract_wrapper::virtualReceivingPointer_nocallback(SimpleStruct *s)
{
    return ::TestTargetNS::DerivedFromPureAbstract::virtualReceivingPointer(s);
}
void DerivedFromPureAbstract_wrapper::voidPureAbstract()
{
    if (m_voidPureAbstractCallback) {
        const void *thisPtr = this;
        m_voidPureAbstractCallback(const_cast<void *>(thisPtr));
    } else {
        ::TestTargetNS::DerivedFromPureAbstract::voidPureAbstract();
    }
}
void DerivedFromPureAbstract_wrapper::voidPureAbstract_nocallback()
{
    ::TestTargetNS::DerivedFromPureAbstract::voidPureAbstract();
}
DerivedFromPureAbstract_wrapper::~DerivedFromPureAbstract_wrapper()
{
}

}
static TestTargetNS::DerivedFromPureAbstract *fromPtr(void *ptr)
{
    return reinterpret_cast<TestTargetNS::DerivedFromPureAbstract *>(ptr);
}
static TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper *>(ptr);
}
extern "C" {
void c_TestTargetNS__DerivedFromPureAbstract_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper *>(cppObj);
}
void *c_TestTargetNS__DerivedFromPureAbstract__constructor()
{
    auto ptr = new TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper();
    return reinterpret_cast<void *>(ptr);
}
void *c_TestTargetNS__DerivedFromPureAbstract__constructor_int(int arg__1)
{
    auto ptr = new TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper(arg__1);
    return reinterpret_cast<void *>(ptr);
}
// foo()
int c_TestTargetNS__DerivedFromPureAbstract__foo(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->foo_nocallback();
        } else {
            return targetPtr->foo();
        }
    }();
    return result;
}
// indirectionCallsVirtualReceivingStruct(SimpleStruct s)
int c_TestTargetNS__DerivedFromPureAbstract__indirectionCallsVirtualReceivingStruct_SimpleStruct(
    void *thisObj, void *s_)
{
    assert(s_);
    auto &s = *reinterpret_cast<SimpleStruct *>(s_);
    const auto &result = fromPtr(thisObj)->indirectionCallsVirtualReceivingStruct(s);
    return result;
}
// nonVirtualCallsVirtual()
int c_TestTargetNS__DerivedFromPureAbstract__nonVirtualCallsVirtual(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->nonVirtualCallsVirtual();
    return result;
}
// receivesValueStruct(SimpleStruct arg__1)
int c_TestTargetNS__DerivedFromPureAbstract__receivesValueStruct_SimpleStruct(void *thisObj,
                                                                              void *arg__1_)
{
    assert(arg__1_);
    auto &arg__1 = *reinterpret_cast<SimpleStruct *>(arg__1_);
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->receivesValueStruct_nocallback(arg__1);
        } else {
            return targetPtr->receivesValueStruct(arg__1);
        }
    }();
    return result;
}
// renamedPureVirtual()
void c_TestTargetNS__DerivedFromPureAbstract__renamedPureVirtual1(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->renamedPureVirtual_nocallback();
        } else {
            return targetPtr->renamedPureVirtual();
        }
    }();
}
// unnamedOverriddenDefaultArgCase(int arg__1)
void c_TestTargetNS__DerivedFromPureAbstract__unnamedOverriddenDefaultArgCase_int(void *thisObj,
                                                                                  int arg__1)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->unnamedOverriddenDefaultArgCase_nocallback(arg__1);
        } else {
            return targetPtr->unnamedOverriddenDefaultArgCase(arg__1);
        }
    }();
}
// virtualReceivingPointer(SimpleStruct * s)
int c_TestTargetNS__DerivedFromPureAbstract__virtualReceivingPointer_SimpleStruct(void *thisObj,
                                                                                  void *s_)
{
    auto s = reinterpret_cast<SimpleStruct *>(s_);
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReceivingPointer_nocallback(s);
        } else {
            return targetPtr->virtualReceivingPointer(s);
        }
    }();
    return result;
}
// voidPureAbstract()
void c_TestTargetNS__DerivedFromPureAbstract__voidPureAbstract(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->voidPureAbstract_nocallback();
        } else {
            return targetPtr->voidPureAbstract();
        }
    }();
}
void c_TestTargetNS__DerivedFromPureAbstract__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
void c_TestTargetNS__DerivedFromPureAbstract__registerVirtualMethodCallback(void *ptr,
                                                                            void *callback,
                                                                            int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 13:
        wrapper->m_fooCallback = reinterpret_cast<
            TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper::Callback_foo>(callback);
        break;
    case 193:
        wrapper->m_receivesValueStructCallback = reinterpret_cast<
            TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper::Callback_receivesValueStruct>(
            callback);
        break;
    case 14:
        wrapper->m_renamedPureVirtual1Callback = reinterpret_cast<
            TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper::Callback_renamedPureVirtual1>(
            callback);
        break;
    case 17:
        wrapper->m_unnamedOverriddenDefaultArgCaseCallback =
            reinterpret_cast<TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper::
                                 Callback_unnamedOverriddenDefaultArgCase>(callback);
        break;
    case 18:
        wrapper->m_virtualReceivingPointerCallback =
            reinterpret_cast<TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper::
                                 Callback_virtualReceivingPointer>(callback);
        break;
    case 19:
        wrapper->m_voidPureAbstractCallback = reinterpret_cast<
            TestBindings_wrappersNS::DerivedFromPureAbstract_wrapper::Callback_voidPureAbstract>(
            callback);
        break;
    }
}
}

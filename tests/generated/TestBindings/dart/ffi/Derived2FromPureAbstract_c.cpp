#include "Derived2FromPureAbstract_c.h"


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
Derived2FromPureAbstract_wrapper::Derived2FromPureAbstract_wrapper()
    : ::TestTargetNS::Derived2FromPureAbstract()
{
}
int Derived2FromPureAbstract_wrapper::foo()
{
    if (m_fooCallback) {
        const void *thisPtr = this;
        return m_fooCallback(const_cast<void *>(thisPtr));
    } else {
        std::cerr << "foo: Warning: Calling pure-virtual\n";
        return {};
    }
}
int Derived2FromPureAbstract_wrapper::foo_nocallback()
{
    std::cerr << "foo: Warning: Calling pure-virtual\n";
    return {};
}
void Derived2FromPureAbstract_wrapper::renamedPureVirtual()
{
    if (m_renamedPureVirtual1Callback) {
        const void *thisPtr = this;
        m_renamedPureVirtual1Callback(const_cast<void *>(thisPtr));
    } else {
        std::cerr << "renamedPureVirtual1: Warning: Calling pure-virtual\n";
        return;
    }
}
void Derived2FromPureAbstract_wrapper::renamedPureVirtual_nocallback()
{
    std::cerr << "renamedPureVirtual1: Warning: Calling pure-virtual\n";
    return;
}
void Derived2FromPureAbstract_wrapper::unnamedOverriddenDefaultArgCase(int myarg)
{
    if (m_unnamedOverriddenDefaultArgCaseCallback) {
        const void *thisPtr = this;
        m_unnamedOverriddenDefaultArgCaseCallback(const_cast<void *>(thisPtr), myarg);
    } else {
        ::TestTargetNS::Derived2FromPureAbstract::unnamedOverriddenDefaultArgCase(myarg);
    }
}
void Derived2FromPureAbstract_wrapper::unnamedOverriddenDefaultArgCase_nocallback(int myarg)
{
    ::TestTargetNS::Derived2FromPureAbstract::unnamedOverriddenDefaultArgCase(myarg);
}
int Derived2FromPureAbstract_wrapper::virtualReceivingPointer(SimpleStruct *s)
{
    if (m_virtualReceivingPointerCallback) {
        const void *thisPtr = this;
        return m_virtualReceivingPointerCallback(const_cast<void *>(thisPtr), s);
    } else {
        return ::TestTargetNS::Derived2FromPureAbstract::virtualReceivingPointer(s);
    }
}
int Derived2FromPureAbstract_wrapper::virtualReceivingPointer_nocallback(SimpleStruct *s)
{
    return ::TestTargetNS::Derived2FromPureAbstract::virtualReceivingPointer(s);
}
void Derived2FromPureAbstract_wrapper::voidPureAbstract()
{
    if (m_voidPureAbstractCallback) {
        const void *thisPtr = this;
        m_voidPureAbstractCallback(const_cast<void *>(thisPtr));
    } else {
        std::cerr << "voidPureAbstract: Warning: Calling pure-virtual\n";
        return;
    }
}
void Derived2FromPureAbstract_wrapper::voidPureAbstract_nocallback()
{
    std::cerr << "voidPureAbstract: Warning: Calling pure-virtual\n";
    return;
}
Derived2FromPureAbstract_wrapper::~Derived2FromPureAbstract_wrapper()
{
}

}
static TestTargetNS::Derived2FromPureAbstract *fromPtr(void *ptr)
{
    return reinterpret_cast<TestTargetNS::Derived2FromPureAbstract *>(ptr);
}
static TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper *>(ptr);
}
extern "C" {
void c_TestTargetNS__Derived2FromPureAbstract_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper *>(cppObj);
}
void *c_TestTargetNS__Derived2FromPureAbstract__constructor()
{
    auto ptr = new TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// foo()
int c_TestTargetNS__Derived2FromPureAbstract__foo(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->foo_nocallback();
        } else {
            return targetPtr->foo();
        }
    }();
    return result;
}
// renamedPureVirtual()
void c_TestTargetNS__Derived2FromPureAbstract__renamedPureVirtual1(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->renamedPureVirtual_nocallback();
        } else {
            return targetPtr->renamedPureVirtual();
        }
    }();
}
// unnamedOverriddenDefaultArgCase(int myarg)
void c_TestTargetNS__Derived2FromPureAbstract__unnamedOverriddenDefaultArgCase_int(void *thisObj,
                                                                                   int myarg)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->unnamedOverriddenDefaultArgCase_nocallback(myarg);
        } else {
            return targetPtr->unnamedOverriddenDefaultArgCase(myarg);
        }
    }();
}
// virtualReceivingPointer(SimpleStruct * s)
int c_TestTargetNS__Derived2FromPureAbstract__virtualReceivingPointer_SimpleStruct(void *thisObj,
                                                                                   void *s_)
{
    auto s = reinterpret_cast<SimpleStruct *>(s_);
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReceivingPointer_nocallback(s);
        } else {
            return targetPtr->virtualReceivingPointer(s);
        }
    }();
    return result;
}
// voidPureAbstract()
void c_TestTargetNS__Derived2FromPureAbstract__voidPureAbstract(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->voidPureAbstract_nocallback();
        } else {
            return targetPtr->voidPureAbstract();
        }
    }();
}
void c_TestTargetNS__Derived2FromPureAbstract__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
void c_TestTargetNS__Derived2FromPureAbstract__registerVirtualMethodCallback(void *ptr,
                                                                             void *callback,
                                                                             int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 13:
        wrapper->m_fooCallback = reinterpret_cast<
            TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper::Callback_foo>(callback);
        break;
    case 14:
        wrapper->m_renamedPureVirtual1Callback =
            reinterpret_cast<TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper::
                                 Callback_renamedPureVirtual1>(callback);
        break;
    case 17:
        wrapper->m_unnamedOverriddenDefaultArgCaseCallback =
            reinterpret_cast<TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper::
                                 Callback_unnamedOverriddenDefaultArgCase>(callback);
        break;
    case 18:
        wrapper->m_virtualReceivingPointerCallback =
            reinterpret_cast<TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper::
                                 Callback_virtualReceivingPointer>(callback);
        break;
    case 19:
        wrapper->m_voidPureAbstractCallback = reinterpret_cast<
            TestBindings_wrappersNS::Derived2FromPureAbstract_wrapper::Callback_voidPureAbstract>(
            callback);
        break;
    }
}
}

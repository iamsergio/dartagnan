#include "PureAbstract_c.h"


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
PureAbstract_wrapper::PureAbstract_wrapper()
    : ::TestTargetNS::PureAbstract()
{
}
int PureAbstract_wrapper::callVirtualReceivingPointer(SimpleStruct *s)
{
    return ::TestTargetNS::PureAbstract::callVirtualReceivingPointer(s);
}
void PureAbstract_wrapper::flagsWithDefaultArgs(
    QFlags<AnotherNamespace::NamespaceLevelEnum> options)
{
    ::TestTargetNS::PureAbstract::flagsWithDefaultArgs(options);
}
int PureAbstract_wrapper::foo()
{
    if (m_fooCallback) {
        const void *thisPtr = this;
        return m_fooCallback(const_cast<void *>(thisPtr));
    } else {
        std::cerr << "foo: Warning: Calling pure-virtual\n";
        return {};
    }
}
int PureAbstract_wrapper::foo_nocallback()
{
    std::cerr << "foo: Warning: Calling pure-virtual\n";
    return {};
}
void PureAbstract_wrapper::renamedPureVirtual()
{
    if (m_renamedPureVirtual1Callback) {
        const void *thisPtr = this;
        m_renamedPureVirtual1Callback(const_cast<void *>(thisPtr));
    } else {
        std::cerr << "renamedPureVirtual1: Warning: Calling pure-virtual\n";
        return;
    }
}
void PureAbstract_wrapper::renamedPureVirtual_nocallback()
{
    std::cerr << "renamedPureVirtual1: Warning: Calling pure-virtual\n";
    return;
}
void PureAbstract_wrapper::renamedStatic()
{
    ::TestTargetNS::PureAbstract::renamedStatic();
}
int PureAbstract_wrapper::returnsInt() const
{
    return ::TestTargetNS::PureAbstract::returnsInt();
}
void PureAbstract_wrapper::unnamedOverriddenDefaultArgCase(int myarg)
{
    if (m_unnamedOverriddenDefaultArgCaseCallback) {
        const void *thisPtr = this;
        m_unnamedOverriddenDefaultArgCaseCallback(const_cast<void *>(thisPtr), myarg);
    } else {
        ::TestTargetNS::PureAbstract::unnamedOverriddenDefaultArgCase(myarg);
    }
}
void PureAbstract_wrapper::unnamedOverriddenDefaultArgCase_nocallback(int myarg)
{
    ::TestTargetNS::PureAbstract::unnamedOverriddenDefaultArgCase(myarg);
}
int PureAbstract_wrapper::virtualReceivingPointer(SimpleStruct *s)
{
    if (m_virtualReceivingPointerCallback) {
        const void *thisPtr = this;
        return m_virtualReceivingPointerCallback(const_cast<void *>(thisPtr), s);
    } else {
        return ::TestTargetNS::PureAbstract::virtualReceivingPointer(s);
    }
}
int PureAbstract_wrapper::virtualReceivingPointer_nocallback(SimpleStruct *s)
{
    return ::TestTargetNS::PureAbstract::virtualReceivingPointer(s);
}
void PureAbstract_wrapper::voidPureAbstract()
{
    if (m_voidPureAbstractCallback) {
        const void *thisPtr = this;
        m_voidPureAbstractCallback(const_cast<void *>(thisPtr));
    } else {
        std::cerr << "voidPureAbstract: Warning: Calling pure-virtual\n";
        return;
    }
}
void PureAbstract_wrapper::voidPureAbstract_nocallback()
{
    std::cerr << "voidPureAbstract: Warning: Calling pure-virtual\n";
    return;
}
PureAbstract_wrapper::~PureAbstract_wrapper()
{
}

}
static TestTargetNS::PureAbstract *fromPtr(void *ptr)
{
    return reinterpret_cast<TestTargetNS::PureAbstract *>(ptr);
}
static TestBindings_wrappersNS::PureAbstract_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::PureAbstract_wrapper *>(ptr);
}
extern "C" {
void c_TestTargetNS__PureAbstract_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::PureAbstract_wrapper *>(cppObj);
}
void *c_TestTargetNS__PureAbstract__constructor()
{
    auto ptr = new TestBindings_wrappersNS::PureAbstract_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// callVirtualReceivingPointer(SimpleStruct * s)
int c_TestTargetNS__PureAbstract__callVirtualReceivingPointer_SimpleStruct(void *thisObj, void *s_)
{
    auto s = reinterpret_cast<SimpleStruct *>(s_);
    const auto &result = fromPtr(thisObj)->callVirtualReceivingPointer(s);
    return result;
}
// flagsWithDefaultArgs(QFlags<AnotherNamespace::NamespaceLevelEnum> options)
void c_TestTargetNS__PureAbstract__flagsWithDefaultArgs_NamespaceLevelEnums(void *thisObj,
                                                                            int options_)
{
    auto options = static_cast<QFlags<AnotherNamespace::NamespaceLevelEnum>>(options_);
    fromPtr(thisObj)->flagsWithDefaultArgs(options);
}
// foo()
int c_TestTargetNS__PureAbstract__foo(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::PureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->foo_nocallback();
        } else {
            return targetPtr->foo();
        }
    }();
    return result;
}
// renamedPureVirtual()
void c_TestTargetNS__PureAbstract__renamedPureVirtual1(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::PureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->renamedPureVirtual_nocallback();
        } else {
            return targetPtr->renamedPureVirtual();
        }
    }();
}
// renamedStatic()
void c_static_TestTargetNS__PureAbstract__renamedStatic1()
{
    TestBindings_wrappersNS::PureAbstract_wrapper::renamedStatic();
}
// returnsInt() const
int c_TestTargetNS__PureAbstract__returnsInt(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->returnsInt();
    return result;
}
// unnamedOverriddenDefaultArgCase(int myarg)
void c_TestTargetNS__PureAbstract__unnamedOverriddenDefaultArgCase_int(void *thisObj, int myarg)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::PureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->unnamedOverriddenDefaultArgCase_nocallback(myarg);
        } else {
            return targetPtr->unnamedOverriddenDefaultArgCase(myarg);
        }
    }();
}
// virtualReceivingPointer(SimpleStruct * s)
int c_TestTargetNS__PureAbstract__virtualReceivingPointer_SimpleStruct(void *thisObj, void *s_)
{
    auto s = reinterpret_cast<SimpleStruct *>(s_);
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::PureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReceivingPointer_nocallback(s);
        } else {
            return targetPtr->virtualReceivingPointer(s);
        }
    }();
    return result;
}
// voidPureAbstract()
void c_TestTargetNS__PureAbstract__voidPureAbstract(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::PureAbstract_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->voidPureAbstract_nocallback();
        } else {
            return targetPtr->voidPureAbstract();
        }
    }();
}
void c_TestTargetNS__PureAbstract__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
int c_static_TestTargetNS__PureAbstract___get_s_instanceCount()
{
    return TestBindings_wrappersNS::PureAbstract_wrapper::s_instanceCount;
}
void c_static_TestTargetNS__PureAbstract___set_s_instanceCount_int(int s_instanceCount_)
{
    TestBindings_wrappersNS::PureAbstract_wrapper::s_instanceCount = s_instanceCount_;
}
void c_TestTargetNS__PureAbstract__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                 int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 13:
        wrapper->m_fooCallback =
            reinterpret_cast<TestBindings_wrappersNS::PureAbstract_wrapper::Callback_foo>(callback);
        break;
    case 14:
        wrapper->m_renamedPureVirtual1Callback = reinterpret_cast<
            TestBindings_wrappersNS::PureAbstract_wrapper::Callback_renamedPureVirtual1>(callback);
        break;
    case 17:
        wrapper->m_unnamedOverriddenDefaultArgCaseCallback =
            reinterpret_cast<TestBindings_wrappersNS::PureAbstract_wrapper::
                                 Callback_unnamedOverriddenDefaultArgCase>(callback);
        break;
    case 18:
        wrapper->m_virtualReceivingPointerCallback = reinterpret_cast<
            TestBindings_wrappersNS::PureAbstract_wrapper::Callback_virtualReceivingPointer>(
            callback);
        break;
    case 19:
        wrapper->m_voidPureAbstractCallback = reinterpret_cast<
            TestBindings_wrappersNS::PureAbstract_wrapper::Callback_voidPureAbstract>(callback);
        break;
    }
}
}

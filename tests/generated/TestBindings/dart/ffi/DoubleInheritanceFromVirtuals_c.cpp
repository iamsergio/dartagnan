#include "DoubleInheritanceFromVirtuals_c.h"


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
DoubleInheritanceFromVirtuals_wrapper::DoubleInheritanceFromVirtuals_wrapper()
    : ::DoubleInheritanceFromVirtuals()
{
}
void DoubleInheritanceFromVirtuals_wrapper::virtualMethod1()
{
    if (m_virtualMethod1Callback) {
        const void *thisPtr = this;
        m_virtualMethod1Callback(const_cast<void *>(thisPtr));
    } else {
        ::DoubleInheritanceFromVirtuals::virtualMethod1();
    }
}
void DoubleInheritanceFromVirtuals_wrapper::virtualMethod1_nocallback()
{
    ::DoubleInheritanceFromVirtuals::virtualMethod1();
}
void DoubleInheritanceFromVirtuals_wrapper::virtualMethod2()
{
    if (m_virtualMethod2Callback) {
        const void *thisPtr = this;
        m_virtualMethod2Callback(const_cast<void *>(thisPtr));
    } else {
        ::DoubleInheritanceFromVirtuals::virtualMethod2();
    }
}
void DoubleInheritanceFromVirtuals_wrapper::virtualMethod2_nocallback()
{
    ::DoubleInheritanceFromVirtuals::virtualMethod2();
}
DoubleInheritanceFromVirtuals_wrapper::~DoubleInheritanceFromVirtuals_wrapper()
{
}

}
static DoubleInheritanceFromVirtuals *fromPtr(void *ptr)
{
    return reinterpret_cast<DoubleInheritanceFromVirtuals *>(ptr);
}
static TestBindings_wrappersNS::DoubleInheritanceFromVirtuals_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::DoubleInheritanceFromVirtuals_wrapper *>(ptr);
}
extern "C" {
void c_DoubleInheritanceFromVirtuals_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::DoubleInheritanceFromVirtuals_wrapper *>(
        cppObj);
}
void *c_DoubleInheritanceFromVirtuals__constructor()
{
    auto ptr = new TestBindings_wrappersNS::DoubleInheritanceFromVirtuals_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// virtualMethod1()
void c_DoubleInheritanceFromVirtuals__virtualMethod1(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DoubleInheritanceFromVirtuals_wrapper *>(
                targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualMethod1_nocallback();
        } else {
            return targetPtr->virtualMethod1();
        }
    }();
}
// virtualMethod2()
void c_DoubleInheritanceFromVirtuals__virtualMethod2(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DoubleInheritanceFromVirtuals_wrapper *>(
                targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualMethod2_nocallback();
        } else {
            return targetPtr->virtualMethod2();
        }
    }();
}
void c_DoubleInheritanceFromVirtuals__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
void c_DoubleInheritanceFromVirtuals__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                    int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 3:
        wrapper->m_virtualMethod1Callback =
            reinterpret_cast<TestBindings_wrappersNS::DoubleInheritanceFromVirtuals_wrapper::
                                 Callback_virtualMethod1>(callback);
        break;
    case 1:
        wrapper->m_virtualMethod2Callback =
            reinterpret_cast<TestBindings_wrappersNS::DoubleInheritanceFromVirtuals_wrapper::
                                 Callback_virtualMethod2>(callback);
        break;
    }
}
}

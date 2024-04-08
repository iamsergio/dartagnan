#include "Virtual1_c.h"


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
Virtual1_wrapper::Virtual1_wrapper()
    : ::Virtual1()
{
}
void Virtual1_wrapper::virtualMethod1()
{
    if (m_virtualMethod1Callback) {
        const void *thisPtr = this;
        m_virtualMethod1Callback(const_cast<void *>(thisPtr));
    } else {
        ::Virtual1::virtualMethod1();
    }
}
void Virtual1_wrapper::virtualMethod1_nocallback()
{
    ::Virtual1::virtualMethod1();
}
Virtual1_wrapper::~Virtual1_wrapper()
{
}

}
static Virtual1 *fromPtr(void *ptr)
{
    return reinterpret_cast<Virtual1 *>(ptr);
}
static TestBindings_wrappersNS::Virtual1_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::Virtual1_wrapper *>(ptr);
}
extern "C" {
void c_Virtual1_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::Virtual1_wrapper *>(cppObj);
}
void *c_Virtual1__constructor()
{
    auto ptr = new TestBindings_wrappersNS::Virtual1_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// virtualMethod1()
void c_Virtual1__virtualMethod1(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::Virtual1_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualMethod1_nocallback();
        } else {
            return targetPtr->virtualMethod1();
        }
    }();
}
void c_Virtual1__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
void c_Virtual1__registerVirtualMethodCallback(void *ptr, void *callback, int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 3:
        wrapper->m_virtualMethod1Callback =
            reinterpret_cast<TestBindings_wrappersNS::Virtual1_wrapper::Callback_virtualMethod1>(
                callback);
        break;
    }
}
}

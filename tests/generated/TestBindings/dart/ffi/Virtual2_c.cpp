#include "Virtual2_c.h"


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
Virtual2_wrapper::Virtual2_wrapper()
    : ::Virtual2()
{
}
void Virtual2_wrapper::virtualMethod2()
{
    if (m_virtualMethod2Callback) {
        const void *thisPtr = this;
        m_virtualMethod2Callback(const_cast<void *>(thisPtr));
    } else {
        ::Virtual2::virtualMethod2();
    }
}
void Virtual2_wrapper::virtualMethod2_nocallback()
{
    ::Virtual2::virtualMethod2();
}
Virtual2_wrapper::~Virtual2_wrapper()
{
}

}
static Virtual2 *fromPtr(void *ptr)
{
    return reinterpret_cast<Virtual2 *>(ptr);
}
static TestBindings_wrappersNS::Virtual2_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::Virtual2_wrapper *>(ptr);
}
extern "C" {
void c_Virtual2_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::Virtual2_wrapper *>(cppObj);
}
void *c_Virtual2__constructor()
{
    auto ptr = new TestBindings_wrappersNS::Virtual2_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// virtualMethod2()
void c_Virtual2__virtualMethod2(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::Virtual2_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualMethod2_nocallback();
        } else {
            return targetPtr->virtualMethod2();
        }
    }();
}
void c_Virtual2__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
void c_Virtual2__registerVirtualMethodCallback(void *ptr, void *callback, int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 1:
        wrapper->m_virtualMethod2Callback =
            reinterpret_cast<TestBindings_wrappersNS::Virtual2_wrapper::Callback_virtualMethod2>(
                callback);
        break;
    }
}
}

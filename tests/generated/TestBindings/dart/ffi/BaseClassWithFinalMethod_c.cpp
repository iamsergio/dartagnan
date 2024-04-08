#include "BaseClassWithFinalMethod_c.h"


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
BaseClassWithFinalMethod_wrapper::BaseClassWithFinalMethod_wrapper()
    : ::BaseClassWithFinalMethod()
{
}
BaseClassWithFinalMethod_wrapper::~BaseClassWithFinalMethod_wrapper()
{
}

}
static BaseClassWithFinalMethod *fromPtr(void *ptr)
{
    return reinterpret_cast<BaseClassWithFinalMethod *>(ptr);
}
static TestBindings_wrappersNS::BaseClassWithFinalMethod_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::BaseClassWithFinalMethod_wrapper *>(ptr);
}
extern "C" {
void c_BaseClassWithFinalMethod_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::BaseClassWithFinalMethod_wrapper *>(cppObj);
}
void *c_BaseClassWithFinalMethod__constructor()
{
    auto ptr = new TestBindings_wrappersNS::BaseClassWithFinalMethod_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// finalMethod()
void c_BaseClassWithFinalMethod__finalMethod(void *thisObj)
{
    fromPtr(thisObj)->finalMethod();
}
void c_BaseClassWithFinalMethod__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
void c_BaseClassWithFinalMethod__registerVirtualMethodCallback(void *ptr, void *callback,
                                                               int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 1200:
        wrapper->m_finalMethodCallback = reinterpret_cast<
            TestBindings_wrappersNS::BaseClassWithFinalMethod_wrapper::Callback_finalMethod>(
            callback);
        break;
    }
}
}

#include "AnotherNamespaceStruct_c.h"


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
AnotherNamespaceStruct_wrapper::AnotherNamespaceStruct_wrapper()
    : ::AnotherNamespace::AnotherNamespaceStruct()
{
}
void AnotherNamespaceStruct_wrapper::receivesEnumerator(AnotherNamespace::NamespaceLevelEnum arg__1)
{
    ::AnotherNamespace::AnotherNamespaceStruct::receivesEnumerator(arg__1);
}
AnotherNamespaceStruct_wrapper::~AnotherNamespaceStruct_wrapper()
{
}

}
static AnotherNamespace::AnotherNamespaceStruct *fromPtr(void *ptr)
{
    return reinterpret_cast<AnotherNamespace::AnotherNamespaceStruct *>(ptr);
}
static TestBindings_wrappersNS::AnotherNamespaceStruct_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::AnotherNamespaceStruct_wrapper *>(ptr);
}
extern "C" {
void c_AnotherNamespace__AnotherNamespaceStruct_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::AnotherNamespaceStruct_wrapper *>(cppObj);
}
void *c_AnotherNamespace__AnotherNamespaceStruct__constructor()
{
    auto ptr = new TestBindings_wrappersNS::AnotherNamespaceStruct_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// receivesEnumerator(AnotherNamespace::NamespaceLevelEnum arg__1)
void c_AnotherNamespace__AnotherNamespaceStruct__receivesEnumerator_NamespaceLevelEnum(
    void *thisObj, int arg__1)
{
    fromPtr(thisObj)->receivesEnumerator(static_cast<AnotherNamespace::NamespaceLevelEnum>(arg__1));
}
void c_AnotherNamespace__AnotherNamespaceStruct__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
}

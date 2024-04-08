#include "EmptyStruct_c.h"


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
EmptyStruct_wrapper::EmptyStruct_wrapper()
    : ::EmptyStruct()
{
}
EmptyStruct_wrapper::~EmptyStruct_wrapper()
{
}

}
static EmptyStruct *fromPtr(void *ptr)
{
    return reinterpret_cast<EmptyStruct *>(ptr);
}
static TestBindings_wrappersNS::EmptyStruct_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::EmptyStruct_wrapper *>(ptr);
}
extern "C" {
void c_EmptyStruct_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::EmptyStruct_wrapper *>(cppObj);
}
void *c_EmptyStruct__constructor()
{
    auto ptr = new TestBindings_wrappersNS::EmptyStruct_wrapper();
    return reinterpret_cast<void *>(ptr);
}
void c_EmptyStruct__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
}

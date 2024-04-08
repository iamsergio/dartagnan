#include "SimpleStruct_c.h"


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
SimpleStruct_wrapper::SimpleStruct_wrapper()
    : ::SimpleStruct()
{
}
SimpleStruct_wrapper::~SimpleStruct_wrapper()
{
}

}
static SimpleStruct *fromPtr(void *ptr)
{
    return reinterpret_cast<SimpleStruct *>(ptr);
}
static TestBindings_wrappersNS::SimpleStruct_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::SimpleStruct_wrapper *>(ptr);
}
extern "C" {
void c_SimpleStruct_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::SimpleStruct_wrapper *>(cppObj);
}
void *c_SimpleStruct__constructor()
{
    auto ptr = new TestBindings_wrappersNS::SimpleStruct_wrapper();
    return reinterpret_cast<void *>(ptr);
}
void c_SimpleStruct__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
int c_SimpleStruct___get_value(void *thisObj)
{
    return fromPtr(thisObj)->value;
}
void c_SimpleStruct___set_value_int(void *thisObj, int value_)
{
    fromPtr(thisObj)->value = value_;
}
}

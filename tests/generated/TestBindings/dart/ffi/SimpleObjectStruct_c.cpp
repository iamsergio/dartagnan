#include "SimpleObjectStruct_c.h"


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
SimpleObjectStruct_wrapper::SimpleObjectStruct_wrapper()
    : ::SimpleObjectStruct()
{
}
void SimpleObjectStruct_wrapper::receivesStructWithDefaultArg(SimpleObjectStruct arg__1)
{
    ::SimpleObjectStruct::receivesStructWithDefaultArg(arg__1);
}
SimpleObjectStruct_wrapper::~SimpleObjectStruct_wrapper()
{
}

}
static SimpleObjectStruct *fromPtr(void *ptr)
{
    return reinterpret_cast<SimpleObjectStruct *>(ptr);
}
static TestBindings_wrappersNS::SimpleObjectStruct_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::SimpleObjectStruct_wrapper *>(ptr);
}
extern "C" {
void c_SimpleObjectStruct_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::SimpleObjectStruct_wrapper *>(cppObj);
}
void *c_SimpleObjectStruct__constructor()
{
    auto ptr = new TestBindings_wrappersNS::SimpleObjectStruct_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// receivesStructWithDefaultArg(SimpleObjectStruct arg__1)
void c_SimpleObjectStruct__receivesStructWithDefaultArg_SimpleObjectStruct(void *thisObj,
                                                                           void *arg__1_)
{
    assert(arg__1_);
    auto &arg__1 = *reinterpret_cast<SimpleObjectStruct *>(arg__1_);
    fromPtr(thisObj)->receivesStructWithDefaultArg(arg__1);
}
void c_SimpleObjectStruct__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
}

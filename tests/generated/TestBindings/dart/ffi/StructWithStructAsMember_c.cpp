#include "StructWithStructAsMember_c.h"


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
StructWithStructAsMember_wrapper::StructWithStructAsMember_wrapper()
    : ::TestTargetNS::StructWithStructAsMember()
{
}
StructWithStructAsMember_wrapper::~StructWithStructAsMember_wrapper()
{
}

}
static TestTargetNS::StructWithStructAsMember *fromPtr(void *ptr)
{
    return reinterpret_cast<TestTargetNS::StructWithStructAsMember *>(ptr);
}
static TestBindings_wrappersNS::StructWithStructAsMember_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::StructWithStructAsMember_wrapper *>(ptr);
}
extern "C" {
void c_TestTargetNS__StructWithStructAsMember_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::StructWithStructAsMember_wrapper *>(cppObj);
}
void *c_TestTargetNS__StructWithStructAsMember__constructor()
{
    auto ptr = new TestBindings_wrappersNS::StructWithStructAsMember_wrapper();
    return reinterpret_cast<void *>(ptr);
}
void c_TestTargetNS__StructWithStructAsMember__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
}

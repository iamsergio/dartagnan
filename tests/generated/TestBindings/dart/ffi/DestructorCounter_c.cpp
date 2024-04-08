#include "DestructorCounter_c.h"


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
DestructorCounter_wrapper::DestructorCounter_wrapper()
    : ::TestTargetNS::DestructorCounter()
{
}
int DestructorCounter_wrapper::instanceCount()
{
    return ::TestTargetNS::DestructorCounter::instanceCount();
}
TestTargetNS::DestructorCounter *DestructorCounter_wrapper::newOnTheHeap()
{
    return ::TestTargetNS::DestructorCounter::newOnTheHeap();
}
TestTargetNS::DestructorCounter DestructorCounter_wrapper::newOnTheStack()
{
    return ::TestTargetNS::DestructorCounter::newOnTheStack();
}
DestructorCounter_wrapper::~DestructorCounter_wrapper()
{
}

}
static TestTargetNS::DestructorCounter *fromPtr(void *ptr)
{
    return reinterpret_cast<TestTargetNS::DestructorCounter *>(ptr);
}
static TestBindings_wrappersNS::DestructorCounter_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::DestructorCounter_wrapper *>(ptr);
}
extern "C" {
void c_TestTargetNS__DestructorCounter_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::DestructorCounter_wrapper *>(cppObj);
}
void *c_TestTargetNS__DestructorCounter__constructor()
{
    auto ptr = new TestBindings_wrappersNS::DestructorCounter_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// instanceCount()
int c_static_TestTargetNS__DestructorCounter__instanceCount()
{
    const auto &result = TestBindings_wrappersNS::DestructorCounter_wrapper::instanceCount();
    return result;
}
// newOnTheHeap()
void *c_static_TestTargetNS__DestructorCounter__newOnTheHeap()
{
    const auto &result = TestBindings_wrappersNS::DestructorCounter_wrapper::newOnTheHeap();
    return result;
}
// newOnTheStack()
void *c_static_TestTargetNS__DestructorCounter__newOnTheStack()
{
    const auto &result = new Dartagnan::ValueWrapper<TestTargetNS::DestructorCounter> {
        TestBindings_wrappersNS::DestructorCounter_wrapper::newOnTheStack()
    };
    return result;
}
void c_TestTargetNS__DestructorCounter__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
int c_static_TestTargetNS__DestructorCounter___get_s_instanceCount()
{
    return TestBindings_wrappersNS::DestructorCounter_wrapper::s_instanceCount;
}
void c_static_TestTargetNS__DestructorCounter___set_s_instanceCount_int(int s_instanceCount_)
{
    TestBindings_wrappersNS::DestructorCounter_wrapper::s_instanceCount = s_instanceCount_;
}
}

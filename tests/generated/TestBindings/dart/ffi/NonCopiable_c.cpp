#include "NonCopiable_c.h"


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
NonCopiable_wrapper::NonCopiable_wrapper()
    : ::NonCopiable()
{
}
int NonCopiable_wrapper::count() const
{
    return ::NonCopiable::count();
}
NonCopiable_wrapper::~NonCopiable_wrapper()
{
}

}
static NonCopiable *fromPtr(void *ptr)
{
    return reinterpret_cast<NonCopiable *>(ptr);
}
static TestBindings_wrappersNS::NonCopiable_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::NonCopiable_wrapper *>(ptr);
}
extern "C" {
void c_NonCopiable_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::NonCopiable_wrapper *>(cppObj);
}
void *c_NonCopiable__constructor()
{
    auto ptr = new TestBindings_wrappersNS::NonCopiable_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// count() const
int c_NonCopiable__count(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->count();
    return result;
}
void c_NonCopiable__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
}

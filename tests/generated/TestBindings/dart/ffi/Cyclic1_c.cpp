#include "Cyclic1_c.h"


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
Cyclic1_wrapper::Cyclic1_wrapper(Cyclic2 *arg__1)
    : ::Cyclic1(arg__1)
{
}
Cyclic2 *Cyclic1_wrapper::getCyclic2() const
{
    return ::Cyclic1::getCyclic2();
}
Cyclic1_wrapper::~Cyclic1_wrapper()
{
}

}
static Cyclic1 *fromPtr(void *ptr)
{
    return reinterpret_cast<Cyclic1 *>(ptr);
}
static TestBindings_wrappersNS::Cyclic1_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::Cyclic1_wrapper *>(ptr);
}
extern "C" {
void c_Cyclic1_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::Cyclic1_wrapper *>(cppObj);
}
void *c_Cyclic1__constructor_Cyclic2(void *arg__1_)
{
    auto arg__1 = reinterpret_cast<Cyclic2 *>(arg__1_);
    auto ptr = new TestBindings_wrappersNS::Cyclic1_wrapper(arg__1);
    return reinterpret_cast<void *>(ptr);
}
// getCyclic2() const
void *c_Cyclic1__getCyclic2(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->getCyclic2();
    return result;
}
void c_Cyclic1__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
}

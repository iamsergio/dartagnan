#include "Cyclic2_c.h"


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
Cyclic1 *Cyclic2_wrapper::getCyclic1() const
{
    return ::Cyclic2::getCyclic1();
}
Cyclic2_wrapper::~Cyclic2_wrapper()
{
}

}
static Cyclic2 *fromPtr(void *ptr)
{
    return reinterpret_cast<Cyclic2 *>(ptr);
}
static TestBindings_wrappersNS::Cyclic2_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::Cyclic2_wrapper *>(ptr);
}
extern "C" {
void c_Cyclic2_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::Cyclic2_wrapper *>(cppObj);
} // getCyclic1() const
void *c_Cyclic2__getCyclic1(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->getCyclic1();
    return result;
}
void c_Cyclic2__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
}

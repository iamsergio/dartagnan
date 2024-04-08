#include "PureAbstractWithUnknownType_c.h"


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
int PureAbstractWithUnknownType_wrapper::getValue() const
{
    return ::PureAbstractWithUnknownType::getValue();
}
PureAbstractWithUnknownType_wrapper::~PureAbstractWithUnknownType_wrapper()
{
}

}
static PureAbstractWithUnknownType *fromPtr(void *ptr)
{
    return reinterpret_cast<PureAbstractWithUnknownType *>(ptr);
}
static TestBindings_wrappersNS::PureAbstractWithUnknownType_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::PureAbstractWithUnknownType_wrapper *>(ptr);
}
extern "C" {
void c_PureAbstractWithUnknownType_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::PureAbstractWithUnknownType_wrapper *>(cppObj);
} // getValue() const
int c_PureAbstractWithUnknownType__getValue(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->getValue();
    return result;
}
void c_PureAbstractWithUnknownType__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
}

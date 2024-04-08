#include "UnusedTemplate_c.h"


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
template<typename T>
UnusedTemplate_wrapper<T>::UnusedTemplate_wrapper()
    : ::UnusedTemplate<T>()
{
}
template<typename T>
UnusedTemplate_wrapper<T>::~UnusedTemplate_wrapper()
{
}

}
template<typename T>
static UnusedTemplate<T> *fromPtr(void *ptr)
{
    return reinterpret_cast<UnusedTemplate<T> *>(ptr);
}
template<typename T>
static TestBindings_wrappersNS::UnusedTemplate_wrapper<T> *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::UnusedTemplate_wrapper<T> *>(ptr);
}
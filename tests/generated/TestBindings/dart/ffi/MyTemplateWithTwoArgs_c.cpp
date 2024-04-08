#include "MyTemplateWithTwoArgs_c.h"


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
template<typename T0, typename T1>
MyTemplateWithTwoArgs_wrapper<T0, T1>::MyTemplateWithTwoArgs_wrapper()
    : ::MyTemplateWithTwoArgs<T0, T1>()
{
}
template<typename T0, typename T1>
int MyTemplateWithTwoArgs_wrapper<T0, T1>::returnInt() const
{
    return ::MyTemplateWithTwoArgs<T0, T1>::returnInt();
}
template<typename T0, typename T1>
MyTemplateWithTwoArgs_wrapper<T0, T1>::~MyTemplateWithTwoArgs_wrapper()
{
}

}
template<typename T0, typename T1>
static MyTemplateWithTwoArgs<T0, T1> *fromPtr(void *ptr)
{
    return reinterpret_cast<MyTemplateWithTwoArgs<T0, T1> *>(ptr);
}
template<typename T0, typename T1>
static TestBindings_wrappersNS::MyTemplateWithTwoArgs_wrapper<T0, T1> *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::MyTemplateWithTwoArgs_wrapper<T0, T1> *>(ptr);
}
extern "C" {
void c_MyTemplateWithTwoArgs_T_int_double_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::MyTemplateWithTwoArgs_wrapper<int, double> *>(
        cppObj);
}
void *c_MyTemplateWithTwoArgs_T_int_double_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::MyTemplateWithTwoArgs_wrapper<int, double>();
    return reinterpret_cast<void *>(ptr);
}
// returnInt() const
int c_MyTemplateWithTwoArgs_T_int_double_T___returnInt(void *thisObj)
{
    const auto &result = fromPtr<int, double>(thisObj)->returnInt();
    return result;
}
void c_MyTemplateWithTwoArgs_T_int_double_T___destructor(void *thisObj)
{
    delete fromPtr<int, double>(thisObj);
}
}

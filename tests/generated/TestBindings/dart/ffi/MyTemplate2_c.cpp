#include "MyTemplate2_c.h"


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
MyTemplate2_wrapper<T>::MyTemplate2_wrapper()
    : ::MyTemplate2<T>()
{
}
template<typename T>
void MyTemplate2_wrapper<T>::assignsT()
{
    ::MyTemplate2<T>::assignsT();
}
template<typename T>
int MyTemplate2_wrapper<T>::count() const
{
    return ::MyTemplate2<T>::count();
}
template<typename T>
void MyTemplate2_wrapper<T>::receivesT(T arg__1)
{
    ::MyTemplate2<T>::receivesT(arg__1);
}
template<typename T>
MyTemplate2<NonCopiable *> MyTemplate2_wrapper<T>::returnTemplate1()
{
    return ::MyTemplate2<T>::returnTemplate1();
}
template<typename T>
MyTemplate2_wrapper<T>::~MyTemplate2_wrapper()
{
}

}
template<typename T>
static MyTemplate2<T> *fromPtr(void *ptr)
{
    return reinterpret_cast<MyTemplate2<T> *>(ptr);
}
template<typename T>
static TestBindings_wrappersNS::MyTemplate2_wrapper<T> *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::MyTemplate2_wrapper<T> *>(ptr);
}
extern "C" {
void c_MyTemplate2_T_NonCopiable_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::MyTemplate2_wrapper<NonCopiable *> *>(cppObj);
}
void *c_MyTemplate2_T_NonCopiable_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::MyTemplate2_wrapper<NonCopiable *>();
    return reinterpret_cast<void *>(ptr);
}
// assignsT()
void c_MyTemplate2_T_NonCopiable_T___assignsT(void *thisObj)
{
    fromPtr<NonCopiable *>(thisObj)->assignsT();
}
// count() const
int c_MyTemplate2_T_NonCopiable_T___count(void *thisObj)
{
    const auto &result = fromPtr<NonCopiable *>(thisObj)->count();
    return result;
}
// receivesT(T arg__1)
void c_MyTemplate2_T_NonCopiable_T___receivesT_NonCopiable(void *thisObj, void *arg__1_)
{
    auto arg__1 = reinterpret_cast<NonCopiable *>(arg__1_);
    fromPtr<NonCopiable *>(thisObj)->receivesT(arg__1);
}
// returnTemplate1()
void *c_MyTemplate2_T_NonCopiable_T___returnTemplate1(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate2<NonCopiable *>> {
        fromPtr<NonCopiable *>(thisObj)->returnTemplate1()
    };
    return result;
}
void c_MyTemplate2_T_NonCopiable_T___destructor(void *thisObj)
{
    delete fromPtr<NonCopiable *>(thisObj);
}
}

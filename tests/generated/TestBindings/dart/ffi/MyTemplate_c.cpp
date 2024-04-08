#include "MyTemplate_c.h"


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
MyTemplate_wrapper<T>::MyTemplate_wrapper()
    : ::MyTemplate<T>()
{
}
template<typename T>
int MyTemplate_wrapper<T>::receivesT(T arg__1)
{
    return ::MyTemplate<T>::receivesT(arg__1);
}
template<typename T>
int MyTemplate_wrapper<T>::receivesTemplate(MyTemplate<T> arg__1)
{
    return ::MyTemplate<T>::receivesTemplate(arg__1);
}
template<typename T>
int MyTemplate_wrapper<T>::returnInt() const
{
    return ::MyTemplate<T>::returnInt();
}
template<typename T>
MyTemplate<EmptyStruct> MyTemplate_wrapper<T>::returnTemplate2()
{
    return ::MyTemplate<T>::returnTemplate2();
}
template<typename T>
MyTemplate<EmptyStruct *> MyTemplate_wrapper<T>::returnTemplate3()
{
    return ::MyTemplate<T>::returnTemplate3();
}
template<typename T>
MyTemplate<const EmptyStruct *> MyTemplate_wrapper<T>::returnTemplate4()
{
    return ::MyTemplate<T>::returnTemplate4();
}
template<typename T>
T MyTemplate_wrapper<T>::returnsT()
{
    return ::MyTemplate<T>::returnsT();
}
template<typename T>
MyTemplate<T> MyTemplate_wrapper<T>::returnsTemplate()
{
    return ::MyTemplate<T>::returnsTemplate();
}
template<typename T>
MyTemplate_wrapper<T>::~MyTemplate_wrapper()
{
}

}
template<typename T>
static MyTemplate<T> *fromPtr(void *ptr)
{
    return reinterpret_cast<MyTemplate<T> *>(ptr);
}
template<typename T>
static TestBindings_wrappersNS::MyTemplate_wrapper<T> *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::MyTemplate_wrapper<T> *>(ptr);
}
extern "C" {
void c_MyTemplate_T_int_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::MyTemplate_wrapper<int> *>(cppObj);
}
void *c_MyTemplate_T_int_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::MyTemplate_wrapper<int>();
    return reinterpret_cast<void *>(ptr);
}
// receivesT(T arg__1)
int c_MyTemplate_T_int_T___receivesT_int(void *thisObj, int arg__1)
{
    const auto &result = fromPtr<int>(thisObj)->receivesT(arg__1);
    return result;
}
// receivesTemplate(MyTemplate<T > arg__1)
int c_MyTemplate_T_int_T___receivesTemplate_MyTemplate_T(void *thisObj, void *arg__1_)
{
    assert(arg__1_);
    auto &arg__1 = *reinterpret_cast<MyTemplate<int> *>(arg__1_);
    const auto &result = fromPtr<int>(thisObj)->receivesTemplate(arg__1);
    return result;
}
// returnInt() const
int c_MyTemplate_T_int_T___returnInt(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->returnInt();
    return result;
}
// returnTemplate2()
void *c_MyTemplate_T_int_T___returnTemplate2(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<EmptyStruct>> {
        fromPtr<int>(thisObj)->returnTemplate2()
    };
    return result;
}
// returnTemplate3()
void *c_MyTemplate_T_int_T___returnTemplate3(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<EmptyStruct *>> {
        fromPtr<int>(thisObj)->returnTemplate3()
    };
    return result;
}
// returnTemplate4()
void *c_MyTemplate_T_int_T___returnTemplate4(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<const EmptyStruct *>> {
        fromPtr<int>(thisObj)->returnTemplate4()
    };
    return result;
}
// returnsT()
int c_MyTemplate_T_int_T___returnsT(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->returnsT();
    return result;
}
// returnsTemplate()
void *c_MyTemplate_T_int_T___returnsTemplate(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<MyTemplate<int>> { fromPtr<int>(thisObj)->returnsTemplate() };
    return result;
}
void c_MyTemplate_T_int_T___destructor(void *thisObj)
{
    delete fromPtr<int>(thisObj);
}
}
extern "C" {
void c_MyTemplate_T_double_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::MyTemplate_wrapper<double> *>(cppObj);
}
void *c_MyTemplate_T_double_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::MyTemplate_wrapper<double>();
    return reinterpret_cast<void *>(ptr);
}
// receivesT(T arg__1)
int c_MyTemplate_T_double_T___receivesT_double(void *thisObj, double arg__1)
{
    const auto &result = fromPtr<double>(thisObj)->receivesT(arg__1);
    return result;
}
// receivesTemplate(MyTemplate<T > arg__1)
int c_MyTemplate_T_double_T___receivesTemplate_MyTemplate_T(void *thisObj, void *arg__1_)
{
    assert(arg__1_);
    auto &arg__1 = *reinterpret_cast<MyTemplate<double> *>(arg__1_);
    const auto &result = fromPtr<double>(thisObj)->receivesTemplate(arg__1);
    return result;
}
// returnInt() const
int c_MyTemplate_T_double_T___returnInt(void *thisObj)
{
    const auto &result = fromPtr<double>(thisObj)->returnInt();
    return result;
}
// returnTemplate2()
void *c_MyTemplate_T_double_T___returnTemplate2(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<EmptyStruct>> {
        fromPtr<double>(thisObj)->returnTemplate2()
    };
    return result;
}
// returnTemplate3()
void *c_MyTemplate_T_double_T___returnTemplate3(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<EmptyStruct *>> {
        fromPtr<double>(thisObj)->returnTemplate3()
    };
    return result;
}
// returnTemplate4()
void *c_MyTemplate_T_double_T___returnTemplate4(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<const EmptyStruct *>> {
        fromPtr<double>(thisObj)->returnTemplate4()
    };
    return result;
}
// returnsT()
double c_MyTemplate_T_double_T___returnsT(void *thisObj)
{
    const auto &result = fromPtr<double>(thisObj)->returnsT();
    return result;
}
// returnsTemplate()
void *c_MyTemplate_T_double_T___returnsTemplate(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<double>> {
        fromPtr<double>(thisObj)->returnsTemplate()
    };
    return result;
}
void c_MyTemplate_T_double_T___destructor(void *thisObj)
{
    delete fromPtr<double>(thisObj);
}
}
extern "C" {
void c_MyTemplate_T_EmptyStruct_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::MyTemplate_wrapper<EmptyStruct> *>(cppObj);
}
void *c_MyTemplate_T_EmptyStruct_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::MyTemplate_wrapper<EmptyStruct>();
    return reinterpret_cast<void *>(ptr);
}
// receivesT(T arg__1)
int c_MyTemplate_T_EmptyStruct_T___receivesT_EmptyStruct(void *thisObj, void *arg__1_)
{
    assert(arg__1_);
    auto &arg__1 = *reinterpret_cast<EmptyStruct *>(arg__1_);
    const auto &result = fromPtr<EmptyStruct>(thisObj)->receivesT(arg__1);
    return result;
}
// receivesTemplate(MyTemplate<T > arg__1)
int c_MyTemplate_T_EmptyStruct_T___receivesTemplate_MyTemplate_T(void *thisObj, void *arg__1_)
{
    assert(arg__1_);
    auto &arg__1 = *reinterpret_cast<MyTemplate<EmptyStruct> *>(arg__1_);
    const auto &result = fromPtr<EmptyStruct>(thisObj)->receivesTemplate(arg__1);
    return result;
}
// returnInt() const
int c_MyTemplate_T_EmptyStruct_T___returnInt(void *thisObj)
{
    const auto &result = fromPtr<EmptyStruct>(thisObj)->returnInt();
    return result;
}
// returnTemplate2()
void *c_MyTemplate_T_EmptyStruct_T___returnTemplate2(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<EmptyStruct>> {
        fromPtr<EmptyStruct>(thisObj)->returnTemplate2()
    };
    return result;
}
// returnTemplate3()
void *c_MyTemplate_T_EmptyStruct_T___returnTemplate3(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<EmptyStruct *>> {
        fromPtr<EmptyStruct>(thisObj)->returnTemplate3()
    };
    return result;
}
// returnTemplate4()
void *c_MyTemplate_T_EmptyStruct_T___returnTemplate4(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<const EmptyStruct *>> {
        fromPtr<EmptyStruct>(thisObj)->returnTemplate4()
    };
    return result;
}
// returnsT()
void *c_MyTemplate_T_EmptyStruct_T___returnsT(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<EmptyStruct> { fromPtr<EmptyStruct>(thisObj)->returnsT() };
    return result;
}
// returnsTemplate()
void *c_MyTemplate_T_EmptyStruct_T___returnsTemplate(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<MyTemplate<EmptyStruct>> {
        fromPtr<EmptyStruct>(thisObj)->returnsTemplate()
    };
    return result;
}
void c_MyTemplate_T_EmptyStruct_T___destructor(void *thisObj)
{
    delete fromPtr<EmptyStruct>(thisObj);
}
}

#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
template<typename T>
class MyTemplate_wrapper : public ::MyTemplate<T>
{
public:
    ~MyTemplate_wrapper();
    MyTemplate_wrapper();
    int receivesT(T arg__1);
    int receivesTemplate(MyTemplate<T> arg__1);
    int returnInt() const;
    MyTemplate<EmptyStruct> returnTemplate2();
    MyTemplate<EmptyStruct *> returnTemplate3();
    MyTemplate<const EmptyStruct *> returnTemplate4();
    T returnsT();
    MyTemplate<T> returnsTemplate();
};
}
extern "C" {
// MyTemplate::MyTemplate<T>()
TestBindings_EXPORT void *c_MyTemplate_T_int_T___constructor();
// MyTemplate::receivesT(T arg__1)
TestBindings_EXPORT int c_MyTemplate_T_int_T___receivesT_int(void *thisObj, int arg__1);
// MyTemplate::receivesTemplate(MyTemplate<T > arg__1)
TestBindings_EXPORT int c_MyTemplate_T_int_T___receivesTemplate_MyTemplate_T(void *thisObj,
                                                                             void *arg__1_);
// MyTemplate::returnInt() const
TestBindings_EXPORT int c_MyTemplate_T_int_T___returnInt(void *thisObj);
// MyTemplate::returnTemplate2()
TestBindings_EXPORT void *c_MyTemplate_T_int_T___returnTemplate2(void *thisObj);
// MyTemplate::returnTemplate3()
TestBindings_EXPORT void *c_MyTemplate_T_int_T___returnTemplate3(void *thisObj);
// MyTemplate::returnTemplate4()
TestBindings_EXPORT void *c_MyTemplate_T_int_T___returnTemplate4(void *thisObj);
// MyTemplate::returnsT()
TestBindings_EXPORT int c_MyTemplate_T_int_T___returnsT(void *thisObj);
// MyTemplate::returnsTemplate()
TestBindings_EXPORT void *c_MyTemplate_T_int_T___returnsTemplate(void *thisObj);
TestBindings_EXPORT void c_MyTemplate_T_int_T___destructor(void *thisObj);
TestBindings_EXPORT void c_MyTemplate_T_int_T__Finalizer(void *cppObj);
}
extern "C" {
// MyTemplate::MyTemplate<T>()
TestBindings_EXPORT void *c_MyTemplate_T_double_T___constructor();
// MyTemplate::receivesT(T arg__1)
TestBindings_EXPORT int c_MyTemplate_T_double_T___receivesT_double(void *thisObj, double arg__1);
// MyTemplate::receivesTemplate(MyTemplate<T > arg__1)
TestBindings_EXPORT int c_MyTemplate_T_double_T___receivesTemplate_MyTemplate_T(void *thisObj,
                                                                                void *arg__1_);
// MyTemplate::returnInt() const
TestBindings_EXPORT int c_MyTemplate_T_double_T___returnInt(void *thisObj);
// MyTemplate::returnTemplate2()
TestBindings_EXPORT void *c_MyTemplate_T_double_T___returnTemplate2(void *thisObj);
// MyTemplate::returnTemplate3()
TestBindings_EXPORT void *c_MyTemplate_T_double_T___returnTemplate3(void *thisObj);
// MyTemplate::returnTemplate4()
TestBindings_EXPORT void *c_MyTemplate_T_double_T___returnTemplate4(void *thisObj);
// MyTemplate::returnsT()
TestBindings_EXPORT double c_MyTemplate_T_double_T___returnsT(void *thisObj);
// MyTemplate::returnsTemplate()
TestBindings_EXPORT void *c_MyTemplate_T_double_T___returnsTemplate(void *thisObj);
TestBindings_EXPORT void c_MyTemplate_T_double_T___destructor(void *thisObj);
TestBindings_EXPORT void c_MyTemplate_T_double_T__Finalizer(void *cppObj);
}
extern "C" {
// MyTemplate::MyTemplate<T>()
TestBindings_EXPORT void *c_MyTemplate_T_EmptyStruct_T___constructor();
// MyTemplate::receivesT(T arg__1)
TestBindings_EXPORT int c_MyTemplate_T_EmptyStruct_T___receivesT_EmptyStruct(void *thisObj,
                                                                             void *arg__1_);
// MyTemplate::receivesTemplate(MyTemplate<T > arg__1)
TestBindings_EXPORT int c_MyTemplate_T_EmptyStruct_T___receivesTemplate_MyTemplate_T(void *thisObj,
                                                                                     void *arg__1_);
// MyTemplate::returnInt() const
TestBindings_EXPORT int c_MyTemplate_T_EmptyStruct_T___returnInt(void *thisObj);
// MyTemplate::returnTemplate2()
TestBindings_EXPORT void *c_MyTemplate_T_EmptyStruct_T___returnTemplate2(void *thisObj);
// MyTemplate::returnTemplate3()
TestBindings_EXPORT void *c_MyTemplate_T_EmptyStruct_T___returnTemplate3(void *thisObj);
// MyTemplate::returnTemplate4()
TestBindings_EXPORT void *c_MyTemplate_T_EmptyStruct_T___returnTemplate4(void *thisObj);
// MyTemplate::returnsT()
TestBindings_EXPORT void *c_MyTemplate_T_EmptyStruct_T___returnsT(void *thisObj);
// MyTemplate::returnsTemplate()
TestBindings_EXPORT void *c_MyTemplate_T_EmptyStruct_T___returnsTemplate(void *thisObj);
TestBindings_EXPORT void c_MyTemplate_T_EmptyStruct_T___destructor(void *thisObj);
TestBindings_EXPORT void c_MyTemplate_T_EmptyStruct_T__Finalizer(void *cppObj);
}

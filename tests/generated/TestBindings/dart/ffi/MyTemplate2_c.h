#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
template<typename T>
class MyTemplate2_wrapper : public ::MyTemplate2<T>
{
public:
    ~MyTemplate2_wrapper();
    MyTemplate2_wrapper();
    void assignsT();
    int count() const;
    void receivesT(T arg__1);
    MyTemplate2<NonCopiable *> returnTemplate1();
};
}
extern "C" {
// MyTemplate2::MyTemplate2()
TestBindings_EXPORT void *c_MyTemplate2_T_NonCopiable_T___constructor();
// MyTemplate2::assignsT()
TestBindings_EXPORT void c_MyTemplate2_T_NonCopiable_T___assignsT(void *thisObj);
// MyTemplate2::count() const
TestBindings_EXPORT int c_MyTemplate2_T_NonCopiable_T___count(void *thisObj);
// MyTemplate2::receivesT(T arg__1)
TestBindings_EXPORT void c_MyTemplate2_T_NonCopiable_T___receivesT_NonCopiable(void *thisObj,
                                                                               void *arg__1_);
// MyTemplate2::returnTemplate1()
TestBindings_EXPORT void *c_MyTemplate2_T_NonCopiable_T___returnTemplate1(void *thisObj);
TestBindings_EXPORT void c_MyTemplate2_T_NonCopiable_T___destructor(void *thisObj);
TestBindings_EXPORT void c_MyTemplate2_T_NonCopiable_T__Finalizer(void *cppObj);
}

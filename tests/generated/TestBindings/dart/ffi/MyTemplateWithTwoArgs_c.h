#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
template<typename T0, typename T1>
class MyTemplateWithTwoArgs_wrapper : public ::MyTemplateWithTwoArgs<T0, T1>
{
public:
    ~MyTemplateWithTwoArgs_wrapper();
    MyTemplateWithTwoArgs_wrapper();
    int returnInt() const;
};
}
extern "C" {
// MyTemplateWithTwoArgs::MyTemplateWithTwoArgs<T0, T1>()
TestBindings_EXPORT void *c_MyTemplateWithTwoArgs_T_int_double_T___constructor();
// MyTemplateWithTwoArgs::returnInt() const
TestBindings_EXPORT int c_MyTemplateWithTwoArgs_T_int_double_T___returnInt(void *thisObj);
TestBindings_EXPORT void c_MyTemplateWithTwoArgs_T_int_double_T___destructor(void *thisObj);
TestBindings_EXPORT void c_MyTemplateWithTwoArgs_T_int_double_T__Finalizer(void *cppObj);
}

#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class SimpleStruct_wrapper : public ::SimpleStruct
{
public:
    ~SimpleStruct_wrapper();
    SimpleStruct_wrapper();
};
}
extern "C" {
// SimpleStruct::SimpleStruct()
TestBindings_EXPORT void *c_SimpleStruct__constructor();
TestBindings_EXPORT void c_SimpleStruct__destructor(void *thisObj);
TestBindings_EXPORT int c_SimpleStruct___get_value(void *thisObj);
TestBindings_EXPORT void c_SimpleStruct___set_value_int(void *thisObj, int value_);
TestBindings_EXPORT void c_SimpleStruct_Finalizer(void *cppObj);
}

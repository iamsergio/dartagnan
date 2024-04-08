#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class SimpleObjectStruct_wrapper : public ::SimpleObjectStruct
{
public:
    ~SimpleObjectStruct_wrapper();
    SimpleObjectStruct_wrapper();
    void receivesStructWithDefaultArg(SimpleObjectStruct arg__1 = {});
};
}
extern "C" {
// SimpleObjectStruct::SimpleObjectStruct()
TestBindings_EXPORT void *c_SimpleObjectStruct__constructor();
// SimpleObjectStruct::receivesStructWithDefaultArg(SimpleObjectStruct arg__1)
TestBindings_EXPORT void
c_SimpleObjectStruct__receivesStructWithDefaultArg_SimpleObjectStruct(void *thisObj, void *arg__1_);
TestBindings_EXPORT void c_SimpleObjectStruct__destructor(void *thisObj);
TestBindings_EXPORT void c_SimpleObjectStruct_Finalizer(void *cppObj);
}

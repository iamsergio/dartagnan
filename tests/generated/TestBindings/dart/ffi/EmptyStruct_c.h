#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class EmptyStruct_wrapper : public ::EmptyStruct
{
public:
    ~EmptyStruct_wrapper();
    EmptyStruct_wrapper();
};
}
extern "C" {
// EmptyStruct::EmptyStruct()
TestBindings_EXPORT void *c_EmptyStruct__constructor();
TestBindings_EXPORT void c_EmptyStruct__destructor(void *thisObj);
TestBindings_EXPORT void c_EmptyStruct_Finalizer(void *cppObj);
}

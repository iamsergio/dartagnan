#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class StructWithStructAsMember_wrapper : public ::TestTargetNS::StructWithStructAsMember
{
public:
    ~StructWithStructAsMember_wrapper();
    StructWithStructAsMember_wrapper();
};
}
extern "C" {
// TestTargetNS::StructWithStructAsMember::StructWithStructAsMember()
TestBindings_EXPORT void *c_TestTargetNS__StructWithStructAsMember__constructor();
TestBindings_EXPORT void c_TestTargetNS__StructWithStructAsMember__destructor(void *thisObj);
TestBindings_EXPORT void c_TestTargetNS__StructWithStructAsMember_Finalizer(void *cppObj);
}

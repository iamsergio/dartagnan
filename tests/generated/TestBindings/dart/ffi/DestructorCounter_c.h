#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class DestructorCounter_wrapper : public ::TestTargetNS::DestructorCounter
{
public:
    ~DestructorCounter_wrapper();
    DestructorCounter_wrapper();
    static int instanceCount();
    static TestTargetNS::DestructorCounter *newOnTheHeap();
    static TestTargetNS::DestructorCounter newOnTheStack();
};
}
extern "C" {
// TestTargetNS::DestructorCounter::DestructorCounter()
TestBindings_EXPORT void *c_TestTargetNS__DestructorCounter__constructor();
// TestTargetNS::DestructorCounter::instanceCount()
TestBindings_EXPORT int c_static_TestTargetNS__DestructorCounter__instanceCount();
// TestTargetNS::DestructorCounter::newOnTheHeap()
TestBindings_EXPORT void *c_static_TestTargetNS__DestructorCounter__newOnTheHeap();
// TestTargetNS::DestructorCounter::newOnTheStack()
TestBindings_EXPORT void *c_static_TestTargetNS__DestructorCounter__newOnTheStack();
TestBindings_EXPORT void c_TestTargetNS__DestructorCounter__destructor(void *thisObj);
TestBindings_EXPORT int c_static_TestTargetNS__DestructorCounter___get_s_instanceCount();
TestBindings_EXPORT void
c_static_TestTargetNS__DestructorCounter___set_s_instanceCount_int(int s_instanceCount_);
TestBindings_EXPORT void c_TestTargetNS__DestructorCounter_Finalizer(void *cppObj);
}

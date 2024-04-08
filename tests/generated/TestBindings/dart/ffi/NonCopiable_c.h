#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class NonCopiable_wrapper : public ::NonCopiable
{
public:
    ~NonCopiable_wrapper();
    NonCopiable_wrapper();
    int count() const;
};
}
extern "C" {
// NonCopiable::NonCopiable()
TestBindings_EXPORT void *c_NonCopiable__constructor();
// NonCopiable::count() const
TestBindings_EXPORT int c_NonCopiable__count(void *thisObj);
TestBindings_EXPORT void c_NonCopiable__destructor(void *thisObj);
TestBindings_EXPORT void c_NonCopiable_Finalizer(void *cppObj);
}

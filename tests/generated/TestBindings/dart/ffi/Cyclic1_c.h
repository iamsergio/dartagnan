#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class Cyclic1_wrapper : public ::Cyclic1
{
public:
    ~Cyclic1_wrapper();
    Cyclic1_wrapper(Cyclic2 *arg__1);
    Cyclic2 *getCyclic2() const;
};
}
extern "C" {
// Cyclic1::Cyclic1(Cyclic2 * arg__1)
TestBindings_EXPORT void *c_Cyclic1__constructor_Cyclic2(void *arg__1_);
// Cyclic1::getCyclic2() const
TestBindings_EXPORT void *c_Cyclic1__getCyclic2(void *thisObj);
TestBindings_EXPORT void c_Cyclic1__destructor(void *thisObj);
TestBindings_EXPORT void c_Cyclic1_Finalizer(void *cppObj);
}

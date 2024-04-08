#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class Cyclic2_wrapper : public ::Cyclic2
{
public:
    ~Cyclic2_wrapper();
    Cyclic1 *getCyclic1() const;
};
}
extern "C" {
// Cyclic2::getCyclic1() const
TestBindings_EXPORT void *c_Cyclic2__getCyclic1(void *thisObj);
TestBindings_EXPORT void c_Cyclic2__destructor(void *thisObj);
TestBindings_EXPORT void c_Cyclic2_Finalizer(void *cppObj);
}

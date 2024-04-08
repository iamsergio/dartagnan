#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class PureAbstractWithUnknownType_wrapper : public ::PureAbstractWithUnknownType
{
public:
    ~PureAbstractWithUnknownType_wrapper();
    int getValue() const;
};
}
extern "C" {
// PureAbstractWithUnknownType::getValue() const
TestBindings_EXPORT int c_PureAbstractWithUnknownType__getValue(void *thisObj);
TestBindings_EXPORT void c_PureAbstractWithUnknownType__destructor(void *thisObj);
TestBindings_EXPORT void c_PureAbstractWithUnknownType_Finalizer(void *cppObj);
}

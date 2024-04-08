#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
template<typename T>
class UnusedTemplate_wrapper : public ::UnusedTemplate<T>
{
public:
    ~UnusedTemplate_wrapper();
    UnusedTemplate_wrapper();
};
}
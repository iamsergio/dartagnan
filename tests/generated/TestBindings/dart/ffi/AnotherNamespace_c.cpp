#include "AnotherNamespace_c.h"


#include <iostream>

#include <cassert>


namespace Dartagnan {

typedef int (*CleanupCallback)(void *thisPtr);
static CleanupCallback s_cleanupCallback = nullptr;

template<typename T>
struct ValueWrapper
{
    T value;
};

}
extern "C" {
// size(QString s)
void *c_static_AnotherNamespace__size_QString(const char *s_)
{
    const auto s = QString::fromUtf8(s_);
    const auto &result = new Dartagnan::ValueWrapper<QString> { AnotherNamespace::size(s) };
    free(( char * )s_);
    return result;
}
}

#include "QSet_c.h"


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
namespace TestBindings_wrappersNS {
template<typename T>
QSet_wrapper<T>::QSet_wrapper()
    : ::QSet<T>()
{
}
template<typename T>
qsizetype QSet_wrapper<T>::capacity() const
{
    return ::QSet<T>::capacity();
}
template<typename T>
void QSet_wrapper<T>::clear()
{
    ::QSet<T>::clear();
}
template<typename T>
bool QSet_wrapper<T>::contains(const QSet<T> &set) const
{
    return ::QSet<T>::contains(set);
}
template<typename T>
qsizetype QSet_wrapper<T>::count() const
{
    return ::QSet<T>::count();
}
template<typename T>
void QSet_wrapper<T>::detach()
{
    ::QSet<T>::detach();
}
template<typename T>
bool QSet_wrapper<T>::empty() const
{
    return ::QSet<T>::empty();
}
template<typename T>
QSet<T> &QSet_wrapper<T>::intersect(const QSet<T> &other)
{
    return ::QSet<T>::intersect(other);
}
template<typename T>
bool QSet_wrapper<T>::intersects(const QSet<T> &other) const
{
    return ::QSet<T>::intersects(other);
}
template<typename T>
bool QSet_wrapper<T>::isDetached() const
{
    return ::QSet<T>::isDetached();
}
template<typename T>
bool QSet_wrapper<T>::isEmpty() const
{
    return ::QSet<T>::isEmpty();
}
template<typename T>
void QSet_wrapper<T>::reserve(qsizetype size)
{
    ::QSet<T>::reserve(size);
}
template<typename T>
qsizetype QSet_wrapper<T>::size() const
{
    return ::QSet<T>::size();
}
template<typename T>
void QSet_wrapper<T>::squeeze()
{
    ::QSet<T>::squeeze();
}
template<typename T>
QSet<T> &QSet_wrapper<T>::subtract(const QSet<T> &other)
{
    return ::QSet<T>::subtract(other);
}
template<typename T>
QSet<T> &QSet_wrapper<T>::unite(const QSet<T> &other)
{
    return ::QSet<T>::unite(other);
}
template<typename T>
QList<T> QSet_wrapper<T>::values() const
{
    return ::QSet<T>::values();
}
template<typename T>
QSet_wrapper<T>::~QSet_wrapper()
{
}

}
template<typename T>
static QSet<T> *fromPtr(void *ptr)
{
    return reinterpret_cast<QSet<T> *>(ptr);
}
template<typename T>
static TestBindings_wrappersNS::QSet_wrapper<T> *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::QSet_wrapper<T> *>(ptr);
}
#include "QMap_c.h"


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
template<typename Key, typename T>
QMap_wrapper<Key, T>::QMap_wrapper()
    : ::QMap<Key, T>()
{
}
template<typename Key, typename T>
void QMap_wrapper<Key, T>::clear()
{
    ::QMap<Key, T>::clear();
}
template<typename Key, typename T>
bool QMap_wrapper<Key, T>::contains(const Key &key) const
{
    return ::QMap<Key, T>::contains(key);
}
template<typename Key, typename T>
void QMap_wrapper<Key, T>::detach()
{
    ::QMap<Key, T>::detach();
}
template<typename Key, typename T>
bool QMap_wrapper<Key, T>::empty() const
{
    return ::QMap<Key, T>::empty();
}
template<typename Key, typename T>
T &QMap_wrapper<Key, T>::first()
{
    return ::QMap<Key, T>::first();
}
template<typename Key, typename T>
const Key &QMap_wrapper<Key, T>::firstKey() const
{
    return ::QMap<Key, T>::firstKey();
}
template<typename Key, typename T>
void QMap_wrapper<Key, T>::insert(const QMap<Key, T> &map)
{
    ::QMap<Key, T>::insert(map);
}
template<typename Key, typename T>
bool QMap_wrapper<Key, T>::isDetached() const
{
    return ::QMap<Key, T>::isDetached();
}
template<typename Key, typename T>
bool QMap_wrapper<Key, T>::isEmpty() const
{
    return ::QMap<Key, T>::isEmpty();
}
template<typename Key, typename T>
bool QMap_wrapper<Key, T>::isSharedWith(const QMap<Key, T> &other) const
{
    return ::QMap<Key, T>::isSharedWith(other);
}
template<typename Key, typename T>
Key QMap_wrapper<Key, T>::key(const T &value, const Key &defaultKey) const
{
    return ::QMap<Key, T>::key(value, defaultKey);
}
template<typename Key, typename T>
QList<Key> QMap_wrapper<Key, T>::keys() const
{
    return ::QMap<Key, T>::keys();
}
template<typename Key, typename T>
QList<Key> QMap_wrapper<Key, T>::keys(const T &value) const
{
    return ::QMap<Key, T>::keys(value);
}
template<typename Key, typename T>
T &QMap_wrapper<Key, T>::last()
{
    return ::QMap<Key, T>::last();
}
template<typename Key, typename T>
const Key &QMap_wrapper<Key, T>::lastKey() const
{
    return ::QMap<Key, T>::lastKey();
}
template<typename Key, typename T>
T QMap_wrapper<Key, T>::take(const Key &key)
{
    return ::QMap<Key, T>::take(key);
}
template<typename Key, typename T>
T QMap_wrapper<Key, T>::value(const Key &key, const T &defaultValue) const
{
    return ::QMap<Key, T>::value(key, defaultValue);
}
template<typename Key, typename T>
QList<T> QMap_wrapper<Key, T>::values() const
{
    return ::QMap<Key, T>::values();
}
template<typename Key, typename T>
QMap_wrapper<Key, T>::~QMap_wrapper()
{
}

}
template<typename Key, typename T>
static QMap<Key, T> *fromPtr(void *ptr)
{
    return reinterpret_cast<QMap<Key, T> *>(ptr);
}
template<typename Key, typename T>
static TestBindings_wrappersNS::QMap_wrapper<Key, T> *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::QMap_wrapper<Key, T> *>(ptr);
}
extern "C" {
void c_QMap_T_QString_QVariant_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::QMap_wrapper<QString, QVariant> *>(cppObj);
}
void *c_QMap_T_QString_QVariant_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::QMap_wrapper<QString, QVariant>();
    return reinterpret_cast<void *>(ptr);
}
// clear()
void c_QMap_T_QString_QVariant_T___clear(void *thisObj)
{
    fromPtr<QString, QVariant>(thisObj)->clear();
}
// contains(const Key & key) const
bool c_QMap_T_QString_QVariant_T___contains_QString(void *thisObj, const char *key_)
{
    const auto key = QString::fromUtf8(key_);
    const auto &result = fromPtr<QString, QVariant>(thisObj)->contains(key);
    free(( char * )key_);
    return result;
}
// detach()
void c_QMap_T_QString_QVariant_T___detach(void *thisObj)
{
    fromPtr<QString, QVariant>(thisObj)->detach();
}
// empty() const
bool c_QMap_T_QString_QVariant_T___empty(void *thisObj)
{
    const auto &result = fromPtr<QString, QVariant>(thisObj)->empty();
    return result;
}
// first()
void *c_QMap_T_QString_QVariant_T___first(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QString, QVariant>(thisObj)->first() };
    return result;
}
// firstKey() const
const void *c_QMap_T_QString_QVariant_T___firstKey(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QString> { fromPtr<QString, QVariant>(thisObj)->firstKey() };
    return result;
}
// insert(const QMap<Key,T > & map)
void c_QMap_T_QString_QVariant_T___insert_QMap_Key_T(void *thisObj, void *map_)
{
    assert(map_);
    auto &map = *reinterpret_cast<QMap<QString, QVariant> *>(map_);
    fromPtr<QString, QVariant>(thisObj)->insert(map);
}
// isDetached() const
bool c_QMap_T_QString_QVariant_T___isDetached(void *thisObj)
{
    const auto &result = fromPtr<QString, QVariant>(thisObj)->isDetached();
    return result;
}
// isEmpty() const
bool c_QMap_T_QString_QVariant_T___isEmpty(void *thisObj)
{
    const auto &result = fromPtr<QString, QVariant>(thisObj)->isEmpty();
    return result;
}
// isSharedWith(const QMap<Key,T > & other) const
bool c_QMap_T_QString_QVariant_T___isSharedWith_QMap_Key_T(void *thisObj, void *other_)
{
    assert(other_);
    auto &other = *reinterpret_cast<QMap<QString, QVariant> *>(other_);
    const auto &result = fromPtr<QString, QVariant>(thisObj)->isSharedWith(other);
    return result;
}
// key(const T & value, const Key & defaultKey) const
void *c_QMap_T_QString_QVariant_T___key_QVariant_QString(void *thisObj, void *value_,
                                                         const char *defaultKey_)
{
    assert(value_);
    auto &value = *reinterpret_cast<QVariant *>(value_);
    const auto defaultKey = QString::fromUtf8(defaultKey_);
    const auto &result = new Dartagnan::ValueWrapper<QString> {
        fromPtr<QString, QVariant>(thisObj)->key(value, defaultKey)
    };
    free(( char * )defaultKey_);
    return result;
}
// keys() const
void *c_QMap_T_QString_QVariant_T___keys(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QString>> { fromPtr<QString, QVariant>(thisObj)->keys() };
    return result;
}
// keys(const T & value) const
void *c_QMap_T_QString_QVariant_T___keys_QVariant(void *thisObj, void *value_)
{
    assert(value_);
    auto &value = *reinterpret_cast<QVariant *>(value_);
    const auto &result = new Dartagnan::ValueWrapper<QList<QString>> {
        fromPtr<QString, QVariant>(thisObj)->keys(value)
    };
    return result;
}
// last()
void *c_QMap_T_QString_QVariant_T___last(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QString, QVariant>(thisObj)->last() };
    return result;
}
// lastKey() const
const void *c_QMap_T_QString_QVariant_T___lastKey(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QString> { fromPtr<QString, QVariant>(thisObj)->lastKey() };
    return result;
}
// take(const Key & key)
void *c_QMap_T_QString_QVariant_T___take_QString(void *thisObj, const char *key_)
{
    const auto key = QString::fromUtf8(key_);
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QString, QVariant>(thisObj)->take(key) };
    free(( char * )key_);
    return result;
}
// value(const Key & key, const T & defaultValue) const
void *c_QMap_T_QString_QVariant_T___value_QString_QVariant(void *thisObj, const char *key_,
                                                           void *defaultValue_)
{
    const auto key = QString::fromUtf8(key_);
    assert(defaultValue_);
    auto &defaultValue = *reinterpret_cast<QVariant *>(defaultValue_);
    const auto &result = new Dartagnan::ValueWrapper<QVariant> {
        fromPtr<QString, QVariant>(thisObj)->value(key, defaultValue)
    };
    free(( char * )key_);
    return result;
}
// values() const
void *c_QMap_T_QString_QVariant_T___values(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<QVariant>> {
        fromPtr<QString, QVariant>(thisObj)->values()
    };
    return result;
}
void c_QMap_T_QString_QVariant_T___destructor(void *thisObj)
{
    delete fromPtr<QString, QVariant>(thisObj);
}
}

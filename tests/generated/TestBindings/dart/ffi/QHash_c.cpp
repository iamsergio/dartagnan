#include "QHash_c.h"


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
QHash_wrapper<Key, T>::QHash_wrapper()
    : ::QHash<Key, T>()
{
}
template<typename Key, typename T>
qsizetype QHash_wrapper<Key, T>::capacity() const
{
    return ::QHash<Key, T>::capacity();
}
template<typename Key, typename T>
void QHash_wrapper<Key, T>::clear()
{
    ::QHash<Key, T>::clear();
}
template<typename Key, typename T>
bool QHash_wrapper<Key, T>::contains(const Key &key) const
{
    return ::QHash<Key, T>::contains(key);
}
template<typename Key, typename T>
qsizetype QHash_wrapper<Key, T>::count() const
{
    return ::QHash<Key, T>::count();
}
template<typename Key, typename T>
qsizetype QHash_wrapper<Key, T>::count(const Key &key) const
{
    return ::QHash<Key, T>::count(key);
}
template<typename Key, typename T>
void QHash_wrapper<Key, T>::detach()
{
    ::QHash<Key, T>::detach();
}
template<typename Key, typename T>
bool QHash_wrapper<Key, T>::empty() const
{
    return ::QHash<Key, T>::empty();
}
template<typename Key, typename T>
void QHash_wrapper<Key, T>::insert(const QHash<Key, T> &hash)
{
    ::QHash<Key, T>::insert(hash);
}
template<typename Key, typename T>
bool QHash_wrapper<Key, T>::isDetached() const
{
    return ::QHash<Key, T>::isDetached();
}
template<typename Key, typename T>
bool QHash_wrapper<Key, T>::isEmpty() const
{
    return ::QHash<Key, T>::isEmpty();
}
template<typename Key, typename T>
bool QHash_wrapper<Key, T>::isSharedWith(const QHash<Key, T> &other) const
{
    return ::QHash<Key, T>::isSharedWith(other);
}
template<typename Key, typename T>
Key QHash_wrapper<Key, T>::key(const T &value) const
{
    return ::QHash<Key, T>::key(value);
}
template<typename Key, typename T>
Key QHash_wrapper<Key, T>::key(const T &value, const Key &defaultKey) const
{
    return ::QHash<Key, T>::key(value, defaultKey);
}
template<typename Key, typename T>
QList<Key> QHash_wrapper<Key, T>::keys() const
{
    return ::QHash<Key, T>::keys();
}
template<typename Key, typename T>
QList<Key> QHash_wrapper<Key, T>::keys(const T &value) const
{
    return ::QHash<Key, T>::keys(value);
}
template<typename Key, typename T>
float QHash_wrapper<Key, T>::load_factor() const
{
    return ::QHash<Key, T>::load_factor();
}
template<typename Key, typename T>
bool QHash_wrapper<Key, T>::remove(const Key &key)
{
    return ::QHash<Key, T>::remove(key);
}
template<typename Key, typename T>
void QHash_wrapper<Key, T>::reserve(qsizetype size)
{
    ::QHash<Key, T>::reserve(size);
}
template<typename Key, typename T>
qsizetype QHash_wrapper<Key, T>::size() const
{
    return ::QHash<Key, T>::size();
}
template<typename Key, typename T>
void QHash_wrapper<Key, T>::squeeze()
{
    ::QHash<Key, T>::squeeze();
}
template<typename Key, typename T>
T QHash_wrapper<Key, T>::take(const Key &key)
{
    return ::QHash<Key, T>::take(key);
}
template<typename Key, typename T>
T QHash_wrapper<Key, T>::value(const Key &key) const
{
    return ::QHash<Key, T>::value(key);
}
template<typename Key, typename T>
T QHash_wrapper<Key, T>::value(const Key &key, const T &defaultValue) const
{
    return ::QHash<Key, T>::value(key, defaultValue);
}
template<typename Key, typename T>
QList<T> QHash_wrapper<Key, T>::values() const
{
    return ::QHash<Key, T>::values();
}
template<typename Key, typename T>
QHash_wrapper<Key, T>::~QHash_wrapper()
{
}

}
template<typename Key, typename T>
static QHash<Key, T> *fromPtr(void *ptr)
{
    return reinterpret_cast<QHash<Key, T> *>(ptr);
}
template<typename Key, typename T>
static TestBindings_wrappersNS::QHash_wrapper<Key, T> *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::QHash_wrapper<Key, T> *>(ptr);
}
extern "C" {
void c_QHash_T_QString_QVariant_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::QHash_wrapper<QString, QVariant> *>(cppObj);
}
void *c_QHash_T_QString_QVariant_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::QHash_wrapper<QString, QVariant>();
    return reinterpret_cast<void *>(ptr);
}
// capacity() const
qsizetype c_QHash_T_QString_QVariant_T___capacity(void *thisObj)
{
    const auto &result = fromPtr<QString, QVariant>(thisObj)->capacity();
    return result;
}
// clear()
void c_QHash_T_QString_QVariant_T___clear(void *thisObj)
{
    fromPtr<QString, QVariant>(thisObj)->clear();
}
// contains(const Key & key) const
bool c_QHash_T_QString_QVariant_T___contains_QString(void *thisObj, const char *key_)
{
    const auto key = QString::fromUtf8(key_);
    const auto &result = fromPtr<QString, QVariant>(thisObj)->contains(key);
    free(( char * )key_);
    return result;
}
// count() const
qsizetype c_QHash_T_QString_QVariant_T___count(void *thisObj)
{
    const auto &result = fromPtr<QString, QVariant>(thisObj)->count();
    return result;
}
// count(const Key & key) const
qsizetype c_QHash_T_QString_QVariant_T___count_QString(void *thisObj, const char *key_)
{
    const auto key = QString::fromUtf8(key_);
    const auto &result = fromPtr<QString, QVariant>(thisObj)->count(key);
    free(( char * )key_);
    return result;
}
// detach()
void c_QHash_T_QString_QVariant_T___detach(void *thisObj)
{
    fromPtr<QString, QVariant>(thisObj)->detach();
}
// empty() const
bool c_QHash_T_QString_QVariant_T___empty(void *thisObj)
{
    const auto &result = fromPtr<QString, QVariant>(thisObj)->empty();
    return result;
}
// insert(const QHash<Key,T > & hash)
void c_QHash_T_QString_QVariant_T___insert_QHash_Key_T(void *thisObj, void *hash_)
{
    assert(hash_);
    auto &hash = *reinterpret_cast<QHash<QString, QVariant> *>(hash_);
    fromPtr<QString, QVariant>(thisObj)->insert(hash);
}
// isDetached() const
bool c_QHash_T_QString_QVariant_T___isDetached(void *thisObj)
{
    const auto &result = fromPtr<QString, QVariant>(thisObj)->isDetached();
    return result;
}
// isEmpty() const
bool c_QHash_T_QString_QVariant_T___isEmpty(void *thisObj)
{
    const auto &result = fromPtr<QString, QVariant>(thisObj)->isEmpty();
    return result;
}
// isSharedWith(const QHash<Key,T > & other) const
bool c_QHash_T_QString_QVariant_T___isSharedWith_QHash_Key_T(void *thisObj, void *other_)
{
    assert(other_);
    auto &other = *reinterpret_cast<QHash<QString, QVariant> *>(other_);
    const auto &result = fromPtr<QString, QVariant>(thisObj)->isSharedWith(other);
    return result;
}
// key(const T & value) const
void *c_QHash_T_QString_QVariant_T___key_QVariant(void *thisObj, void *value_)
{
    assert(value_);
    auto &value = *reinterpret_cast<QVariant *>(value_);
    const auto &result =
        new Dartagnan::ValueWrapper<QString> { fromPtr<QString, QVariant>(thisObj)->key(value) };
    return result;
}
// key(const T & value, const Key & defaultKey) const
void *c_QHash_T_QString_QVariant_T___key_QVariant_QString(void *thisObj, void *value_,
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
void *c_QHash_T_QString_QVariant_T___keys(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QString>> { fromPtr<QString, QVariant>(thisObj)->keys() };
    return result;
}
// keys(const T & value) const
void *c_QHash_T_QString_QVariant_T___keys_QVariant(void *thisObj, void *value_)
{
    assert(value_);
    auto &value = *reinterpret_cast<QVariant *>(value_);
    const auto &result = new Dartagnan::ValueWrapper<QList<QString>> {
        fromPtr<QString, QVariant>(thisObj)->keys(value)
    };
    return result;
}
// load_factor() const
float c_QHash_T_QString_QVariant_T___load_factor(void *thisObj)
{
    const auto &result = fromPtr<QString, QVariant>(thisObj)->load_factor();
    return result;
}
// remove(const Key & key)
bool c_QHash_T_QString_QVariant_T___remove_QString(void *thisObj, const char *key_)
{
    const auto key = QString::fromUtf8(key_);
    const auto &result = fromPtr<QString, QVariant>(thisObj)->remove(key);
    free(( char * )key_);
    return result;
}
// reserve(qsizetype size)
void c_QHash_T_QString_QVariant_T___reserve_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<QString, QVariant>(thisObj)->reserve(size);
}
// size() const
qsizetype c_QHash_T_QString_QVariant_T___size(void *thisObj)
{
    const auto &result = fromPtr<QString, QVariant>(thisObj)->size();
    return result;
}
// squeeze()
void c_QHash_T_QString_QVariant_T___squeeze(void *thisObj)
{
    fromPtr<QString, QVariant>(thisObj)->squeeze();
}
// take(const Key & key)
void *c_QHash_T_QString_QVariant_T___take_QString(void *thisObj, const char *key_)
{
    const auto key = QString::fromUtf8(key_);
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QString, QVariant>(thisObj)->take(key) };
    free(( char * )key_);
    return result;
}
// value(const Key & key) const
void *c_QHash_T_QString_QVariant_T___value_QString(void *thisObj, const char *key_)
{
    const auto key = QString::fromUtf8(key_);
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QString, QVariant>(thisObj)->value(key) };
    free(( char * )key_);
    return result;
}
// value(const Key & key, const T & defaultValue) const
void *c_QHash_T_QString_QVariant_T___value_QString_QVariant(void *thisObj, const char *key_,
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
void *c_QHash_T_QString_QVariant_T___values(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<QVariant>> {
        fromPtr<QString, QVariant>(thisObj)->values()
    };
    return result;
}
void c_QHash_T_QString_QVariant_T___destructor(void *thisObj)
{
    delete fromPtr<QString, QVariant>(thisObj);
}
}

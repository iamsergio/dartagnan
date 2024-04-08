#include "TestBindings_exports.h"
#include <qbytearray.h>
#include <qhash.h>
#include <qlist.h>
#include <qmap.h>
#include <qobject.h>
#include <qstring.h>
#include <qvariant.h>

namespace TestBindings_wrappersNS {
template<typename Key, typename T>
class QHash_wrapper : public ::QHash<Key, T>
{
public:
    ~QHash_wrapper();
    QHash_wrapper();
    qsizetype capacity() const;
    void clear();
    bool contains(const Key &key) const;
    qsizetype count() const;
    qsizetype count(const Key &key) const;
    void detach();
    bool empty() const;
    void insert(const QHash<Key, T> &hash);
    bool isDetached() const;
    bool isEmpty() const;
    bool isSharedWith(const QHash<Key, T> &other) const;
    Key key(const T &value) const;
    Key key(const T &value, const Key &defaultKey) const;
    QList<Key> keys() const;
    QList<Key> keys(const T &value) const;
    float load_factor() const;
    bool remove(const Key &key);
    void reserve(qsizetype size);
    qsizetype size() const;
    void squeeze();
    T take(const Key &key);
    T value(const Key &key) const;
    T value(const Key &key, const T &defaultValue) const;
    QList<T> values() const;
};
}
extern "C" {
// QHash::QHash<Key, T>()
TestBindings_EXPORT void *c_QHash_T_QString_QVariant_T___constructor();
// QHash::capacity() const
TestBindings_EXPORT qsizetype c_QHash_T_QString_QVariant_T___capacity(void *thisObj);
// QHash::clear()
TestBindings_EXPORT void c_QHash_T_QString_QVariant_T___clear(void *thisObj);
// QHash::contains(const Key & key) const
TestBindings_EXPORT bool c_QHash_T_QString_QVariant_T___contains_QString(void *thisObj,
                                                                         const char *key_);
// QHash::count() const
TestBindings_EXPORT qsizetype c_QHash_T_QString_QVariant_T___count(void *thisObj);
// QHash::count(const Key & key) const
TestBindings_EXPORT qsizetype c_QHash_T_QString_QVariant_T___count_QString(void *thisObj,
                                                                           const char *key_);
// QHash::detach()
TestBindings_EXPORT void c_QHash_T_QString_QVariant_T___detach(void *thisObj);
// QHash::empty() const
TestBindings_EXPORT bool c_QHash_T_QString_QVariant_T___empty(void *thisObj);
// QHash::insert(const QHash<Key,T > & hash)
TestBindings_EXPORT void c_QHash_T_QString_QVariant_T___insert_QHash_Key_T(void *thisObj,
                                                                           void *hash_);
// QHash::isDetached() const
TestBindings_EXPORT bool c_QHash_T_QString_QVariant_T___isDetached(void *thisObj);
// QHash::isEmpty() const
TestBindings_EXPORT bool c_QHash_T_QString_QVariant_T___isEmpty(void *thisObj);
// QHash::isSharedWith(const QHash<Key,T > & other) const
TestBindings_EXPORT bool c_QHash_T_QString_QVariant_T___isSharedWith_QHash_Key_T(void *thisObj,
                                                                                 void *other_);
// QHash::key(const T & value) const
TestBindings_EXPORT void *c_QHash_T_QString_QVariant_T___key_QVariant(void *thisObj, void *value_);
// QHash::key(const T & value, const Key & defaultKey) const
TestBindings_EXPORT void *
c_QHash_T_QString_QVariant_T___key_QVariant_QString(void *thisObj, void *value_,
                                                    const char *defaultKey_);
// QHash::keys() const
TestBindings_EXPORT void *c_QHash_T_QString_QVariant_T___keys(void *thisObj);
// QHash::keys(const T & value) const
TestBindings_EXPORT void *c_QHash_T_QString_QVariant_T___keys_QVariant(void *thisObj, void *value_);
// QHash::load_factor() const
TestBindings_EXPORT float c_QHash_T_QString_QVariant_T___load_factor(void *thisObj);
// QHash::remove(const Key & key)
TestBindings_EXPORT bool c_QHash_T_QString_QVariant_T___remove_QString(void *thisObj,
                                                                       const char *key_);
// QHash::reserve(qsizetype size)
TestBindings_EXPORT void c_QHash_T_QString_QVariant_T___reserve_qsizetype(void *thisObj,
                                                                          qsizetype size);
// QHash::size() const
TestBindings_EXPORT qsizetype c_QHash_T_QString_QVariant_T___size(void *thisObj);
// QHash::squeeze()
TestBindings_EXPORT void c_QHash_T_QString_QVariant_T___squeeze(void *thisObj);
// QHash::take(const Key & key)
TestBindings_EXPORT void *c_QHash_T_QString_QVariant_T___take_QString(void *thisObj,
                                                                      const char *key_);
// QHash::value(const Key & key) const
TestBindings_EXPORT void *c_QHash_T_QString_QVariant_T___value_QString(void *thisObj,
                                                                       const char *key_);
// QHash::value(const Key & key, const T & defaultValue) const
TestBindings_EXPORT void *
c_QHash_T_QString_QVariant_T___value_QString_QVariant(void *thisObj, const char *key_,
                                                      void *defaultValue_);
// QHash::values() const
TestBindings_EXPORT void *c_QHash_T_QString_QVariant_T___values(void *thisObj);
TestBindings_EXPORT void c_QHash_T_QString_QVariant_T___destructor(void *thisObj);
TestBindings_EXPORT void c_QHash_T_QString_QVariant_T__Finalizer(void *cppObj);
}

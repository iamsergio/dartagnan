#include "TestBindings_exports.h"
#include <map>
#include <qbytearray.h>
#include <qhash.h>
#include <qlist.h>
#include <qmap.h>
#include <qobject.h>
#include <qstring.h>
#include <qvariant.h>

namespace TestBindings_wrappersNS {
template<typename Key, typename T>
class QMap_wrapper : public ::QMap<Key, T>
{
public:
    ~QMap_wrapper();
    QMap_wrapper();
    void clear();
    bool contains(const Key &key) const;
    void detach();
    bool empty() const;
    T &first();
    const Key &firstKey() const;
    void insert(const QMap<Key, T> &map);
    bool isDetached() const;
    bool isEmpty() const;
    bool isSharedWith(const QMap<Key, T> &other) const;
    Key key(const T &value, const Key &defaultKey = Key()) const;
    QList<Key> keys() const;
    QList<Key> keys(const T &value) const;
    T &last();
    const Key &lastKey() const;
    T take(const Key &key);
    T value(const Key &key, const T &defaultValue = T()) const;
    QList<T> values() const;
};
}
extern "C" {
// QMap::QMap<Key, T>()
TestBindings_EXPORT void *c_QMap_T_QString_QVariant_T___constructor();
// QMap::clear()
TestBindings_EXPORT void c_QMap_T_QString_QVariant_T___clear(void *thisObj);
// QMap::contains(const Key & key) const
TestBindings_EXPORT bool c_QMap_T_QString_QVariant_T___contains_QString(void *thisObj,
                                                                        const char *key_);
// QMap::detach()
TestBindings_EXPORT void c_QMap_T_QString_QVariant_T___detach(void *thisObj);
// QMap::empty() const
TestBindings_EXPORT bool c_QMap_T_QString_QVariant_T___empty(void *thisObj);
// QMap::first()
TestBindings_EXPORT void *c_QMap_T_QString_QVariant_T___first(void *thisObj);
// QMap::firstKey() const
TestBindings_EXPORT const void *c_QMap_T_QString_QVariant_T___firstKey(void *thisObj);
// QMap::insert(const QMap<Key,T > & map)
TestBindings_EXPORT void c_QMap_T_QString_QVariant_T___insert_QMap_Key_T(void *thisObj, void *map_);
// QMap::isDetached() const
TestBindings_EXPORT bool c_QMap_T_QString_QVariant_T___isDetached(void *thisObj);
// QMap::isEmpty() const
TestBindings_EXPORT bool c_QMap_T_QString_QVariant_T___isEmpty(void *thisObj);
// QMap::isSharedWith(const QMap<Key,T > & other) const
TestBindings_EXPORT bool c_QMap_T_QString_QVariant_T___isSharedWith_QMap_Key_T(void *thisObj,
                                                                               void *other_);
// QMap::key(const T & value, const Key & defaultKey) const
TestBindings_EXPORT void *
c_QMap_T_QString_QVariant_T___key_QVariant_QString(void *thisObj, void *value_,
                                                   const char *defaultKey_);
// QMap::keys() const
TestBindings_EXPORT void *c_QMap_T_QString_QVariant_T___keys(void *thisObj);
// QMap::keys(const T & value) const
TestBindings_EXPORT void *c_QMap_T_QString_QVariant_T___keys_QVariant(void *thisObj, void *value_);
// QMap::last()
TestBindings_EXPORT void *c_QMap_T_QString_QVariant_T___last(void *thisObj);
// QMap::lastKey() const
TestBindings_EXPORT const void *c_QMap_T_QString_QVariant_T___lastKey(void *thisObj);
// QMap::take(const Key & key)
TestBindings_EXPORT void *c_QMap_T_QString_QVariant_T___take_QString(void *thisObj,
                                                                     const char *key_);
// QMap::value(const Key & key, const T & defaultValue) const
TestBindings_EXPORT void *c_QMap_T_QString_QVariant_T___value_QString_QVariant(void *thisObj,
                                                                               const char *key_,
                                                                               void *defaultValue_);
// QMap::values() const
TestBindings_EXPORT void *c_QMap_T_QString_QVariant_T___values(void *thisObj);
TestBindings_EXPORT void c_QMap_T_QString_QVariant_T___destructor(void *thisObj);
TestBindings_EXPORT void c_QMap_T_QString_QVariant_T__Finalizer(void *cppObj);
}

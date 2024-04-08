#include "QVariant_c.h"


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
QVariant_wrapper::QVariant_wrapper()
    : ::QVariant()
{
}
QVariant_wrapper::QVariant_wrapper(bool b)
    : ::QVariant(b)
{
}
QVariant_wrapper::QVariant_wrapper(const QByteArray &bytearray)
    : ::QVariant(bytearray)
{
}
QVariant_wrapper::QVariant_wrapper(const QHash<QString, QVariant> &hash)
    : ::QVariant(hash)
{
}
QVariant_wrapper::QVariant_wrapper(const QList<QString> &stringlist)
    : ::QVariant(stringlist)
{
}
QVariant_wrapper::QVariant_wrapper(const QList<QVariant> &list)
    : ::QVariant(list)
{
}
QVariant_wrapper::QVariant_wrapper(const QMap<QString, QVariant> &map)
    : ::QVariant(map)
{
}
QVariant_wrapper::QVariant_wrapper(const QString &string)
    : ::QVariant(string)
{
}
QVariant_wrapper::QVariant_wrapper(const char *str)
    : ::QVariant(str)
{
}
QVariant_wrapper::QVariant_wrapper(double d)
    : ::QVariant(d)
{
}
QVariant_wrapper::QVariant_wrapper(float f)
    : ::QVariant(f)
{
}
QVariant_wrapper::QVariant_wrapper(int i)
    : ::QVariant(i)
{
}
QVariant_wrapper::QVariant_wrapper(qint64 ll)
    : ::QVariant(ll)
{
}
void QVariant_wrapper::clear()
{
    ::QVariant::clear();
}
void QVariant_wrapper::detach()
{
    ::QVariant::detach();
}
bool QVariant_wrapper::equals(const QVariant &other) const
{
    return ::QVariant::equals(other);
}

// ========================================================================
// START of custom code block [file: glue/qvariant.cpp (qvariant-fromObject)]

/** static*/
QVariant QVariant_wrapper::fromObject(QObject *obj)
{
    return QVariant::fromValue<QObject *>(obj);
}
// END of custom code block [file: glue/qvariant.cpp (qvariant-fromObject)]
// ========================================================================

bool QVariant_wrapper::isDetached() const
{
    return ::QVariant::isDetached();
}
bool QVariant_wrapper::isNull() const
{
    return ::QVariant::isNull();
}
bool QVariant_wrapper::isValid() const
{
    return ::QVariant::isValid();
}
void QVariant_wrapper::setValue(const QVariant &avalue)
{
    ::QVariant::setValue(avalue);
}
bool QVariant_wrapper::toBool() const
{
    return ::QVariant::toBool();
}
QByteArray QVariant_wrapper::toByteArray() const
{
    return ::QVariant::toByteArray();
}
QHash<QString, QVariant> QVariant_wrapper::toHash() const
{
    return ::QVariant::toHash();
}
QList<QVariant> QVariant_wrapper::toList() const
{
    return ::QVariant::toList();
}
QMap<QString, QVariant> QVariant_wrapper::toMap() const
{
    return ::QVariant::toMap();
}
QList<QString> QVariant_wrapper::toStringList() const
{
    return ::QVariant::toStringList();
}
int QVariant_wrapper::typeId() const
{
    return ::QVariant::typeId();
}
const char *QVariant_wrapper::typeName() const
{
    return ::QVariant::typeName();
}
int QVariant_wrapper::userType() const
{
    return ::QVariant::userType();
}
QVariant_wrapper::~QVariant_wrapper()
{
}

}
static QVariant *fromPtr(void *ptr)
{
    return reinterpret_cast<QVariant *>(ptr);
}
static TestBindings_wrappersNS::QVariant_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::QVariant_wrapper *>(ptr);
}
extern "C" {
void c_QVariant_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::QVariant_wrapper *>(cppObj);
}
void *c_QVariant__constructor()
{
    auto ptr = new TestBindings_wrappersNS::QVariant_wrapper();
    return reinterpret_cast<void *>(ptr);
}
void *c_QVariant__constructor_bool(bool b)
{
    auto ptr = new TestBindings_wrappersNS::QVariant_wrapper(b);
    return reinterpret_cast<void *>(ptr);
}
void *c_QVariant__constructor_QByteArray(void *bytearray_)
{
    assert(bytearray_);
    auto &bytearray = *reinterpret_cast<QByteArray *>(bytearray_);
    auto ptr = new TestBindings_wrappersNS::QVariant_wrapper(bytearray);
    return reinterpret_cast<void *>(ptr);
}
void *c_QVariant__constructor_QHash_QString_QVariant(void *hash_)
{
    assert(hash_);
    auto &hash = *reinterpret_cast<QHash<QString, QVariant> *>(hash_);
    auto ptr = new TestBindings_wrappersNS::QVariant_wrapper(hash);
    return reinterpret_cast<void *>(ptr);
}
void *c_QVariant__constructor_QList_QString(void *stringlist_)
{
    assert(stringlist_);
    auto &stringlist = *reinterpret_cast<QList<QString> *>(stringlist_);
    auto ptr = new TestBindings_wrappersNS::QVariant_wrapper(stringlist);
    return reinterpret_cast<void *>(ptr);
}
void *c_QVariant__constructor_QList_QVariant(void *list_)
{
    assert(list_);
    auto &list = *reinterpret_cast<QList<QVariant> *>(list_);
    auto ptr = new TestBindings_wrappersNS::QVariant_wrapper(list);
    return reinterpret_cast<void *>(ptr);
}
void *c_QVariant__constructor_QMap_QString_QVariant(void *map_)
{
    assert(map_);
    auto &map = *reinterpret_cast<QMap<QString, QVariant> *>(map_);
    auto ptr = new TestBindings_wrappersNS::QVariant_wrapper(map);
    return reinterpret_cast<void *>(ptr);
}
void *c_QVariant__constructor_QString(const char *string_)
{
    const auto string = QString::fromUtf8(string_);
    auto ptr = new TestBindings_wrappersNS::QVariant_wrapper(string);
    return reinterpret_cast<void *>(ptr);
}
void *c_QVariant__constructor_char(const char *str)
{
    auto ptr = new TestBindings_wrappersNS::QVariant_wrapper(str);
    return reinterpret_cast<void *>(ptr);
}
void *c_QVariant__constructor_double(double d)
{
    auto ptr = new TestBindings_wrappersNS::QVariant_wrapper(d);
    return reinterpret_cast<void *>(ptr);
}
void *c_QVariant__constructor_float(float f)
{
    auto ptr = new TestBindings_wrappersNS::QVariant_wrapper(f);
    return reinterpret_cast<void *>(ptr);
}
void *c_QVariant__constructor_int(int i)
{
    auto ptr = new TestBindings_wrappersNS::QVariant_wrapper(i);
    return reinterpret_cast<void *>(ptr);
}
void *c_QVariant__constructor_qint64(qint64 ll)
{
    auto ptr = new TestBindings_wrappersNS::QVariant_wrapper(ll);
    return reinterpret_cast<void *>(ptr);
}
// clear()
void c_QVariant__clear(void *thisObj)
{
    fromPtr(thisObj)->clear();
}
// detach()
void c_QVariant__detach(void *thisObj)
{
    fromPtr(thisObj)->detach();
}
// equals(const QVariant & other) const
bool c_QVariant__equals_QVariant(void *thisObj, void *other_)
{
    assert(other_);
    auto &other = *reinterpret_cast<QVariant *>(other_);
    const auto &result = fromWrapperPtr(thisObj)->equals(other);
    return result;
}
// fromObject(QObject * arg__1)
void *c_static_QVariant__fromObject_QObject(void *arg__1_)
{
    auto arg__1 = reinterpret_cast<QObject *>(arg__1_);
    const auto &result = new Dartagnan::ValueWrapper<QVariant> {
        TestBindings_wrappersNS::QVariant_wrapper::fromObject(arg__1)
    };
    return result;
}
// isDetached() const
bool c_QVariant__isDetached(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->isDetached();
    return result;
}
// isNull() const
bool c_QVariant__isNull(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->isNull();
    return result;
}
// isValid() const
bool c_QVariant__isValid(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->isValid();
    return result;
}
// setValue(const QVariant & avalue)
void c_QVariant__setValue_QVariant(void *thisObj, void *avalue_)
{
    assert(avalue_);
    auto &avalue = *reinterpret_cast<QVariant *>(avalue_);
    fromPtr(thisObj)->setValue(avalue);
}
// toBool() const
bool c_QVariant__toBool(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->toBool();
    return result;
}
// toByteArray() const
void *c_QVariant__toByteArray(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QByteArray> { fromPtr(thisObj)->toByteArray() };
    return result;
}
// toHash() const
void *c_QVariant__toHash(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QHash<QString, QVariant>> { fromPtr(thisObj)->toHash() };
    return result;
}
// toList() const
void *c_QVariant__toList(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QVariant>> { fromPtr(thisObj)->toList() };
    return result;
}
// toMap() const
void *c_QVariant__toMap(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QMap<QString, QVariant>> { fromPtr(thisObj)->toMap() };
    return result;
}
// toStringList() const
void *c_QVariant__toStringList(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QString>> { fromPtr(thisObj)->toStringList() };
    return result;
}
// typeId() const
int c_QVariant__typeId(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->typeId();
    return result;
}
// typeName() const
const char *c_QVariant__typeName(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->typeName();
    return result;
}
// userType() const
int c_QVariant__userType(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->userType();
    return result;
}
void c_QVariant__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
}

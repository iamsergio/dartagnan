#include "TestBindings_exports.h"
#include <qbytearray.h>
#include <qhash.h>
#include <qlist.h>
#include <qmap.h>
#include <qobject.h>
#include <qstring.h>
#include <qvariant.h>

namespace TestBindings_wrappersNS {
class QVariant_wrapper : public ::QVariant
{
public:
    ~QVariant_wrapper();
    QVariant_wrapper();
    QVariant_wrapper(bool b);
    QVariant_wrapper(const QByteArray &bytearray);
    QVariant_wrapper(const QHash<QString, QVariant> &hash);
    QVariant_wrapper(const QList<QString> &stringlist);
    QVariant_wrapper(const QList<QVariant> &list);
    QVariant_wrapper(const QMap<QString, QVariant> &map);
    QVariant_wrapper(const QString &string);
    QVariant_wrapper(const char *str);
    QVariant_wrapper(double d);
    QVariant_wrapper(float f);
    QVariant_wrapper(int i);
    QVariant_wrapper(qint64 ll);
    void clear();
    void detach();
    bool equals(const QVariant &other) const;
    static QVariant fromObject(QObject *arg__1);
    bool isDetached() const;
    bool isNull() const;
    bool isValid() const;
    void setValue(const QVariant &avalue);
    bool toBool() const;
    QByteArray toByteArray() const;
    QHash<QString, QVariant> toHash() const;
    QList<QVariant> toList() const;
    QMap<QString, QVariant> toMap() const;
    QList<QString> toStringList() const;
    int typeId() const;
    const char *typeName() const;
    int userType() const;
};
}
extern "C" {
// QVariant::QVariant()
TestBindings_EXPORT void *c_QVariant__constructor();
// QVariant::QVariant(bool b)
TestBindings_EXPORT void *c_QVariant__constructor_bool(bool b);
// QVariant::QVariant(const QByteArray & bytearray)
TestBindings_EXPORT void *c_QVariant__constructor_QByteArray(void *bytearray_);
// QVariant::QVariant(const QHash<QString,QVariant > & hash)
TestBindings_EXPORT void *c_QVariant__constructor_QHash_QString_QVariant(void *hash_);
// QVariant::QVariant(const QList<QString > & stringlist)
TestBindings_EXPORT void *c_QVariant__constructor_QList_QString(void *stringlist_);
// QVariant::QVariant(const QList<QVariant > & list)
TestBindings_EXPORT void *c_QVariant__constructor_QList_QVariant(void *list_);
// QVariant::QVariant(const QMap<QString,QVariant > & map)
TestBindings_EXPORT void *c_QVariant__constructor_QMap_QString_QVariant(void *map_);
// QVariant::QVariant(const QString & string)
TestBindings_EXPORT void *c_QVariant__constructor_QString(const char *string_);
// QVariant::QVariant(const char * str)
TestBindings_EXPORT void *c_QVariant__constructor_char(const char *str);
// QVariant::QVariant(double d)
TestBindings_EXPORT void *c_QVariant__constructor_double(double d);
// QVariant::QVariant(float f)
TestBindings_EXPORT void *c_QVariant__constructor_float(float f);
// QVariant::QVariant(int i)
TestBindings_EXPORT void *c_QVariant__constructor_int(int i);
// QVariant::QVariant(qint64 ll)
TestBindings_EXPORT void *c_QVariant__constructor_qint64(qint64 ll);
// QVariant::clear()
TestBindings_EXPORT void c_QVariant__clear(void *thisObj);
// QVariant::detach()
TestBindings_EXPORT void c_QVariant__detach(void *thisObj);
// QVariant::equals(const QVariant & other) const
TestBindings_EXPORT bool c_QVariant__equals_QVariant(void *thisObj, void *other_);
// QVariant::fromObject(QObject * arg__1)
TestBindings_EXPORT void *c_static_QVariant__fromObject_QObject(void *arg__1_);
// QVariant::isDetached() const
TestBindings_EXPORT bool c_QVariant__isDetached(void *thisObj);
// QVariant::isNull() const
TestBindings_EXPORT bool c_QVariant__isNull(void *thisObj);
// QVariant::isValid() const
TestBindings_EXPORT bool c_QVariant__isValid(void *thisObj);
// QVariant::setValue(const QVariant & avalue)
TestBindings_EXPORT void c_QVariant__setValue_QVariant(void *thisObj, void *avalue_);
// QVariant::toBool() const
TestBindings_EXPORT bool c_QVariant__toBool(void *thisObj);
// QVariant::toByteArray() const
TestBindings_EXPORT void *c_QVariant__toByteArray(void *thisObj);
// QVariant::toHash() const
TestBindings_EXPORT void *c_QVariant__toHash(void *thisObj);
// QVariant::toList() const
TestBindings_EXPORT void *c_QVariant__toList(void *thisObj);
// QVariant::toMap() const
TestBindings_EXPORT void *c_QVariant__toMap(void *thisObj);
// QVariant::toStringList() const
TestBindings_EXPORT void *c_QVariant__toStringList(void *thisObj);
// QVariant::typeId() const
TestBindings_EXPORT int c_QVariant__typeId(void *thisObj);
// QVariant::typeName() const
TestBindings_EXPORT const char *c_QVariant__typeName(void *thisObj);
// QVariant::userType() const
TestBindings_EXPORT int c_QVariant__userType(void *thisObj);
TestBindings_EXPORT void c_QVariant__destructor(void *thisObj);
TestBindings_EXPORT void c_QVariant_Finalizer(void *cppObj);
}

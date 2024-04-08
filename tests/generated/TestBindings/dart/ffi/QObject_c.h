#include "TestBindings_exports.h"
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qlist.h>
#include <qobject.h>
#include <qstring.h>
#include <qvariant.h>

namespace TestBindings_wrappersNS {
class QObject_wrapper : public ::QObject
{
public:
    ~QObject_wrapper();
    QObject_wrapper(QObject *parent = nullptr);
    bool blockSignals(bool b);
    const QList<QObject *> &children() const;
    virtual void customEvent(QEvent *event);
    virtual void customEvent_nocallback(QEvent *event);
    void deleteLater();
    void destroyed(QObject *arg__1 = nullptr);
    bool disconnect(const QObject *receiver, const char *member = nullptr) const;
    static bool disconnect(const QObject *sender, const char *signal, const QObject *receiver,
                           const char *member);
    bool disconnect(const char *signal = nullptr, const QObject *receiver = nullptr,
                    const char *member = nullptr) const;
    void dumpObjectInfo() const;
    void dumpObjectTree() const;
    QList<QByteArray> dynamicPropertyNames() const;
    virtual bool event(QEvent *event);
    virtual bool event_nocallback(QEvent *event);
    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual bool eventFilter_nocallback(QObject *watched, QEvent *event);
    bool inherits(const char *classname) const;
    void installEventFilter(QObject *filterObj);
    bool isWidgetType() const;
    bool isWindowType() const;
    void killTimer(int id);
    QString objectName() const;
    QObject *parent() const;
    QVariant property(const char *name) const;
    int receivers(const char *signal) const;
    void removeEventFilter(QObject *obj);
    QObject *sender() const;
    int senderSignalIndex() const;
    void setObjectName(const QString &name);
    void setParent(QObject *parent);
    bool setProperty(const char *name, const QVariant &value);
    bool signalsBlocked() const;
    int startTimer(int interval);
    static QString tr(const char *s, const char *c, int n);
    typedef void (*Callback_customEvent)(void *, QEvent *event);
    Callback_customEvent m_customEventCallback = nullptr;
    typedef bool (*Callback_event)(void *, QEvent *event);
    Callback_event m_eventCallback = nullptr;
    typedef bool (*Callback_eventFilter)(void *, QObject *watched, QEvent *event);
    Callback_eventFilter m_eventFilterCallback = nullptr;
};
}
extern "C" {
// QObject::QObject(QObject * parent)
TestBindings_EXPORT void *c_QObject__constructor_QObject(void *parent_);
// QObject::blockSignals(bool b)
TestBindings_EXPORT bool c_QObject__blockSignals_bool(void *thisObj, bool b);
// QObject::children() const
TestBindings_EXPORT void *c_QObject__children(void *thisObj);
// QObject::customEvent(QEvent * event)
TestBindings_EXPORT void c_QObject__customEvent_QEvent(void *thisObj, void *event_);
// QObject::deleteLater()
TestBindings_EXPORT void c_QObject__deleteLater(void *thisObj);
// QObject::destroyed(QObject * arg__1)
TestBindings_EXPORT void c_QObject__destroyed_QObject(void *thisObj, void *arg__1_);
TestBindings_EXPORT void
c_QObject__onDestroyed_QObject(void *thisObj, void *contextQObject,
                               void *callback); // QObject::disconnect(const QObject * receiver,
                                                // const char * member) const
TestBindings_EXPORT bool c_QObject__disconnect_QObject_char(void *thisObj, void *receiver_,
                                                            const char *member);
// QObject::disconnect(const QObject * sender, const char * signal, const QObject * receiver, const
// char * member)
TestBindings_EXPORT bool c_static_QObject__disconnect_QObject_char_QObject_char(void *sender_,
                                                                                const char *signal,
                                                                                void *receiver_,
                                                                                const char *member);
// QObject::disconnect(const char * signal, const QObject * receiver, const char * member) const
TestBindings_EXPORT bool c_QObject__disconnect_char_QObject_char(void *thisObj, const char *signal,
                                                                 void *receiver_,
                                                                 const char *member);
// QObject::dumpObjectInfo() const
TestBindings_EXPORT void c_QObject__dumpObjectInfo(void *thisObj);
// QObject::dumpObjectTree() const
TestBindings_EXPORT void c_QObject__dumpObjectTree(void *thisObj);
// QObject::dynamicPropertyNames() const
TestBindings_EXPORT void *c_QObject__dynamicPropertyNames(void *thisObj);
// QObject::event(QEvent * event)
TestBindings_EXPORT bool c_QObject__event_QEvent(void *thisObj, void *event_);
// QObject::eventFilter(QObject * watched, QEvent * event)
TestBindings_EXPORT bool c_QObject__eventFilter_QObject_QEvent(void *thisObj, void *watched_,
                                                               void *event_);
// QObject::inherits(const char * classname) const
TestBindings_EXPORT bool c_QObject__inherits_char(void *thisObj, const char *classname);
// QObject::installEventFilter(QObject * filterObj)
TestBindings_EXPORT void c_QObject__installEventFilter_QObject(void *thisObj, void *filterObj_);
// QObject::isWidgetType() const
TestBindings_EXPORT bool c_QObject__isWidgetType(void *thisObj);
// QObject::isWindowType() const
TestBindings_EXPORT bool c_QObject__isWindowType(void *thisObj);
// QObject::killTimer(int id)
TestBindings_EXPORT void c_QObject__killTimer_int(void *thisObj, int id);
// QObject::objectName() const
TestBindings_EXPORT void *c_QObject__objectName(void *thisObj);
// QObject::parent() const
TestBindings_EXPORT void *c_QObject__parent(void *thisObj);
// QObject::property(const char * name) const
TestBindings_EXPORT void *c_QObject__property_char(void *thisObj, const char *name);
// QObject::receivers(const char * signal) const
TestBindings_EXPORT int c_QObject__receivers_char(void *thisObj, const char *signal);
// QObject::removeEventFilter(QObject * obj)
TestBindings_EXPORT void c_QObject__removeEventFilter_QObject(void *thisObj, void *obj_);
// QObject::sender() const
TestBindings_EXPORT void *c_QObject__sender(void *thisObj);
// QObject::senderSignalIndex() const
TestBindings_EXPORT int c_QObject__senderSignalIndex(void *thisObj);
// QObject::setObjectName(const QString & name)
TestBindings_EXPORT void c_QObject__setObjectName_QString(void *thisObj, const char *name_);
// QObject::setParent(QObject * parent)
TestBindings_EXPORT void c_QObject__setParent_QObject(void *thisObj, void *parent_);
// QObject::setProperty(const char * name, const QVariant & value)
TestBindings_EXPORT bool c_QObject__setProperty_char_QVariant(void *thisObj, const char *name,
                                                              void *value_);
// QObject::signalsBlocked() const
TestBindings_EXPORT bool c_QObject__signalsBlocked(void *thisObj);
// QObject::startTimer(int interval)
TestBindings_EXPORT int c_QObject__startTimer_int(void *thisObj, int interval);
// QObject::tr(const char * s, const char * c, int n)
TestBindings_EXPORT void *c_static_QObject__tr_char_char_int(const char *s, const char *c, int n);
TestBindings_EXPORT void c_QObject__destructor(void *thisObj);
TestBindings_EXPORT void c_QObject__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                  int methodId);
TestBindings_EXPORT void c_QObject_Finalizer(void *cppObj);
}

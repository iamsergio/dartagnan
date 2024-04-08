#include "TestBindings_exports.h"
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qhash.h>
#include <qlist.h>
#include <qmap.h>
#include <qobject.h>
#include <qstring.h>
#include <qvariant.h>
#include <test.h>

namespace TestBindings_wrappersNS {
template<typename T>
class QList_wrapper : public ::QList<T>
{
public:
    ~QList_wrapper();
    QList_wrapper();
    QList_wrapper(qsizetype size);
    void append(const QList<T> &l);
    const T &at(qsizetype i) const;
    T &back();
    qsizetype capacity() const;
    void clear();
    const T &constFirst() const;
    const T &constLast() const;
    qsizetype count() const;
    void detach();
    bool empty() const;
    T &first();
    QList<T> first(qsizetype n) const;
    T &front();
    bool isDetached() const;
    bool isEmpty() const;
    bool isSharedWith(const QList<T> &other) const;
    T &last();
    QList<T> last(qsizetype n) const;
    qsizetype length() const;
    QList<T> mid(qsizetype pos, qsizetype len = -1) const;
    void move(qsizetype from, qsizetype to);
    void pop_back();
    void pop_front();
    void remove(qsizetype i, qsizetype n = 1);
    void removeAt(qsizetype i);
    void removeFirst();
    void removeLast();
    void reserve(qsizetype size);
    void resize(qsizetype size);
    void shrink_to_fit();
    qsizetype size() const;
    QList<T> sliced(qsizetype pos) const;
    QList<T> sliced(qsizetype pos, qsizetype n) const;
    void squeeze();
    void swapItemsAt(qsizetype i, qsizetype j);
    T takeAt(qsizetype i);
    QList<T> toList() const;
    QList<T> toVector() const;
    T value(qsizetype i) const;
};
}
extern "C" {
// QList::QList<T>()
TestBindings_EXPORT void *c_QList_T_SimpleStruct_T___constructor();
// QList::QList<T>(qsizetype size)
TestBindings_EXPORT void *c_QList_T_SimpleStruct_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
TestBindings_EXPORT void c_QList_T_SimpleStruct_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
TestBindings_EXPORT const void *c_QList_T_SimpleStruct_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
TestBindings_EXPORT void *c_QList_T_SimpleStruct_T___back(void *thisObj);
// QList::capacity() const
TestBindings_EXPORT qsizetype c_QList_T_SimpleStruct_T___capacity(void *thisObj);
// QList::clear()
TestBindings_EXPORT void c_QList_T_SimpleStruct_T___clear(void *thisObj);
// QList::constFirst() const
TestBindings_EXPORT const void *c_QList_T_SimpleStruct_T___constFirst(void *thisObj);
// QList::constLast() const
TestBindings_EXPORT const void *c_QList_T_SimpleStruct_T___constLast(void *thisObj);
// QList::count() const
TestBindings_EXPORT qsizetype c_QList_T_SimpleStruct_T___count(void *thisObj);
// QList::detach()
TestBindings_EXPORT void c_QList_T_SimpleStruct_T___detach(void *thisObj);
// QList::empty() const
TestBindings_EXPORT bool c_QList_T_SimpleStruct_T___empty(void *thisObj);
// QList::first()
TestBindings_EXPORT void *c_QList_T_SimpleStruct_T___first(void *thisObj);
// QList::first(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_SimpleStruct_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
TestBindings_EXPORT void *c_QList_T_SimpleStruct_T___front(void *thisObj);
// QList::isDetached() const
TestBindings_EXPORT bool c_QList_T_SimpleStruct_T___isDetached(void *thisObj);
// QList::isEmpty() const
TestBindings_EXPORT bool c_QList_T_SimpleStruct_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
TestBindings_EXPORT bool c_QList_T_SimpleStruct_T___isSharedWith_QList_T(void *thisObj,
                                                                         void *other_);
// QList::last()
TestBindings_EXPORT void *c_QList_T_SimpleStruct_T___last(void *thisObj);
// QList::last(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_SimpleStruct_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
TestBindings_EXPORT qsizetype c_QList_T_SimpleStruct_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
TestBindings_EXPORT void *
c_QList_T_SimpleStruct_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len);
// QList::move(qsizetype from, qsizetype to)
TestBindings_EXPORT void
c_QList_T_SimpleStruct_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to);
// QList::pop_back()
TestBindings_EXPORT void c_QList_T_SimpleStruct_T___pop_back(void *thisObj);
// QList::pop_front()
TestBindings_EXPORT void c_QList_T_SimpleStruct_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
TestBindings_EXPORT void
c_QList_T_SimpleStruct_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
TestBindings_EXPORT void c_QList_T_SimpleStruct_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
TestBindings_EXPORT void c_QList_T_SimpleStruct_T___removeFirst(void *thisObj);
// QList::removeLast()
TestBindings_EXPORT void c_QList_T_SimpleStruct_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
TestBindings_EXPORT void c_QList_T_SimpleStruct_T___reserve_qsizetype(void *thisObj,
                                                                      qsizetype size);
// QList::resize(qsizetype size)
TestBindings_EXPORT void c_QList_T_SimpleStruct_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
TestBindings_EXPORT void c_QList_T_SimpleStruct_T___shrink_to_fit(void *thisObj);
// QList::size() const
TestBindings_EXPORT qsizetype c_QList_T_SimpleStruct_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
TestBindings_EXPORT void *c_QList_T_SimpleStruct_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
TestBindings_EXPORT void *
c_QList_T_SimpleStruct_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QList::squeeze()
TestBindings_EXPORT void c_QList_T_SimpleStruct_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
TestBindings_EXPORT void
c_QList_T_SimpleStruct_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j);
// QList::takeAt(qsizetype i)
TestBindings_EXPORT void *c_QList_T_SimpleStruct_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
TestBindings_EXPORT void *c_QList_T_SimpleStruct_T___toList(void *thisObj);
// QList::toVector() const
TestBindings_EXPORT void *c_QList_T_SimpleStruct_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
TestBindings_EXPORT void *c_QList_T_SimpleStruct_T___value_qsizetype(void *thisObj, qsizetype i);
TestBindings_EXPORT void c_QList_T_SimpleStruct_T___destructor(void *thisObj);
TestBindings_EXPORT void c_QList_T_SimpleStruct_T__Finalizer(void *cppObj);
}
extern "C" {
// QList::QList<T>()
TestBindings_EXPORT void *c_QList_T_qreal_T___constructor();
// QList::QList<T>(qsizetype size)
TestBindings_EXPORT void *c_QList_T_qreal_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
TestBindings_EXPORT void c_QList_T_qreal_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
TestBindings_EXPORT const qreal c_QList_T_qreal_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
TestBindings_EXPORT qreal c_QList_T_qreal_T___back(void *thisObj);
// QList::capacity() const
TestBindings_EXPORT qsizetype c_QList_T_qreal_T___capacity(void *thisObj);
// QList::clear()
TestBindings_EXPORT void c_QList_T_qreal_T___clear(void *thisObj);
// QList::constFirst() const
TestBindings_EXPORT const qreal c_QList_T_qreal_T___constFirst(void *thisObj);
// QList::constLast() const
TestBindings_EXPORT const qreal c_QList_T_qreal_T___constLast(void *thisObj);
// QList::count() const
TestBindings_EXPORT qsizetype c_QList_T_qreal_T___count(void *thisObj);
// QList::detach()
TestBindings_EXPORT void c_QList_T_qreal_T___detach(void *thisObj);
// QList::empty() const
TestBindings_EXPORT bool c_QList_T_qreal_T___empty(void *thisObj);
// QList::first()
TestBindings_EXPORT qreal c_QList_T_qreal_T___first(void *thisObj);
// QList::first(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_qreal_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
TestBindings_EXPORT qreal c_QList_T_qreal_T___front(void *thisObj);
// QList::isDetached() const
TestBindings_EXPORT bool c_QList_T_qreal_T___isDetached(void *thisObj);
// QList::isEmpty() const
TestBindings_EXPORT bool c_QList_T_qreal_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
TestBindings_EXPORT bool c_QList_T_qreal_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
TestBindings_EXPORT qreal c_QList_T_qreal_T___last(void *thisObj);
// QList::last(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_qreal_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
TestBindings_EXPORT qsizetype c_QList_T_qreal_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
TestBindings_EXPORT void *c_QList_T_qreal_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos,
                                                                      qsizetype len);
// QList::move(qsizetype from, qsizetype to)
TestBindings_EXPORT void c_QList_T_qreal_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from,
                                                                      qsizetype to);
// QList::pop_back()
TestBindings_EXPORT void c_QList_T_qreal_T___pop_back(void *thisObj);
// QList::pop_front()
TestBindings_EXPORT void c_QList_T_qreal_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
TestBindings_EXPORT void c_QList_T_qreal_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i,
                                                                        qsizetype n);
// QList::removeAt(qsizetype i)
TestBindings_EXPORT void c_QList_T_qreal_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
TestBindings_EXPORT void c_QList_T_qreal_T___removeFirst(void *thisObj);
// QList::removeLast()
TestBindings_EXPORT void c_QList_T_qreal_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
TestBindings_EXPORT void c_QList_T_qreal_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
TestBindings_EXPORT void c_QList_T_qreal_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
TestBindings_EXPORT void c_QList_T_qreal_T___shrink_to_fit(void *thisObj);
// QList::size() const
TestBindings_EXPORT qsizetype c_QList_T_qreal_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
TestBindings_EXPORT void *c_QList_T_qreal_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
TestBindings_EXPORT void *
c_QList_T_qreal_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QList::squeeze()
TestBindings_EXPORT void c_QList_T_qreal_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
TestBindings_EXPORT void
c_QList_T_qreal_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j);
// QList::takeAt(qsizetype i)
TestBindings_EXPORT qreal c_QList_T_qreal_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
TestBindings_EXPORT void *c_QList_T_qreal_T___toList(void *thisObj);
// QList::toVector() const
TestBindings_EXPORT void *c_QList_T_qreal_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
TestBindings_EXPORT qreal c_QList_T_qreal_T___value_qsizetype(void *thisObj, qsizetype i);
TestBindings_EXPORT void c_QList_T_qreal_T___destructor(void *thisObj);
TestBindings_EXPORT void c_QList_T_qreal_T__Finalizer(void *cppObj);
}
extern "C" {
// QList::QList<T>()
TestBindings_EXPORT void *c_QList_T_int_T___constructor();
// QList::QList<T>(qsizetype size)
TestBindings_EXPORT void *c_QList_T_int_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
TestBindings_EXPORT void c_QList_T_int_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
TestBindings_EXPORT const int c_QList_T_int_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
TestBindings_EXPORT int c_QList_T_int_T___back(void *thisObj);
// QList::capacity() const
TestBindings_EXPORT qsizetype c_QList_T_int_T___capacity(void *thisObj);
// QList::clear()
TestBindings_EXPORT void c_QList_T_int_T___clear(void *thisObj);
// QList::constFirst() const
TestBindings_EXPORT const int c_QList_T_int_T___constFirst(void *thisObj);
// QList::constLast() const
TestBindings_EXPORT const int c_QList_T_int_T___constLast(void *thisObj);
// QList::count() const
TestBindings_EXPORT qsizetype c_QList_T_int_T___count(void *thisObj);
// QList::detach()
TestBindings_EXPORT void c_QList_T_int_T___detach(void *thisObj);
// QList::empty() const
TestBindings_EXPORT bool c_QList_T_int_T___empty(void *thisObj);
// QList::first()
TestBindings_EXPORT int c_QList_T_int_T___first(void *thisObj);
// QList::first(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_int_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
TestBindings_EXPORT int c_QList_T_int_T___front(void *thisObj);
// QList::isDetached() const
TestBindings_EXPORT bool c_QList_T_int_T___isDetached(void *thisObj);
// QList::isEmpty() const
TestBindings_EXPORT bool c_QList_T_int_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
TestBindings_EXPORT bool c_QList_T_int_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
TestBindings_EXPORT int c_QList_T_int_T___last(void *thisObj);
// QList::last(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_int_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
TestBindings_EXPORT qsizetype c_QList_T_int_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
TestBindings_EXPORT void *c_QList_T_int_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos,
                                                                    qsizetype len);
// QList::move(qsizetype from, qsizetype to)
TestBindings_EXPORT void c_QList_T_int_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from,
                                                                    qsizetype to);
// QList::pop_back()
TestBindings_EXPORT void c_QList_T_int_T___pop_back(void *thisObj);
// QList::pop_front()
TestBindings_EXPORT void c_QList_T_int_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
TestBindings_EXPORT void c_QList_T_int_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i,
                                                                      qsizetype n);
// QList::removeAt(qsizetype i)
TestBindings_EXPORT void c_QList_T_int_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
TestBindings_EXPORT void c_QList_T_int_T___removeFirst(void *thisObj);
// QList::removeLast()
TestBindings_EXPORT void c_QList_T_int_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
TestBindings_EXPORT void c_QList_T_int_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
TestBindings_EXPORT void c_QList_T_int_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
TestBindings_EXPORT void c_QList_T_int_T___shrink_to_fit(void *thisObj);
// QList::size() const
TestBindings_EXPORT qsizetype c_QList_T_int_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
TestBindings_EXPORT void *c_QList_T_int_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
TestBindings_EXPORT void *c_QList_T_int_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos,
                                                                       qsizetype n);
// QList::squeeze()
TestBindings_EXPORT void c_QList_T_int_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
TestBindings_EXPORT void
c_QList_T_int_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j);
// QList::takeAt(qsizetype i)
TestBindings_EXPORT int c_QList_T_int_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
TestBindings_EXPORT void *c_QList_T_int_T___toList(void *thisObj);
// QList::toVector() const
TestBindings_EXPORT void *c_QList_T_int_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
TestBindings_EXPORT int c_QList_T_int_T___value_qsizetype(void *thisObj, qsizetype i);
TestBindings_EXPORT void c_QList_T_int_T___destructor(void *thisObj);
TestBindings_EXPORT void c_QList_T_int_T__Finalizer(void *cppObj);
}
extern "C" {
// QList::QList<T>()
TestBindings_EXPORT void *c_QList_T_QVariant_T___constructor();
// QList::QList<T>(qsizetype size)
TestBindings_EXPORT void *c_QList_T_QVariant_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
TestBindings_EXPORT void c_QList_T_QVariant_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
TestBindings_EXPORT const void *c_QList_T_QVariant_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
TestBindings_EXPORT void *c_QList_T_QVariant_T___back(void *thisObj);
// QList::capacity() const
TestBindings_EXPORT qsizetype c_QList_T_QVariant_T___capacity(void *thisObj);
// QList::clear()
TestBindings_EXPORT void c_QList_T_QVariant_T___clear(void *thisObj);
// QList::constFirst() const
TestBindings_EXPORT const void *c_QList_T_QVariant_T___constFirst(void *thisObj);
// QList::constLast() const
TestBindings_EXPORT const void *c_QList_T_QVariant_T___constLast(void *thisObj);
// QList::count() const
TestBindings_EXPORT qsizetype c_QList_T_QVariant_T___count(void *thisObj);
// QList::detach()
TestBindings_EXPORT void c_QList_T_QVariant_T___detach(void *thisObj);
// QList::empty() const
TestBindings_EXPORT bool c_QList_T_QVariant_T___empty(void *thisObj);
// QList::first()
TestBindings_EXPORT void *c_QList_T_QVariant_T___first(void *thisObj);
// QList::first(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_QVariant_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
TestBindings_EXPORT void *c_QList_T_QVariant_T___front(void *thisObj);
// QList::isDetached() const
TestBindings_EXPORT bool c_QList_T_QVariant_T___isDetached(void *thisObj);
// QList::isEmpty() const
TestBindings_EXPORT bool c_QList_T_QVariant_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
TestBindings_EXPORT bool c_QList_T_QVariant_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
TestBindings_EXPORT void *c_QList_T_QVariant_T___last(void *thisObj);
// QList::last(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_QVariant_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
TestBindings_EXPORT qsizetype c_QList_T_QVariant_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
TestBindings_EXPORT void *
c_QList_T_QVariant_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len);
// QList::move(qsizetype from, qsizetype to)
TestBindings_EXPORT void
c_QList_T_QVariant_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to);
// QList::pop_back()
TestBindings_EXPORT void c_QList_T_QVariant_T___pop_back(void *thisObj);
// QList::pop_front()
TestBindings_EXPORT void c_QList_T_QVariant_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
TestBindings_EXPORT void
c_QList_T_QVariant_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
TestBindings_EXPORT void c_QList_T_QVariant_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
TestBindings_EXPORT void c_QList_T_QVariant_T___removeFirst(void *thisObj);
// QList::removeLast()
TestBindings_EXPORT void c_QList_T_QVariant_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
TestBindings_EXPORT void c_QList_T_QVariant_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
TestBindings_EXPORT void c_QList_T_QVariant_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
TestBindings_EXPORT void c_QList_T_QVariant_T___shrink_to_fit(void *thisObj);
// QList::size() const
TestBindings_EXPORT qsizetype c_QList_T_QVariant_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
TestBindings_EXPORT void *c_QList_T_QVariant_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
TestBindings_EXPORT void *
c_QList_T_QVariant_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QList::squeeze()
TestBindings_EXPORT void c_QList_T_QVariant_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
TestBindings_EXPORT void
c_QList_T_QVariant_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j);
// QList::takeAt(qsizetype i)
TestBindings_EXPORT void *c_QList_T_QVariant_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
TestBindings_EXPORT void *c_QList_T_QVariant_T___toList(void *thisObj);
// QList::toVector() const
TestBindings_EXPORT void *c_QList_T_QVariant_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
TestBindings_EXPORT void *c_QList_T_QVariant_T___value_qsizetype(void *thisObj, qsizetype i);
TestBindings_EXPORT void c_QList_T_QVariant_T___destructor(void *thisObj);
TestBindings_EXPORT void c_QList_T_QVariant_T__Finalizer(void *cppObj);
}
extern "C" {
// QList::QList<T>()
TestBindings_EXPORT void *c_QList_T_QString_T___constructor();
// QList::QList<T>(qsizetype size)
TestBindings_EXPORT void *c_QList_T_QString_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
TestBindings_EXPORT void c_QList_T_QString_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
TestBindings_EXPORT const void *c_QList_T_QString_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
TestBindings_EXPORT void *c_QList_T_QString_T___back(void *thisObj);
// QList::capacity() const
TestBindings_EXPORT qsizetype c_QList_T_QString_T___capacity(void *thisObj);
// QList::clear()
TestBindings_EXPORT void c_QList_T_QString_T___clear(void *thisObj);
// QList::constFirst() const
TestBindings_EXPORT const void *c_QList_T_QString_T___constFirst(void *thisObj);
// QList::constLast() const
TestBindings_EXPORT const void *c_QList_T_QString_T___constLast(void *thisObj);
// QList::count() const
TestBindings_EXPORT qsizetype c_QList_T_QString_T___count(void *thisObj);
// QList::detach()
TestBindings_EXPORT void c_QList_T_QString_T___detach(void *thisObj);
// QList::empty() const
TestBindings_EXPORT bool c_QList_T_QString_T___empty(void *thisObj);
// QList::first()
TestBindings_EXPORT void *c_QList_T_QString_T___first(void *thisObj);
// QList::first(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_QString_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
TestBindings_EXPORT void *c_QList_T_QString_T___front(void *thisObj);
// QList::isDetached() const
TestBindings_EXPORT bool c_QList_T_QString_T___isDetached(void *thisObj);
// QList::isEmpty() const
TestBindings_EXPORT bool c_QList_T_QString_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
TestBindings_EXPORT bool c_QList_T_QString_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
TestBindings_EXPORT void *c_QList_T_QString_T___last(void *thisObj);
// QList::last(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_QString_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
TestBindings_EXPORT qsizetype c_QList_T_QString_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
TestBindings_EXPORT void *
c_QList_T_QString_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len);
// QList::move(qsizetype from, qsizetype to)
TestBindings_EXPORT void
c_QList_T_QString_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to);
// QList::pop_back()
TestBindings_EXPORT void c_QList_T_QString_T___pop_back(void *thisObj);
// QList::pop_front()
TestBindings_EXPORT void c_QList_T_QString_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
TestBindings_EXPORT void c_QList_T_QString_T___remove_qsizetype_qsizetype(void *thisObj,
                                                                          qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
TestBindings_EXPORT void c_QList_T_QString_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
TestBindings_EXPORT void c_QList_T_QString_T___removeFirst(void *thisObj);
// QList::removeLast()
TestBindings_EXPORT void c_QList_T_QString_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
TestBindings_EXPORT void c_QList_T_QString_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
TestBindings_EXPORT void c_QList_T_QString_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
TestBindings_EXPORT void c_QList_T_QString_T___shrink_to_fit(void *thisObj);
// QList::size() const
TestBindings_EXPORT qsizetype c_QList_T_QString_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
TestBindings_EXPORT void *c_QList_T_QString_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
TestBindings_EXPORT void *
c_QList_T_QString_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QList::squeeze()
TestBindings_EXPORT void c_QList_T_QString_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
TestBindings_EXPORT void
c_QList_T_QString_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j);
// QList::takeAt(qsizetype i)
TestBindings_EXPORT void *c_QList_T_QString_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
TestBindings_EXPORT void *c_QList_T_QString_T___toList(void *thisObj);
// QList::toVector() const
TestBindings_EXPORT void *c_QList_T_QString_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
TestBindings_EXPORT void *c_QList_T_QString_T___value_qsizetype(void *thisObj, qsizetype i);
TestBindings_EXPORT void c_QList_T_QString_T___destructor(void *thisObj);
TestBindings_EXPORT void c_QList_T_QString_T__Finalizer(void *cppObj);
}
extern "C" {
// QList::QList<T>()
TestBindings_EXPORT void *c_QList_T_unsigned_int_T___constructor();
// QList::QList<T>(qsizetype size)
TestBindings_EXPORT void *c_QList_T_unsigned_int_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
TestBindings_EXPORT void c_QList_T_unsigned_int_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
TestBindings_EXPORT const unsigned int c_QList_T_unsigned_int_T___at_qsizetype(void *thisObj,
                                                                               qsizetype i);
// QList::back()
TestBindings_EXPORT unsigned int c_QList_T_unsigned_int_T___back(void *thisObj);
// QList::capacity() const
TestBindings_EXPORT qsizetype c_QList_T_unsigned_int_T___capacity(void *thisObj);
// QList::clear()
TestBindings_EXPORT void c_QList_T_unsigned_int_T___clear(void *thisObj);
// QList::constFirst() const
TestBindings_EXPORT const unsigned int c_QList_T_unsigned_int_T___constFirst(void *thisObj);
// QList::constLast() const
TestBindings_EXPORT const unsigned int c_QList_T_unsigned_int_T___constLast(void *thisObj);
// QList::count() const
TestBindings_EXPORT qsizetype c_QList_T_unsigned_int_T___count(void *thisObj);
// QList::detach()
TestBindings_EXPORT void c_QList_T_unsigned_int_T___detach(void *thisObj);
// QList::empty() const
TestBindings_EXPORT bool c_QList_T_unsigned_int_T___empty(void *thisObj);
// QList::first()
TestBindings_EXPORT unsigned int c_QList_T_unsigned_int_T___first(void *thisObj);
// QList::first(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_unsigned_int_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
TestBindings_EXPORT unsigned int c_QList_T_unsigned_int_T___front(void *thisObj);
// QList::isDetached() const
TestBindings_EXPORT bool c_QList_T_unsigned_int_T___isDetached(void *thisObj);
// QList::isEmpty() const
TestBindings_EXPORT bool c_QList_T_unsigned_int_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
TestBindings_EXPORT bool c_QList_T_unsigned_int_T___isSharedWith_QList_T(void *thisObj,
                                                                         void *other_);
// QList::last()
TestBindings_EXPORT unsigned int c_QList_T_unsigned_int_T___last(void *thisObj);
// QList::last(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_unsigned_int_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
TestBindings_EXPORT qsizetype c_QList_T_unsigned_int_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
TestBindings_EXPORT void *
c_QList_T_unsigned_int_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len);
// QList::move(qsizetype from, qsizetype to)
TestBindings_EXPORT void
c_QList_T_unsigned_int_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to);
// QList::pop_back()
TestBindings_EXPORT void c_QList_T_unsigned_int_T___pop_back(void *thisObj);
// QList::pop_front()
TestBindings_EXPORT void c_QList_T_unsigned_int_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
TestBindings_EXPORT void
c_QList_T_unsigned_int_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
TestBindings_EXPORT void c_QList_T_unsigned_int_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
TestBindings_EXPORT void c_QList_T_unsigned_int_T___removeFirst(void *thisObj);
// QList::removeLast()
TestBindings_EXPORT void c_QList_T_unsigned_int_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
TestBindings_EXPORT void c_QList_T_unsigned_int_T___reserve_qsizetype(void *thisObj,
                                                                      qsizetype size);
// QList::resize(qsizetype size)
TestBindings_EXPORT void c_QList_T_unsigned_int_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
TestBindings_EXPORT void c_QList_T_unsigned_int_T___shrink_to_fit(void *thisObj);
// QList::size() const
TestBindings_EXPORT qsizetype c_QList_T_unsigned_int_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
TestBindings_EXPORT void *c_QList_T_unsigned_int_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
TestBindings_EXPORT void *
c_QList_T_unsigned_int_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QList::squeeze()
TestBindings_EXPORT void c_QList_T_unsigned_int_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
TestBindings_EXPORT void
c_QList_T_unsigned_int_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j);
// QList::takeAt(qsizetype i)
TestBindings_EXPORT unsigned int c_QList_T_unsigned_int_T___takeAt_qsizetype(void *thisObj,
                                                                             qsizetype i);
// QList::toList() const
TestBindings_EXPORT void *c_QList_T_unsigned_int_T___toList(void *thisObj);
// QList::toVector() const
TestBindings_EXPORT void *c_QList_T_unsigned_int_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
TestBindings_EXPORT unsigned int c_QList_T_unsigned_int_T___value_qsizetype(void *thisObj,
                                                                            qsizetype i);
TestBindings_EXPORT void c_QList_T_unsigned_int_T___destructor(void *thisObj);
TestBindings_EXPORT void c_QList_T_unsigned_int_T__Finalizer(void *cppObj);
}
extern "C" {
// QList::QList<T>()
TestBindings_EXPORT void *c_QList_T_QObject_T___constructor();
// QList::QList<T>(qsizetype size)
TestBindings_EXPORT void *c_QList_T_QObject_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
TestBindings_EXPORT void c_QList_T_QObject_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
TestBindings_EXPORT const void *c_QList_T_QObject_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
TestBindings_EXPORT void *c_QList_T_QObject_T___back(void *thisObj);
// QList::capacity() const
TestBindings_EXPORT qsizetype c_QList_T_QObject_T___capacity(void *thisObj);
// QList::clear()
TestBindings_EXPORT void c_QList_T_QObject_T___clear(void *thisObj);
// QList::constFirst() const
TestBindings_EXPORT const void *c_QList_T_QObject_T___constFirst(void *thisObj);
// QList::constLast() const
TestBindings_EXPORT const void *c_QList_T_QObject_T___constLast(void *thisObj);
// QList::count() const
TestBindings_EXPORT qsizetype c_QList_T_QObject_T___count(void *thisObj);
// QList::detach()
TestBindings_EXPORT void c_QList_T_QObject_T___detach(void *thisObj);
// QList::empty() const
TestBindings_EXPORT bool c_QList_T_QObject_T___empty(void *thisObj);
// QList::first()
TestBindings_EXPORT void *c_QList_T_QObject_T___first(void *thisObj);
// QList::first(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_QObject_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
TestBindings_EXPORT void *c_QList_T_QObject_T___front(void *thisObj);
// QList::isDetached() const
TestBindings_EXPORT bool c_QList_T_QObject_T___isDetached(void *thisObj);
// QList::isEmpty() const
TestBindings_EXPORT bool c_QList_T_QObject_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
TestBindings_EXPORT bool c_QList_T_QObject_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
TestBindings_EXPORT void *c_QList_T_QObject_T___last(void *thisObj);
// QList::last(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_QObject_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
TestBindings_EXPORT qsizetype c_QList_T_QObject_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
TestBindings_EXPORT void *
c_QList_T_QObject_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len);
// QList::move(qsizetype from, qsizetype to)
TestBindings_EXPORT void
c_QList_T_QObject_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to);
// QList::pop_back()
TestBindings_EXPORT void c_QList_T_QObject_T___pop_back(void *thisObj);
// QList::pop_front()
TestBindings_EXPORT void c_QList_T_QObject_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
TestBindings_EXPORT void c_QList_T_QObject_T___remove_qsizetype_qsizetype(void *thisObj,
                                                                          qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
TestBindings_EXPORT void c_QList_T_QObject_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
TestBindings_EXPORT void c_QList_T_QObject_T___removeFirst(void *thisObj);
// QList::removeLast()
TestBindings_EXPORT void c_QList_T_QObject_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
TestBindings_EXPORT void c_QList_T_QObject_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
TestBindings_EXPORT void c_QList_T_QObject_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
TestBindings_EXPORT void c_QList_T_QObject_T___shrink_to_fit(void *thisObj);
// QList::size() const
TestBindings_EXPORT qsizetype c_QList_T_QObject_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
TestBindings_EXPORT void *c_QList_T_QObject_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
TestBindings_EXPORT void *
c_QList_T_QObject_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QList::squeeze()
TestBindings_EXPORT void c_QList_T_QObject_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
TestBindings_EXPORT void
c_QList_T_QObject_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j);
// QList::takeAt(qsizetype i)
TestBindings_EXPORT void *c_QList_T_QObject_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
TestBindings_EXPORT void *c_QList_T_QObject_T___toList(void *thisObj);
// QList::toVector() const
TestBindings_EXPORT void *c_QList_T_QObject_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
TestBindings_EXPORT void *c_QList_T_QObject_T___value_qsizetype(void *thisObj, qsizetype i);
TestBindings_EXPORT void c_QList_T_QObject_T___destructor(void *thisObj);
TestBindings_EXPORT void c_QList_T_QObject_T__Finalizer(void *cppObj);
}
extern "C" {
// QList::QList<T>()
TestBindings_EXPORT void *c_QList_T_QByteArray_T___constructor();
// QList::QList<T>(qsizetype size)
TestBindings_EXPORT void *c_QList_T_QByteArray_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
TestBindings_EXPORT void c_QList_T_QByteArray_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
TestBindings_EXPORT const void *c_QList_T_QByteArray_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
TestBindings_EXPORT void *c_QList_T_QByteArray_T___back(void *thisObj);
// QList::capacity() const
TestBindings_EXPORT qsizetype c_QList_T_QByteArray_T___capacity(void *thisObj);
// QList::clear()
TestBindings_EXPORT void c_QList_T_QByteArray_T___clear(void *thisObj);
// QList::constFirst() const
TestBindings_EXPORT const void *c_QList_T_QByteArray_T___constFirst(void *thisObj);
// QList::constLast() const
TestBindings_EXPORT const void *c_QList_T_QByteArray_T___constLast(void *thisObj);
// QList::count() const
TestBindings_EXPORT qsizetype c_QList_T_QByteArray_T___count(void *thisObj);
// QList::detach()
TestBindings_EXPORT void c_QList_T_QByteArray_T___detach(void *thisObj);
// QList::empty() const
TestBindings_EXPORT bool c_QList_T_QByteArray_T___empty(void *thisObj);
// QList::first()
TestBindings_EXPORT void *c_QList_T_QByteArray_T___first(void *thisObj);
// QList::first(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_QByteArray_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
TestBindings_EXPORT void *c_QList_T_QByteArray_T___front(void *thisObj);
// QList::isDetached() const
TestBindings_EXPORT bool c_QList_T_QByteArray_T___isDetached(void *thisObj);
// QList::isEmpty() const
TestBindings_EXPORT bool c_QList_T_QByteArray_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
TestBindings_EXPORT bool c_QList_T_QByteArray_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
TestBindings_EXPORT void *c_QList_T_QByteArray_T___last(void *thisObj);
// QList::last(qsizetype n) const
TestBindings_EXPORT void *c_QList_T_QByteArray_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
TestBindings_EXPORT qsizetype c_QList_T_QByteArray_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
TestBindings_EXPORT void *
c_QList_T_QByteArray_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len);
// QList::move(qsizetype from, qsizetype to)
TestBindings_EXPORT void
c_QList_T_QByteArray_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to);
// QList::pop_back()
TestBindings_EXPORT void c_QList_T_QByteArray_T___pop_back(void *thisObj);
// QList::pop_front()
TestBindings_EXPORT void c_QList_T_QByteArray_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
TestBindings_EXPORT void
c_QList_T_QByteArray_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
TestBindings_EXPORT void c_QList_T_QByteArray_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
TestBindings_EXPORT void c_QList_T_QByteArray_T___removeFirst(void *thisObj);
// QList::removeLast()
TestBindings_EXPORT void c_QList_T_QByteArray_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
TestBindings_EXPORT void c_QList_T_QByteArray_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
TestBindings_EXPORT void c_QList_T_QByteArray_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
TestBindings_EXPORT void c_QList_T_QByteArray_T___shrink_to_fit(void *thisObj);
// QList::size() const
TestBindings_EXPORT qsizetype c_QList_T_QByteArray_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
TestBindings_EXPORT void *c_QList_T_QByteArray_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
TestBindings_EXPORT void *
c_QList_T_QByteArray_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QList::squeeze()
TestBindings_EXPORT void c_QList_T_QByteArray_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
TestBindings_EXPORT void
c_QList_T_QByteArray_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j);
// QList::takeAt(qsizetype i)
TestBindings_EXPORT void *c_QList_T_QByteArray_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
TestBindings_EXPORT void *c_QList_T_QByteArray_T___toList(void *thisObj);
// QList::toVector() const
TestBindings_EXPORT void *c_QList_T_QByteArray_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
TestBindings_EXPORT void *c_QList_T_QByteArray_T___value_qsizetype(void *thisObj, qsizetype i);
TestBindings_EXPORT void c_QList_T_QByteArray_T___destructor(void *thisObj);
TestBindings_EXPORT void c_QList_T_QByteArray_T__Finalizer(void *cppObj);
}

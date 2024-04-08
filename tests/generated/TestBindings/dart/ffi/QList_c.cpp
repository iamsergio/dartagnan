#include "QList_c.h"


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
QList_wrapper<T>::QList_wrapper()
    : ::QList<T>()
{
}
template<typename T>
QList_wrapper<T>::QList_wrapper(qsizetype size)
    : ::QList<T>(size)
{
}
template<typename T>
void QList_wrapper<T>::append(const QList<T> &l)
{
    ::QList<T>::append(l);
}
template<typename T>
const T &QList_wrapper<T>::at(qsizetype i) const
{
    return ::QList<T>::at(i);
}
template<typename T>
T &QList_wrapper<T>::back()
{
    return ::QList<T>::back();
}
template<typename T>
qsizetype QList_wrapper<T>::capacity() const
{
    return ::QList<T>::capacity();
}
template<typename T>
void QList_wrapper<T>::clear()
{
    ::QList<T>::clear();
}
template<typename T>
const T &QList_wrapper<T>::constFirst() const
{
    return ::QList<T>::constFirst();
}
template<typename T>
const T &QList_wrapper<T>::constLast() const
{
    return ::QList<T>::constLast();
}
template<typename T>
qsizetype QList_wrapper<T>::count() const
{
    return ::QList<T>::count();
}
template<typename T>
void QList_wrapper<T>::detach()
{
    ::QList<T>::detach();
}
template<typename T>
bool QList_wrapper<T>::empty() const
{
    return ::QList<T>::empty();
}
template<typename T>
T &QList_wrapper<T>::first()
{
    return ::QList<T>::first();
}
template<typename T>
QList<T> QList_wrapper<T>::first(qsizetype n) const
{
    return ::QList<T>::first(n);
}
template<typename T>
T &QList_wrapper<T>::front()
{
    return ::QList<T>::front();
}
template<typename T>
bool QList_wrapper<T>::isDetached() const
{
    return ::QList<T>::isDetached();
}
template<typename T>
bool QList_wrapper<T>::isEmpty() const
{
    return ::QList<T>::isEmpty();
}
template<typename T>
bool QList_wrapper<T>::isSharedWith(const QList<T> &other) const
{
    return ::QList<T>::isSharedWith(other);
}
template<typename T>
T &QList_wrapper<T>::last()
{
    return ::QList<T>::last();
}
template<typename T>
QList<T> QList_wrapper<T>::last(qsizetype n) const
{
    return ::QList<T>::last(n);
}
template<typename T>
qsizetype QList_wrapper<T>::length() const
{
    return ::QList<T>::length();
}
template<typename T>
QList<T> QList_wrapper<T>::mid(qsizetype pos, qsizetype len) const
{
    return ::QList<T>::mid(pos, len);
}
template<typename T>
void QList_wrapper<T>::move(qsizetype from, qsizetype to)
{
    ::QList<T>::move(from, to);
}
template<typename T>
void QList_wrapper<T>::pop_back()
{
    ::QList<T>::pop_back();
}
template<typename T>
void QList_wrapper<T>::pop_front()
{
    ::QList<T>::pop_front();
}
template<typename T>
void QList_wrapper<T>::remove(qsizetype i, qsizetype n)
{
    ::QList<T>::remove(i, n);
}
template<typename T>
void QList_wrapper<T>::removeAt(qsizetype i)
{
    ::QList<T>::removeAt(i);
}
template<typename T>
void QList_wrapper<T>::removeFirst()
{
    ::QList<T>::removeFirst();
}
template<typename T>
void QList_wrapper<T>::removeLast()
{
    ::QList<T>::removeLast();
}
template<typename T>
void QList_wrapper<T>::reserve(qsizetype size)
{
    ::QList<T>::reserve(size);
}
template<typename T>
void QList_wrapper<T>::resize(qsizetype size)
{
    ::QList<T>::resize(size);
}
template<typename T>
void QList_wrapper<T>::shrink_to_fit()
{
    ::QList<T>::shrink_to_fit();
}
template<typename T>
qsizetype QList_wrapper<T>::size() const
{
    return ::QList<T>::size();
}
template<typename T>
QList<T> QList_wrapper<T>::sliced(qsizetype pos) const
{
    return ::QList<T>::sliced(pos);
}
template<typename T>
QList<T> QList_wrapper<T>::sliced(qsizetype pos, qsizetype n) const
{
    return ::QList<T>::sliced(pos, n);
}
template<typename T>
void QList_wrapper<T>::squeeze()
{
    ::QList<T>::squeeze();
}
template<typename T>
void QList_wrapper<T>::swapItemsAt(qsizetype i, qsizetype j)
{
    ::QList<T>::swapItemsAt(i, j);
}
template<typename T>
T QList_wrapper<T>::takeAt(qsizetype i)
{
    return ::QList<T>::takeAt(i);
}
template<typename T>
QList<T> QList_wrapper<T>::toList() const
{
    return ::QList<T>::toList();
}
template<typename T>
QList<T> QList_wrapper<T>::toVector() const
{
    return ::QList<T>::toVector();
}
template<typename T>
T QList_wrapper<T>::value(qsizetype i) const
{
    return ::QList<T>::value(i);
}
template<typename T>
QList_wrapper<T>::~QList_wrapper()
{
}

}
template<typename T>
static QList<T> *fromPtr(void *ptr)
{
    return reinterpret_cast<QList<T> *>(ptr);
}
template<typename T>
static TestBindings_wrappersNS::QList_wrapper<T> *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::QList_wrapper<T> *>(ptr);
}
extern "C" {
void c_QList_T_SimpleStruct_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::QList_wrapper<SimpleStruct *> *>(cppObj);
}
void *c_QList_T_SimpleStruct_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<SimpleStruct *>();
    return reinterpret_cast<void *>(ptr);
}
void *c_QList_T_SimpleStruct_T___constructor_qsizetype(qsizetype size)
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<SimpleStruct *>(size);
    return reinterpret_cast<void *>(ptr);
}
// append(const QList<T > & l)
void c_QList_T_SimpleStruct_T___append_QList_T(void *thisObj, void *l_)
{
    assert(l_);
    auto &l = *reinterpret_cast<QList<SimpleStruct *> *>(l_);
    fromPtr<SimpleStruct *>(thisObj)->append(l);
}
// at(qsizetype i) const
const void *c_QList_T_SimpleStruct_T___at_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->at(i);
    return result;
}
// back()
void *c_QList_T_SimpleStruct_T___back(void *thisObj)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->back();
    return result;
}
// capacity() const
qsizetype c_QList_T_SimpleStruct_T___capacity(void *thisObj)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->capacity();
    return result;
}
// clear()
void c_QList_T_SimpleStruct_T___clear(void *thisObj)
{
    fromPtr<SimpleStruct *>(thisObj)->clear();
}
// constFirst() const
const void *c_QList_T_SimpleStruct_T___constFirst(void *thisObj)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->constFirst();
    return result;
}
// constLast() const
const void *c_QList_T_SimpleStruct_T___constLast(void *thisObj)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->constLast();
    return result;
}
// count() const
qsizetype c_QList_T_SimpleStruct_T___count(void *thisObj)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->count();
    return result;
}
// detach()
void c_QList_T_SimpleStruct_T___detach(void *thisObj)
{
    fromPtr<SimpleStruct *>(thisObj)->detach();
}
// empty() const
bool c_QList_T_SimpleStruct_T___empty(void *thisObj)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->empty();
    return result;
}
// first()
void *c_QList_T_SimpleStruct_T___first(void *thisObj)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->first();
    return result;
}
// first(qsizetype n) const
void *c_QList_T_SimpleStruct_T___first_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<SimpleStruct *>> {
        fromPtr<SimpleStruct *>(thisObj)->first(n)
    };
    return result;
}
// front()
void *c_QList_T_SimpleStruct_T___front(void *thisObj)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->front();
    return result;
}
// isDetached() const
bool c_QList_T_SimpleStruct_T___isDetached(void *thisObj)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->isDetached();
    return result;
}
// isEmpty() const
bool c_QList_T_SimpleStruct_T___isEmpty(void *thisObj)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->isEmpty();
    return result;
}
// isSharedWith(const QList<T > & other) const
bool c_QList_T_SimpleStruct_T___isSharedWith_QList_T(void *thisObj, void *other_)
{
    assert(other_);
    auto &other = *reinterpret_cast<QList<SimpleStruct *> *>(other_);
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->isSharedWith(other);
    return result;
}
// last()
void *c_QList_T_SimpleStruct_T___last(void *thisObj)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->last();
    return result;
}
// last(qsizetype n) const
void *c_QList_T_SimpleStruct_T___last_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<SimpleStruct *>> {
        fromPtr<SimpleStruct *>(thisObj)->last(n)
    };
    return result;
}
// length() const
qsizetype c_QList_T_SimpleStruct_T___length(void *thisObj)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->length();
    return result;
}
// mid(qsizetype pos, qsizetype len) const
void *c_QList_T_SimpleStruct_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos,
                                                         qsizetype len)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<SimpleStruct *>> {
        fromPtr<SimpleStruct *>(thisObj)->mid(pos, len)
    };
    return result;
}
// move(qsizetype from, qsizetype to)
void c_QList_T_SimpleStruct_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from,
                                                         qsizetype to)
{
    fromPtr<SimpleStruct *>(thisObj)->move(from, to);
}
// pop_back()
void c_QList_T_SimpleStruct_T___pop_back(void *thisObj)
{
    fromPtr<SimpleStruct *>(thisObj)->pop_back();
}
// pop_front()
void c_QList_T_SimpleStruct_T___pop_front(void *thisObj)
{
    fromPtr<SimpleStruct *>(thisObj)->pop_front();
}
// remove(qsizetype i, qsizetype n)
void c_QList_T_SimpleStruct_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n)
{
    fromPtr<SimpleStruct *>(thisObj)->remove(i, n);
}
// removeAt(qsizetype i)
void c_QList_T_SimpleStruct_T___removeAt_qsizetype(void *thisObj, qsizetype i)
{
    fromPtr<SimpleStruct *>(thisObj)->removeAt(i);
}
// removeFirst()
void c_QList_T_SimpleStruct_T___removeFirst(void *thisObj)
{
    fromPtr<SimpleStruct *>(thisObj)->removeFirst();
}
// removeLast()
void c_QList_T_SimpleStruct_T___removeLast(void *thisObj)
{
    fromPtr<SimpleStruct *>(thisObj)->removeLast();
}
// reserve(qsizetype size)
void c_QList_T_SimpleStruct_T___reserve_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<SimpleStruct *>(thisObj)->reserve(size);
}
// resize(qsizetype size)
void c_QList_T_SimpleStruct_T___resize_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<SimpleStruct *>(thisObj)->resize(size);
}
// shrink_to_fit()
void c_QList_T_SimpleStruct_T___shrink_to_fit(void *thisObj)
{
    fromPtr<SimpleStruct *>(thisObj)->shrink_to_fit();
}
// size() const
qsizetype c_QList_T_SimpleStruct_T___size(void *thisObj)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->size();
    return result;
}
// sliced(qsizetype pos) const
void *c_QList_T_SimpleStruct_T___sliced_qsizetype(void *thisObj, qsizetype pos)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<SimpleStruct *>> {
        fromPtr<SimpleStruct *>(thisObj)->sliced(pos)
    };
    return result;
}
// sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_SimpleStruct_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos,
                                                            qsizetype n)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<SimpleStruct *>> {
        fromPtr<SimpleStruct *>(thisObj)->sliced(pos, n)
    };
    return result;
}
// squeeze()
void c_QList_T_SimpleStruct_T___squeeze(void *thisObj)
{
    fromPtr<SimpleStruct *>(thisObj)->squeeze();
}
// swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_SimpleStruct_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i,
                                                                qsizetype j)
{
    fromPtr<SimpleStruct *>(thisObj)->swapItemsAt(i, j);
}
// takeAt(qsizetype i)
void *c_QList_T_SimpleStruct_T___takeAt_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->takeAt(i);
    return result;
}
// toList() const
void *c_QList_T_SimpleStruct_T___toList(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<SimpleStruct *>> {
        fromPtr<SimpleStruct *>(thisObj)->toList()
    };
    return result;
}
// toVector() const
void *c_QList_T_SimpleStruct_T___toVector(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<SimpleStruct *>> {
        fromPtr<SimpleStruct *>(thisObj)->toVector()
    };
    return result;
}
// value(qsizetype i) const
void *c_QList_T_SimpleStruct_T___value_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<SimpleStruct *>(thisObj)->value(i);
    return result;
}
void c_QList_T_SimpleStruct_T___destructor(void *thisObj)
{
    delete fromPtr<SimpleStruct *>(thisObj);
}
}
extern "C" {
void c_QList_T_qreal_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::QList_wrapper<qreal> *>(cppObj);
}
void *c_QList_T_qreal_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<qreal>();
    return reinterpret_cast<void *>(ptr);
}
void *c_QList_T_qreal_T___constructor_qsizetype(qsizetype size)
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<qreal>(size);
    return reinterpret_cast<void *>(ptr);
}
// append(const QList<T > & l)
void c_QList_T_qreal_T___append_QList_T(void *thisObj, void *l_)
{
    assert(l_);
    auto &l = *reinterpret_cast<QList<qreal> *>(l_);
    fromPtr<qreal>(thisObj)->append(l);
}
// at(qsizetype i) const
const qreal c_QList_T_qreal_T___at_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<qreal>(thisObj)->at(i);
    return result;
}
// back()
qreal c_QList_T_qreal_T___back(void *thisObj)
{
    const auto &result = fromPtr<qreal>(thisObj)->back();
    return result;
}
// capacity() const
qsizetype c_QList_T_qreal_T___capacity(void *thisObj)
{
    const auto &result = fromPtr<qreal>(thisObj)->capacity();
    return result;
}
// clear()
void c_QList_T_qreal_T___clear(void *thisObj)
{
    fromPtr<qreal>(thisObj)->clear();
}
// constFirst() const
const qreal c_QList_T_qreal_T___constFirst(void *thisObj)
{
    const auto &result = fromPtr<qreal>(thisObj)->constFirst();
    return result;
}
// constLast() const
const qreal c_QList_T_qreal_T___constLast(void *thisObj)
{
    const auto &result = fromPtr<qreal>(thisObj)->constLast();
    return result;
}
// count() const
qsizetype c_QList_T_qreal_T___count(void *thisObj)
{
    const auto &result = fromPtr<qreal>(thisObj)->count();
    return result;
}
// detach()
void c_QList_T_qreal_T___detach(void *thisObj)
{
    fromPtr<qreal>(thisObj)->detach();
}
// empty() const
bool c_QList_T_qreal_T___empty(void *thisObj)
{
    const auto &result = fromPtr<qreal>(thisObj)->empty();
    return result;
}
// first()
qreal c_QList_T_qreal_T___first(void *thisObj)
{
    const auto &result = fromPtr<qreal>(thisObj)->first();
    return result;
}
// first(qsizetype n) const
void *c_QList_T_qreal_T___first_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<qreal>> { fromPtr<qreal>(thisObj)->first(n) };
    return result;
}
// front()
qreal c_QList_T_qreal_T___front(void *thisObj)
{
    const auto &result = fromPtr<qreal>(thisObj)->front();
    return result;
}
// isDetached() const
bool c_QList_T_qreal_T___isDetached(void *thisObj)
{
    const auto &result = fromPtr<qreal>(thisObj)->isDetached();
    return result;
}
// isEmpty() const
bool c_QList_T_qreal_T___isEmpty(void *thisObj)
{
    const auto &result = fromPtr<qreal>(thisObj)->isEmpty();
    return result;
}
// isSharedWith(const QList<T > & other) const
bool c_QList_T_qreal_T___isSharedWith_QList_T(void *thisObj, void *other_)
{
    assert(other_);
    auto &other = *reinterpret_cast<QList<qreal> *>(other_);
    const auto &result = fromPtr<qreal>(thisObj)->isSharedWith(other);
    return result;
}
// last()
qreal c_QList_T_qreal_T___last(void *thisObj)
{
    const auto &result = fromPtr<qreal>(thisObj)->last();
    return result;
}
// last(qsizetype n) const
void *c_QList_T_qreal_T___last_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<qreal>> { fromPtr<qreal>(thisObj)->last(n) };
    return result;
}
// length() const
qsizetype c_QList_T_qreal_T___length(void *thisObj)
{
    const auto &result = fromPtr<qreal>(thisObj)->length();
    return result;
}
// mid(qsizetype pos, qsizetype len) const
void *c_QList_T_qreal_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<qreal>> { fromPtr<qreal>(thisObj)->mid(pos, len) };
    return result;
}
// move(qsizetype from, qsizetype to)
void c_QList_T_qreal_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to)
{
    fromPtr<qreal>(thisObj)->move(from, to);
}
// pop_back()
void c_QList_T_qreal_T___pop_back(void *thisObj)
{
    fromPtr<qreal>(thisObj)->pop_back();
}
// pop_front()
void c_QList_T_qreal_T___pop_front(void *thisObj)
{
    fromPtr<qreal>(thisObj)->pop_front();
}
// remove(qsizetype i, qsizetype n)
void c_QList_T_qreal_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n)
{
    fromPtr<qreal>(thisObj)->remove(i, n);
}
// removeAt(qsizetype i)
void c_QList_T_qreal_T___removeAt_qsizetype(void *thisObj, qsizetype i)
{
    fromPtr<qreal>(thisObj)->removeAt(i);
}
// removeFirst()
void c_QList_T_qreal_T___removeFirst(void *thisObj)
{
    fromPtr<qreal>(thisObj)->removeFirst();
}
// removeLast()
void c_QList_T_qreal_T___removeLast(void *thisObj)
{
    fromPtr<qreal>(thisObj)->removeLast();
}
// reserve(qsizetype size)
void c_QList_T_qreal_T___reserve_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<qreal>(thisObj)->reserve(size);
}
// resize(qsizetype size)
void c_QList_T_qreal_T___resize_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<qreal>(thisObj)->resize(size);
}
// shrink_to_fit()
void c_QList_T_qreal_T___shrink_to_fit(void *thisObj)
{
    fromPtr<qreal>(thisObj)->shrink_to_fit();
}
// size() const
qsizetype c_QList_T_qreal_T___size(void *thisObj)
{
    const auto &result = fromPtr<qreal>(thisObj)->size();
    return result;
}
// sliced(qsizetype pos) const
void *c_QList_T_qreal_T___sliced_qsizetype(void *thisObj, qsizetype pos)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<qreal>> { fromPtr<qreal>(thisObj)->sliced(pos) };
    return result;
}
// sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_qreal_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<qreal>> { fromPtr<qreal>(thisObj)->sliced(pos, n) };
    return result;
}
// squeeze()
void c_QList_T_qreal_T___squeeze(void *thisObj)
{
    fromPtr<qreal>(thisObj)->squeeze();
}
// swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_qreal_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j)
{
    fromPtr<qreal>(thisObj)->swapItemsAt(i, j);
}
// takeAt(qsizetype i)
qreal c_QList_T_qreal_T___takeAt_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<qreal>(thisObj)->takeAt(i);
    return result;
}
// toList() const
void *c_QList_T_qreal_T___toList(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<qreal>> { fromPtr<qreal>(thisObj)->toList() };
    return result;
}
// toVector() const
void *c_QList_T_qreal_T___toVector(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<qreal>> { fromPtr<qreal>(thisObj)->toVector() };
    return result;
}
// value(qsizetype i) const
qreal c_QList_T_qreal_T___value_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<qreal>(thisObj)->value(i);
    return result;
}
void c_QList_T_qreal_T___destructor(void *thisObj)
{
    delete fromPtr<qreal>(thisObj);
}
}
extern "C" {
void c_QList_T_int_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::QList_wrapper<int> *>(cppObj);
}
void *c_QList_T_int_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<int>();
    return reinterpret_cast<void *>(ptr);
}
void *c_QList_T_int_T___constructor_qsizetype(qsizetype size)
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<int>(size);
    return reinterpret_cast<void *>(ptr);
}
// append(const QList<T > & l)
void c_QList_T_int_T___append_QList_T(void *thisObj, void *l_)
{
    assert(l_);
    auto &l = *reinterpret_cast<QList<int> *>(l_);
    fromPtr<int>(thisObj)->append(l);
}
// at(qsizetype i) const
const int c_QList_T_int_T___at_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<int>(thisObj)->at(i);
    return result;
}
// back()
int c_QList_T_int_T___back(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->back();
    return result;
}
// capacity() const
qsizetype c_QList_T_int_T___capacity(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->capacity();
    return result;
}
// clear()
void c_QList_T_int_T___clear(void *thisObj)
{
    fromPtr<int>(thisObj)->clear();
}
// constFirst() const
const int c_QList_T_int_T___constFirst(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->constFirst();
    return result;
}
// constLast() const
const int c_QList_T_int_T___constLast(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->constLast();
    return result;
}
// count() const
qsizetype c_QList_T_int_T___count(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->count();
    return result;
}
// detach()
void c_QList_T_int_T___detach(void *thisObj)
{
    fromPtr<int>(thisObj)->detach();
}
// empty() const
bool c_QList_T_int_T___empty(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->empty();
    return result;
}
// first()
int c_QList_T_int_T___first(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->first();
    return result;
}
// first(qsizetype n) const
void *c_QList_T_int_T___first_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<int>> { fromPtr<int>(thisObj)->first(n) };
    return result;
}
// front()
int c_QList_T_int_T___front(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->front();
    return result;
}
// isDetached() const
bool c_QList_T_int_T___isDetached(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->isDetached();
    return result;
}
// isEmpty() const
bool c_QList_T_int_T___isEmpty(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->isEmpty();
    return result;
}
// isSharedWith(const QList<T > & other) const
bool c_QList_T_int_T___isSharedWith_QList_T(void *thisObj, void *other_)
{
    assert(other_);
    auto &other = *reinterpret_cast<QList<int> *>(other_);
    const auto &result = fromPtr<int>(thisObj)->isSharedWith(other);
    return result;
}
// last()
int c_QList_T_int_T___last(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->last();
    return result;
}
// last(qsizetype n) const
void *c_QList_T_int_T___last_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<int>> { fromPtr<int>(thisObj)->last(n) };
    return result;
}
// length() const
qsizetype c_QList_T_int_T___length(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->length();
    return result;
}
// mid(qsizetype pos, qsizetype len) const
void *c_QList_T_int_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<int>> { fromPtr<int>(thisObj)->mid(pos, len) };
    return result;
}
// move(qsizetype from, qsizetype to)
void c_QList_T_int_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to)
{
    fromPtr<int>(thisObj)->move(from, to);
}
// pop_back()
void c_QList_T_int_T___pop_back(void *thisObj)
{
    fromPtr<int>(thisObj)->pop_back();
}
// pop_front()
void c_QList_T_int_T___pop_front(void *thisObj)
{
    fromPtr<int>(thisObj)->pop_front();
}
// remove(qsizetype i, qsizetype n)
void c_QList_T_int_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n)
{
    fromPtr<int>(thisObj)->remove(i, n);
}
// removeAt(qsizetype i)
void c_QList_T_int_T___removeAt_qsizetype(void *thisObj, qsizetype i)
{
    fromPtr<int>(thisObj)->removeAt(i);
}
// removeFirst()
void c_QList_T_int_T___removeFirst(void *thisObj)
{
    fromPtr<int>(thisObj)->removeFirst();
}
// removeLast()
void c_QList_T_int_T___removeLast(void *thisObj)
{
    fromPtr<int>(thisObj)->removeLast();
}
// reserve(qsizetype size)
void c_QList_T_int_T___reserve_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<int>(thisObj)->reserve(size);
}
// resize(qsizetype size)
void c_QList_T_int_T___resize_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<int>(thisObj)->resize(size);
}
// shrink_to_fit()
void c_QList_T_int_T___shrink_to_fit(void *thisObj)
{
    fromPtr<int>(thisObj)->shrink_to_fit();
}
// size() const
qsizetype c_QList_T_int_T___size(void *thisObj)
{
    const auto &result = fromPtr<int>(thisObj)->size();
    return result;
}
// sliced(qsizetype pos) const
void *c_QList_T_int_T___sliced_qsizetype(void *thisObj, qsizetype pos)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<int>> { fromPtr<int>(thisObj)->sliced(pos) };
    return result;
}
// sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_int_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<int>> { fromPtr<int>(thisObj)->sliced(pos, n) };
    return result;
}
// squeeze()
void c_QList_T_int_T___squeeze(void *thisObj)
{
    fromPtr<int>(thisObj)->squeeze();
}
// swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_int_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j)
{
    fromPtr<int>(thisObj)->swapItemsAt(i, j);
}
// takeAt(qsizetype i)
int c_QList_T_int_T___takeAt_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<int>(thisObj)->takeAt(i);
    return result;
}
// toList() const
void *c_QList_T_int_T___toList(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<int>> { fromPtr<int>(thisObj)->toList() };
    return result;
}
// toVector() const
void *c_QList_T_int_T___toVector(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<int>> { fromPtr<int>(thisObj)->toVector() };
    return result;
}
// value(qsizetype i) const
int c_QList_T_int_T___value_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<int>(thisObj)->value(i);
    return result;
}
void c_QList_T_int_T___destructor(void *thisObj)
{
    delete fromPtr<int>(thisObj);
}
}
extern "C" {
void c_QList_T_QVariant_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::QList_wrapper<QVariant> *>(cppObj);
}
void *c_QList_T_QVariant_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<QVariant>();
    return reinterpret_cast<void *>(ptr);
}
void *c_QList_T_QVariant_T___constructor_qsizetype(qsizetype size)
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<QVariant>(size);
    return reinterpret_cast<void *>(ptr);
}
// append(const QList<T > & l)
void c_QList_T_QVariant_T___append_QList_T(void *thisObj, void *l_)
{
    assert(l_);
    auto &l = *reinterpret_cast<QList<QVariant> *>(l_);
    fromPtr<QVariant>(thisObj)->append(l);
}
// at(qsizetype i) const
const void *c_QList_T_QVariant_T___at_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QVariant>(thisObj)->at(i) };
    return result;
}
// back()
void *c_QList_T_QVariant_T___back(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QVariant>(thisObj)->back() };
    return result;
}
// capacity() const
qsizetype c_QList_T_QVariant_T___capacity(void *thisObj)
{
    const auto &result = fromPtr<QVariant>(thisObj)->capacity();
    return result;
}
// clear()
void c_QList_T_QVariant_T___clear(void *thisObj)
{
    fromPtr<QVariant>(thisObj)->clear();
}
// constFirst() const
const void *c_QList_T_QVariant_T___constFirst(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QVariant>(thisObj)->constFirst() };
    return result;
}
// constLast() const
const void *c_QList_T_QVariant_T___constLast(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QVariant>(thisObj)->constLast() };
    return result;
}
// count() const
qsizetype c_QList_T_QVariant_T___count(void *thisObj)
{
    const auto &result = fromPtr<QVariant>(thisObj)->count();
    return result;
}
// detach()
void c_QList_T_QVariant_T___detach(void *thisObj)
{
    fromPtr<QVariant>(thisObj)->detach();
}
// empty() const
bool c_QList_T_QVariant_T___empty(void *thisObj)
{
    const auto &result = fromPtr<QVariant>(thisObj)->empty();
    return result;
}
// first()
void *c_QList_T_QVariant_T___first(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QVariant>(thisObj)->first() };
    return result;
}
// first(qsizetype n) const
void *c_QList_T_QVariant_T___first_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QVariant>> { fromPtr<QVariant>(thisObj)->first(n) };
    return result;
}
// front()
void *c_QList_T_QVariant_T___front(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QVariant>(thisObj)->front() };
    return result;
}
// isDetached() const
bool c_QList_T_QVariant_T___isDetached(void *thisObj)
{
    const auto &result = fromPtr<QVariant>(thisObj)->isDetached();
    return result;
}
// isEmpty() const
bool c_QList_T_QVariant_T___isEmpty(void *thisObj)
{
    const auto &result = fromPtr<QVariant>(thisObj)->isEmpty();
    return result;
}
// isSharedWith(const QList<T > & other) const
bool c_QList_T_QVariant_T___isSharedWith_QList_T(void *thisObj, void *other_)
{
    assert(other_);
    auto &other = *reinterpret_cast<QList<QVariant> *>(other_);
    const auto &result = fromPtr<QVariant>(thisObj)->isSharedWith(other);
    return result;
}
// last()
void *c_QList_T_QVariant_T___last(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QVariant>(thisObj)->last() };
    return result;
}
// last(qsizetype n) const
void *c_QList_T_QVariant_T___last_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QVariant>> { fromPtr<QVariant>(thisObj)->last(n) };
    return result;
}
// length() const
qsizetype c_QList_T_QVariant_T___length(void *thisObj)
{
    const auto &result = fromPtr<QVariant>(thisObj)->length();
    return result;
}
// mid(qsizetype pos, qsizetype len) const
void *c_QList_T_QVariant_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QVariant>> { fromPtr<QVariant>(thisObj)->mid(pos, len) };
    return result;
}
// move(qsizetype from, qsizetype to)
void c_QList_T_QVariant_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to)
{
    fromPtr<QVariant>(thisObj)->move(from, to);
}
// pop_back()
void c_QList_T_QVariant_T___pop_back(void *thisObj)
{
    fromPtr<QVariant>(thisObj)->pop_back();
}
// pop_front()
void c_QList_T_QVariant_T___pop_front(void *thisObj)
{
    fromPtr<QVariant>(thisObj)->pop_front();
}
// remove(qsizetype i, qsizetype n)
void c_QList_T_QVariant_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n)
{
    fromPtr<QVariant>(thisObj)->remove(i, n);
}
// removeAt(qsizetype i)
void c_QList_T_QVariant_T___removeAt_qsizetype(void *thisObj, qsizetype i)
{
    fromPtr<QVariant>(thisObj)->removeAt(i);
}
// removeFirst()
void c_QList_T_QVariant_T___removeFirst(void *thisObj)
{
    fromPtr<QVariant>(thisObj)->removeFirst();
}
// removeLast()
void c_QList_T_QVariant_T___removeLast(void *thisObj)
{
    fromPtr<QVariant>(thisObj)->removeLast();
}
// reserve(qsizetype size)
void c_QList_T_QVariant_T___reserve_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<QVariant>(thisObj)->reserve(size);
}
// resize(qsizetype size)
void c_QList_T_QVariant_T___resize_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<QVariant>(thisObj)->resize(size);
}
// shrink_to_fit()
void c_QList_T_QVariant_T___shrink_to_fit(void *thisObj)
{
    fromPtr<QVariant>(thisObj)->shrink_to_fit();
}
// size() const
qsizetype c_QList_T_QVariant_T___size(void *thisObj)
{
    const auto &result = fromPtr<QVariant>(thisObj)->size();
    return result;
}
// sliced(qsizetype pos) const
void *c_QList_T_QVariant_T___sliced_qsizetype(void *thisObj, qsizetype pos)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QVariant>> { fromPtr<QVariant>(thisObj)->sliced(pos) };
    return result;
}
// sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_QVariant_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QVariant>> { fromPtr<QVariant>(thisObj)->sliced(pos, n) };
    return result;
}
// squeeze()
void c_QList_T_QVariant_T___squeeze(void *thisObj)
{
    fromPtr<QVariant>(thisObj)->squeeze();
}
// swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_QVariant_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j)
{
    fromPtr<QVariant>(thisObj)->swapItemsAt(i, j);
}
// takeAt(qsizetype i)
void *c_QList_T_QVariant_T___takeAt_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QVariant>(thisObj)->takeAt(i) };
    return result;
}
// toList() const
void *c_QList_T_QVariant_T___toList(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QVariant>> { fromPtr<QVariant>(thisObj)->toList() };
    return result;
}
// toVector() const
void *c_QList_T_QVariant_T___toVector(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QVariant>> { fromPtr<QVariant>(thisObj)->toVector() };
    return result;
}
// value(qsizetype i) const
void *c_QList_T_QVariant_T___value_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QVariant> { fromPtr<QVariant>(thisObj)->value(i) };
    return result;
}
void c_QList_T_QVariant_T___destructor(void *thisObj)
{
    delete fromPtr<QVariant>(thisObj);
}
}
extern "C" {
void c_QList_T_QString_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::QList_wrapper<QString> *>(cppObj);
}
void *c_QList_T_QString_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<QString>();
    return reinterpret_cast<void *>(ptr);
}
void *c_QList_T_QString_T___constructor_qsizetype(qsizetype size)
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<QString>(size);
    return reinterpret_cast<void *>(ptr);
}
// append(const QList<T > & l)
void c_QList_T_QString_T___append_QList_T(void *thisObj, void *l_)
{
    assert(l_);
    auto &l = *reinterpret_cast<QList<QString> *>(l_);
    fromPtr<QString>(thisObj)->append(l);
}
// at(qsizetype i) const
const void *c_QList_T_QString_T___at_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = new Dartagnan::ValueWrapper<QString> { fromPtr<QString>(thisObj)->at(i) };
    return result;
}
// back()
void *c_QList_T_QString_T___back(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<QString> { fromPtr<QString>(thisObj)->back() };
    return result;
}
// capacity() const
qsizetype c_QList_T_QString_T___capacity(void *thisObj)
{
    const auto &result = fromPtr<QString>(thisObj)->capacity();
    return result;
}
// clear()
void c_QList_T_QString_T___clear(void *thisObj)
{
    fromPtr<QString>(thisObj)->clear();
}
// constFirst() const
const void *c_QList_T_QString_T___constFirst(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QString> { fromPtr<QString>(thisObj)->constFirst() };
    return result;
}
// constLast() const
const void *c_QList_T_QString_T___constLast(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QString> { fromPtr<QString>(thisObj)->constLast() };
    return result;
}
// count() const
qsizetype c_QList_T_QString_T___count(void *thisObj)
{
    const auto &result = fromPtr<QString>(thisObj)->count();
    return result;
}
// detach()
void c_QList_T_QString_T___detach(void *thisObj)
{
    fromPtr<QString>(thisObj)->detach();
}
// empty() const
bool c_QList_T_QString_T___empty(void *thisObj)
{
    const auto &result = fromPtr<QString>(thisObj)->empty();
    return result;
}
// first()
void *c_QList_T_QString_T___first(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QString> { fromPtr<QString>(thisObj)->first() };
    return result;
}
// first(qsizetype n) const
void *c_QList_T_QString_T___first_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QString>> { fromPtr<QString>(thisObj)->first(n) };
    return result;
}
// front()
void *c_QList_T_QString_T___front(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QString> { fromPtr<QString>(thisObj)->front() };
    return result;
}
// isDetached() const
bool c_QList_T_QString_T___isDetached(void *thisObj)
{
    const auto &result = fromPtr<QString>(thisObj)->isDetached();
    return result;
}
// isEmpty() const
bool c_QList_T_QString_T___isEmpty(void *thisObj)
{
    const auto &result = fromPtr<QString>(thisObj)->isEmpty();
    return result;
}
// isSharedWith(const QList<T > & other) const
bool c_QList_T_QString_T___isSharedWith_QList_T(void *thisObj, void *other_)
{
    assert(other_);
    auto &other = *reinterpret_cast<QList<QString> *>(other_);
    const auto &result = fromPtr<QString>(thisObj)->isSharedWith(other);
    return result;
}
// last()
void *c_QList_T_QString_T___last(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<QString> { fromPtr<QString>(thisObj)->last() };
    return result;
}
// last(qsizetype n) const
void *c_QList_T_QString_T___last_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QString>> { fromPtr<QString>(thisObj)->last(n) };
    return result;
}
// length() const
qsizetype c_QList_T_QString_T___length(void *thisObj)
{
    const auto &result = fromPtr<QString>(thisObj)->length();
    return result;
}
// mid(qsizetype pos, qsizetype len) const
void *c_QList_T_QString_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QString>> { fromPtr<QString>(thisObj)->mid(pos, len) };
    return result;
}
// move(qsizetype from, qsizetype to)
void c_QList_T_QString_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to)
{
    fromPtr<QString>(thisObj)->move(from, to);
}
// pop_back()
void c_QList_T_QString_T___pop_back(void *thisObj)
{
    fromPtr<QString>(thisObj)->pop_back();
}
// pop_front()
void c_QList_T_QString_T___pop_front(void *thisObj)
{
    fromPtr<QString>(thisObj)->pop_front();
}
// remove(qsizetype i, qsizetype n)
void c_QList_T_QString_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n)
{
    fromPtr<QString>(thisObj)->remove(i, n);
}
// removeAt(qsizetype i)
void c_QList_T_QString_T___removeAt_qsizetype(void *thisObj, qsizetype i)
{
    fromPtr<QString>(thisObj)->removeAt(i);
}
// removeFirst()
void c_QList_T_QString_T___removeFirst(void *thisObj)
{
    fromPtr<QString>(thisObj)->removeFirst();
}
// removeLast()
void c_QList_T_QString_T___removeLast(void *thisObj)
{
    fromPtr<QString>(thisObj)->removeLast();
}
// reserve(qsizetype size)
void c_QList_T_QString_T___reserve_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<QString>(thisObj)->reserve(size);
}
// resize(qsizetype size)
void c_QList_T_QString_T___resize_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<QString>(thisObj)->resize(size);
}
// shrink_to_fit()
void c_QList_T_QString_T___shrink_to_fit(void *thisObj)
{
    fromPtr<QString>(thisObj)->shrink_to_fit();
}
// size() const
qsizetype c_QList_T_QString_T___size(void *thisObj)
{
    const auto &result = fromPtr<QString>(thisObj)->size();
    return result;
}
// sliced(qsizetype pos) const
void *c_QList_T_QString_T___sliced_qsizetype(void *thisObj, qsizetype pos)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QString>> { fromPtr<QString>(thisObj)->sliced(pos) };
    return result;
}
// sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_QString_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QString>> { fromPtr<QString>(thisObj)->sliced(pos, n) };
    return result;
}
// squeeze()
void c_QList_T_QString_T___squeeze(void *thisObj)
{
    fromPtr<QString>(thisObj)->squeeze();
}
// swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_QString_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j)
{
    fromPtr<QString>(thisObj)->swapItemsAt(i, j);
}
// takeAt(qsizetype i)
void *c_QList_T_QString_T___takeAt_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QString> { fromPtr<QString>(thisObj)->takeAt(i) };
    return result;
}
// toList() const
void *c_QList_T_QString_T___toList(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QString>> { fromPtr<QString>(thisObj)->toList() };
    return result;
}
// toVector() const
void *c_QList_T_QString_T___toVector(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QString>> { fromPtr<QString>(thisObj)->toVector() };
    return result;
}
// value(qsizetype i) const
void *c_QList_T_QString_T___value_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QString> { fromPtr<QString>(thisObj)->value(i) };
    return result;
}
void c_QList_T_QString_T___destructor(void *thisObj)
{
    delete fromPtr<QString>(thisObj);
}
}
extern "C" {
void c_QList_T_unsigned_int_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::QList_wrapper<unsigned int> *>(cppObj);
}
void *c_QList_T_unsigned_int_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<unsigned int>();
    return reinterpret_cast<void *>(ptr);
}
void *c_QList_T_unsigned_int_T___constructor_qsizetype(qsizetype size)
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<unsigned int>(size);
    return reinterpret_cast<void *>(ptr);
}
// append(const QList<T > & l)
void c_QList_T_unsigned_int_T___append_QList_T(void *thisObj, void *l_)
{
    assert(l_);
    auto &l = *reinterpret_cast<QList<unsigned int> *>(l_);
    fromPtr<unsigned int>(thisObj)->append(l);
}
// at(qsizetype i) const
const unsigned int c_QList_T_unsigned_int_T___at_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->at(i);
    return result;
}
// back()
unsigned int c_QList_T_unsigned_int_T___back(void *thisObj)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->back();
    return result;
}
// capacity() const
qsizetype c_QList_T_unsigned_int_T___capacity(void *thisObj)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->capacity();
    return result;
}
// clear()
void c_QList_T_unsigned_int_T___clear(void *thisObj)
{
    fromPtr<unsigned int>(thisObj)->clear();
}
// constFirst() const
const unsigned int c_QList_T_unsigned_int_T___constFirst(void *thisObj)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->constFirst();
    return result;
}
// constLast() const
const unsigned int c_QList_T_unsigned_int_T___constLast(void *thisObj)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->constLast();
    return result;
}
// count() const
qsizetype c_QList_T_unsigned_int_T___count(void *thisObj)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->count();
    return result;
}
// detach()
void c_QList_T_unsigned_int_T___detach(void *thisObj)
{
    fromPtr<unsigned int>(thisObj)->detach();
}
// empty() const
bool c_QList_T_unsigned_int_T___empty(void *thisObj)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->empty();
    return result;
}
// first()
unsigned int c_QList_T_unsigned_int_T___first(void *thisObj)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->first();
    return result;
}
// first(qsizetype n) const
void *c_QList_T_unsigned_int_T___first_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<unsigned int>> {
        fromPtr<unsigned int>(thisObj)->first(n)
    };
    return result;
}
// front()
unsigned int c_QList_T_unsigned_int_T___front(void *thisObj)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->front();
    return result;
}
// isDetached() const
bool c_QList_T_unsigned_int_T___isDetached(void *thisObj)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->isDetached();
    return result;
}
// isEmpty() const
bool c_QList_T_unsigned_int_T___isEmpty(void *thisObj)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->isEmpty();
    return result;
}
// isSharedWith(const QList<T > & other) const
bool c_QList_T_unsigned_int_T___isSharedWith_QList_T(void *thisObj, void *other_)
{
    assert(other_);
    auto &other = *reinterpret_cast<QList<unsigned int> *>(other_);
    const auto &result = fromPtr<unsigned int>(thisObj)->isSharedWith(other);
    return result;
}
// last()
unsigned int c_QList_T_unsigned_int_T___last(void *thisObj)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->last();
    return result;
}
// last(qsizetype n) const
void *c_QList_T_unsigned_int_T___last_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<unsigned int>> {
        fromPtr<unsigned int>(thisObj)->last(n)
    };
    return result;
}
// length() const
qsizetype c_QList_T_unsigned_int_T___length(void *thisObj)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->length();
    return result;
}
// mid(qsizetype pos, qsizetype len) const
void *c_QList_T_unsigned_int_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos,
                                                         qsizetype len)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<unsigned int>> {
        fromPtr<unsigned int>(thisObj)->mid(pos, len)
    };
    return result;
}
// move(qsizetype from, qsizetype to)
void c_QList_T_unsigned_int_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from,
                                                         qsizetype to)
{
    fromPtr<unsigned int>(thisObj)->move(from, to);
}
// pop_back()
void c_QList_T_unsigned_int_T___pop_back(void *thisObj)
{
    fromPtr<unsigned int>(thisObj)->pop_back();
}
// pop_front()
void c_QList_T_unsigned_int_T___pop_front(void *thisObj)
{
    fromPtr<unsigned int>(thisObj)->pop_front();
}
// remove(qsizetype i, qsizetype n)
void c_QList_T_unsigned_int_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n)
{
    fromPtr<unsigned int>(thisObj)->remove(i, n);
}
// removeAt(qsizetype i)
void c_QList_T_unsigned_int_T___removeAt_qsizetype(void *thisObj, qsizetype i)
{
    fromPtr<unsigned int>(thisObj)->removeAt(i);
}
// removeFirst()
void c_QList_T_unsigned_int_T___removeFirst(void *thisObj)
{
    fromPtr<unsigned int>(thisObj)->removeFirst();
}
// removeLast()
void c_QList_T_unsigned_int_T___removeLast(void *thisObj)
{
    fromPtr<unsigned int>(thisObj)->removeLast();
}
// reserve(qsizetype size)
void c_QList_T_unsigned_int_T___reserve_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<unsigned int>(thisObj)->reserve(size);
}
// resize(qsizetype size)
void c_QList_T_unsigned_int_T___resize_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<unsigned int>(thisObj)->resize(size);
}
// shrink_to_fit()
void c_QList_T_unsigned_int_T___shrink_to_fit(void *thisObj)
{
    fromPtr<unsigned int>(thisObj)->shrink_to_fit();
}
// size() const
qsizetype c_QList_T_unsigned_int_T___size(void *thisObj)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->size();
    return result;
}
// sliced(qsizetype pos) const
void *c_QList_T_unsigned_int_T___sliced_qsizetype(void *thisObj, qsizetype pos)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<unsigned int>> {
        fromPtr<unsigned int>(thisObj)->sliced(pos)
    };
    return result;
}
// sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_unsigned_int_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos,
                                                            qsizetype n)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<unsigned int>> {
        fromPtr<unsigned int>(thisObj)->sliced(pos, n)
    };
    return result;
}
// squeeze()
void c_QList_T_unsigned_int_T___squeeze(void *thisObj)
{
    fromPtr<unsigned int>(thisObj)->squeeze();
}
// swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_unsigned_int_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i,
                                                                qsizetype j)
{
    fromPtr<unsigned int>(thisObj)->swapItemsAt(i, j);
}
// takeAt(qsizetype i)
unsigned int c_QList_T_unsigned_int_T___takeAt_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->takeAt(i);
    return result;
}
// toList() const
void *c_QList_T_unsigned_int_T___toList(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<unsigned int>> {
        fromPtr<unsigned int>(thisObj)->toList()
    };
    return result;
}
// toVector() const
void *c_QList_T_unsigned_int_T___toVector(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<unsigned int>> {
        fromPtr<unsigned int>(thisObj)->toVector()
    };
    return result;
}
// value(qsizetype i) const
unsigned int c_QList_T_unsigned_int_T___value_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<unsigned int>(thisObj)->value(i);
    return result;
}
void c_QList_T_unsigned_int_T___destructor(void *thisObj)
{
    delete fromPtr<unsigned int>(thisObj);
}
}
extern "C" {
void c_QList_T_QObject_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::QList_wrapper<QObject *> *>(cppObj);
}
void *c_QList_T_QObject_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<QObject *>();
    return reinterpret_cast<void *>(ptr);
}
void *c_QList_T_QObject_T___constructor_qsizetype(qsizetype size)
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<QObject *>(size);
    return reinterpret_cast<void *>(ptr);
}
// append(const QList<T > & l)
void c_QList_T_QObject_T___append_QList_T(void *thisObj, void *l_)
{
    assert(l_);
    auto &l = *reinterpret_cast<QList<QObject *> *>(l_);
    fromPtr<QObject *>(thisObj)->append(l);
}
// at(qsizetype i) const
const void *c_QList_T_QObject_T___at_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<QObject *>(thisObj)->at(i);
    return result;
}
// back()
void *c_QList_T_QObject_T___back(void *thisObj)
{
    const auto &result = fromPtr<QObject *>(thisObj)->back();
    return result;
}
// capacity() const
qsizetype c_QList_T_QObject_T___capacity(void *thisObj)
{
    const auto &result = fromPtr<QObject *>(thisObj)->capacity();
    return result;
}
// clear()
void c_QList_T_QObject_T___clear(void *thisObj)
{
    fromPtr<QObject *>(thisObj)->clear();
}
// constFirst() const
const void *c_QList_T_QObject_T___constFirst(void *thisObj)
{
    const auto &result = fromPtr<QObject *>(thisObj)->constFirst();
    return result;
}
// constLast() const
const void *c_QList_T_QObject_T___constLast(void *thisObj)
{
    const auto &result = fromPtr<QObject *>(thisObj)->constLast();
    return result;
}
// count() const
qsizetype c_QList_T_QObject_T___count(void *thisObj)
{
    const auto &result = fromPtr<QObject *>(thisObj)->count();
    return result;
}
// detach()
void c_QList_T_QObject_T___detach(void *thisObj)
{
    fromPtr<QObject *>(thisObj)->detach();
}
// empty() const
bool c_QList_T_QObject_T___empty(void *thisObj)
{
    const auto &result = fromPtr<QObject *>(thisObj)->empty();
    return result;
}
// first()
void *c_QList_T_QObject_T___first(void *thisObj)
{
    const auto &result = fromPtr<QObject *>(thisObj)->first();
    return result;
}
// first(qsizetype n) const
void *c_QList_T_QObject_T___first_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QObject *>> { fromPtr<QObject *>(thisObj)->first(n) };
    return result;
}
// front()
void *c_QList_T_QObject_T___front(void *thisObj)
{
    const auto &result = fromPtr<QObject *>(thisObj)->front();
    return result;
}
// isDetached() const
bool c_QList_T_QObject_T___isDetached(void *thisObj)
{
    const auto &result = fromPtr<QObject *>(thisObj)->isDetached();
    return result;
}
// isEmpty() const
bool c_QList_T_QObject_T___isEmpty(void *thisObj)
{
    const auto &result = fromPtr<QObject *>(thisObj)->isEmpty();
    return result;
}
// isSharedWith(const QList<T > & other) const
bool c_QList_T_QObject_T___isSharedWith_QList_T(void *thisObj, void *other_)
{
    assert(other_);
    auto &other = *reinterpret_cast<QList<QObject *> *>(other_);
    const auto &result = fromPtr<QObject *>(thisObj)->isSharedWith(other);
    return result;
}
// last()
void *c_QList_T_QObject_T___last(void *thisObj)
{
    const auto &result = fromPtr<QObject *>(thisObj)->last();
    return result;
}
// last(qsizetype n) const
void *c_QList_T_QObject_T___last_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QObject *>> { fromPtr<QObject *>(thisObj)->last(n) };
    return result;
}
// length() const
qsizetype c_QList_T_QObject_T___length(void *thisObj)
{
    const auto &result = fromPtr<QObject *>(thisObj)->length();
    return result;
}
// mid(qsizetype pos, qsizetype len) const
void *c_QList_T_QObject_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QObject *>> { fromPtr<QObject *>(thisObj)->mid(pos,
                                                                                         len) };
    return result;
}
// move(qsizetype from, qsizetype to)
void c_QList_T_QObject_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to)
{
    fromPtr<QObject *>(thisObj)->move(from, to);
}
// pop_back()
void c_QList_T_QObject_T___pop_back(void *thisObj)
{
    fromPtr<QObject *>(thisObj)->pop_back();
}
// pop_front()
void c_QList_T_QObject_T___pop_front(void *thisObj)
{
    fromPtr<QObject *>(thisObj)->pop_front();
}
// remove(qsizetype i, qsizetype n)
void c_QList_T_QObject_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n)
{
    fromPtr<QObject *>(thisObj)->remove(i, n);
}
// removeAt(qsizetype i)
void c_QList_T_QObject_T___removeAt_qsizetype(void *thisObj, qsizetype i)
{
    fromPtr<QObject *>(thisObj)->removeAt(i);
}
// removeFirst()
void c_QList_T_QObject_T___removeFirst(void *thisObj)
{
    fromPtr<QObject *>(thisObj)->removeFirst();
}
// removeLast()
void c_QList_T_QObject_T___removeLast(void *thisObj)
{
    fromPtr<QObject *>(thisObj)->removeLast();
}
// reserve(qsizetype size)
void c_QList_T_QObject_T___reserve_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<QObject *>(thisObj)->reserve(size);
}
// resize(qsizetype size)
void c_QList_T_QObject_T___resize_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<QObject *>(thisObj)->resize(size);
}
// shrink_to_fit()
void c_QList_T_QObject_T___shrink_to_fit(void *thisObj)
{
    fromPtr<QObject *>(thisObj)->shrink_to_fit();
}
// size() const
qsizetype c_QList_T_QObject_T___size(void *thisObj)
{
    const auto &result = fromPtr<QObject *>(thisObj)->size();
    return result;
}
// sliced(qsizetype pos) const
void *c_QList_T_QObject_T___sliced_qsizetype(void *thisObj, qsizetype pos)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QObject *>> { fromPtr<QObject *>(thisObj)->sliced(pos) };
    return result;
}
// sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_QObject_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QObject *>> { fromPtr<QObject *>(thisObj)->sliced(pos,
                                                                                            n) };
    return result;
}
// squeeze()
void c_QList_T_QObject_T___squeeze(void *thisObj)
{
    fromPtr<QObject *>(thisObj)->squeeze();
}
// swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_QObject_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j)
{
    fromPtr<QObject *>(thisObj)->swapItemsAt(i, j);
}
// takeAt(qsizetype i)
void *c_QList_T_QObject_T___takeAt_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<QObject *>(thisObj)->takeAt(i);
    return result;
}
// toList() const
void *c_QList_T_QObject_T___toList(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QObject *>> { fromPtr<QObject *>(thisObj)->toList() };
    return result;
}
// toVector() const
void *c_QList_T_QObject_T___toVector(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QObject *>> { fromPtr<QObject *>(thisObj)->toVector() };
    return result;
}
// value(qsizetype i) const
void *c_QList_T_QObject_T___value_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result = fromPtr<QObject *>(thisObj)->value(i);
    return result;
}
void c_QList_T_QObject_T___destructor(void *thisObj)
{
    delete fromPtr<QObject *>(thisObj);
}
}
extern "C" {
void c_QList_T_QByteArray_T__Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::QList_wrapper<QByteArray> *>(cppObj);
}
void *c_QList_T_QByteArray_T___constructor()
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<QByteArray>();
    return reinterpret_cast<void *>(ptr);
}
void *c_QList_T_QByteArray_T___constructor_qsizetype(qsizetype size)
{
    auto ptr = new TestBindings_wrappersNS::QList_wrapper<QByteArray>(size);
    return reinterpret_cast<void *>(ptr);
}
// append(const QList<T > & l)
void c_QList_T_QByteArray_T___append_QList_T(void *thisObj, void *l_)
{
    assert(l_);
    auto &l = *reinterpret_cast<QList<QByteArray> *>(l_);
    fromPtr<QByteArray>(thisObj)->append(l);
}
// at(qsizetype i) const
const void *c_QList_T_QByteArray_T___at_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QByteArray> { fromPtr<QByteArray>(thisObj)->at(i) };
    return result;
}
// back()
void *c_QList_T_QByteArray_T___back(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QByteArray> { fromPtr<QByteArray>(thisObj)->back() };
    return result;
}
// capacity() const
qsizetype c_QList_T_QByteArray_T___capacity(void *thisObj)
{
    const auto &result = fromPtr<QByteArray>(thisObj)->capacity();
    return result;
}
// clear()
void c_QList_T_QByteArray_T___clear(void *thisObj)
{
    fromPtr<QByteArray>(thisObj)->clear();
}
// constFirst() const
const void *c_QList_T_QByteArray_T___constFirst(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QByteArray> { fromPtr<QByteArray>(thisObj)->constFirst() };
    return result;
}
// constLast() const
const void *c_QList_T_QByteArray_T___constLast(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QByteArray> { fromPtr<QByteArray>(thisObj)->constLast() };
    return result;
}
// count() const
qsizetype c_QList_T_QByteArray_T___count(void *thisObj)
{
    const auto &result = fromPtr<QByteArray>(thisObj)->count();
    return result;
}
// detach()
void c_QList_T_QByteArray_T___detach(void *thisObj)
{
    fromPtr<QByteArray>(thisObj)->detach();
}
// empty() const
bool c_QList_T_QByteArray_T___empty(void *thisObj)
{
    const auto &result = fromPtr<QByteArray>(thisObj)->empty();
    return result;
}
// first()
void *c_QList_T_QByteArray_T___first(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QByteArray> { fromPtr<QByteArray>(thisObj)->first() };
    return result;
}
// first(qsizetype n) const
void *c_QList_T_QByteArray_T___first_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QByteArray>> { fromPtr<QByteArray>(thisObj)->first(n) };
    return result;
}
// front()
void *c_QList_T_QByteArray_T___front(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QByteArray> { fromPtr<QByteArray>(thisObj)->front() };
    return result;
}
// isDetached() const
bool c_QList_T_QByteArray_T___isDetached(void *thisObj)
{
    const auto &result = fromPtr<QByteArray>(thisObj)->isDetached();
    return result;
}
// isEmpty() const
bool c_QList_T_QByteArray_T___isEmpty(void *thisObj)
{
    const auto &result = fromPtr<QByteArray>(thisObj)->isEmpty();
    return result;
}
// isSharedWith(const QList<T > & other) const
bool c_QList_T_QByteArray_T___isSharedWith_QList_T(void *thisObj, void *other_)
{
    assert(other_);
    auto &other = *reinterpret_cast<QList<QByteArray> *>(other_);
    const auto &result = fromPtr<QByteArray>(thisObj)->isSharedWith(other);
    return result;
}
// last()
void *c_QList_T_QByteArray_T___last(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QByteArray> { fromPtr<QByteArray>(thisObj)->last() };
    return result;
}
// last(qsizetype n) const
void *c_QList_T_QByteArray_T___last_qsizetype(void *thisObj, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QByteArray>> { fromPtr<QByteArray>(thisObj)->last(n) };
    return result;
}
// length() const
qsizetype c_QList_T_QByteArray_T___length(void *thisObj)
{
    const auto &result = fromPtr<QByteArray>(thisObj)->length();
    return result;
}
// mid(qsizetype pos, qsizetype len) const
void *c_QList_T_QByteArray_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QByteArray>> { fromPtr<QByteArray>(thisObj)->mid(pos,
                                                                                           len) };
    return result;
}
// move(qsizetype from, qsizetype to)
void c_QList_T_QByteArray_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to)
{
    fromPtr<QByteArray>(thisObj)->move(from, to);
}
// pop_back()
void c_QList_T_QByteArray_T___pop_back(void *thisObj)
{
    fromPtr<QByteArray>(thisObj)->pop_back();
}
// pop_front()
void c_QList_T_QByteArray_T___pop_front(void *thisObj)
{
    fromPtr<QByteArray>(thisObj)->pop_front();
}
// remove(qsizetype i, qsizetype n)
void c_QList_T_QByteArray_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n)
{
    fromPtr<QByteArray>(thisObj)->remove(i, n);
}
// removeAt(qsizetype i)
void c_QList_T_QByteArray_T___removeAt_qsizetype(void *thisObj, qsizetype i)
{
    fromPtr<QByteArray>(thisObj)->removeAt(i);
}
// removeFirst()
void c_QList_T_QByteArray_T___removeFirst(void *thisObj)
{
    fromPtr<QByteArray>(thisObj)->removeFirst();
}
// removeLast()
void c_QList_T_QByteArray_T___removeLast(void *thisObj)
{
    fromPtr<QByteArray>(thisObj)->removeLast();
}
// reserve(qsizetype size)
void c_QList_T_QByteArray_T___reserve_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<QByteArray>(thisObj)->reserve(size);
}
// resize(qsizetype size)
void c_QList_T_QByteArray_T___resize_qsizetype(void *thisObj, qsizetype size)
{
    fromPtr<QByteArray>(thisObj)->resize(size);
}
// shrink_to_fit()
void c_QList_T_QByteArray_T___shrink_to_fit(void *thisObj)
{
    fromPtr<QByteArray>(thisObj)->shrink_to_fit();
}
// size() const
qsizetype c_QList_T_QByteArray_T___size(void *thisObj)
{
    const auto &result = fromPtr<QByteArray>(thisObj)->size();
    return result;
}
// sliced(qsizetype pos) const
void *c_QList_T_QByteArray_T___sliced_qsizetype(void *thisObj, qsizetype pos)
{
    const auto &result = new Dartagnan::ValueWrapper<QList<QByteArray>> {
        fromPtr<QByteArray>(thisObj)->sliced(pos)
    };
    return result;
}
// sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_QByteArray_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QByteArray>> { fromPtr<QByteArray>(thisObj)->sliced(pos,
                                                                                              n) };
    return result;
}
// squeeze()
void c_QList_T_QByteArray_T___squeeze(void *thisObj)
{
    fromPtr<QByteArray>(thisObj)->squeeze();
}
// swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_QByteArray_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i,
                                                              qsizetype j)
{
    fromPtr<QByteArray>(thisObj)->swapItemsAt(i, j);
}
// takeAt(qsizetype i)
void *c_QList_T_QByteArray_T___takeAt_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QByteArray> { fromPtr<QByteArray>(thisObj)->takeAt(i) };
    return result;
}
// toList() const
void *c_QList_T_QByteArray_T___toList(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QByteArray>> { fromPtr<QByteArray>(thisObj)->toList() };
    return result;
}
// toVector() const
void *c_QList_T_QByteArray_T___toVector(void *thisObj)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QList<QByteArray>> { fromPtr<QByteArray>(thisObj)->toVector() };
    return result;
}
// value(qsizetype i) const
void *c_QList_T_QByteArray_T___value_qsizetype(void *thisObj, qsizetype i)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QByteArray> { fromPtr<QByteArray>(thisObj)->value(i) };
    return result;
}
void c_QList_T_QByteArray_T___destructor(void *thisObj)
{
    delete fromPtr<QByteArray>(thisObj);
}
}

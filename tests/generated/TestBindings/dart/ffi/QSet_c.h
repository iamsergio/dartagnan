#include "TestBindings_exports.h"
#include <qlist.h>
#include <qset.h>

namespace TestBindings_wrappersNS {
template<typename T>
class QSet_wrapper : public ::QSet<T>
{
public:
    ~QSet_wrapper();
    QSet_wrapper();
    qsizetype capacity() const;
    void clear();
    bool contains(const QSet<T> &set) const;
    qsizetype count() const;
    void detach();
    bool empty() const;
    QSet<T> &intersect(const QSet<T> &other);
    bool intersects(const QSet<T> &other) const;
    bool isDetached() const;
    bool isEmpty() const;
    void reserve(qsizetype size);
    qsizetype size() const;
    void squeeze();
    QSet<T> &subtract(const QSet<T> &other);
    QSet<T> &unite(const QSet<T> &other);
    QList<T> values() const;
};
}
// @snippet qvariant-fromObject

/** static*/
QVariant QVariant_wrapper::fromObject(QObject *obj)
{
    return QVariant::fromValue<QObject *>(obj);
}

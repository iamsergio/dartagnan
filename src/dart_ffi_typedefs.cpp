/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "dart_ffi_typedefs.h"
#include "type_conversions/to_dart.h"

#include <QDebug>

FFITypedefs::FFITypedefs()
{
    m_typedefs << "// tag=1053\n";
    m_typedefs << "typedef void_Func_voidstar = void Function(ffi.Pointer<void>);";
    m_typedefs << "typedef void_Func_voidstar_FFI = ffi.Void Function(ffi.Pointer<void>);";

    m_typedefs << "typedef RegisterMethodIsReimplementedCallback = void "
                  "Function(ffi.Pointer<void>, ffi.Pointer<void>, int);";
    m_typedefs << "typedef RegisterMethodIsReimplementedCallback_FFI = ffi.Void "
                  "Function(ffi.Pointer<void>, ffi.Pointer<void>, ffi.Int32);";

    m_typedefs << "typedef SignalHandler = void Function(ffi.Pointer<void>, ffi.Pointer<void>, "
                  "ffi.Pointer<void>);";
    m_typedefs << "typedef SignalHandler_FFI = ffi.Void Function(ffi.Pointer<void>, "
                  "ffi.Pointer<void>, ffi.Pointer<void>);";
}

const QStringList FFITypedefs::typedefs() const
{
    return m_typedefs;
}

FFITypedefs &FFITypedefs::instance()
{
    static FFITypedefs s_instance;
    return s_instance;
}

void FFITypedefs::addDartFunctionTypedef(const AbstractMetaFunction *func)
{
    const AbstractMetaTypeList templateInstantiations = Dartagnan::instantiationsForFunction(func);

    if (templateInstantiations.isEmpty() && !Dartagnan::hasTemplateArguments(func)) {
        addDartFunctionTypedef(func, {});
    } else {
        for (AbstractMetaType templateInstantiation : templateInstantiations) {
            addDartFunctionTypedef(func, templateInstantiation);
        }
    }
}

void FFITypedefs::addDartFunctionTypedef(const AbstractMetaFunction *func,
                                         AbstractMetaType templateInstantiation)
{
    const QString typedefstr = functionTypedef(func, templateInstantiation);
    if (m_typedefs.contains(typedefstr))
        return;

    m_typedefs << typedefstr;
    m_typedefs << ffiFunctionTypedef(func, templateInstantiation);
}

QString FFITypedefs::functionTypedef(const AbstractMetaFunction *func,
                                     AbstractMetaType templateInstantiation) const
{
    const QString returnType =
        ToDartConversions::type(func, ToDartConversions::Option::ForTypedef, templateInstantiation);
    const AbstractMetaArgumentList arguments = func->arguments();
    QStringList memberTypes;
    if (!func->isStatic() && !func->isConstructor())
        memberTypes << "ffi.Pointer<void>"; // 'this' pointer

    for (AbstractMetaArgument argument : arguments) {
        AbstractMetaType actualType = Dartagnan::actualType(argument.type(), templateInstantiation);
        memberTypes << ToDartConversions::type(
            actualType,
            ToDartConversions::Options(ToDartConversions::Option::NoBool)
                | ToDartConversions::Option::ForTypedef);
    }

    return QStringLiteral("typedef %1 = %2 Function(%3);")
        .arg(typedefName(func, templateInstantiation), returnType, memberTypes.join(","));
}

QString FFITypedefs::ffiFunctionTypedef(const AbstractMetaFunction *func,
                                        AbstractMetaType templateInstantiation) const
{
    const QString returnTypeFFI = ToDartConversions::typeForFFI(func, templateInstantiation);
    if (returnTypeFFI.isEmpty()) {
        qWarning() << Q_FUNC_INFO << "Failed to get type for function" << func->name();
        return {};
    }

    QStringList memberTypesFFI;
    if (!func->isStatic() && !func->isConstructor())
        memberTypesFFI << "ffi.Pointer<void>"; // 'this' pointer

    const AbstractMetaArgumentList arguments = func->arguments();
    for (AbstractMetaArgument argument : arguments)
        memberTypesFFI << ToDartConversions::typeForFFI(argument.type(), templateInstantiation);


    return QStringLiteral("typedef %1 = %2 Function(%3);")
        .arg(ToDartConversions::mangle(ffiTypedefName(func, templateInstantiation)), returnTypeFFI,
             memberTypesFFI.join(","));
}

QString FFITypedefs::typedefName(const AbstractMetaFunction *method,
                                 AbstractMetaType templateInstantiation)
{
    const QString returnType =
        ToDartConversions::type(method,
                                ToDartConversions::Options(ToDartConversions::Option::ForTypedef)
                                    | ToDartConversions::Option::ForTypedefName,
                                templateInstantiation);

    QStringList memberTypes;
    if (!method->isStatic() && !method->isConstructor() && method->ownerClass()) {
        // When calling a method we need to pass 'this'
        memberTypes << "ffi.Pointer<void>";
    }

    const AbstractMetaArgumentList arguments = method->arguments();
    for (AbstractMetaArgument argument : arguments) {

        AbstractMetaType actualType = Dartagnan::actualType(argument.type(), templateInstantiation);
        memberTypes << ToDartConversions::type(
            actualType,
            ToDartConversions::Options(ToDartConversions::Option::ForTypedef)
                | ToDartConversions::Option::ForTypedefName);
    }

    const QString memberTypesTypedef =
        memberTypes.isEmpty() ? QString("void") : memberTypes.join("_");

    return QStringLiteral("%1_Func_%2")
        .arg(ToDartConversions::mangle(returnType), ToDartConversions::mangle(memberTypesTypedef));
}

QString FFITypedefs::ffiTypedefName(const AbstractMetaFunction *func,
                                    AbstractMetaType templateInstantiation)
{
    const QString returnType =
        ToDartConversions::type(func,
                                ToDartConversions::Options(ToDartConversions::Option::ForTypedef)
                                    | ToDartConversions::Option::ForTypedefName,
                                templateInstantiation);

    QStringList memberTypesFFI;
    if (!func->isStatic() && !func->isConstructor() && func->ownerClass())
        memberTypesFFI << "voidstar"; // 'this' is the first argument for members

    const AbstractMetaArgumentList arguments = func->arguments();
    for (AbstractMetaArgument argument : arguments) {
        memberTypesFFI << ToDartConversions::typeForFFI(argument.type(), templateInstantiation);
    }

    const QString memberTypesTypedefFFI =
        memberTypesFFI.isEmpty() ? QString("void") : memberTypesFFI.join("_");

    return ToDartConversions::mangle(
        QStringLiteral("%1_Func_%2_FFI").arg(returnType, memberTypesTypedefFFI));
}

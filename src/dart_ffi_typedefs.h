/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#include "dartagnan.h"

/// @brief Class to help generate the TypeHelpers.dart, which has a list of FFI function typedefs
class FFITypedefs
{
public:
    /// @brief It's a singleton
    static FFITypedefs &instance();

    /// @brief Adds the needed FFI typedefs for the specified method

    void addDartFunctionTypedef(const AbstractMetaFunction *func);

    void addDartFunctionTypedef(const AbstractMetaFunction *func,
                                AbstractMetaType templateInstantiation);

    /**
     *  @brief returns the list of typefefs that should go into TypeHelpers.dart
     * Example:
     *     "typedef int_Func_void = int Function();"
     *     "typedef int_Func_void_FFI = ffi.Int32 Function();"
     */
    const QStringList typedefs() const;

    /// Returns the name portion of the typedef
    /// If the typedef was "typedef A = B" this function would return: A
    static QString typedefName(const AbstractMetaFunction *,
                               AbstractMetaType templateInstantiation);

    /// Like typedefName() but with FFI types
    static QString ffiTypedefName(const AbstractMetaFunction *method,
                                  AbstractMetaType templateInstantiation);

private:
    FFITypedefs();

    /// Returns the complete typedef
    QString functionTypedef(const AbstractMetaFunction *func,
                            AbstractMetaType templateInstantiation) const;

    /// Returns the complete ffi typedef
    QString ffiFunctionTypedef(const AbstractMetaFunction *func,
                               AbstractMetaType templateInstantiation) const;

    /// @brief list of typedefs to dump into our TypeHelpers.dart file
    QStringList m_typedefs;
};

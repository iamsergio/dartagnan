/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#include "dartagnan.h"

namespace ToCConversions {

///@brief Returns a string representation of the specified type, in a manner suitable for C
/// Mostly means class pointers are void*
QString type(AbstractMetaType type);

///@brief Returns the type that the C function should return
/// Mostly means the C function that represents the C++ ctor should return void*
/// and the dtor should return void
QString functionReturnType(const AbstractMetaFunction *func,
                           const AbstractMetaType templateInstantiation);

/**
 * @brief Return's the function's name in C. This also correspondos to its mangled name in dll/so
 * This is the name of the wrapper function (with extern "C") which will call the real C++.
 *
 * For example, for a static function in a class named POD, in namespace TestTargetNS, it would be
 * "c_TestTargetNS__POD__calculateStatic"
 */
QString functionName(const AbstractMetaFunction *func, const AbstractMetaType instantiation = {},
                     Dartagnan::FunctionFormatOptions = {});

///@brief Returns the C function signature that dart will call
QString functionSignature(const AbstractMetaFunction *func, Dartagnan::FunctionFormatOptions = {},
                          AbstractMetaType instantiation = {});

QString membersText(const AbstractMetaFunction *func,
                    Dartagnan::FunctionFormatOptions formatOpts = {},
                    const AbstractMetaType instantiation = {});

QString membersTextEscaped(const AbstractMetaFunction *func);
QString argumentTypesForSignature(const AbstractMetaFunction *func,
                                  const AbstractMetaType instantiation);
QString registerCallbackFunctionsName(const AbstractMetaClass *metaClass);
QString registerCallbackFunctionSignature(const AbstractMetaClass *metaClass,
                                          Dartagnan::FunctionFormatOptions = {});

QString finalizerName(const AbstractMetaClass *metaClass, const AbstractMetaType instantiation);
QString finalizerSignature(const AbstractMetaClass *metaClass,
                           Dartagnan::FunctionFormatOptions = {},
                           const AbstractMetaType instantiation = {});

/**
 * @brief Returns the dtor's name in C. Example:
 * "void c_TestTargetNS__MyBaseClass__destructor(void *);"
 */
QString dtorFunctionName(const AbstractMetaClass *record, const AbstractMetaType instantiation);

QString argumentCasts(const AbstractMetaFunction *func, Dartagnan::FunctionFormatOptions,
                      AbstractMetaType instantiation);

/**
 * @brief Returns whether the type is primitive and const, examples:
 * "const int"
 * "const int &"
 */
bool typeIsPrimitiveConst(AbstractMetaType type);

/**
 * Returns the string representation of the template arguments, suitable for using in a
 * ffi function name.
 *
 * Example Foo<int, double> would return "int_double"
 *
 */
QString templateArgs(AbstractMetaType type);

QString qualifiedClassName(const AbstractMetaClass *,
                           const AbstractMetaType templateInstantiation = {});

/// @brief Returns whether the specified method returns a bool
bool methodReturnsBool(const AbstractMetaFunction *method, AbstractMetaType templateInstantiation);

/// @brief "const T *"
bool templateArgumentIsPointer(AbstractMetaType type);

} // namespace ToCConversions

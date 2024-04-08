/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#include "dartagnan.h"

namespace ToCppWrapperConversions {

enum class Option
{
    None = 0,
    ForVirtualCallbackReturnType = 1
};
Q_DECLARE_FLAGS(Options, Option);

/// @brief Returns the C++ return type for @p func
QString returnType(const AbstractMetaFunction *func, AbstractMetaType templateInstantiation = {},
                   Options = {});

/// @brief Returns the C++ type for @p func
QString type(const AbstractMetaFunction *func);
QString type(AbstractMetaType type, AbstractMetaType templateInstantiation = {},
             const AbstractMetaClass *protecedEnumWorkaroundFor = nullptr, Options = {});

/// @brief Returns a string representation of the functions members
/// For example "int width, int height"
QString arguments(const AbstractMetaFunction *func, Dartagnan::FunctionFormatOptions = {},
                  Options = {});

///@brief Returns the string representation of the arguments to be passed during a C++ call to @p
/// func For example, if func is resize(width, height), the result would be: "width, height"
///@sa cCallArguments()
QString callArguments(const AbstractMetaFunction *func, Dartagnan::GeneratedCodeType,
                      AbstractMetaType instantiation);

QString wrapperClassName(const AbstractMetaClass *, Dartagnan::FunctionFormatOptions = {},
                         AbstractMetaType instantiation = {});

QString qualifiedWrapperMethodName(const AbstractMetaFunction *,
                                   Dartagnan::FunctionFormatOptions formatOpts,
                                   AbstractMetaType instantiation);

/**
 * @brief Returns the name of the wrapper C++ class.
 * For example, if the target is QWidget, the return is "QWidget_wrapper"
 */
QString wrapperName(const AbstractMetaClass *, Dartagnan::FunctionFormatOptions = {});
QString wrapperMethodName(const AbstractMetaFunction *func);

QString wrappersNamespace();

/// @brief Returns a C++ function pointer representation in string
QString virtualCallbackFunctionPointer(const AbstractMetaFunction *func, const QString &name);

QString virtualCallbackMemberName(const AbstractMetaFunction *);
QString virtualCallbackTypedefName(const AbstractMetaFunction *);

/// Returns, for example "template <typename T>", if the specied class is a template.
/// Empty if no template arguments
QString templateString(const AbstractMetaClass *);

/// Returns, for example "<T>", if the specied class is a template with one argument
/// Empty if no template arguments
QString templateArgs(const AbstractMetaClass *);

/// Returns the template params, for example "<int>"
QString templateParams(AbstractMetaType type);

QString qualifiedClassName(const AbstractMetaClass *, Dartagnan::FunctionFormatOptions formatOpts);

/// @brief Returns whether the type is a class/struct and is not a pointer
bool isValueClass(AbstractMetaType type);


} // namespace ToCppWrapperConversions

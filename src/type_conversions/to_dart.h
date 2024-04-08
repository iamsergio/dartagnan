/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#include "dartagnan.h"

namespace ToDartConversions {

enum class Option {
    None = 0,
    ForTypedef = 1,
    ForTypedefName = 2,
    NoBool = 4,
    NoClasses = 8,
    StringInsteadOfQString = 16,
    ReplaceReservedDartKeyword = 32 /// For example, we don't want arguments named 'var'
};
Q_DECLARE_FLAGS(Options, Option);

/**
 * @brief Returns the type suitable for an FFI typedef which @p func returns
 *
 * For example:
 * if fun returns "qreal", this returns "double"
 * bool -> int
 * pointer -> ffi.Pointer<void>
 * etc
 */
QString typeForFFI(const AbstractMetaFunction *func, AbstractMetaType templateInstantiation);

///@overload
QString typeForFFI(AbstractMetaType type, AbstractMetaType templateInstantiation);

/**
 * @brief Returns a string representation of a dart type which corresponds to @p C++ type
 * For example, if func returns "qreal" or "float", this function returns "double", which is the
 * appropriate dart type.
 *
 * Another example:
 *    const char * -> String
 */
QString type(AbstractMetaType type, Options = {});

/// @overload
QString type(const AbstractMetaFunction *func, Options = {},
             AbstractMetaType templateInstantiation = {});


/**
 * @brief "mangles" a type, mostly replacing special characters like '<' and '>' so we can use it
 * for the name of a typedef.
 */
QString mangle(const QString &type);

/**
 * @brief Receives a "C++ value" and returns a "Dart value".
 * Example:
 *     nullptr -> null;
 */
QString value(AbstractMetaArgument, const QString &value);

/// @brief Returns a string representation of the arguments of a function in dart
/// Example: "int width, int height"
QString functionArguments(const AbstractMetaFunction *func, bool includeDefaultArgumentExpr,
                          Options options = {});

/// @brief Returns a string representing the arguments to be passed to a dart function
/// For example "w, y"
QString callArguments(const AbstractMetaFunction *func, AbstractMetaType templateInstantiation);
QString callArgument(AbstractMetaArgument arg, AbstractMetaType templateInstantiation);

/// @brief Returns the call arguments without any transformations.
/// example: If the dart function is foo(int a, int b), this returns "a, b"
QString directCallArguments(const AbstractMetaFunction *func);

// If the class is scoped, returns <scope>.<name>, otherwise just <name>
QString scopedNameForType(const AbstractMetaClass *metaClass);

/// @brief receives a C++ enum and returns what it would be called in Dart
/// example: The QWidget::RenderTarget enum would be QWidget_Enum_RenderTarget
/// Dart has a few limitations:
///    - Doesn't support enums nested inside classes
///    - Enumerators can't have arbitrary values associated, so we cheat and use a class instead
QString enumName(AbstractMetaEnum);

QString enumeratorName(AbstractMetaEnum metaEnum, const AbstractMetaEnumValue *);

/// @brief Returns the default type for type t.
/// This is used in Pointer.fromFunction(), which requires a fallback result.
/// TODO: Is this the best way ? Haven't spent more than 2m on this though.
QString defaultValueForType(AbstractMetaType t);

/// Returns, for example "<T>", if the specied class is a template with one argument
/// Empty if no template arguments
QString templateArgs(const AbstractMetaClass *);

/// Returns the template params, for example "<int>"
QString templateParams(AbstractMetaType type);

/// Returns the class name for the specified class. Adds the template arguments if needed
QString className(const AbstractMetaClass *, AbstractMetaType templateInstantiation = {},
                  Dartagnan::FunctionFormatOptions = {});

/// overload
QString className(AbstractMetaType type, Dartagnan::FunctionFormatOptions = {});

/// Returns the function's return type as a QString
QString returnType(const AbstractMetaFunction *func, Dartagnan::FunctionFormatOptions = {});

/// Returns the C function name to lookup in dart, example: "c_Foo__constructor"
QString cFunctionNameText(const AbstractMetaFunction *);

/// Returns the name of the finalizer variable name for example: "_finalizer"
/// if templateInstantiation is not nullptr, then the template arguments are suffixed
QString finalizerMemberVariableName(AbstractMetaType templateInstantiation);

/// Returns the default value expression for the specified argument
/// For example, if the function is "void func(int arg = 2)", then this
/// function would return "2"
QString defaultValueExpression(AbstractMetaArgument arg, const AbstractMetaClass *context);

/// Renames reserved dart keywords to something else. We don't want arguments called "var"
QString cleanReservedKeywords(const QString &name);

/// Returns whether the type is nullable
bool typeIsNullable(AbstractMetaArgument type);


} // namespace ToDartConversions

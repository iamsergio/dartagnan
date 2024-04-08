/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#ifdef QT_NO_CAST_FROM_ASCII
#undef QT_NO_CAST_FROM_ASCII
#endif

#include "abstractmetafunction.h"
#include "abstractmetalang.h"
#include "apiextractorresult.h"
#include "modifications.h"
#include "parser/enumvalue.h"
#include "textstream.h"
#include "typesystem.h"

#include <QSet>

#define ADD_READBILITY_TAG(X)                                                                      \
    if (Dartagnan::usesReadabilityTags())                                                          \
        s << "\n//tag=" << X << "\n";

struct DartagnanOptions;

namespace Dartagnan {

enum class SpecialFunctionId {
    Invalid = -1,
    Destructor = -2,
    Finalizer = -3
};

enum RejectedMethod {
    RejectedMethod_Deprecated = 1,
    RejectedMethod_CopyCtor = 2,
    RejectedMethod_MoveCtor = 4,
    RejectedMethod_PureVirtual = 8,
    RejectedMethod_AbstractClassCtor = 16,
    RejectedMethod_Private = 32,
    RejectedMethod_ReturningTemplate = 64, // TODO: Remove once supported
    RejectedMethod_ReceivingTemplate = 128,
    RejectedMethod_ReturningTemplateArgument = 256,
    RejectedMethod_VirtualFunctionExistingInBaseClass = 512,
    RejectedMethod_UnsupportedDartType = 1024,
    RejectedMethod_ExplicitlyBlacklistedAbstractClassCtor = 2048,
    RejectedMethod_Default = RejectedMethod_Deprecated | RejectedMethod_CopyCtor
        | RejectedMethod_MoveCtor | RejectedMethod_Private
        | RejectedMethod_ExplicitlyBlacklistedAbstractClassCtor
};

enum GeneratedCodeType {
    GeneratedCodeType_Unknown = 0,
    GeneratedCodeType_FFI_C_header = 1,
    GeneratedCodeType_FFI_C_impl = 2,
    GeneratedCodeType_Cppwrapper_header = 4,
    GeneratedCodeType_Cppwrapper_impl = 8,
    GeneratedCodeType_Dart = 16,
    GeneratedCodeType_CppwrapperVirtualCallback = 32 | GeneratedCodeType_Cppwrapper_impl,
    GeneratedCodeType_FFI_C = GeneratedCodeType_FFI_C_header | GeneratedCodeType_FFI_C_impl,
    GeneratedCodeType_Cppwrapper =
        GeneratedCodeType_Cppwrapper_impl | GeneratedCodeType_Cppwrapper_header
};


enum class FunctionFormatOption {
    Default = 0,
    TemplateArgs = 1, // Like "<T>"
    TemplateParams = 2, // An instantiatiation like "<int, double>"
    DefaultArgumentExpr = 4, // Includes the default argument expr, for example: "= 4"
    ImplicitThisAs1stParams = 8, // Adds "void*" as the first method parameter
    ExportMacro = 16,
    StringInsteadOfQString = 32,
    ForSignalHandler = 64, /// Uses the name of the signal handler instead of method's name. "foo"
                           /// -> "onFoo".
    QualifiedWithScope = 128 /// Prepends with "<namespace>."
};
Q_DECLARE_FLAGS(FunctionFormatOptions, FunctionFormatOption)

enum class TemplateFormatOption {
    None = 0,
    IncludeBraces = 1,
    IncludeClassName = 2 | IncludeBraces
};
Q_DECLARE_FLAGS(TemplateFormatOptions, TemplateFormatOption)

using RejectedMethods = int;

/// @brief Returns whether the type is "const char *"
bool typeIsConstCharPtr(AbstractMetaType);

/// @brief Returns if the type is a valid and non-void type
bool hasType(AbstractMetaType);

bool returnsValue(const AbstractMetaFunction &);
bool returnsByRef(const AbstractMetaFunction &);
bool returnsPrimitive(const AbstractMetaFunction &);
bool returnsConst(const AbstractMetaFunction &);
bool isMoveConstructor(const AbstractMetaFunction &);
bool isCopyOrMoveConstructor(const AbstractMetaFunction &);
bool isReference(AbstractMetaType);
bool isNonConstReference(AbstractMetaType);
bool isBool(AbstractMetaType);

bool usesReadabilityTags();

/**
 * @brief Returns whether we should add a binding to this function or not
 */
bool acceptsMethod(const AbstractMetaFunction *func,
                   RejectedMethods rejectedMethods = RejectedMethod_Default);

/**
 * Returns whether a function is removed in the typesystem xml file.
 * Example:  <modify-function signature="QApplication(int&amp;,char**,int)" remove="all"/>
 */
bool functionIsRemoved(const AbstractMetaFunction *method);

/// @brief Returns the filename for the exports headers
QString exportsHeaderFilename();

/// @brief Returns the name of the export macro
QString exportMacroName();

/// @brief Returns the first base class in the hierarchy, the root
QString baseMostBaseClass(const AbstractMetaClass *metaClass);

QString emptyReturnStatementFor(const AbstractMetaFunction *method);

/// @brief value types are garbage collected
bool needsGarbageCollection(const AbstractMetaClass *metaClass);

/// @brief Returns the number of base classes up the hierarchy
int numBaseClasses_recursive(const AbstractMetaClass *metaClass);

class SeenFunctions
{
public:
    /**
     * @brief C++ supports several methods having the same signature, only diverging on ending on
     * & and &&. But we only want 1 signature.
     */
    bool functionWasSeen(const AbstractMetaFunction *) const;
    void markAsSeen(const AbstractMetaFunction *);

private:
    QString completeFunctionSig(const AbstractMetaFunction *) const;
    QSet<QString> m_seenFunctions;
};

/// @brief Returns the class that represents the specified type
const AbstractMetaClass *classForType(AbstractMetaType);
const AbstractMetaClass *classForName(const QString &);

AbstractMetaEnum enumForType(AbstractMetaType);

void createFunctionIdCache();

/// Returns a unique numeric id for the specified id
int idForFunction(const AbstractMetaFunction *);

/// Returns the base-most method this method overrides
const AbstractMetaFunction *baseMethodForFunction(const AbstractMetaFunction *);

/// Returns the index of the template argument within the template
/// For example, if the class is MyTemplate<T, Z>, and templateArgument is Z, then this function
/// returns 1

int indexOfTemplateArg(const AbstractMetaClass *metaClass, AbstractMetaType templateArgument);
AbstractMetaType instantiationForTemplateArgument(AbstractMetaType classInstantiation,
                                                  AbstractMetaType templateArgument);

/// @brief Receives for example <T, Z> and returns <int, double>
/// @param classInstantiation, a template instantiation, for example MyTemplate<int, double>
/// @param classTemplate, a class template, for example MyTemplate<T, Z>

QVector<AbstractMetaType> instantiationsForTemplateArguments(AbstractMetaType classInstantiation,
                                                             AbstractMetaType classTemplate);

/// @brief Like instantiationsForTemplateArguments but returns a QString
/// for example, "MyTemplate<int, double>"
QString instantiationsTextForTemplateArguments(AbstractMetaType classInstantiation,
                                               AbstractMetaType classTemplate,
                                               TemplateFormatOptions = {});

/// @brief Returns the template instantiations for the specified function
/// Returns an empty list if the function doesn't return or receive any template arguments
AbstractMetaTypeList instantiationsForFunction(const AbstractMetaFunction *func);

/// @brief Returns whether the specified function returns a template argument
bool returnsTemplateArgument(const AbstractMetaFunction *func);

/// @brief Returns whether the specified function receives a template argument by argument
bool receivesTemplateArgument(const AbstractMetaFunction *func);

/// @brief Returns whether the specified function receives a template argument by argument or
/// returns one
bool hasTemplateArguments(const AbstractMetaFunction *func);

bool typeIsRef(AbstractMetaType type);

bool typeIsValue(AbstractMetaType type);

AbstractMetaType actualType(AbstractMetaType type, AbstractMetaType templateInstantiation);

/// @brief Returns whether the env var 'DARTAGNAN_GENERATES_QDEBUGS" env is set
/// If true, then function calls in the generated code will have some qDebug()
/// This is just for debugging during development of Dartagnan itself
bool generatesQDebugStatements();

/// @brief Returns whether the first base class is is polymorphic
bool firstBaseClassIsPolymorphic(const AbstractMetaClass *);

bool classIsFirstBaseInHierarchy(const AbstractMetaClass *derived, const AbstractMetaClass *base);

/// @brief Returns the index of the overload in its owner class
/// for example, for class with two methods: foo(int) and foo(char)
/// it would return 0 for the 1st one, and 1 for the 2nd method.
/// Doesn't go up the base class.
int overloadNumberInOwnerClass(const AbstractMetaFunction *func);

/// Sorts the list of classes putting the most derived ones first
// So QWidget before QObject, etc.
void sortTemplatesByHierarchy(QList<AbstractMetaType> &);

/// Returns whether the specified class has pure virtual methods
bool hasPureVirtualMethods(const DartagnanOptions &, const AbstractMetaClass *);

class EnumRegistry
{
public:
    static EnumRegistry &instance();
    void registerEnum(AbstractMetaEnum, const AbstractMetaClass *context);

    // Returns for example "Qt_EventPriority.HighEventPriority" for "Qt::HighEventPriority"
    // Context gives a bit of help, since cppEnumerator might be only "HighEventPriority",
    // so context allows us get a more qualified name
    QString dartNameForCppEnumerator(const QString &cppEnumerator,
                                     const AbstractMetaClass *context);

private:
    EnumRegistry() = default;
    /// Contains C++ to Dart enumerator mapping
    /// Example: "Qt::Foo" -> "Qt.FooEnum.Foo"
    QHash<QString, QString> m_enumNameMapping;
};

class DartOverloadRegistry
{
public:
    static DartOverloadRegistry &instance();

    QString nameForMethod(const AbstractMetaFunction *) const;

private:
    mutable QHash<QString, QHash<QString, QString>> m_methodsOverloads;
};

} // namespace Dartagnan

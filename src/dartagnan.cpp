/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "dartagnan.h"
#include "Logging.h"
#include "apiextractor.h"
#include "generator_base.h"
#include "generator_dart.h"
#include "to_dart.h"
#include "typedatabase.h"

#include <QDebug>

#include <algorithm>

using namespace Dartagnan;

static QHash<const AbstractMetaFunction *, int> s_functionIds;

static bool methodHasSameSignatureInAllBases(const AbstractMetaFunction *method)
{
    if (!method->isVirtual() || method->isAbstract())
        return true;

    const QString sig = method->minimalSignature();
    const int minArgCount = method->actualMinimumArgumentCount();

    auto metaClass = method->ownerClass();
    for (auto base : metaClass->baseClasses()) {
        for (auto func : base->functions()) {
            if (func->minimalSignature() == sig) {
                if (!methodHasSameSignatureInAllBases(func.get()))
                    return false;
                if (func->actualMinimumArgumentCount() != minArgCount) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool Dartagnan::acceptsMethod(const AbstractMetaFunction *func, RejectedMethods rejectedMethods)
{
    if (func->name() == "toString") {
        // This conflicts with Dart's Object.toString()
        return false;
    }

    if (func->name() == "is") {
        // "is" is a reserved word in Dart
        return false;
    }

    if (func->name() == "qt_getEnumName") {
        // TODO: Uncomment and fix failures
        return false;
    }

    auto ownerClass = func->ownerClass();
    auto declaringClass = func->declaringClass();
    auto implementingClass = func->implementingClass();

    if (ownerClass->name() == "QList") {
        if (func->name() == "constData" || func->name() == "data") {
            // TODO: Uncomment and fix failures
            qCDebug(discarding) << Q_FUNC_INFO << "Discarding QList data method";
            return false;
        }
    }

    if (func->isStatic()) {
        if (auto metaClass = func->ownerClass()) {
            auto instantiations = DartGenerator::instance()->templateHash().value(metaClass);
            if (!instantiations.isEmpty()) {
                qCDebug(discarding) << Q_FUNC_INFO << "Discarding static function"
                                    << func->signature() << ", Which has template instantiations";
                return false;
            }
        }
    }

    if (!methodHasSameSignatureInAllBases(func)) {
        qCDebug(discarding)
            << Q_FUNC_INFO
            << "Discarding overridden function which has different default arguments in bases"
            << func->signature();
        return false;
    }

    if (func->isVirtual() && (rejectedMethods & RejectedMethod_VirtualFunctionExistingInBaseClass)
        && ownerClass != declaringClass) {
        if (!func->isAbstract()) {
            qCDebug(discarding) << Q_FUNC_INFO
                                << "Discarding virtual function already present in base class"
                                << func->signature()
                                << "class=" << (ownerClass ? ownerClass->name() : "")
                                << "declaring=" << (declaringClass ? declaringClass->name() : "")
                                << "implementing="
                                << (implementingClass ? implementingClass->name() : "");
            return false;
        }
    } else if (!func->isVirtual() && ownerClass != declaringClass && declaringClass
               && implementingClass && ownerClass != implementingClass) {
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding function already present in base class"
                            << func->signature()
                            << "class=" << (ownerClass ? ownerClass->name() : "")
                            << "declaring=" << (declaringClass ? declaringClass->name() : "")
                            << "implementing="
                            << (implementingClass ? implementingClass->name() : "");
        return false;
    }

    if ((rejectedMethods & RejectedMethod_Deprecated) && func->isDeprecated()) {
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding deprecated" << func->signature();
        return false;
    }

    if ((rejectedMethods & RejectedMethod_PureVirtual) && func->isAbstract()) {
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding pure-virtual" << func->signature();
        return false;
    }

    if ((rejectedMethods & RejectedMethod_CopyCtor) && func->isCopyConstructor()) {
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding copy-ctor" << func->signature();
        return false;
    }

    if ((rejectedMethods & RejectedMethod_MoveCtor) && isMoveConstructor(*func)) {
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding move-ctor" << func->signature();
        return false;
    }

    if ((rejectedMethods & RejectedMethod_Private) && func->isPrivate()) {
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding private" << func->signature();
        return false;
    }

    if ((rejectedMethods & RejectedMethod_AbstractClassCtor) && func->isConstructor()) {
        const AbstractMetaClass *metaClass = func->ownerClass();
        if (metaClass->isAbstract()) {
            qCDebug(discarding) << Q_FUNC_INFO << "Discarding abstract class" << func->signature();

            return false;
        }
    }

    if ((rejectedMethods & RejectedMethod_ExplicitlyBlacklistedAbstractClassCtor)
        && func->isConstructor()) {
        const AbstractMetaClass *metaClass = func->ownerClass();
        const bool classIsReallyAbstract =
            DartagnanGeneratorBase::m_optionsFromJson.pureVirtualClassOverrides.contains(
                metaClass->qualifiedCppName());

        if (classIsReallyAbstract) {

            qCDebug(discarding) << Q_FUNC_INFO
                                << "Discarding ctor from class mentioned in dartagnan.json"
                                << func->signature();

            return false;
        }
    }

    if (rejectedMethods & RejectedMethod_ReceivingTemplate) {
        for (auto arg : func->arguments()) {
            if (arg.type().typeUsagePattern() == AbstractMetaType::TemplateArgument) {
                qCDebug(discarding) << Q_FUNC_INFO << "Discarding" << func->signature()
                                    << "Which receives template argument";
                return false;
            }
        }
    }

    if (functionIsRemoved(func)) {
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding removed function" << func->signature();
        return false;
    }

    if (func->functionType() == AbstractMetaFunction::CopyConstructorFunction) {
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding copy-ctor" << func->signature();
        return false;
    }

    if (func->name() == "swap") {
        // Not working. unneeded ? anyway don't want o spend time on it
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding swap()";
        return false;
    }

    if (func->name().startsWith(QLatin1String("operator"))) {
        return false;
    }

    if (Dartagnan::hasTemplateArguments(func)) {
        if (!func->ownerClass()) {
            // TODO: Support function templates too
            qCDebug(discarding) << Q_FUNC_INFO
                                << "Discarding non-method function with template arguments"
                                << func->signature();
            return false;
        }

        auto templateHash = DartGenerator::instance()->templateHash();
        if (!templateHash.contains(func->ownerClass())) {
            qCDebug(discarding) << Q_FUNC_INFO
                                << "Discarding method with no template instantiations"
                                << func->signature();
            return false;
        }
    }

    auto type = func->type();
    const QStringList unsupportedTypes = { "short", "long", "qint64" };

    for (auto arg : func->arguments()) {
        const QString sig = arg.type().cppSignature();
        if ((rejectedMethods & RejectedMethod_UnsupportedDartType)
            && unsupportedTypes.contains(sig)) {
            // Not supported, for now.
            qCDebug(discarding) << Q_FUNC_INFO << "Discarding function with unsupported argments";
            return false;
        }

        if (sig.contains("**") || sig.contains("[]")) {
            qCDebug(discarding) << Q_FUNC_INFO
                                << "Pointer to pointer and array syntax not supported yet"
                                << "Discarding" << func->signature();
            return false;
        }

        if (sig.contains("&&")) {
            qCDebug(discarding) << Q_FUNC_INFO << "Discarding moves" << func->signature();
            return false;
        }

        const QString argTypeName = arg.type().name();
        if (argTypeName == "string" || argTypeName == "wstring" || argTypeName == "std::string"
            || argTypeName == "std::wstring" || argTypeName == "std::map"
            || argTypeName == "std::string_view") { // Just startsWith("std::") ?
            // Not yet supported. We must do the conversions to dart String
            // Clunky but disposable code, will be removed.
            return false;
        }

        if (argTypeName.contains(" ")) {
            // Not yet supported. For example "unassigned int"
            return false;
        }

        if (arg.type().typeUsagePattern() == AbstractMetaType::NativePointerPattern
            && argTypeName != "char") {
            qCDebug(discarding) << Q_FUNC_INFO << "Discarding" << func->signature()
                                << " as it has pointer to native type" << arg.type().name();
            return false;
        }
    }

    if (func->isOperatorOverload()) {
        return false;
    }

    for (auto arg : func->arguments()) {
        if (arg.type().cppSignature() == "char") {
            qCDebug(discarding) << Q_FUNC_INFO << "Char not supported." << func->signature();
            return false; // TODO: support char
        }
    }

    if (func->signature().contains("&&")) {
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding" << func->signature();
        return false;
    }

    if (!hasType(type))
        return true;

    // Validate return types now:

    const QString returnTypeSig = type.cppSignature();

    if (returnTypeSig == "std::string" || returnTypeSig == "std::wstring"
        || returnTypeSig.startsWith("std::vector") || returnTypeSig.startsWith("std::map")) {
        // Not yet supported. Will require implicit conversions
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding function with unsupported types"
                            << func->signature();
        return false;
    }

    if ((rejectedMethods & RejectedMethod_UnsupportedDartType)
        && unsupportedTypes.contains(returnTypeSig)) {
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding function with unsupported types"
                            << func->signature();
        return false;
    }

    if (returnTypeSig.contains("**") || returnTypeSig.contains("[]")) {
        qCDebug(discarding) << Q_FUNC_INFO
                            << "Pointer to pointer and array syntax not supported yet"
                            << "Discarding" << func->signature();
        return false;
    }

    if (type.name().contains(" ")) {
        qCDebug(discarding) << Q_FUNC_INFO << "Types with spaces are not supported yet"
                            << returnTypeSig;
        return false;
    }

    if ((rejectedMethods & RejectedMethod_ReturningTemplate)
        && !func->type().instantiations().isEmpty() && func->type().hasTemplateChildren()) {
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding returning template" << func->signature();
        return false;
    }

    if ((rejectedMethods & RejectedMethod_ReturningTemplateArgument)
        && func->type().typeUsagePattern() == AbstractMetaType::TemplateArgument) {
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding returning template arg"
                            << func->signature();
        return false;
    }

    if (type.isPrimitive() && !type.isConstant() && isReference(type)) {
        // For example a function returning "int &"
        // How do we handle this in dart ?
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding primitive non-const ref"
                            << func->signature();
        return false;
    }

    if (type.typeUsagePattern() == AbstractMetaType::NativePointerPattern && type.isConstant()
        && type.name() == "char") {
        // Supporting "const char*" as return type for now.
        // TODO: Support returning other things via pointer.
        return true;
    }

    switch (type.typeUsagePattern()) {
    case AbstractMetaType::PrimitivePattern:
    case AbstractMetaType::FlagsPattern:
    case AbstractMetaType::EnumPattern:
    case AbstractMetaType::ValuePattern:
    case AbstractMetaType::ObjectPattern:
    case AbstractMetaType::ValuePointerPattern:
    case AbstractMetaType::ContainerPattern:
    case AbstractMetaType::SmartPointerPattern:
    case AbstractMetaType::VoidPattern:
    case AbstractMetaType::TemplateArgument:
        return true;
    case AbstractMetaType::NativePointerAsArrayPattern:
    case AbstractMetaType::VarargsPattern:
    case AbstractMetaType::ArrayPattern:
    case AbstractMetaType::NonTypeTemplateArgument:
    case AbstractMetaType::NativePointerPattern:
        // TODO: Support these
        qCDebug(discarding) << Q_FUNC_INFO << "Discarding" << func->name()
                            << "; pattern=" << type.typeUsagePattern();
        return false;
    }

    return true;
}

bool Dartagnan::functionIsRemoved(const AbstractMetaFunction *method)
{
    const FunctionModificationList modifs = method->modifications();
    for (const auto &modif : modifs) {
        if (modif.isRemoveModifier()) {
            qCDebug(discarding) << Q_FUNC_INFO << "Discarding" << method->name();
            return true;
        }
    }

    return false;
}

bool Dartagnan::SeenFunctions::functionWasSeen(const AbstractMetaFunction *func) const
{
    return m_seenFunctions.contains(completeFunctionSig(func));
}

void Dartagnan::SeenFunctions::markAsSeen(const AbstractMetaFunction *func)
{
    m_seenFunctions.insert(completeFunctionSig(func));
}

QString Dartagnan::SeenFunctions::completeFunctionSig(const AbstractMetaFunction *method) const
{
    QString ret =
        QString("%1::%2").arg(method->ownerClass()->qualifiedCppName(), method->signature());
    ret.replace(") const", ")");

    return ret;
}

QString Dartagnan::exportsHeaderFilename()
{
    if (DartagnanGeneratorBase::m_optionsFromJson.exportsHeaderName.isEmpty()) {
        return QStringLiteral("%1_exports.h").arg(TypeDatabase::instance()->defaultPackageName());
    } else {
        return DartagnanGeneratorBase::m_optionsFromJson.exportsHeaderName;
    }
}

QString Dartagnan::exportMacroName()
{
    if (DartagnanGeneratorBase::m_optionsFromJson.exportsMacroName.isEmpty()) {
        return QStringLiteral("%1_EXPORT").arg(TypeDatabase::instance()->defaultPackageName());
    } else {
        return DartagnanGeneratorBase::m_optionsFromJson.exportsMacroName;
    }
}

bool Dartagnan::typeIsConstCharPtr(AbstractMetaType type)
{
    return type.isConstant() && type.name() == "char"
        && type.typeUsagePattern() == AbstractMetaType::NativePointerPattern;
}

QString Dartagnan::baseMostBaseClass(const AbstractMetaClass *metaClass)
{
    if (auto bc = metaClass->baseClass())
        return baseMostBaseClass(bc);

    return ToDartConversions::scopedNameForType(metaClass);
}

QString Dartagnan::emptyReturnStatementFor(const AbstractMetaFunction *method)
{
    QString result =
        QString("std::cerr << \"%1: Warning: Calling pure-virtual\\n\";\n").arg(method->name());

    if (method->isVoid()) {
        result += "return;";
    } else {
        result += "return {};";
    }

    return result;
}

const AbstractMetaClass *Dartagnan::classForType(AbstractMetaType type)
{
    return AbstractMetaClass::findClass(DartGenerator::instance()->api().classes(),
                                        type.typeEntry());
}

const AbstractMetaClass *Dartagnan::classForName(const QString &name)
{
    for (const AbstractMetaClass *c : DartGenerator::instance()->api().classes()) {
        if (c->name() == name)
            return c;
    }
    return nullptr;
}

AbstractMetaEnum Dartagnan::enumForType(AbstractMetaType metaEnum)
{
    for (auto metaClass : DartGenerator::instance()->api().classes()) {
        for (auto e : metaClass->enums()) {
            if (e.typeEntry() == metaEnum.typeEntry())
                return e;
        }
    }

    for (auto e : DartGenerator::instance()->api().globalEnums()) {
        if (e.typeEntry() == metaEnum.typeEntry())
            return e;
    }

    return {};
}

bool Dartagnan::needsGarbageCollection(const AbstractMetaClass *metaClass)
{
    if (metaClass->isNamespace() || metaClass->isPolymorphic())
        return false;

    return true;
}

const AbstractMetaFunction *Dartagnan::baseMethodForFunction(const AbstractMetaFunction *method)
{
    if (!method->isVirtual() || method->declaringClass() == method->ownerClass()) {
        return method;
    }

    const QString sig = method->minimalSignature();
    for (auto m : method->declaringClass()->functions()) {
        if (m->minimalSignature() == sig)
            return m.get();
    }

    qWarning() << Q_FUNC_INFO << "Couldn't find base method for" << method->signature()
               << method->ownerClass()->name() << method->declaringClass()->name();
    return method;
}

int Dartagnan::idForFunction(const AbstractMetaFunction *func)
{
    if (func->isDestructor())
        return int(SpecialFunctionId::Destructor);

    auto f = Dartagnan::baseMethodForFunction(func);
    return s_functionIds.value(f, int(SpecialFunctionId::Invalid));
}

void Dartagnan::createFunctionIdCache()
{
    if (!s_functionIds.isEmpty()) {
        // Already filled by other generators
        return;
    }

    auto generator = DartGenerator::instance();
    static int s_nextId = 0;

    for (const AbstractMetaClass *metaClass : generator->api().classes()) {
        for (auto f : metaClass->functions()) {
            auto func = f.get();
            auto baseFunc = Dartagnan::baseMethodForFunction(func);
            if (baseFunc == func) { // if it's different then it will be handled in the base class
                s_functionIds[func] = s_nextId++;
            }
        }
    }

    for (auto func : generator->api().globalFunctions()) {
        s_functionIds[func.get()] = s_nextId++;
    }
}

int Dartagnan::indexOfTemplateArg(const AbstractMetaClass *metaClass,
                                  AbstractMetaType templateArgument)
{
    if (!metaClass || !hasType(templateArgument))
        return -1;

    if (templateArgument.typeUsagePattern() != AbstractMetaType::TemplateArgument)
        return -1;

    const QString templateArgName = templateArgument.name();

    // args is for example: T, G, W
    // templateArgument is for example: W
    // The result index for the above example would be: 2
    const auto args = metaClass->templateArguments();

    auto it = std::find_if(args.cbegin(), args.cend(), [templateArgName](const TypeEntry *te) {
        return templateArgName == te->name();
    });

    return it == args.cend() ? -1 : std::distance(args.cbegin(), it);
}

AbstractMetaType Dartagnan::instantiationForTemplateArgument(AbstractMetaType classInstantiation,
                                                             AbstractMetaType templateArgument)
{
    if (!hasType(classInstantiation))
        return {};

    const AbstractMetaClass *metaClass = classForType(classInstantiation);

    const int index = indexOfTemplateArg(metaClass, templateArgument);
    const int numArgs = classInstantiation.instantiations().size();

    if (index >= 0 && index < numArgs) {
        return classInstantiation.instantiations().at(index);
    } else {
        qWarning() << Q_FUNC_INFO << "Failed to find instantiation for"
                   << "; classInstantiation=" << classInstantiation.cppSignature()
                   << "; templateArg=" << templateArgument.cppSignature() << "; index=" << index
                   << "; numArgs=" << numArgs << "; metaClass=" << metaClass;
        Q_ASSERT(false);

        return {};
    }
}

QVector<AbstractMetaType>
Dartagnan::instantiationsForTemplateArguments(AbstractMetaType classInstantiation,
                                              AbstractMetaType classTemplate)
{
    if (!classTemplate.hasTemplateChildren())
        return {};

    QVector<AbstractMetaType> result;

    for (auto t : classTemplate.instantiations()) {
        result << instantiationForTemplateArgument(classInstantiation, t);
    }

    return result;
}

QString Dartagnan::instantiationsTextForTemplateArguments(AbstractMetaType classInstantiation,
                                                          AbstractMetaType classTemplate,
                                                          TemplateFormatOptions formatOptions)
{
    QStringList args;
    const QVector<AbstractMetaType> instantiatedArgs =
        instantiationsForTemplateArguments(classInstantiation, classTemplate);

    for (const AbstractMetaType &t : instantiatedArgs) {
        args << t.cppSignature();
    }

    QString result = args.join(",");

    if (formatOptions & TemplateFormatOption::IncludeBraces)
        result = QString("<%1>").arg(result);

    if (formatOptions & TemplateFormatOption::IncludeClassName)
        result = QString("%1%2").arg(classTemplate.name(), result);

    return result;
}

AbstractMetaTypeList Dartagnan::instantiationsForFunction(const AbstractMetaFunction *func)
{
    const AbstractMetaClass *metaClass = func->ownerClass();
    if (!metaClass || metaClass->isNamespace()) {
        // TODO: We don't support function templates yet
        return {};
    }

    if (!hasTemplateArguments(func))
        return {};

    const auto templateHash = DartGenerator::instance()->templateHash();
    return templateHash.value(metaClass);
}

bool Dartagnan::returnsTemplateArgument(const AbstractMetaFunction *func)
{
    return func && hasType(func->type())
        && func->type().typeUsagePattern() == AbstractMetaType::TemplateArgument;
}

bool Dartagnan::receivesTemplateArgument(const AbstractMetaFunction *func)
{
    if (!func)
        return false;

    const auto args = func->arguments();
    return std::any_of(args.cbegin(), args.cend(), [](AbstractMetaArgument arg) {
        return arg.type().typeUsagePattern() == AbstractMetaType::TemplateArgument;
    });
}

bool Dartagnan::hasTemplateArguments(const AbstractMetaFunction *func)
{
    return returnsTemplateArgument(func) || receivesTemplateArgument(func);
}

bool Dartagnan::typeIsRef(AbstractMetaType type)
{
    return hasType(type) && isReference(type);
}

bool Dartagnan::typeIsValue(AbstractMetaType type)
{
    return hasType(type) && type.isValue() && !isReference(type);
}

AbstractMetaType Dartagnan::actualType(AbstractMetaType type,
                                       AbstractMetaType templateInstantiation)
{
    if (!hasType(templateInstantiation))
        return type;

    AbstractMetaType actualType = type;
    if (hasType(actualType)
        && actualType.typeUsagePattern() == AbstractMetaType::TemplateArgument) {
        actualType = Dartagnan::instantiationForTemplateArgument(templateInstantiation, actualType);
        Q_ASSERT(hasType(actualType));
    }

    return actualType;
}

EnumRegistry &EnumRegistry::instance()
{
    static EnumRegistry s_enumRegistry;
    return s_enumRegistry;
}

void EnumRegistry::registerEnum(AbstractMetaEnum metaEnum, const AbstractMetaClass *context)
{
    // Maps c++ to dart enumerator names, for example:
    // "Qt::HighEventPriority" -> "Qt_EventPriority.HighEventPriority"

    const auto enumerators = metaEnum.values();
    for (auto enumerator : enumerators) {
        const QString dartName = ToDartConversions::enumeratorName(metaEnum, &enumerator);

        auto cppName = [context, &enumerator, &metaEnum](bool extraQualify) {
            QString cppName;

            if (extraQualify)
                cppName = QString("%1::%2").arg(metaEnum.name(), enumerator.name());
            else
                cppName = enumerator.name();

            // Append namespace or owner class
            if (context)
                cppName = QString("%1::%2").arg(context->qualifiedCppName(), cppName);


            return cppName;
        };

        /// If we have func(Enum = Foo) shiboken gives us Enum::Foo as the default argument
        /// even if it's not an enum class, so register both variants:
        m_enumNameMapping.insert(cppName(true), dartName);
        m_enumNameMapping.insert(cppName(false), dartName);
    }
}

QString EnumRegistry::dartNameForCppEnumerator(const QString &cppEnumerator,
                                               const AbstractMetaClass *context)
{
    auto it = m_enumNameMapping.constFind(cppEnumerator);
    if (it != m_enumNameMapping.cend())
        return *it;

    // Let's see if the context can help
    if (context) {
        // A function can have default argument enumerator which is not fully qualified
        // Example
        // void func(int e = MyEnumerator0).
        // MyEnumerator0 might belong to a class, so we need to prefix the class name

        QString result = dartNameForCppEnumerator(
            QString("%1::%2").arg(context->qualifiedCppName(), cppEnumerator), nullptr);

        if (!result.isEmpty())
            return result;

        // Try with the base class as context:
        for (auto base : context->baseClasses()) {
            result = dartNameForCppEnumerator(cppEnumerator, base);
            if (!result.isEmpty())
                return result;
        }

        // Let's tackle another case: It's only smi-qualified, for example
        // MyClass::MyEnumerator , missing namespace. Here we don't want to prefix the class
        // qualified name otherwise we would get Namespace::MyClass::MyClass::MyEnumerator
        // So first get the enumerator without any class prefix
        const QStringList splitted = cppEnumerator.split("::");
        if (splitted.size() >= 2) {
            return dartNameForCppEnumerator(
                QString("%1::%2").arg(context->qualifiedCppName(), splitted.last()), nullptr);
        }
    }

    return QString();
}

bool Dartagnan::usesReadabilityTags()
{
    static const bool uses = qEnvironmentVariableIsSet("DARTAGNAN_READABILITY_TAGS");
    return uses;
}

bool Dartagnan::generatesQDebugStatements()
{
    return qEnvironmentVariableIsSet("DARTAGNAN_GENERATES_QDEBUGS");
}

int Dartagnan::numBaseClasses_recursive(const AbstractMetaClass *metaClass)
{
    const auto bases = metaClass->baseClasses();
    int numBases = bases.size();
    for (auto base : metaClass->baseClasses()) {
        numBases += numBaseClasses_recursive(base);
    }

    return numBases;
}

bool Dartagnan::firstBaseClassIsPolymorphic(const AbstractMetaClass *metaClass)
{
    auto bases = metaClass->baseClasses();
    return !bases.isEmpty() && bases.first()->isPolymorphic();
}

bool Dartagnan::classIsFirstBaseInHierarchy(const AbstractMetaClass *derived,
                                            const AbstractMetaClass *targetBase)
{
    if (derived == targetBase)
        return true;

    const auto bases = derived->baseClasses();
    return !bases.isEmpty() && classIsFirstBaseInHierarchy(bases.first(), targetBase);

    return false;
}

int Dartagnan::overloadNumberInOwnerClass(const AbstractMetaFunction *func)
{
    const AbstractMetaClass *metaClass = func->ownerClass();
    if (!metaClass)
        return 0;

    int index = 0;

    for (auto f : metaClass->functions()) {
        if (f.get() == func)
            break;

        if (f->name() == func->name())
            index++;
    }

    return index;
}

static bool classInheritsFrom(const AbstractMetaClass *child, const AbstractMetaClass *maybeParent)
{
    const auto bases = child->baseClasses();
    if (bases.contains(maybeParent))
        return true;

    for (auto base : bases) {
        if (classInheritsFrom(base, maybeParent))
            return true;
    }

    return false;
}

void Dartagnan::sortTemplatesByHierarchy(QList<AbstractMetaType> &classes)
{
    std::sort(classes.begin(), classes.end(),
              [](const AbstractMetaType &a, const AbstractMetaType &b) {
                  auto instantitionsA = a.instantiations();
                  auto instantitionsB = b.instantiations();

                  if (instantitionsA.size() > instantitionsB.size()) {
                      return true;
                  } else if (instantitionsA.size() < instantitionsB.size()) {
                      return false;
                  } else if (instantitionsA.isEmpty()) {
                      return a.cppSignature().compare(b.cppSignature()) < 0;
                  } else if (instantitionsA.size() != 1) {
                      // Maybe we can improve this case
                      return a.cppSignature().compare(b.cppSignature()) < 0;
                  } else {
                      const AbstractMetaClass *classA = classForType(instantitionsA.first());
                      const AbstractMetaClass *classB = classForType(instantitionsB.first());

                      if (classA && !classB) {
                          return true;
                      } else if (!classA && classB) {
                          return false;
                      } else if (!classA && !classB) {
                          return a.cppSignature().compare(b.cppSignature()) < 0;
                      } else {
                          if (classInheritsFrom(classA, classB)) {
                              return true;
                          } else if (classInheritsFrom(classB, classA)) {
                              return false;
                          } else {
                              return a.cppSignature().compare(b.cppSignature()) < 0;
                          }
                      }
                  }
              });
}

bool Dartagnan::hasType(AbstractMetaType t)
{
    return t.typeEntry() != nullptr && !t.isVoid();
}

bool Dartagnan::returnsValue(const AbstractMetaFunction &f)
{
    return hasType(f.type()) && f.type().isValue() && !Dartagnan::returnsByRef(f);
}

bool Dartagnan::returnsByRef(const AbstractMetaFunction &f)
{
    return hasType(f.type()) && isReference(f.type());
}

bool Dartagnan::returnsPrimitive(const AbstractMetaFunction &f)
{
    return hasType(f.type()) && f.type().isPrimitive();
}

bool Dartagnan::returnsConst(const AbstractMetaFunction &f)
{
    return hasType(f.type()) && f.type().isConstant();
}

bool Dartagnan::isMoveConstructor(const AbstractMetaFunction &f)
{
    return f.functionType() == AbstractMetaFunction::MoveConstructorFunction;
}

bool Dartagnan::isCopyOrMoveConstructor(const AbstractMetaFunction &f)
{
    return f.isCopyConstructor() || isMoveConstructor(f);
}

bool Dartagnan::isReference(AbstractMetaType t)
{
    return t.cppSignature().contains(QLatin1String("&"));
}

bool Dartagnan::isNonConstReference(AbstractMetaType t)
{
    return !t.isConstant() && isReference(t);
}

bool Dartagnan::isBool(AbstractMetaType t)
{
    return t.name() == QLatin1String("bool");
}

DartOverloadRegistry &DartOverloadRegistry::instance()
{
    static DartOverloadRegistry s_instance;
    return s_instance;
}

QString DartOverloadRegistry::nameForMethod(const AbstractMetaFunction *func) const
{
    if (func->functionType() == AbstractMetaFunction::GetAttroFunction
        || func->functionType() == AbstractMetaFunction::SetAttroFunction) {
        return func->name();
    }

    if (!func->declaringClass())
        return func->name();

    // Simple name is for example: "QWidget.resize"
    // or even "MyScope.QWidget.resize" if using scopes
    const QString scopedClassName = ToDartConversions::scopedNameForType(func->declaringClass());
    const QString simpleName = scopedClassName + "." + func->name();

    // Complete name is for example: "QWidget.resize(int,int)"
    const QString completeName = func->declaringClass()->name() + "." + func->minimalSignature();


    QHash<QString, QString> &overloads = m_methodsOverloads[simpleName];
    if (overloads.contains(completeName)) {

        return overloads.value(completeName);
    }

    auto newNameGenerator = [func](int index) {
        if (func->isConstructor()) {
            return QString("%1.ctor%2").arg(func->name()).arg(index);
        } else {
            return QString("%1_%2").arg(func->name()).arg(index);
        }
    };

    if (overloads.isEmpty()) {
        // The first overload gets to keep its natural name
        const int index = overloadNumberInOwnerClass(func);
        QString name = func->name();

        if (index > 0 && !func->isConstructor() && func->implementingClass()->baseClass()) {
            // Fixes the following case (for example):
            // BaseClass with: foo(int)
            // DerivedClass with: foo(int) and foo(int,int)
            // foo(int) would be hashed as BaseClass.foo
            // and foo(int,int) would be hashed as DerivedClass.foo, getting index 0 too.
            // DerivedClass would then have two methods with the same name in dart, which is
            // illegal
            name = newNameGenerator(index);
        }
        overloads.insert(completeName, name);
    } else {
        int index = overloads.size() + 1;
        while (true) {
            const QString newName = newNameGenerator(index);
            const bool containsValue = overloads.constFind(newName) != overloads.constEnd();
            if (!containsValue) {
                overloads.insert(completeName, newName);
                break;
            }

            ++index;
        }
    }

    return overloads.value(completeName);
}

bool Dartagnan::hasPureVirtualMethods(const DartagnanOptions &opts,
                                      const AbstractMetaClass *metaClass)
{
    if (metaClass->isAbstract())
        return true;

    return opts.pureVirtualClassOverrides.contains(metaClass->qualifiedCppName());
}

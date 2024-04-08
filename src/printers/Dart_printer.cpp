/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "Dart_printer.h"
#include "../type_conversions/to_dart.h"
#include "dart_ffi_typedefs.h"
#include "generator_base.h"
#include "generator_dart.h"
#include "to_CppWrapper.h"

#include <QDebug>

using namespace Dartagnan;

DartClassPrinter::DartClassPrinter(TextStream &s, const AbstractMetaClass *metaClass)
    : Printer(s)
{
    const QString className = metaClass->name();
    const QString classNameWithTemplateArgs =
        ToDartConversions::className(metaClass, {}, FunctionFormatOption::TemplateArgs);

    QString extendsStr;
    AbstractMetaClass *baseClass = metaClass->baseClass();
    if (baseClass)
        extendsStr = QString("extends %1").arg(ToDartConversions::scopedNameForType(baseClass));
    else
        extendsStr = "implements ffi.Finalizable";

    for (AbstractMetaEnum metaEnum : metaClass->enums()) {
        if (!metaEnum.isAnonymous())
            DartEnumPrinter printer(s, metaEnum, metaClass);
    }

    s << QString("class %1 %2").arg(classNameWithTemplateArgs, extendsStr);
    s << "{";

    // Anonymous enums are simply const variables instead of enum
    for (AbstractMetaEnum metaEnum : metaClass->enums()) {
        if (metaEnum.isAnonymous())
            DartEnumPrinter printer(s, metaEnum, metaClass);
    }

    if (className == "QObject") {
        s << "Map<Function, List<Function>> signalHandlerersBySignal = {};\n";
    }

    if (baseClass) {
        ADD_READBILITY_TAG(1064)
        s << QString("%1.fromCppPointer(var cppPointer, [var needsAutoDelete = false]) : "
                     "super.fromCppPointer(cppPointer, needsAutoDelete) {}")
                 .arg(className);
        s << QString("%1.init() : super.init() {}").arg(className);

        ADD_READBILITY_TAG(1062)
        s << QString("factory %1.fromCache(var cppPointer, [needsAutoDelete = false]) {")
                 .arg(className);
        s << QString("if (%1.isCached(cppPointer))\n").arg(Dartagnan::baseMostBaseClass(metaClass));
        s << "{";
        s << "var instance =";
        s << QString("%1.s_dartInstanceByCppPtr[cppPointer.address];")
                 .arg(Dartagnan::baseMostBaseClass(metaClass));
        s << QString("if (instance != null) return instance as %1;").arg(className);
        s << "}";
        s << QString("return %1.fromCppPointer(cppPointer, needsAutoDelete);\n").arg(className);
        s << "}";

    } else {
        // The first base class gets these members
        ADD_READBILITY_TAG(1060)
        s << QString("static var s_dartInstanceByCppPtr = Map<int, %1>();\n").arg(className);
        s << "var _thisCpp = null;";
        s << QString("bool _needsAutoDelete = %1;")
                 .arg(Dartagnan::needsGarbageCollection(metaClass) ? "true" : "false");
        s << "get thisCpp => _thisCpp;";
        s << "set thisCpp (var ptr) {";
        s << "_thisCpp = ptr;";
        s << "ffi.Pointer<ffi.Void> ptrvoid = ptr.cast<ffi.Void>();\n";
        s << "if (_needsAutoDelete) {\n";

        s << "final String finalizerName = getFinalizerName();";
        s << "if (!_finalizers.keys.contains(runtimeType)) {";
        s << QString("_finalizers[finalizerName] = "
                     "ffi.NativeFinalizer(_finalizerFunc(finalizerName).cast());\n");
        s << "}";
        s << "_finalizers[finalizerName]!.attach(this, ptrvoid);\n";

        s << "}}";
        s << QString("static bool isCached(var cppPointer) {");
        ADD_READBILITY_TAG(1024)
        s << "    return s_dartInstanceByCppPtr.containsKey(cppPointer.address);";
        s << "}";

        ADD_READBILITY_TAG(1061)
        s << QString("factory %1.fromCache(var cppPointer, [needsAutoDelete = false]) {")
                 .arg(className);
        s << "return (s_dartInstanceByCppPtr[cppPointer.address] ??\n";
        s << QString("%1.fromCppPointer(cppPointer, needsAutoDelete)) as %2;")
                 .arg(className, classNameWithTemplateArgs);
        s << "}";

        s << QString("%1.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {")
                 .arg(className);
        ADD_READBILITY_TAG(1024)
        s << "thisCpp = cppPointer;";
        s << "}";

        ADD_READBILITY_TAG(1025)
        s << QString("%1.init() {}").arg(className);
    }

    const auto templateHash = DartGenerator::instance()->templateHash();
    const auto templateInstantiations = templateHash[metaClass];
    if (!metaClass->templateArguments().isEmpty()) {
        ADD_READBILITY_TAG(1063)
        s << "String getCFunctionName(int id) {";

        for (const AbstractMetaType &templateInstantiation : templateInstantiations) {
            s << QString("if (this is %1%2) {")
                     .arg(className, ToDartConversions::templateParams(templateInstantiation));
            s << "switch (id) {";

            for (auto method : metaClass->functions()) {
                if (!Dartagnan::acceptsMethod(
                        method.get(),
                        RejectedMethod::RejectedMethod_Default
                            | RejectedMethod::RejectedMethod_UnsupportedDartType))
                    continue;

                s << QString("case %1:").arg(Dartagnan::idForFunction(method.get()));
                s << QString("return \"%1\";")
                         .arg(ToCConversions::functionName(method.get(), templateInstantiation));
                s << "break;";
            }

            s << "}"; // switch
            s << "}";
        }

        s << "    return \"\" ;";
        s << "}"; // end getCFunctionName();
    }

    ADD_READBILITY_TAG(1090)
    s << "String getFinalizerName() {";

    if (metaClass->templateArguments().isEmpty()) {
        const QString finalizerName = ToCConversions::finalizerName(metaClass, {});
        s << QString("return \"%1\";").arg(finalizerName);
    } else {
        for (const AbstractMetaType &templateInstantiation : templateInstantiations) {

            const QString finalizerVariableName =
                ToDartConversions::finalizerMemberVariableName(templateInstantiation);

            s << QString("if (this is %1%2) {")
                     .arg(className, ToDartConversions::templateParams(templateInstantiation));

            s << QString("return \"%1\";")
                     .arg(ToCConversions::finalizerName(metaClass, templateInstantiation));
            s << "}";
        }
        s << "print(\"ERROR: Couldn't find finalizerName for\" + this.runtimeType.toString());";
        s << "return \"\";";
    }

    s << "}";

    // Add the members
    const AbstractMetaFieldList fields = metaClass->fields();
    for (AbstractMetaField field : fields) {
        printGetterText(field);
        printSetterText(field);
    }

    // Add the methods

    const auto methods = metaClass->functions();
    bool seenDtor = false;
    for (auto m : methods) {
        auto method = m.get();
        if (Dartagnan::functionIsRemoved(method) || m_seenFunctions.functionWasSeen(method))
            continue;

        m_seenFunctions.markAsSeen(method);

        createDartFunctionPrinter(s, method);
        static const bool supportsQtSignals =
            DartGenerator::instance()->m_optionsFromJson.supportsQtSignals;
        if (supportsQtSignals && method->isSignal()
            && method->ownerClass() == method->implementingClass())
            DartSignalHandlerPrinter printer(s, method);

        if (method->isDestructor())
            seenDtor = true;
    }

    if (!seenDtor) {
        auto m = Dartagnan::createDestructor(metaClass);
        auto printer = createDartFunctionPrinter(s, m.get());
    }

    if (metaClass->name() == "QString") {
        // QString gets a toDartString() for convenience

        QString code = DartagnanGeneratorBase::m_optionsFromJson.qStringToDartCode;
        if (code.isEmpty())
            code = "return toUtf8().constData();";

        s << QString("String toDartString() { %1 }").arg(code);
    }

    printOverriddenMethodHelpers(s, metaClass);
}

DartClassPrinter::~DartClassPrinter()
{
    s << "}";
}

void DartClassPrinter::printOverriddenMethodHelpers(TextStream &s,
                                                    const AbstractMetaClass *metaclass)
{
    if (!metaclass->isPolymorphic())
        return;

    ADD_READBILITY_TAG(1019)

    s << "String cFunctionSymbolName(int methodId) {";
    const auto methods = metaclass->functions();
    s << "    switch (methodId) {\n";
    for (auto method : methods) {
        if (!method->isVirtual()
            || !Dartagnan::acceptsMethod(method.get(),
                                         Dartagnan::RejectedMethod_ReturningTemplate
                                             | RejectedMethod::RejectedMethod_UnsupportedDartType))
            continue;
        s << QString("    case %1:\n").arg(Dartagnan::idForFunction(method.get()));
        s << QString("        return \"%1\";")
                 .arg(ToDartConversions::cFunctionNameText(method.get()));
    }
    s << "}\n";

    if (Dartagnan::firstBaseClassIsPolymorphic(metaclass)) {
        s << "return super.cFunctionSymbolName(methodId);";
    } else {
        s << "return \"\";";
    }
    s << "}";
    s << "static String methodNameFromId(int methodId) {\n";
    s << "    switch (methodId) {\n";

    for (auto method : methods) {
        if (!method->isVirtual()
            || !Dartagnan::acceptsMethod(method.get(),
                                         Dartagnan::RejectedMethod_ReturningTemplate
                                             | RejectedMethod::RejectedMethod_UnsupportedDartType))
            continue;

        s << QString("    case %1:\n").arg(Dartagnan::idForFunction(method.get()));
        s << QString("        return \"%1\";")
                 .arg(DartOverloadRegistry::instance().nameForMethod(method.get()));
    }

    s << "    }";
    s << "    throw Error();";
    s << "}\n";

    ADD_READBILITY_TAG(1020)
    s << "void registerCallbacks() {\n";
    s << "assert(thisCpp != null);\n";
    s << "final RegisterMethodIsReimplementedCallback registerCallback = _dylib\n";
    s << QString(".lookup<ffi.NativeFunction<RegisterMethodIsReimplementedCallback_FFI>>('%1')."
                 "asFunction();\n")
             .arg(ToCConversions::registerCallbackFunctionsName(metaclass));

    for (auto method : methods) {
        if (!method->isVirtual()
            || !Dartagnan::acceptsMethod(method.get(),
                                         Dartagnan::RejectedMethod_ReturningTemplate
                                             | RejectedMethod::RejectedMethod_UnsupportedDartType))
            continue;

        if (method->ownerClass() != method->declaringClass()
            && !classIsFirstBaseInHierarchy(method->ownerClass(), method->declaringClass()))
            continue;

        const auto returnType = method->type();
        const QString returnTypeName = ToDartConversions::type(returnType);

        const bool needsExceptionalValue = returnTypeName == "int" || returnTypeName == "bool"
            || returnType.isEnum() || returnType.isFlags();

        const int id = Dartagnan::idForFunction(method.get());
        const QString callbackExceptName = QString("callbackExcept%1").arg(id);

        const QString callbackExceptArg =
            needsExceptionalValue ? QString(", %1").arg(callbackExceptName) : QString();

        if (needsExceptionalValue)
            s << QString("const %1 = %2;")
                     .arg(callbackExceptName, ToDartConversions::defaultValueForType(returnType));

        ADD_READBILITY_TAG(1021)
        const QString methodsBaseClass =
            ToDartConversions::scopedNameForType(method->implementingClass());
        s << QString("final callback%1 = ffi.Pointer.fromFunction<%2>(%3.%4_calledFromC %5);\n")
                 .arg(id)
                 .arg(FFITypedefs::ffiTypedefName(method.get(), {}), methodsBaseClass,
                      DartOverloadRegistry::instance().nameForMethod(method.get()),
                      callbackExceptArg);

        s << QString("registerCallback(thisCpp, callback%1, %1);").arg(id);
    }

    s << "}";
}

DartNamespacePrinter::DartNamespacePrinter(TextStream &s, const AbstractMetaClass *metaClass)
    : Printer(s)
{
    for (AbstractMetaEnum metaEnum : metaClass->enums()) {
        DartEnumPrinter printer(s, metaEnum, metaClass);
    }

    const auto methods = metaClass->functions();
    for (auto method : methods) {
        auto printer = createDartFunctionPrinter(s, method.get());
    }
}

void DartClassPrinter::printGetterText(AbstractMetaField field)
{
    if (auto fakeMethod = Dartagnan::createGetterFor(field, Dartagnan::GeneratedCodeType_Dart)) {
        DartMethodPrinter methodPrinter(s, fakeMethod.get());
        FFITypedefs::instance().addDartFunctionTypedef(fakeMethod.get());
    }
}

void DartClassPrinter::printSetterText(AbstractMetaField field)
{
    if (auto fakeMethod = Dartagnan::createSetterFor(field, Dartagnan::GeneratedCodeType_Dart)) {
        DartMethodPrinter methodPrinter(s, fakeMethod.get());
        FFITypedefs::instance().addDartFunctionTypedef(fakeMethod.get());
    }
}

DartFunctionPrinterBase::DartFunctionPrinterBase(TextStream &s, const AbstractMetaFunction *func)
    : Printer(s)
    , m_func(func)
{
}

DartFunctionPrinterBase::~DartFunctionPrinterBase()
{
    s << "}";
}

DartDtorPrinter::DartDtorPrinter(TextStream &s, const AbstractMetaFunction *dtor)
    : DartFunctionPrinterBase(s, dtor)
{
    // Skip, Dart has no dtors. But maybe we can add a release() function.
    ADD_READBILITY_TAG(1022)
    s << "void release() {";
    s << QString("final %1 func = _dylib.lookup<ffi.NativeFunction<%2>>('%3').asFunction();")
             .arg(FFITypedefs::typedefName(dtor, {}))
             .arg(FFITypedefs::ffiTypedefName(dtor, {}))
             .arg(ToDartConversions::cFunctionNameText(dtor));
    s << "func(thisCpp);";
}

DartCtorPrinter::DartCtorPrinter(TextStream &s, const AbstractMetaFunction *ctor)
    : DartFunctionPrinterBase(s, ctor)
{
    QString callBaseClassInit;
    const AbstractMetaClass *metaClass = ctor->ownerClass();
    const bool usesDummyInit = metaClass->baseClass() != nullptr;
    if (usesDummyInit)
        callBaseClassInit = ": super.init()";

    const auto templateHash = DartGenerator::instance()->templateHash();
    const bool processInstantiations = Dartagnan::hasTemplateArguments(ctor);
    AbstractMetaTypeList templateInstantiations;
    if (processInstantiations)
        templateInstantiations = templateHash.value(ctor->ownerClass());

    if (templateInstantiations.isEmpty())
        templateInstantiations << AbstractMetaType();

    ADD_READBILITY_TAG(1023)
    s << QString("//%1\n").arg(ctor->signature());
    s << QString("%1(%2) %3 {")
             .arg(DartOverloadRegistry::instance().nameForMethod(ctor))
             .arg(ToDartConversions::functionArguments(
                 ctor, true, ToDartConversions::Option::StringInsteadOfQString))
             .arg(callBaseClassInit);

    for (const AbstractMetaType &templateInstantiation : templateInstantiations) {
        ADD_READBILITY_TAG(1075)

        if (hasType(templateInstantiation))
            s << QString("if (this is %1%2) {")
                     .arg(metaClass->name(),
                          ToDartConversions::templateParams(templateInstantiation));

        s << QString("final %1 func = _dylib.lookup<ffi.NativeFunction<%2>>('%3').asFunction();")
                 .arg(FFITypedefs::typedefName(ctor, templateInstantiation))
                 .arg(FFITypedefs::ffiTypedefName(ctor, templateInstantiation))
                 .arg(ToDartConversions::cFunctionNameText(ctor));
        s << QString("thisCpp = func(%1);")
                 .arg(ToDartConversions::callArguments(ctor, templateInstantiation));
        s << QString("%1.s_dartInstanceByCppPtr[thisCpp.address] = this;")
                 .arg(Dartagnan::baseMostBaseClass(metaClass));

        if (hasType(templateInstantiation))
            s << QString("}\n"); // end if (this is T)
    }

    if (metaClass->isPolymorphic()) {
        s << "registerCallbacks();";
    }
}

std::unique_ptr<DartFunctionPrinterBase> createDartFunctionPrinter(TextStream &s,
                                                                   const AbstractMetaFunction *func)
{
    if (!Dartagnan::acceptsMethod(func,
                                  RejectedMethod_MoveCtor | RejectedMethod_CopyCtor
                                      | RejectedMethod_ReturningTemplate
                                      | RejectedMethod::RejectedMethod_UnsupportedDartType)) {
        return {};
    }

    DartFunctionPrinterBase *printer = nullptr;
    if (func->isConstructor()) {
        printer = new DartCtorPrinter(s, func);
    } else if (func->isDestructor()) {
        printer = new DartDtorPrinter(s, func);
    } else if (func->isInGlobalScope()) {
        printer = new DartGlobalFuncPrinter(s, func);
    } else {
        printer = new DartMethodPrinter(s, func);
    }

    FFITypedefs::instance().addDartFunctionTypedef(func);
    return std::unique_ptr<DartFunctionPrinterBase>(printer);
}

DartGlobalFuncPrinter::DartGlobalFuncPrinter(TextStream &s, const AbstractMetaFunction *func)
    : DartFunctionPrinterBase(s, func)
{
    Q_ASSERT(false);
}

DartMethodPrinter::DartMethodPrinter(TextStream &s, const AbstractMetaFunction *method)
    : DartFunctionPrinterBase(s, method)
{

    auto ownerClass = method->ownerClass();
    auto declaringClass = method->declaringClass();
    const bool methodAlreadyInBaseClass = method->isVirtual() && !method->isAbstract()
        && ownerClass != declaringClass
        && ownerClass->baseClasses().size() == 1; // TODO: Support more base classes

    ADD_READBILITY_TAG(1024)

    const QString methodName = DartOverloadRegistry::instance().nameForMethod(method);

    bool needsClosing = false;
    if (!methodAlreadyInBaseClass) {
        needsClosing = true;
        if (method->isStatic() && (ownerClass && !ownerClass->isNamespace()))
            s << "static ";

        const QString returnType = ToDartConversions::type(method->type());

        if (method->functionType() == AbstractMetaFunction::GetAttroFunction) {
            // A getter
            ADD_READBILITY_TAG(1025)
            s << QString("%1 get %2 {").arg(returnType, methodName);
        } else if (method->functionType() == AbstractMetaFunction::SetAttroFunction) {
            // A setter
            ADD_READBILITY_TAG(1026)
            s << QString("%1 set %2(%3) {")
                     .arg(returnType, methodName,
                          ToDartConversions::functionArguments(method, true));
        } else {
            ADD_READBILITY_TAG(1027)
            s << QString("// %1 \n").arg(method->signature());
            s << QString("%1 %2(%3) {")
                     .arg(returnType, methodName,
                          ToDartConversions::functionArguments(
                              method, true,
                              ToDartConversions::Options(
                                  ToDartConversions::Option::StringInsteadOfQString)
                                  | ToDartConversions::Option::ReplaceReservedDartKeyword));
        }

        const auto templateHash = DartGenerator::instance()->templateHash();
        const bool processInstantiations = Dartagnan::hasTemplateArguments(method);

        AbstractMetaTypeList templateInstantiations;
        if (processInstantiations)
            templateInstantiations = templateHash.value(method->ownerClass());

        const bool hasTemplateInstantiations = !templateInstantiations.isEmpty();
        if (!hasTemplateInstantiations)
            templateInstantiations << AbstractMetaType();

        Dartagnan::sortTemplatesByHierarchy(templateInstantiations);
        auto printMethod = [&s, method, returnType,
                            &templateInstantiations](AbstractMetaType templateInstantiation) {
            ADD_READBILITY_TAG(1028)

            const AbstractMetaClass *metaClass = method->ownerClass();
            const QString className = metaClass ? metaClass->name() : QString();

            if (hasType(templateInstantiation)) {
                s << QString("if (this is %1%2) {")
                         .arg(className, ToDartConversions::templateParams(templateInstantiation));
            }

            QString cFunctionSymbolName;
            if (method->isVirtual()) {
                cFunctionSymbolName =
                    QString("cFunctionSymbolName(%1)").arg(Dartagnan::idForFunction(method));
            } else {
                cFunctionSymbolName =
                    QString("'%1'").arg(ToDartConversions::cFunctionNameText(method));
            }

            s << QString("final %1 func = _dylib.lookup<ffi.NativeFunction<%2>>(%3).asFunction();")
                     .arg(FFITypedefs::typedefName(method, templateInstantiation))
                     .arg(FFITypedefs::ffiTypedefName(method, templateInstantiation))
                     .arg(cFunctionSymbolName);

            const QString arguments =
                ToDartConversions::callArguments(method, templateInstantiation);

            const bool returnsTemplateArgument = hasType(method->type())
                && method->type().typeUsagePattern() == AbstractMetaType::TemplateArgument;
            const AbstractMetaType type = returnsTemplateArgument
                ? Dartagnan::instantiationForTemplateArgument(templateInstantiation, method->type())
                : method->type();

            QString returnExpr;
            const bool needsReturn = hasType(type) && !method->isVoid();

            if (ToCConversions::methodReturnsBool(method, templateInstantiation)) {
                ADD_READBILITY_TAG(1029)
                returnExpr = QString("func(%1) != 0").arg(arguments);
            } else if (!hasType(type) || method->isVoid()) {
                ADD_READBILITY_TAG(1030)
                returnExpr = QString("func(%1)").arg(arguments);
            } else if (type.isPrimitive() && type.name() == "char") {
                ADD_READBILITY_TAG(1031)
                returnExpr = QString("String.fromCharCode(func(%1))").arg(arguments);
            } else if (type.isPrimitive() || type.isEnum() || type.isFlags()) {
                ADD_READBILITY_TAG(1031)
                returnExpr = QString("func(%1)").arg(arguments);
            } else if (Dartagnan::typeIsConstCharPtr(type)) {
                ADD_READBILITY_TAG(1032)
                s << QString("ffi.Pointer<Utf8> result = func(%1);").arg(arguments);
                returnExpr = QString("result.toDartString()");
            } else if (type.isValuePointer() || type.isObject() || Dartagnan::typeIsRef(type)
                       || Dartagnan::typeIsValue(type)) {
                ADD_READBILITY_TAG(1033)
                s << QString("ffi.Pointer<void> result = func(%1);").arg(arguments);
                const QString needsAutoDelete = Dartagnan::typeIsValue(type) ? "true" : "false";

                returnExpr =
                    QString("%1.fromCppPointer(result, %2)")
                        .arg(ToDartConversions::className(
                                 type,
                                 FunctionFormatOptions(
                                     Dartagnan::FunctionFormatOption::TemplateParams)
                                     | Dartagnan::FunctionFormatOption::QualifiedWithScope),
                             needsAutoDelete);
            } else {
                ADD_READBILITY_TAG(1034)
                s << QString("ffi.Pointer<void> result = func(%1);").arg(arguments);
                returnExpr = QString("result");
            }

            const QString returnStatement = needsReturn ? QString("return") : QString();

            if (needsReturn) {
                if (returnsTemplateArgument) {
                    // Dart needs a cast to T. Even though this should be obvious to the compiler.
                    s << QString("%1 (%2 as %3);").arg(returnStatement, returnExpr, returnType);
                } else {
                    s << QString("%1 %2;").arg(returnStatement, returnExpr);
                }

                if (hasType(templateInstantiation)) {
                    s << "}"; // end if (this is Foo<T>)
                    const bool isLastTemplateInstantiation =
                        templateInstantiation == templateInstantiations.last();
                    if (isLastTemplateInstantiation) {
                        s << "print(\"Unreachable, but required, due to null safety we need to "
                             "return something\");";
                        s << "throw Error();";
                    }
                }
            } else {
                s << QString("%1;").arg(returnExpr);
                if (hasType(templateInstantiation))
                    s << "}"; // end if (this is Foo<T>)
            }
        };

        for (const AbstractMetaType &templateInstantiation : templateInstantiations) {
            printMethod(templateInstantiation);
        }

        s << "\n";
    }

    if (method->isVirtual()) {
        if (needsClosing)
            s << "}";
        ADD_READBILITY_TAG(1035)
        QString args = ToDartConversions::functionArguments(method, false,
                                                            ToDartConversions::Option::ForTypedef);
        if (args.isEmpty())
            args = "ffi.Pointer<void> thisCpp";
        else
            args.prepend("ffi.Pointer<void> thisCpp, ");
        s << QString("static %1 %2_calledFromC(%3) {\n")
                 .arg(
                     ToDartConversions::type(method->type(), ToDartConversions::Option::ForTypedef),
                     methodName, args);
        const QString downcast = method->ownerClass()->baseClass()
            ? QString("as %1").arg(method->ownerClass()->name())
            : QString();
        s << QString("var dartInstance = %1.s_dartInstanceByCppPtr[thisCpp.address] %2;")
                 .arg(Dartagnan::baseMostBaseClass(method->declaringClass()), downcast);

        s << "if (dartInstance == null) {";
        const QString className = method->ownerClass() ? method->ownerClass()->name() : QString();
        s << QString("print(\"Dart instance not found for %1::%2! (${thisCpp.address})\");")
                 .arg(className, method->signature());
        s << "throw Error();\n";
        s << "}";

        const QString call = QString("dartInstance.%1(%2);\n")
                                 .arg(methodName, ToDartConversions::directCallArguments(method));

        if (method->isVoid()) {
            ADD_READBILITY_TAG(1036)
            s << call;
        } else {
            ADD_READBILITY_TAG(1037)
            s << "final result = " << call;
            s << "return ";

            if (isBool(method->type())) {
                s << "result ? 1 : 0;";
            } else if (method->type().isValuePointer() || method->type().isObject()
                       || method->type().isValue()) {
                s << "result.thisCpp;";
            } else if (ToDartConversions::type(method->type()) == "String") {
                s << " result.toNativeUtf8();";
            } else {
                s << " result;";
            }
        }
    }
}

DartSignalHandlerPrinter::DartSignalHandlerPrinter(TextStream &s, const AbstractMetaFunction *func)
    : DartFunctionPrinterBase(s, func)
{
    ADD_READBILITY_TAG(1077);
    const QString className = func->ownerClass()->name();
    QString signalName = func->name();
    signalName[0] = signalName[0].toUpper();
    const QString signalHandlerName = QString("on%1").arg(signalName);


    s << QString("void %1(Function callback, {QObject? context}) {").arg(signalHandlerName);
    s << "final SignalHandler func = ";
    s << "_dylib.lookup<ffi.NativeFunction<SignalHandler_FFI>>(";
    s << QString("'%1').asFunction();")
             .arg(ToCConversions::functionName(func, {}, FunctionFormatOption::ForSignalHandler));
    const QString callbackName = QString("%1_callback").arg(signalHandlerName);
    s << "final dartCallback =";
    s << QString("ffi.Pointer.fromFunction<ffi.Void Function(ffi.Pointer<void>)>(%1);")
             .arg(callbackName);

    s << QString("final callbackMethod = %1;\n").arg(callbackName);
    s << "var handlers = signalHandlerersBySignal[callbackMethod] ?? [];\n";
    s << "handlers.add(callback);\n";
    s << "signalHandlerersBySignal[callbackMethod] = handlers;\n";
    s << "ffi.Pointer<void> contextPtr = context == null ? ffi.nullptr : context.thisCpp;\n";
    s << "func(thisCpp, contextPtr, dartCallback);";
    s << "}";

    s << QString("static void %1_callback(ffi.Pointer<void> thisCpp) {\n").arg(signalHandlerName);
    s << QString("var dartInstance = QObject.s_dartInstanceByCppPtr[thisCpp.address] as %1;")
             .arg(className);

    s << "final signalHandlers =\n";
    s << QString("dartInstance.signalHandlerersBySignal[%1] ?? [];\n").arg(callbackName);
    s << "for (var signalHandler in signalHandlers) {\n";
    s << "    signalHandler()\n;";
    s << "}\n";
}

DartEnumPrinter::DartEnumPrinter(TextStream &s, AbstractMetaEnum metaEnum,
                                 const AbstractMetaClass *context)
    : Printer(s)
{
    const auto values = metaEnum.values();
    const int numEnumerators = values.size();

    if (metaEnum.isAnonymous()) {
        ADD_READBILITY_TAG(1076)
        s << "// Anonymous enum \n";
        for (AbstractMetaEnumValue value : values)
            s << QString("static const %1 = %2;").arg(value.name(), value.value().toString());
    } else {
        ADD_READBILITY_TAG(1038)
        const QString dartName = ToDartConversions::enumName(metaEnum);
        s << QStringLiteral("class %1 {").arg(dartName);
        for (AbstractMetaEnumValue value : values)
            s << QString("static const %1 = %2;").arg(value.name(), value.value().toString());
        s << "}";
    }
}

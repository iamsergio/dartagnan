/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "ExternC_ImplPrinter.h"
#include "generator_dart.h"
#include "to_CppWrapper.h"

#include <QDebug>

#include <vector>

using namespace Dartagnan;

ExternCImplPrinter::ExternCImplPrinter(TextStream &s, const AbstractMetaClass *metaClass,
                                       AbstractMetaType instantiation)
    : ExternCPrinterBase(s, metaClass, instantiation)
{
    const QString wrapperClassName = ToCppWrapperConversions::wrapperClassName(metaClass);
    if (!metaClass->isNamespace()) {
        ADD_READBILITY_TAG(1049)
        s << ToCConversions::finalizerSignature(metaClass, {}, instantiation) << "{";
        s << QString("delete reinterpret_cast<%1 *>(cppObj);")
                 .arg(ToCppWrapperConversions::wrapperClassName(
                     metaClass, FunctionFormatOption::TemplateParams, instantiation));
        s << "}";
    }

    // Also print the C getters/setters impl for members:

    const auto methods = metaClass->functions();
    bool seenDtor = false;
    for (auto m : methods) {
        auto method = m.get();
        if (m_seenFunctions.functionWasSeen(method))
            continue;
        if (method->isDestructor())
            seenDtor = true;

        m_seenFunctions.markAsSeen(method);
        createExternCMethodPrinter(s, method, instantiation);

        static const bool supportsQtSignals =
            DartGenerator::instance()->m_optionsFromJson.supportsQtSignals;

        if (supportsQtSignals && method->isSignal())
            ExternCSignalHandlerPrinter signalHandler(s, method);
    }

    if (!seenDtor && !metaClass->isNamespace()) {
        auto dtor = Dartagnan::createDestructor(metaClass);
        ExternCDtorImplPrinter dtorPrinter(s, dtor.get(), instantiation);
    }

    auto getters =
        Dartagnan::syntheticGetters(metaClass, Dartagnan::GeneratedCodeType_Cppwrapper_impl);
    auto setters =
        Dartagnan::syntheticSetters(metaClass, Dartagnan::GeneratedCodeType_Cppwrapper_impl);
    for (const auto &func : getters)
        createExternCMethodPrinter(s, func.get(), instantiation);
    for (const auto &func : setters)
        createExternCMethodPrinter(s, func.get(), instantiation);

    if (m_metaClass->isPolymorphic()) {
        s << ToCConversions::registerCallbackFunctionSignature(metaClass);
        s << "{";
        ADD_READBILITY_TAG(1048)
        s << "auto wrapper = fromWrapperPtr(ptr);\n";
        s << "switch (methodId) {\n";

        for (auto m : methods) {
            auto method = m.get();
            if (!method->isVirtual() || !Dartagnan::acceptsMethod(method))
                continue;

            s << QString("case %1:\n").arg(Dartagnan::idForFunction(method));
            s << QString("wrapper->%1 = %2;")
                     .arg(ToCppWrapperConversions::virtualCallbackMemberName(method),
                          QString("reinterpret_cast<%1::%2>(callback)")
                              .arg(wrapperClassName,
                                   ToCppWrapperConversions::virtualCallbackTypedefName(method)));
            s << "break;";
        }
        s << "}\n"; // switch
        s << "}";
    }
}

std::unique_ptr<MethodImplPrinterBase> createExternCMethodPrinter(TextStream &s,
                                                                  const AbstractMetaFunction *func,
                                                                  AbstractMetaType instantiation)
{
    if (!Dartagnan::acceptsMethod(func, RejectedMethod::RejectedMethod_Default))
        return {};

    MethodImplPrinterBase *printer = nullptr;
    if (func->isConstructor()) {
        printer = new ExternCCtorImplPrinter(s, func, instantiation);
    } else if (func->isDestructor()) {
        printer = new ExternCDtorImplPrinter(s, func, instantiation);
    } else if (func->functionType()
               == AbstractMetaFunction::GetAttroFunction) { // TODO: Find out of this is the best
                                                            // way to mark our getters and setters
        printer = new ExternCGetterImplPrinter(s, func, instantiation);
    } else if (func->functionType() == AbstractMetaFunction::SetAttroFunction) {
        printer = new ExternCSetterImplPrinter(s, func, instantiation);
    } else {
        printer = new ExternCMethodImplPrinter(s, func, instantiation);
    }

    return std::unique_ptr<MethodImplPrinterBase>(printer);
}

ExternCMethodImplPrinter::ExternCMethodImplPrinter(TextStream &s,
                                                   const AbstractMetaFunction *method,
                                                   AbstractMetaType instantiation)
    : MethodImplPrinterBase(s, method, instantiation)
{
    ADD_READBILITY_TAG(1050)

    const bool isFinal = method->attributes() & AbstractMetaFunction::FinalCppMethod;

    s << QString("//%1\n").arg(method->signature());

    const FunctionFormatOptions options = FunctionFormatOption::StringInsteadOfQString;
    s << ToCConversions::functionSignature(method, options, instantiation);
    s << "{";

    s << ToCConversions::argumentCasts(method, options, instantiation);

    if (needsReturn())
        s << "const auto &result = ";

    const QString argsCallText = ToCppWrapperConversions::callArguments(
        method, Dartagnan::GeneratedCodeType_FFI_C, instantiation);
    QString returnText;

    if (method->isStatic()) {
        ADD_READBILITY_TAG(1068)
        const QString wrapperName = ToCppWrapperConversions::qualifiedWrapperMethodName(
            method, FunctionFormatOption::TemplateParams, instantiation);
        returnText = QString("%1(%2)").arg(wrapperName, argsCallText);
    } else if (!method->ownerClass()) {
        // global func
        ADD_READBILITY_TAG(1012)
        returnText = QString("%1(%2)").arg(method->name(), argsCallText);
    } else {
        if (method->isPublic()) {
            // Since method is public, call target class directly

            if (method->isVirtual() && !isFinal) {
                ADD_READBILITY_TAG(1016)

                returnText =
                    QString("[&]{"
                            "auto targetPtr = fromPtr(thisObj);"
                            "auto wrapperPtr = dynamic_cast<%1*>(targetPtr);"
                            "if (wrapperPtr) {"
                            "    return wrapperPtr->%2_nocallback(%3);"
                            "} else {"
                            "    return targetPtr->%4(%5);"
                            "}"
                            "}()")
                        .arg(ToCppWrapperConversions::wrapperClassName(method->ownerClass()),
                             method->originalName(), argsCallText, method->originalName(),
                             argsCallText);
            } else {
                ADD_READBILITY_TAG(1010)

                returnText = QString("fromPtr%1(thisObj)->%2(%3)")
                                 .arg(ToCppWrapperConversions::templateParams(instantiation),
                                      method->originalName(), argsCallText);

                if (method->type().isEnum()) {
                    // Cast to int. Required if "enum class"
                    returnText = QString("int(%1)").arg(returnText);
                }
            }
        } else if (method->isProtected()) {
            ADD_READBILITY_TAG(1011)
            // It's protected, so we go through an indirection. This will only work when the
            // instance was created in dart. For something created in C++, it won't have a wrapper,
            // this will fail. User shouldn't call these protected methods. We'll need to hide them
            // in the dart class
            if (method->isVirtual()) {
                ADD_READBILITY_TAG(1074)
                returnText = QString("fromWrapperPtr%1(thisObj)->%2_nocallback(%3)")
                                 .arg(ToCppWrapperConversions::templateParams(instantiation),
                                      method->name(), argsCallText);
            } else {
                ADD_READBILITY_TAG(1073)
                returnText = QString("fromWrapperPtr%1(thisObj)->%2(%3)")
                                 .arg(ToCppWrapperConversions::templateParams(instantiation),
                                      method->originalName(), argsCallText);
            }
        } else {
            // private methods don't reach here
            Q_ASSERT(false);
        }
    }

    const AbstractMetaType actualType = Dartagnan::actualType(method->type(), instantiation);

    const bool isNonVoid = hasType(actualType);
    const bool isConstant = isNonVoid && actualType.isConstant();
    const bool isObject = isNonVoid && actualType.isObject();
    const bool isValue = isNonVoid && actualType.isValue();
    const bool isValuePointer = isNonVoid && actualType.isValuePointer();
    const bool isReference = isNonVoid && Dartagnan::isReference(actualType);
    const bool isPrimitive = isNonVoid && actualType.isPrimitive();

    if (!isPrimitive) {
        if (isValue && !isReference) {
            ADD_READBILITY_TAG(1072)
            returnText =
                QString("new Dartagnan::ValueWrapper<%1>{%2}")
                    .arg(ToCppWrapperConversions::returnType(m_method, instantiation), returnText);
        } else if (isReference) {
            if (isConstant) {
                ADD_READBILITY_TAG(1071)
                returnText =
                    QString("const_cast<void*>(static_cast<const void*>(&%1))").arg(returnText);
            } else {
                ADD_READBILITY_TAG(1070)
                returnText = "&" + returnText;
            }
        } else if (isObject || isValuePointer || isValue) {
            if (isConstant) {
                ADD_READBILITY_TAG(1069)
                returnText =
                    QString("const_cast<void*>(static_cast<const void*>(%1))").arg(returnText);
            }
        }
    }

    s << returnText + ";";

    // Delete "const char *" arguments, if any. They were allocated in dart with "toNativeUtf8()"
    for (AbstractMetaArgument arg : method->arguments()) {
        const AbstractMetaType actualType = Dartagnan::actualType(arg.type(), instantiation);
        const bool isString = actualType.name() == "char" && actualType.isPointer();
        const bool isQString = actualType.name() == "QString";

        if (isString || isQString) {
            const QString suffix = isQString ? "_" : "";
            s << QString("free((char*)%1%2);\n").arg(arg.name(), suffix);
        }
    }

    if (needsReturn())
        s << "return result;";
}

ExternCCtorImplPrinter::ExternCCtorImplPrinter(TextStream &s, const AbstractMetaFunction *ctor,
                                               AbstractMetaType instantiation)
    : MethodImplPrinterBase(s, ctor, instantiation)
{
    const FunctionFormatOptions options = FunctionFormatOption::StringInsteadOfQString;
    s << ToCConversions::functionSignature(ctor, options, instantiation) << "\n";
    s << "{\n";
    s << ToCConversions::argumentCasts(ctor, options, instantiation);
    ADD_READBILITY_TAG(1056);
    s << QString("auto ptr = new %1(%2);")
             .arg(ToCppWrapperConversions::wrapperClassName(
                 ctor->ownerClass(), FunctionFormatOption::TemplateParams, instantiation))
             .arg(ToCppWrapperConversions::callArguments(ctor, Dartagnan::GeneratedCodeType_FFI_C,
                                                         instantiation));
    s << "return reinterpret_cast<void*>(ptr);";
}

ExternCDtorImplPrinter::ExternCDtorImplPrinter(TextStream &s, const AbstractMetaFunction *method,
                                               AbstractMetaType instantiation)
    : MethodImplPrinterBase(s, method, instantiation)
{
    s << ToCConversions::functionSignature(method, {}, instantiation) << "\n";
    s << "{\n";
    ADD_READBILITY_TAG(1055);
    s << QString("delete fromPtr%1(thisObj);")
             .arg(ToCppWrapperConversions::templateParams(instantiation));
}

ExternCGetterImplPrinter::ExternCGetterImplPrinter(TextStream &s, const AbstractMetaFunction *func,
                                                   AbstractMetaType instantiation)
    : MethodImplPrinterBase(s, func, instantiation)
{
    s << ToCConversions::functionSignature(func) << "\n";
    s << "{\n";

    if (func->isStatic()) {
        ADD_READBILITY_TAG(1054);
        s << QString("return %1::%2;")
                 .arg(ToCppWrapperConversions::wrapperClassName(func->ownerClass()),
                      func->fieldName());
    } else {
        ADD_READBILITY_TAG(1058);
        s << QString("return fromPtr(thisObj)->%1;").arg(func->fieldName());
    }
}

ExternCSetterImplPrinter::ExternCSetterImplPrinter(TextStream &s, const AbstractMetaFunction *func,
                                                   AbstractMetaType instantiation)
    : MethodImplPrinterBase(s, func, instantiation)
{
    s << ToCConversions::functionSignature(func) << "\n";
    s << "{\n";

    auto arg = func->arguments().constFirst();

    if (func->isStatic()) {
        ADD_READBILITY_TAG(1059);
        s << QString("%1::%2 = %3;")
                 .arg(ToCppWrapperConversions::wrapperClassName(func->ownerClass()),
                      func->fieldName(), arg.name());
    } else {
        ADD_READBILITY_TAG(1057);
        s << QString("fromPtr(thisObj)->%1 = %2;").arg(func->fieldName(), arg.name());
    }
}

ExternCSignalHandlerPrinter::ExternCSignalHandlerPrinter(TextStream &s,
                                                         const AbstractMetaFunction *func)
    : MethodImplPrinterBase(s, func)
{
    ADD_READBILITY_TAG(1079)
    s << ToCConversions::functionSignature(func, FunctionFormatOption::ForSignalHandler) << "\n";
    s << "{\n";

    const QString className = func->ownerClass()->name();
    s << QString("auto instance = reinterpret_cast<%1 *>(thisObj);\n").arg(className);
    s << "auto context = reinterpret_cast<QObject *>(contextQObject);\n";
    s << QString("QObject::connect(instance, &%1::%2, context ? context : instance, [thisObj, "
                 "callback] {\n")
             .arg(className, func->name());
    s << "typedef void (*SignalHandler_callback)(void *);\n";
    s << "auto dartCallback = reinterpret_cast<SignalHandler_callback>(callback);\n";
    s << "dartCallback(thisObj);});\n";
}

/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "generator_cppwrapper_impl.h"
#include "abstractmetalang.h"
#include "fileout.h"
#include "printers.h"
#include "printers/ExternC_ImplPrinter.h"
#include "type_conversions/to_CppWrapper.h"
#include "typedatabase.h"
#include "typesystem.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>

using namespace Dartagnan;

DartFFICPPGenerator::DartFFICPPGenerator()
    : m_valueWrapperContents(readSnippet("ValueWrapper.h"))
{
}

QString DartFFICPPGenerator::fileNameSuffix() const
{
    return {};
}

QString DartFFICPPGenerator::fileNameForContext(const GeneratorContext &context) const
{
    const QString scope = m_optionsFromJson.scopeForType(context.metaClass());
    if (scope.isEmpty())
        return QStringLiteral("dart/ffi/%1_c.cpp").arg(context.metaClass()->name());

    return QStringLiteral("dart/ffi/%1/%2_c.cpp").arg(scope, context.metaClass()->name());
}

void DartFFICPPGenerator::generateClass(TextStream &s, const GeneratorContext &classContext)
{
    s << licenseComment();

    QString filename = absoluteFileNameForContext(classContext);

    m_generatedFileNames << filename;
    auto metaClass = classContext.metaClass();
    s << QStringLiteral("#include \"%1_c.h\"\n\n").arg(metaClass->name());

    s << QStringLiteral("\n#include <iostream>\n");
    s << QStringLiteral("\n#include <cassert>\n");
    s << "\n";

    s << m_valueWrapperContents;
    if (metaClass->isNamespace()) {
        ExternCImplPrinter externCPrinter(s, metaClass);
    } else {
        generateClass(s, metaClass);
    }
}

void DartFFICPPGenerator::generateClass(TextStream &s, const AbstractMetaClass *metaClass)
{
    {
        const auto methods = metaClass->functions();
        NamespacePrinter nsPrinter(s, QStringLiteral("%1_wrappersNS").arg(packageName()));

        // Add a namespace for the scope as well:
        auto scopeNSPrinter = m_optionsFromJson.namespacePrinterForType(s, metaClass);

        bool seenDtor = false;
        for (auto m : methods) {
            auto method = m.get();
            if (m_seenFunctions.functionWasSeen(method))
                continue;

            m_seenFunctions.markAsSeen(method);

            if (Dartagnan::functionIsRemoved(method))
                continue;

            auto methodPrinter = createMethodPrinter(s, method);
            if (method->isDestructor())
                seenDtor = true;
        }

        if (!seenDtor) {
            auto dtor = Dartagnan::createDestructor(metaClass);
            DtorImplPrinter dtorPrinter(s, dtor.get());
        }

        s << "\n";
    }

    ADD_READBILITY_TAG(1013);
    s << ToCppWrapperConversions::templateString(metaClass);
    s << QString("static %1* fromPtr(void *ptr)\n")
             .arg(ToCppWrapperConversions::qualifiedClassName(metaClass,
                                                              FunctionFormatOption::TemplateArgs));
    s << "{";
    s << QString("return reinterpret_cast<%1*>(ptr);")
             .arg(ToCppWrapperConversions::qualifiedClassName(metaClass,
                                                              FunctionFormatOption::TemplateArgs));
    s << "}";
    const QString wrapperClassName =
        ToCppWrapperConversions::wrapperClassName(metaClass, FunctionFormatOption::TemplateArgs);
    ADD_READBILITY_TAG(1014);
    s << ToCppWrapperConversions::templateString(metaClass);
    s << QString("static %1* fromWrapperPtr(void *ptr)\n").arg(wrapperClassName);
    s << "{";
    s << QString("return reinterpret_cast<%1*>(ptr);").arg(wrapperClassName);
    s << "}";

    if (metaClass->templateArguments().isEmpty()) {
        ExternCImplPrinter externCPrinter(s, metaClass);
    } else {
        const AbstractMetaTypeList instantiations = m_templateHash.value(metaClass);
        for (AbstractMetaType instantiation : instantiations) {
            ExternCImplPrinter externCPrinter(s, metaClass, instantiation);
        }
    }
}

QString DartFFICPPGenerator::moduleFileName() const
{
    return QString("%1.cpp").arg(packageName());
}

QString DartFFICPPGenerator::moduleFileNameAbsolutePath() const
{
    return QStringLiteral("%1/%2/dart/ffi/%3")
        .arg(outputDirectory(), dartPackageName(), moduleFileName());
}

bool DartFFICPPGenerator::finishGeneration()
{
    const auto enums = api().globalEnums();
    const auto funcs = api().globalFunctions();
    if (!enums.isEmpty() || !funcs.isEmpty()) {
        FileOut file(moduleFileNameAbsolutePath());
        QFileInfo info(moduleFileNameAbsolutePath());
        m_generatedFileNames << info.absoluteFilePath();
        file.stream << licenseComment();
        file.stream << QStringLiteral("#include \"%1\"\n\n").arg(moduleHeaderFileName());

        for (auto func : funcs) {
            ExternCMethodImplPrinter printer(file.stream, func.get(), {});
        }

        file.done();
    }

    if (!DartagnanGeneratorBase::finishGeneration())
        return false;

    if (m_optionsFromJson.createCMakeLists)
        return createCMakeFile();

    return true;
}

bool DartFFICPPGenerator::doSetup()
{
    return DartagnanGeneratorBase::doSetup();
}

bool DartFFICPPGenerator::createCMakeFile()
{
    const QString filename =
        QStringLiteral("%1/%2/CMakeLists.txt").arg(outputDirectory(), dartPackageName());
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << Q_FUNC_INFO << "Failed to open" << filename << file.errorString();
        return false;
    }

    TextStream s(&file);
    s << "cmake_minimum_required(VERSION 3.10)\n\n";
    s << QStringLiteral("project(%1 LANGUAGES CXX)\n\n").arg(cmakeTargetName());

    s << "set(SOURCES\n";

    for (const QString &filename : m_generatedFileNames) {
        QFileInfo info(filename);

        if (info.dir().dirName() == QLatin1String("ffi"))
            s << QStringLiteral("    dart/ffi/%1\n").arg(info.fileName());
        else // it's scoped
            s << QStringLiteral("    dart/ffi/%1/%2\n").arg(info.dir().dirName(), info.fileName());
    }
    s << ")\n\n";

    s << "set(CMAKE_CXX_VISIBILITY_PRESET hidden)\n\n";

    s << "find_package(Qt6Widgets)\n\n";
    s << QStringLiteral("add_library(%1 SHARED ${SOURCES})\n\n").arg(cmakeTargetName());

    s << "include(GenerateExportHeader)\n";
    s << QString("generate_export_header(%1 EXPORT_FILE_NAME "
                 "\"${CMAKE_CURRENT_BINARY_DIR}/%2\" EXPORT_MACRO_NAME %3)\n")
             .arg(cmakeTargetName(), Dartagnan::exportsHeaderFilename(),
                  Dartagnan::exportMacroName());

    s << QStringLiteral("set_property(TARGET %1 PROPERTY CXX_STANDARD 14)\n\n")
             .arg(cmakeTargetName());

    s << QStringLiteral("target_link_libraries(%1 %2 Qt6::Core Qt6::Widgets)\n")
             .arg(cmakeTargetName(), m_optionsFromJson.targetLinkLibraries);
    s << QStringLiteral("target_include_directories(%1 PUBLIC "
                        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cpp/include>  "
                        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>\n"
                        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)\n\n")
             .arg(cmakeTargetName());

    return true;
}

/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "generator_cppwrapper_header.h"
#include "abstractmetalang.h"
#include "apiextractor.h"
#include "fileout.h"
#include "generator_dart.h"
#include "printers/Cpp_HeaderPrinter.h"
#include "printers/ExternC_HeaderPrinter.h"
#include "type_conversions/to_CppWrapper.h"
#include "typedatabase.h"
#include "typesystem.h"

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QProcess>

#include <memory>

using namespace Dartagnan;

static std::unique_ptr<ClassPrinter> classPrinterFor(TextStream &s,
                                                     const AbstractMetaClass *metaClass)
{
    if (metaClass->isPolymorphic())
        return std::unique_ptr<ClassPrinter>(new PolymorphicClassPrinter(s, metaClass));

    return std::unique_ptr<ClassPrinter>(new NonPolymorphicClassPrinter(s, metaClass));
}

static IncludeList includesFor(const TypeEntry *typeEntry)
{
    IncludeList includes;

    if (auto ce = typeEntry)
        includes << ce->include() << ce->extraIncludes();

    return includes;
}

static IncludeList includesFor(const AbstractMetaClass *metaClass)
{
    IncludeList includes = includesFor(metaClass->typeEntry());

    const AbstractMetaTypeList templateInstantiations =
        DartGenerator::instance()->templateHash().value(metaClass);
    for (AbstractMetaType templateInstantiation : templateInstantiations) {
        const auto templateParams = templateInstantiation.instantiations();
        for (auto templateParam : templateParams) {
            if (auto metaClass = classForType(templateParam)) {
                includes += includesFor(metaClass->typeEntry());
            }
        }
    }

    return includes;
}

static IncludeList includesFor(const AbstractMetaFunction *func)
{
    return includesFor(func->typeEntry());
}

static QString includeStatement(Include inc)
{
    if (inc.type() == Include::LocalPath) {
        return QStringLiteral("#include \"%1\"").arg(inc.name());
    } else {
        return QStringLiteral("#include <%1>").arg(inc.name());
    }
}

template<typename T>
static QStringList includesStrListFor(const T *meta)
{
    QStringList includeList;
    const IncludeList includes = includesFor(meta);
    for (const Include &include : includes) {
        if (include.isValid() && !includeList.contains(includeStatement(include)))
            includeList << includeStatement(include);
    }

    return includeList;
}

static QStringList includesStrListFor(const IncludeList &includes)
{
    QStringList includeList;
    for (const Include &include : includes) {
        if (include.isValid() && !includeList.contains(includeStatement(include)))
            includeList << includeStatement(include);
    }

    return includeList;
}

template<typename T>
static QString includesStrFor(const T *meta)
{
    return includesStrListFor(meta).join('\n');
}

static QString includesStrFor(const AbstractMetaFunctionCList &funcs)
{
    IncludeList includes;
    for (auto func : funcs) {
        includes << includesFor(func.get());
    }

    return includesStrListFor(includes).join("\n");
}

DartFFIHeaderGenerator::DartFFIHeaderGenerator()
{
}

DartFFIHeaderGenerator::~DartFFIHeaderGenerator()
{
}

QString DartFFIHeaderGenerator::fileNameSuffix() const
{
    return QStringLiteral("my-suffix");
}

QString DartFFIHeaderGenerator::fileNameForContext(const GeneratorContext &context) const
{
    const QString scope = m_optionsFromJson.scopeForType(context.metaClass());
    if (scope.isEmpty())
        return QStringLiteral("dart/ffi/%1_c.h").arg(context.metaClass()->name());

    return QStringLiteral("dart/ffi/%1/%2_c.h").arg(scope, context.metaClass()->name());
}

QString DartFFIHeaderGenerator::globalCIncludeFileName() const
{
    return QStringLiteral("%1/%2/dart/ffi/c_%3.h")
        .arg(outputDirectory(), dartPackageName(), TypeDatabase::instance()->defaultPackageName());
}

void DartFFIHeaderGenerator::generateClass(TextStream &s, const GeneratorContext &classContext)
{
    s << licenseComment();
    generateClass_(s, classContext);
    generateClass_(*m_globalCIncludesStream, classContext, true);
}

void DartFFIHeaderGenerator::generateClass_(TextStream &s, const GeneratorContext &classContext,
                                            bool pureCOnly)
{
    m_generatedFileNames << absoluteFileNameForContext(classContext);
    // s << "#pragma once\n\n";

    const AbstractMetaClass *metaClass = classContext.metaClass();

    if (!pureCOnly) {
        ADD_READBILITY_TAG(1040)
        s << QStringLiteral("#include \"%1\"\n").arg(Dartagnan::exportsHeaderFilename());
        s << includesStrFor(metaClass);
        s << "\n\n";
    }

    if (metaClass->isNamespace()) {
        // Write the C wrappers for the namespace-level functions
        ExternCHeaderPrinter externPrinter(s, metaClass, {}, pureCOnly);
    } else {
        if (!pureCOnly)
            generateClass(s, metaClass);

        if (metaClass->templateArguments().isEmpty()) {
            ExternCHeaderPrinter externPrinter(s, metaClass, {}, pureCOnly);
        } else {
            const AbstractMetaTypeList instantiations = m_templateHash.value(metaClass);
            for (AbstractMetaType instantiation : instantiations) {
                ExternCHeaderPrinter externPrinter(s, metaClass, instantiation, pureCOnly);
            }
        }
    }
}

void DartFFIHeaderGenerator::generateClass(TextStream &s, const AbstractMetaClass *metaClass)
{
    // TODO: More namespaces
    NamespacePrinter nsPrinter(s, ToCppWrapperConversions::wrappersNamespace());

    // Add a namespace for the scope as well:
    auto scopeNSPrinter = m_optionsFromJson.namespacePrinterForType(s, metaClass);

    auto classPrinter = classPrinterFor(s, metaClass);
    classPrinter->printMethods();
    classPrinter->printMembers();
    classPrinter->printVirtualCallbacks();

    s << "\n\n";
}

bool DartFFIHeaderGenerator::doSetup()
{
    auto file = new QFile(globalCIncludeFileName(), qApp);
    file->open(QFile::WriteOnly);
    m_globalCIncludesStream = new TextStream(file);
    *m_globalCIncludesStream << licenseComment();
    *m_globalCIncludesStream << "#include <stdbool.h>\n"
                             << "\n";

    return DartagnanGeneratorBase::doSetup();
}

bool DartFFIHeaderGenerator::finishGeneration()
{
    const auto funcs = api().globalFunctions();
    if (!funcs.isEmpty()) {
        FileOut file(moduleFileNameAbsolutePath());
        QFileInfo info(moduleFileNameAbsolutePath());
        m_generatedFileNames << info.absoluteFilePath();

        file.stream << QStringLiteral("#include \"%1\"\n").arg(Dartagnan::exportsHeaderFilename());
        file.stream << includesStrFor(funcs);
        file.stream << "\n\n";

        file.stream << "extern \"C\" {\n";

        for (auto func : funcs) {
            file.stream << ToCConversions::functionSignature(func.get(),
                                                             FunctionFormatOption::ExportMacro)
                        << ";\n";
        }

        file.stream << "}\n";
        file.done();
    }

    if (!DartagnanGeneratorBase::finishGeneration())
        return false;

    return true;
}

QString DartFFIHeaderGenerator::moduleFileNameAbsolutePath() const
{
    return QStringLiteral("%1/%2/dart/ffi/%3")
        .arg(outputDirectory(), dartPackageName(), moduleHeaderFileName());
}

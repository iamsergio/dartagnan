/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "generator_dart.h"
#include "abstractmetalang.h"
#include "dart_ffi_typedefs.h"
#include "dartagnan.h"
#include "fileout.h"
#include "printers.h"
#include "printers/Dart_printer.h"
#include "to_dart.h"

#include <QDebug>
#include <QFileInfo>
#include <QProcess>

using namespace Dartagnan;

static DartGenerator *s_dartGeneratorInstance = nullptr;

DartGenerator::DartGenerator()
{
    s_dartGeneratorInstance = this;
}

DartGenerator::~DartGenerator()
{
}

DartGenerator *DartGenerator::instance()
{
    return s_dartGeneratorInstance;
}

QString DartGenerator::fileNameSuffix() const
{
    return QStringLiteral("my-suffix");
}

QString DartGenerator::fileNameForContext(const GeneratorContext &context) const
{
    const QString scope = m_optionsFromJson.scopeForType(context.metaClass());

    if (scope.isEmpty())
        return QStringLiteral("dart/lib/src/%1.dart").arg(context.metaClass()->name());

    return QStringLiteral("dart/lib/src/%1/%2.dart").arg(scope, context.metaClass()->name());
}

QString DartGenerator::dartExportsForGlobalScope() const
{
    QStringList result;

    const auto enums = api().globalEnums();
    for (auto metaEnum : enums) {
        if (!metaEnum.isAnonymous())
            result << ToDartConversions::enumName(metaEnum);
    }

    const auto funcs = api().globalFunctions();
    for (auto func : funcs) {
        result << func->name();
    }

    return result.join(",");
}

QString DartGenerator::dartExportsFor(const AbstractMetaClass *metaClass)
{
    if (!metaClass)
        return dartExportsForGlobalScope();

    QStringList result;
    if (metaClass->isNamespace()) {
        for (auto func : metaClass->functions()) {
            if (Dartagnan::acceptsMethod(func.get()))
                result << func->name();
        }
    } else {
        result << metaClass->name();
    }

    for (auto metaEnum : metaClass->enums()) {
        if (!metaEnum.isAnonymous())
            result << ToDartConversions::enumName(metaEnum);
    }

    return result.join(",");
}

void DartGenerator::writeImports(TextStream &s, const AbstractMetaClass *metaClass)
{
    const QString scope = m_optionsFromJson.scopeForType(metaClass);
    const QString relative = scope.isEmpty() ? QString() : "../";

    ADD_READBILITY_TAG(1052)
    s << "import 'dart:ffi' as ffi;";
    s << "import 'package:ffi/ffi.dart';";
    s << QStringLiteral("import '%1TypeHelpers.dart';").arg(relative);

    s << QStringLiteral("import '%1../Bindings.dart';").arg(relative);
    for (const auto &scope : m_optionsFromJson.scopes)
        s << QStringLiteral("import '%1../Bindings_%2.dart' as %3;")
                 .arg(relative, scope.name, scope.name);

    s << QStringLiteral("import '%1../LibraryLoader.dart';").arg(relative);

    ADD_READBILITY_TAG(1051)
    s << "var _dylib = Library.instance().dylib;";

    if (metaClass && !metaClass->isNamespace() && !metaClass->baseClass()) {
        // Print the _finalizer variable
        const QHash<const AbstractMetaClass *, AbstractMetaTypeList> templateHash =
            DartGenerator::instance()->templateHash();

        s << QString("final _finalizerFunc = (String name) {return "
                     "_dylib.lookup<ffi.NativeFunction<ffi.Void Function(ffi.Pointer)>>"
                     "(name);};\n\n");

        s << "Map<String, ffi.NativeFinalizer> _finalizers = {};\n\n";
    }
}

void DartGenerator::generateClass(TextStream &s, const GeneratorContext &classContext)
{
    s << licenseComment();

    auto metaClass = classContext.metaClass();

    writeImports(s, metaClass);

    m_generatedFileNames << absoluteFileNameForContext(classContext);

    if (metaClass->isNamespace()) {
        // print namespace-level functions and enums
        DartNamespacePrinter printer(s, metaClass);
    } else {
        DartClassPrinter printer(s, metaClass);
    }

    QFileInfo info(fileNameForContext(classContext));
    const QString exports = dartExportsFor(metaClass);
    if (!exports.isEmpty()) {
        const QString scope = m_optionsFromJson.scopeForType(metaClass);

        QString contents = m_exportsFileContentsByNamespace.value(scope);
        const QString filename =
            scope.isEmpty() ? info.fileName() : QStringLiteral("%1/%2").arg(scope, info.fileName());
        contents = QStringLiteral("export 'src/%1' show %2;\n").arg(filename, exports) + contents;
        m_exportsFileContentsByNamespace[scope] = contents;
    }
}

bool DartGenerator::finishGeneration()
{
    if (!createPubSpecFile())
        return false;

    const auto globalEnums = this->api().globalEnums();
    const auto globalFuncs = api().globalFunctions();
    if (!globalEnums.isEmpty() || !globalFuncs.isEmpty()) {
        FileOut file(dartModuleFileName());
        QFileInfo info(dartModuleFileName());
        m_generatedFileNames << info.absoluteFilePath();

        writeImports(file.stream);

        const QString enumExport = QStringLiteral("export 'src/%1' show %2;\n")
                                       .arg(info.fileName(), dartExportsForGlobalScope());
        m_exportsFileContentsByNamespace[QString()] =
            enumExport + m_exportsFileContentsByNamespace[QString()];

        for (AbstractMetaEnum e : globalEnums) {
            DartEnumPrinter printer(file.stream, e, /*context=*/nullptr);
        }

        for (auto func : globalFuncs) {
            DartMethodPrinter printer(file.stream, func.get());
        }

        file.done();
    }

    if (!createBindingsFiles())
        return false;

    if (!createLibraryLoaderFile())
        return false;

    if (!createTypeHelpersFile())
        return false;

    if (!DartagnanGeneratorBase::finishGeneration())
        return false;

    return true;
}

QString DartGenerator::dartModuleFileName() const
{
    return QStringLiteral("%1/%2/dart/lib/src/%3.dart")
        .arg(outputDirectory(), packageName(), dartPackageName());
}

QString DartGenerator::pubspecFileName() const
{
    return QStringLiteral("%1/%2/dart/pubspec.yaml").arg(outputDirectory(), packageName());
}

QString DartGenerator::exportsFileName(const QString &suffix) const
{
    const QString actualSuffix = suffix.isEmpty() ? QString() : QStringLiteral("_%1").arg(suffix);

    return QStringLiteral("%1/%2/dart/lib/Bindings%3.dart")
        .arg(outputDirectory(), packageName(), actualSuffix);
}

QString DartGenerator::libraryLoaderFileName() const
{
    return QStringLiteral("%1/%2/dart/lib/LibraryLoader.dart")
        .arg(outputDirectory(), packageName());
}

QString DartGenerator::typeHelpersFileName() const
{
    return QStringLiteral("%1/%2/dart/lib/src/TypeHelpers.dart")
        .arg(outputDirectory(), packageName());
}

bool DartGenerator::createPubSpecFile()
{
    QString pubSpecContents = readSnippet("pubspec.yaml");
    if (pubSpecContents.isEmpty())
        return false;

    pubSpecContents = pubSpecContents.arg(dartPackageName(), "Bindings");

    return createFile(pubspecFileName(), pubSpecContents);
}

bool DartGenerator::createBindingsFiles()
{
    if (!createBindingsFile())
        return false;

    for (const auto &ns : m_optionsFromJson.scopes) {
        if (!createBindingsFile(ns.name))
            return false;
    }

    return true;
}

bool DartGenerator::createBindingsFile(const QString &ns)
{
    const QString contents = licenseComment() + m_exportsFileContentsByNamespace[ns];
    return createFile(exportsFileName(ns), contents);
}

bool DartGenerator::createLibraryLoaderFile()
{
    const QString contents =
        licenseComment() + readSnippet("LibraryLoader.dart").arg(m_optionsFromJson.bindingsLibrary);

    return createFile(libraryLoaderFileName(), contents);
}

bool DartGenerator::createTypeHelpersFile()
{
    const QString typedefs = FFITypedefs::instance().typedefs().join("\n");

    const QString contents = licenseComment() + "import 'dart:ffi' as ffi;\n"
        + QString("import 'package:ffi/ffi.dart';\n") + typedefs;
    return createFile(typeHelpersFileName(), contents);
}

bool DartGenerator::doSetup()
{
    {
        // Register all enums
        auto &er = EnumRegistry::instance();
        for (const AbstractMetaClass *c : api().classes()) {
            for (AbstractMetaEnum e : c->enums())
                er.registerEnum(e, c);
        }

        for (AbstractMetaEnum globalEnum : api().globalEnums())
            er.registerEnum(globalEnum, /*context=*/nullptr);
    }

    return DartagnanGeneratorBase::doSetup();
}

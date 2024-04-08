/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "generator_base.h"
#include "apiextractor.h"
#include "printers.h"
#include "type_conversions/to_C.h"
#include "typedatabase.h"
#include "typesystem.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QProcess>
#include <QString>

DartagnanOptions DartagnanGeneratorBase::m_optionsFromJson = {};

static bool runFormatter(const QString &formatter, const QStringList &arguments)
{
    if (QProcess::execute(formatter, arguments) != 0) {
        qWarning() << Q_FUNC_INFO << "Error running" << formatter << arguments;
        return false;
    }

    return true;
}

static bool runDartFormatter(const QString &filename)
{
    QString cmd = "dart";
    QStringList args = { "format", "--fix", filename };

#ifdef Q_OS_WIN
    cmd = "cmd.exe";
    args = QStringList { "/C", "dart" } + args;
#endif

    return runFormatter(cmd, args);
}

static QString clangFormatExecutable()
{
    const QString defaultClangFormat = "clang-format";
    return qEnvironmentVariable("DARTAGNAN_CLANG_FORMAT", defaultClangFormat);
}

DartagnanGeneratorBase::~DartagnanGeneratorBase()
{
    for (QTextStream *ts : m_textStreams) {
        delete ts->device();
        delete ts;
    }

    m_textStreams.clear();
}

QHash<const AbstractMetaClass *, QVector<AbstractMetaType>>
DartagnanGeneratorBase::templateHash() const
{
    return m_templateHash;
}

bool DartagnanGeneratorBase::finishGeneration()
{
    // Format the generated dart files
    for (const QString &filename : m_generatedFileNames) {
        if (!formatFile(filename)) {
            qWarning() << Q_FUNC_INFO << "Error formating file" << filename;
            return false;
        }
    }

    return true;
}

bool DartagnanGeneratorBase::doSetup()
{
    Dartagnan::createFunctionIdCache();
    constructTemplateHash();

    QFileInfo info(typeSystemFileName());
    const QString dartagnanConfig = QStringLiteral("%1/dartagnan.json").arg(info.absolutePath());

    QFile file(dartagnanConfig);
    if (file.exists()) {
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning() << Q_FUNC_INFO << "Failed to open" << dartagnanConfig;
            return false;
        }

        auto doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject obj = doc.object();
        m_optionsFromJson.targetLinkLibraries =
            obj.value(QStringLiteral("target_link_libraries")).toString();

        m_optionsFromJson.exportsHeaderName =
            obj.value(QStringLiteral("exportsHeaderName")).toString();

        m_optionsFromJson.exportsMacroName =
            obj.value(QStringLiteral("exportsMacroName")).toString();

        m_optionsFromJson.qStringToDartCode =
            obj.value(QStringLiteral("QStringToDartCode")).toString();

        m_optionsFromJson.createCMakeLists =
            obj.value(QStringLiteral("createCMakeLists")).toBool(true);

        m_optionsFromJson.bindingsLibrary =
            obj.value(QStringLiteral("bindingsLibrary")).toString(dartPackageName());

        m_optionsFromJson.supportsQtSignals =
            obj.value(QStringLiteral("supportsQtSignals")).toBool(true);

        for (auto value : obj.value(QStringLiteral("pureVirtualClassOverrides")).toArray()) {
            m_optionsFromJson.pureVirtualClassOverrides.append(value.toString());
        }

        for (auto value : obj.value(QStringLiteral("namespaces")).toArray()) {
            DartagnanOptions::Scope scope;

            scope.name = value.toObject().value("name").toString();
            if (scope.name.isEmpty())
                qFatal("Scopes in dartagnan.json need to have a name");

            for (auto t : value.toObject().value("types").toArray()) {
                scope.types.append(t.toString());
            }

            m_optionsFromJson.scopes.append(scope);
        }
    }

    return true;
}

QString DartagnanGeneratorBase::absoluteFileNameForContext(const GeneratorContext &context) const
{
    const QString scope = m_optionsFromJson.scopeForType(context.metaClass());

    if (scope.isEmpty())
        return QStringLiteral("%1/%2/%3")
            .arg(outputDirectory(), packageName(), fileNameForContext(context));


    return QStringLiteral("%1/%2/%3/%4")
        .arg(outputDirectory(), packageName(), scope, fileNameForContext(context));
}

QString DartagnanGeneratorBase::readSnippet(const QString &name)
{
    // TODO: Cache

    const QString filename = QStringLiteral(":/snippets/%1").arg(name);
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    return file.readAll();
}

bool DartagnanGeneratorBase::createFile(const QString &filename, const QString &contents)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
        return false;

    file.write(contents.toUtf8());
    return true;
}

QTextStream *DartagnanGeneratorBase::streamForFileName(const QString &filename) const
{
    auto it = m_textStreams.find(filename);
    if (it != m_textStreams.end())
        return *it;

    QFileInfo info(filename);
    QDir dir;
    dir.mkpath(info.absolutePath());

    auto file = new QFile(filename);
    if (!file->open(QIODevice::WriteOnly)) {
        qWarning() << Q_FUNC_INFO << "Could not open" << filename << file->errorString();
        delete file;
        return nullptr;
    }

    auto ts = new QTextStream(file);
    m_textStreams.insert(filename, ts);
    return ts;
}

bool DartagnanGeneratorBase::formatFile(const QString &filename)
{
    if (!qEnvironmentVariableIsSet("DARTAGNAN_RUNS_CODE_FORMAT")) {
        // User didn't want dartfmt and clang-format to run
        return true;
    }

    if (filename.endsWith(".dart")) {
        if (!runDartFormatter(filename))
            return false;
    } else if (filename.endsWith(".h") || filename.endsWith(".cpp")) {
        if (!runFormatter(clangFormatExecutable(), { "-i", filename })) {

            qWarning() << "Make sure clang-format is in path. Tried" << clangFormatExecutable()
                       << ". Set the DARTAGNAN_CLANG_FORMAT env variable if needed";

            return false;
        }
    }

    return true;
}

QString DartagnanGeneratorBase::typeSystemFileName() const
{
    return api().typeSystem();
}

QString DartagnanGeneratorBase::dartPackageName() const
{
    return packageName();
}

QString DartagnanGeneratorBase::cmakeTargetName() const
{
    // Same as the package name is fine
    return dartPackageName();
}

QString DartagnanGeneratorBase::moduleHeaderFileName() const
{
    return QString("%1.h").arg(packageName());
}

void DartagnanGeneratorBase::constructTemplateHash()
{
    QHash<const AbstractMetaClass *, AbstractMetaTypeList> hash;

    auto processType = [this](AbstractMetaType type) {
        if (!Dartagnan::hasType(type) || type.instantiations().isEmpty()
            || type.hasTemplateChildren())
            return;
        const AbstractMetaClass *templateClass = Dartagnan::classForType(type);
        auto &list = m_templateHash[templateClass];
        if (list.contains(type))
            return;

        // Looks like there can be different AbstractMetaType instances for the same string
        // representation So check for strings already inserted, before adding to list
        const QString templateArgsStr = ToCConversions::templateArgs(type);
        const bool found =
            std::find_if(list.cbegin(), list.cend(),
                         [templateArgsStr](AbstractMetaType type) {
                             return templateArgsStr == ToCConversions::templateArgs(type);
                         })
            != list.cend();

        if (!found)
            list.append(type);
    };

    for (const AbstractMetaClass *metaClass : api().classes()) {
        for (auto func : metaClass->functions())
            processType(func->type());
    }

    for (auto func : api().globalFunctions()) {
        processType(func->type());
    }
}

std::unique_ptr<AbstractMetaFunction>
Dartagnan::createDestructor(const AbstractMetaClass *metaClass)
{
    auto func = new AbstractMetaFunction();

    func->setName(metaClass->name());
    func->setOwnerClass(metaClass);
    func->setFunctionType(AbstractMetaFunction::DestructorFunction);

    return std::unique_ptr<AbstractMetaFunction>(func);
}

std::unique_ptr<AbstractMetaFunction> Dartagnan::createGetterFor(AbstractMetaField field,
                                                                 GeneratedCodeType codeType)
{
    Q_UNUSED(codeType);
    if (!field.type().isPrimitive())
        return {}; // TODO

    if (field.isPrivate())
        return nullptr;

    if (field.isProtected()) {
        // Not supported yet. C can't access protected C++ functions. We'll need to make more
        // indirections
        return nullptr;
    }

    auto func = new AbstractMetaFunction();

    func->setName(field.name());
    func->setOwnerClass(field.enclosingClass());
    func->setType(field.type());
    func->setFieldName(field.name());
    func->setFunctionType(AbstractMetaFunction::GetAttroFunction);
    if (field.isStatic())
        func->setAttributes(func->attributes() | AbstractMetaFunction::Static);

    return std::unique_ptr<AbstractMetaFunction>(func);
}

std::unique_ptr<AbstractMetaFunction> Dartagnan::createSetterFor(AbstractMetaField field,
                                                                 GeneratedCodeType codeType)
{
    Q_UNUSED(codeType);
    if (!field.type().isPrimitive())
        return nullptr; // TODO

    if (field.type().isConstant() || field.isPrivate()) {
        // We don't give write access to private and constant members
        return nullptr;
    }

    if (field.isProtected()) {
        // Not supported yet. C can't access protected C++ functions. We'll need to make more
        // indirections
        return nullptr;
    }

    auto func = new AbstractMetaFunction();

    func->setName(field.name());
    func->setOwnerClass(field.enclosingClass());
    func->setFunctionType(AbstractMetaFunction::SetAttroFunction);
    if (field.isStatic())
        func->setAttributes(func->attributes() | AbstractMetaFunction::Static);

    AbstractMetaArgumentList args;
    AbstractMetaArgument arg;
    arg.setName(QString("%1_").arg(field.name()));
    arg.setType(field.type());

    func->setArguments({ arg });
    func->setFieldName(field.name());

    return std::unique_ptr<AbstractMetaFunction>(func);
}

std::vector<std::unique_ptr<AbstractMetaFunction>>
Dartagnan::syntheticGetters(const AbstractMetaClass *metaClass, GeneratedCodeType codeType)
{
    if (metaClass->isNamespace()) {
        // Not supported yet. Feel free to comment out and see if tests still pass.
        return {};
    }

    std::vector<std::unique_ptr<AbstractMetaFunction>> functions;

    const AbstractMetaFieldList fields = metaClass->fields();
    for (AbstractMetaField field : fields) {
        if (auto getter = Dartagnan::createGetterFor(field, codeType))
            functions.push_back(std::move(getter));
    }

    return functions;
}

std::vector<std::unique_ptr<AbstractMetaFunction>>
Dartagnan::syntheticSetters(const AbstractMetaClass *metaClass, GeneratedCodeType codeType)
{
    if (metaClass->isNamespace()) {
        // Not supported yet. Feel free to comment out and see if tests still pass.
        return {};
    }

    std::vector<std::unique_ptr<AbstractMetaFunction>> functions;

    const AbstractMetaFieldList fields = metaClass->fields();
    for (AbstractMetaField field : fields) {
        if (auto setter = Dartagnan::createSetterFor(field, codeType))
            functions.push_back(std::move(setter));
    }

    return functions;
}

QString DartagnanOptions::scopeForType(const QString &type) const
{
    for (const auto &scope : scopes) {
        if (scope.types.contains(type))
            return scope.name;
    }

    return QString();
}

QString DartagnanOptions::scopeForType(const AbstractMetaClass *metaClass) const
{
    if (metaClass)
        return scopeForType(metaClass->qualifiedCppName());

    return {};
}

std::unique_ptr<NamespacePrinter>
DartagnanOptions::namespacePrinterForType(TextStream &s, const AbstractMetaClass *metaClass) const
{
    const QString scope = scopeForType(metaClass);
    if (scope.isEmpty())
        return {};

    return std::make_unique<NamespacePrinter>(s, scope);
}

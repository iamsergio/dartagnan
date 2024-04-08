/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#include "abstractmetafield.h"
#include "abstractmetafunction.h"
#include "abstractmetalang.h"
#include "abstractmetatype.h"

#include "dartagnan.h"
#include "typesystem.h"

#include <generator.h>

#include <QHash>
#include <QSet>

#include <memory>

class NamespacePrinter;

namespace Dartagnan {
std::unique_ptr<AbstractMetaFunction> createDestructor(const AbstractMetaClass *metaClass);
std::unique_ptr<AbstractMetaFunction> createGetterFor(AbstractMetaField field,
                                                      GeneratedCodeType codeType);
std::unique_ptr<AbstractMetaFunction> createSetterFor(AbstractMetaField field,
                                                      GeneratedCodeType codeType);

std::vector<std::unique_ptr<AbstractMetaFunction>>
syntheticGetters(const AbstractMetaClass *metaClass, GeneratedCodeType codeType);
std::vector<std::unique_ptr<AbstractMetaFunction>>
syntheticSetters(const AbstractMetaClass *metaClass, GeneratedCodeType codeType);
}

/// @brief Struct for loading dartagnan.json
struct DartagnanOptions
{
    struct Scope
    {
        // The name of this scope, for creation of the Bindings_<name>.dart file
        QString name;

        // The types that should go into this scope
        QStringList types;
    };

    QString targetLinkLibraries;

    QString exportsHeaderName;
    QString exportsMacroName;

    QString qStringToDartCode;

    /// Controls whether we also generate the CMakeLists.txt for building the generated bindings
    bool createCMakeLists = true;

    bool supportsQtSignals = true;

    /// The name of the dll, without "lib" prefix and without so/dll suffixes.
    /// If empty then dartPackageName() is used
    QString bindingsLibrary;

    /// AbstractMetaClass::isAbstract() can be false if the pure-virtual methods have unknown types
    /// use this to override
    QStringList pureVirtualClassOverrides;

    /// List of explicit scopes
    QVector<Scope> scopes;

    QString scopeForType(const QString &type) const;
    QString scopeForType(const AbstractMetaClass *) const;
    std::unique_ptr<NamespacePrinter> namespacePrinterForType(TextStream &,
                                                              const AbstractMetaClass *) const;
};

class DartagnanGeneratorBase : public Generator
{
public:
    ~DartagnanGeneratorBase();

    QHash<const AbstractMetaClass *, QVector<AbstractMetaType>> templateHash() const;
    static QHash<const AbstractMetaFunction *, int> functionIds();

    static QString readSnippet(const QString &name);
    static DartagnanOptions m_optionsFromJson;

protected:
    bool doSetup() override;
    bool finishGeneration() override;
    QString absoluteFileNameForContext(const GeneratorContext &context) const;

    bool createFile(const QString &filename, const QString &contents);

    QTextStream *streamForFileName(const QString &filename) const;

    QString typeSystemFileName() const;
    QString dartPackageName() const;
    QString cmakeTargetName() const;
    QString moduleHeaderFileName() const;

protected:
    QHash<const AbstractMetaClass *, QVector<AbstractMetaType>> m_templateHash;
    Dartagnan::SeenFunctions m_seenFunctions;
    QStringList m_generatedFileNames;

private:
    void constructTemplateHash();
    bool formatFile(const QString &filename);
    mutable QHash<QString, QTextStream *> m_textStreams;
};

/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "generator_base.h"

class QTextStream;

class DartGenerator : public DartagnanGeneratorBase
{
public:
    DartGenerator();
    ~DartGenerator();
    OptionDescriptions options() const override
    {
        return OptionDescriptions();
    }
    const char *name() const override
    {
        return "Dart Generator";
    }
    static DartGenerator *instance();

protected:
    QString fileNameSuffix() const override;
    QString fileNameForContext(const GeneratorContext &context) const override;
    void generateClass(TextStream &s, const GeneratorContext &classContext) override;

    bool doSetup() override;

    bool finishGeneration() override;

private:
    void writeImports(TextStream &s, const AbstractMetaClass *metaClass = nullptr);
    QString dartExportsForGlobalScope() const;
    QString dartExportsFor(const AbstractMetaClass *metaClass);
    QString dartModuleFileName() const;
    QString pubspecFileName() const;
    QString exportsFileName(const QString &suffix = {}) const;
    QString libraryLoaderFileName() const;
    QString typeHelpersFileName() const;
    bool createPubSpecFile();
    bool createBindingsFile(const QString &ns = {});
    bool createBindingsFiles();
    bool createLibraryLoaderFile();
    bool createTypeHelpersFile();

    QStringList m_generatedDartFiles;
    QHash<QString, QString> m_exportsFileContentsByNamespace; // The Bindings_foo.dart files,
                                                              // indexed by "foo" in this example
};

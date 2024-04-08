/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "generator_base.h"

class DartFFICPPGenerator : public DartagnanGeneratorBase
{
public:
    DartFFICPPGenerator();
    OptionDescriptions options() const override
    {
        return OptionDescriptions();
    }
    const char *name() const override
    {
        return "Dart FFI .cpp Generator";
    }

protected:
    QString fileNameSuffix() const override;
    QString fileNameForContext(const GeneratorContext &context) const override;
    void generateClass(TextStream &s, const GeneratorContext &classContext) override;

    bool doSetup() override;

    bool finishGeneration() override;

private:
    void generateClass(TextStream &s, const AbstractMetaClass *metaClass);
    bool createCMakeFile();
    QString moduleFileName() const;
    QString moduleFileNameAbsolutePath() const;
    const QString m_valueWrapperContents;
};

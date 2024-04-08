/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include "generator_base.h"
#include <textstream.h>

#include <QFile>

class DartFFIHeaderGenerator : public DartagnanGeneratorBase
{
public:
    DartFFIHeaderGenerator();
    ~DartFFIHeaderGenerator();
    OptionDescriptions options() const override
    {
        return OptionDescriptions();
    }
    const char *name() const override
    {
        return "Dart FFI .h Generator";
    }

protected:
    QString fileNameSuffix() const override;
    QString fileNameForContext(const GeneratorContext &context) const override;
    void generateClass(TextStream &s, const GeneratorContext &classContext) override;
    bool doSetup() override;
    bool finishGeneration() override;

private:
    /// @brief Returns the file name of the include that declares the whole C API.
    QString globalCIncludeFileName() const;

    void generateClass_(TextStream &s, const GeneratorContext &classContext,
                        bool pureCOnly = false);
    void generateClass(TextStream &s, const AbstractMetaClass *);
    QString moduleFileNameAbsolutePath() const;
    TextStream *m_globalCIncludesStream = nullptr;
};

/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#include <QCoreApplication>
#include <QDebug>
#include <QProcess>

#include <algorithm>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    QStringList arguments = app.arguments();
    arguments.removeAt(0);

    const bool hasGeneratorSet =
        std::any_of(arguments.cbegin(), arguments.cend(),
                    [](const QString &arg) { return arg.startsWith("--generator-set="); });

    if (hasGeneratorSet) {
        qWarning() << "Don't pass --generator-set=, dart will be used by default";
        return 1;
    }

    arguments << "--generator-set=dart"
              << "--skip-deprecated"
              << "--clang-option=-DDARTAGNAN_BINDINGS_RUN";

    return QProcess::execute("shiboken6", arguments);
}

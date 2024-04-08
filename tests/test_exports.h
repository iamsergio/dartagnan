/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

#pragma once

#include <QtCore/QtGlobal>

#if defined(BUILDING_TEST_LIBRARY)
#  define TEST_EXPORT Q_DECL_EXPORT
#else
#  define TEST_EXPORT Q_DECL_IMPORT
#endif

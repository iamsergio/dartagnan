#!/bin/sh -l

# SPDX-FileCopyrightText: 2024 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
#
# SPDX-License-Identifier: MIT
cd /github/workspace/ || exit 1

export TZ=Europe/Berlin
export LC_CTYPE=C.UTF-8
export PATH=$PATH:/home/ubuntu/flutter/bin/:/home/ubuntu/flutter/bin/cache/dart-sdk/bin/:/dartagnan/build-dev/installed/bin/
export LD_LIBRARY_PATH=/dartagnan/build-dev/tests/generated/TestBindings/
export DARTAGNAN_CLANG_FORMAT=clang-format-15

cmake --preset=dev -DCMAKE_INSTALL_PREFIX=/dartagnan/build-dev/installed/ && \
cd build-dev && ninja && ninja install && ctest -j1 --output-on-failure


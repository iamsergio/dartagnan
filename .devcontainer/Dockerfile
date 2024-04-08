#
# This file is part of Dartagnan.
#
# SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
# Author: Sérgio Martins <sergio.martins@kdab.com>
#
# SPDX-License-Identifier: MIT

# Instructions:
# docker build -t dartagnan .
# docker run -it -v /data/sources/dart/dartagnan/:/dartagnan/ -u 1000:1000 dartagnan
# cd /dartagnan/ && cmake --preset=dev -DCMAKE_INSTALL_PREFIX=/dartagnan/build-dev/installed/
# cd build-dev && ninja && ninja install
# cd .. && dart pub get && dart run_tests.dart

# To publish in docker hub:
# docker build -t dartagnan .
# docker run -it dartagnan # and exit
# docker ps # to check sha
# docker export -o mycontainer.tar <container_sha>
# docker import mycontainer.tar
# docker images # to check sha
# docker tag <image_sha> iamsergio/ci-dartagnan
# docker push iamsergio/ci-dartagnan

FROM ubuntu:23.04
MAINTAINER Sergio Martins (sergio.martins@kdab.com)

ENV TZ=Europe/Berlin
ENV LC_CTYPE=C.UTF-8
ENV PATH=$PATH:/home/ubuntu/flutter/bin/:/home/ubuntu/flutter/bin/cache/dart-sdk/bin/:/dartagnan/build-dev/installed/bin/
ENV LD_LIBRARY_PATH=/dartagnan/build-dev/tests/generated/TestBindings/
ENV DARTAGNAN_CLANG_FORMAT=clang-format-15

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt update -qq && apt install -y vim build-essential software-properties-common lld git cmake ninja-build python3 \
    python3-dev clang llvm libclang-15-dev libxslt-dev mesa-common-dev libglu1-mesa-dev libglib2.0-dev libfontconfig \
    libxkbcommon-dev mesa-utils libgl1-mesa-dev libglu1-mesa-dev nlohmann-json3-dev clang-format-15 qt6-base-dev wget curl \
    file unzip zip which xz-utils

RUN ln -sf /usr/lib/x86_64-linux-gnu/libasan.so.8 /usr/lib/libasan.so
RUN ln -sf /usr/bin/qmake6 /usr/bin/qmake

WORKDIR /home/ubuntu
USER ubuntu
RUN git config --global advice.detachedHead false
RUN git clone https://github.com/flutter/flutter.git -b 3.19.5
RUN flutter --version

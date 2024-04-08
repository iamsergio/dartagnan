#
# This file is part of Dartagnan.
#
# SPDX-FileCopyrightText: 2024 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
# Author: Sérgio Martins <sergio.martins@kdab.com>
#
# SPDX-License-Identifier: MIT

# Dockerfile for dartagnan GitHub Action
# Based over .devcontainer/Dockerfile

FROM iamsergio/ci-dartagnan
MAINTAINER Sergio Martins (sergio.martins@kdab.com)

COPY entrypoint.sh /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]

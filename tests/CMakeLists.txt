# This file is part of Dartagnan.
#
# SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.10)

project(TestTarget LANGUAGES CXX)

# Uncomment once Qt bindings are exported too
# set(CMAKE_CXX_VISIBILITY_PRESET hidden)

set(SOURCES
    test.cpp
)

set(CMAKE_AUTOMOC ON)

find_package(Qt6Widgets)


# Enables sanitizers
set(ECM_MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/ECM/modules/")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../cmake" ${ECM_MODULE_DIR})
include(ECMEnableSanitizers)


# The TestTarget is the client C++ library, which we'll generate bindings for
add_library(TestTarget SHARED ${SOURCES})

set_property(TARGET TestTarget PROPERTY CXX_STANDARD 14)

target_compile_definitions(TestTarget PRIVATE BUILDING_TEST_LIBRARY)
target_include_directories(TestTarget
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
)

target_link_libraries(TestTarget Qt::Widgets)

# This file is part of Dartagnan.
#
# SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.9)
project(dartagnan)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_subdirectory(3rdparty/shiboken)

find_package(Qt6Core 6.1 REQUIRED)

set(dartagnan_SRCS
    src/dartagnan.cpp
    src/dart_ffi_typedefs.cpp

    src/Logging.cpp

    # Generators
    src/generator_base.cpp
    src/generator_dart.cpp
    src/generator_cppwrapper_impl.cpp
    src/generator_cppwrapper_header.cpp

    # Helpers to convert types between languages
    src/type_conversions/to_dart.cpp
    src/type_conversions/to_C.cpp
    src/type_conversions/to_CppWrapper.cpp

    # The actual printers
    src/printers/printers.cpp
    src/printers/ExternC_HeaderPrinter.cpp
    src/printers/ExternC_ImplPrinter.cpp
    src/printers/Dart_printer.cpp
    src/printers/Cpp_ImplPrinter.cpp
    src/printers/Cpp_HeaderPrinter.cpp
)

qt_add_resources(DARTAGNAN_RESOURCES dartagnan.qrc)

add_library(dartagnanlib STATIC ${dartagnan_SRCS} ${DARTAGNAN_RESOURCES})

target_include_directories(dartagnanlib
                    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
                    PRIVATE
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/type_conversions/
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/printers
                    ${CMAKE_CURRENT_SOURCE_DIR}/src
                    ${CMAKE_CURRENT_BINARY_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/shiboken/sources/shiboken6/generator/
                    3rdparty/shiboken/sources/shiboken6/ApiExtractor/ )

target_link_libraries(dartagnanlib Qt${QT_MAJOR_VERSION}::Core)

option(DARTAGNAN_DEVELOPER_BUILD "Enables tests" OFF)

if (DARTAGNAN_DEVELOPER_BUILD)
    option(RUN_DART_PUB_GET "Runs \"dart pub get\" for convenience. Required for running run_tests.dart" ON)
    enable_testing()
    add_subdirectory(tests)
    add_test(NAME tests COMMAND dart run_tests.dart ${CMAKE_BINARY_DIR} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
    if (RUN_DART_PUB_GET)
        add_custom_command(
            TARGET dartagnanlib
            POST_BUILD
            COMMAND dart
            ARGS pub get
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    endif()
endif()

add_executable(dartagnan src/main.cpp)
target_link_libraries(dartagnan Qt6::Core)
install(TARGETS dartagnan
        DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")

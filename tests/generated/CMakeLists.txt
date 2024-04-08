cmake_minimum_required(VERSION 3.10)

project(MyBindings LANGUAGES CXX)


set(ECM_MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/ECM/modules/")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake" ${ECM_MODULE_DIR})
include(ECMEnableSanitizers)

include_directories(..)
link_directories(${CMAKE_BINARY_DIR}/..)

add_subdirectory(TestBindings/)

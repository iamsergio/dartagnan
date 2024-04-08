cmake_minimum_required(VERSION 3.10)

project(TestBindings LANGUAGES CXX)

set(SOURCES
    dart/ffi/Virtual2_c.cpp
    dart/ffi/Virtual1_c.cpp
    dart/ffi/UnusedTemplate_c.cpp
    dart/ffi/TestTargetNS_c.cpp
    dart/ffi/PureAbstract_c.cpp
    dart/ffi/POD_c.cpp
    dart/ffi/StructWithStructAsMember_c.cpp
    dart/ffi/MyBaseClass_c.cpp
    dart/ffi/MyDerivedClass_c.cpp
    dart/ffi/DestructorCounter_c.cpp
    dart/ffi/DerivedFromPureAbstract_c.cpp
    dart/ffi/Derived2FromPureAbstract_c.cpp
    dart/ffi/SimpleStruct_c.cpp
    dart/ffi/SimpleObjectStruct_c.cpp
    dart/ffi/Qt_c.cpp
    dart/ffi/QVariant_c.cpp
    dart/ffi/QString_c.cpp
    dart/ffi/QSet_c.cpp
    dart/ffi/QObject_c.cpp
    dart/ffi/QMap_c.cpp
    dart/ffi/QList_c.cpp
    dart/ffi/QHash_c.cpp
    dart/ffi/QEvent_c.cpp
    dart/ffi/QCoreApplication_c.cpp
    dart/ffi/QGuiApplication_c.cpp
    dart/ffi/QColor_c.cpp
    dart/ffi/QByteArray_c.cpp
    dart/ffi/QApplication_c.cpp
    dart/ffi/PureAbstractWithUnknownType_c.cpp
    dart/ffi/NonCopiable_c.cpp
    dart/ffi/NameClashingNS2_c.cpp
    dart/ffi/ExplicitNamespace2/SimpleClash_c.cpp
    dart/ffi/NameClashingNS1_c.cpp
    dart/ffi/ExplicitNamespace1/SimpleClash_c.cpp
    dart/ffi/MyTemplateWithTwoArgs_c.cpp
    dart/ffi/MyTemplate2_c.cpp
    dart/ffi/MyTemplate_c.cpp
    dart/ffi/MyObject_c.cpp
    dart/ffi/EmptyStruct_c.cpp
    dart/ffi/EmptyNameSpace_c.cpp
    dart/ffi/DoubleInheritanceFromVirtuals_c.cpp
    dart/ffi/DoubleInheritance_c.cpp
    dart/ffi/Cyclic1_c.cpp
    dart/ffi/Cyclic2_c.cpp
    dart/ffi/BaseClassWithFinalMethod_c.cpp
    dart/ffi/AnotherNamespace_c.cpp
    dart/ffi/AnotherNamespaceStruct_c.cpp
    dart/ffi/TestBindings.cpp
)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)

find_package(Qt6Widgets)

add_library(TestBindings SHARED ${SOURCES})

include(GenerateExportHeader)
generate_export_header(TestBindings EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/TestBindings_exports.h" EXPORT_MACRO_NAME TestBindings_EXPORT)
set_property(TARGET TestBindings PROPERTY CXX_STANDARD 14)

target_link_libraries(TestBindings TestTarget Qt6::Core Qt6::Widgets)
target_include_directories(TestBindings PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cpp/include>  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)


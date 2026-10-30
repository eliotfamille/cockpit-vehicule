cmake_minimum_required(VERSION 3.16)

project(cockpit_vehicule VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.10)

# Content of downloaded design from Figma to Qt or similar
if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/importedcontent/CMakeLists.txt")
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/importedcontent)
endif()

qt_add_executable(appcockpit_vehicule
    src/main.cpp
)

target_include_directories(appcockpit_vehicule PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

qt_add_qml_module(appcockpit_vehicule
    URI cockpit_vehicule
    VERSION 1.0
    QML_FILES
        qml/Main.qml
    SOURCES
        src/VehicleData.h
        src/VehicleData.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appcockpit_vehicule PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appcockpit_vehicule
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appcockpit_vehicule
    PRIVATE Qt6::Quick
)

install(TARGETS appcockpit_vehicule
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

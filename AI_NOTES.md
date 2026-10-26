# AI Notes Index

## Project: cockpit_vehicule (Qt 6 Quick + C++)
- Root: /home/eliot/qt_projet/cockpit_vehicule
- Build: /home/eliot/qt_projet/cockpit_vehicule/build/Desktop_Qt_6_12_0_Debug

## Current State (verified)
- CMakeLists.txt: qt_add_executable + qt_add_qml_module with SOURCES for VehicleData
- src/main.cpp: test mode with QCoreApplication + qDebug (QML commented)
- src/VehicleData.h/.cpp: complete with 3 Q_PROPERTY (speed/rpm/temperature), clamp + emit
- qml/Main.qml: basic ApplicationWindow with light/dark toggle
- Build passes cleanly

## Note Files
- architecture.md - project structure, CMake/QML/C++ connections
- features.md - planned features per week
- decisions.md - technical decisions made
- progress.md - what's done, what's next
- qt-facts.md - verified Qt API facts with sources

## Current Task
S3: QML UI integration - qmlRegisterType, gauges binding to VehicleData, live data simulation
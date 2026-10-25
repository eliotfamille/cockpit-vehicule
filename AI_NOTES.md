# AI Notes Index

## Project: cockpit_vehicule (Qt 6 Quick + C++)
- Root: /home/eliot/qt_projet/cockpit_vehicule
- Build: /home/eliot/qt_projet/cockpit_vehicule/build/Desktop_Qt_6_12_0_Debug

## Current State (verified)
- CMakeLists.txt exists, uses qt_add_executable + qt_add_qml_module
- src/main.cpp loads QML from module "cockpit_vehicule"
- qml/Main.qml is a basic ApplicationWindow with light/dark toggle
- No VehicleData class yet (S2)
- No src/ folder for C++ classes (only main.cpp)

## Note Files
- architecture.md - project structure, CMake/QML/C++ connections
- features.md - planned features per week
- decisions.md - technical decisions made
- progress.md - what's done, what's next
- qt-facts.md - verified Qt API facts with sources

## Current Task
S1: Project skeleton - CMakeLists.txt review, empty QML window works
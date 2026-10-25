# Architecture - cockpit_vehicule

## Project Structure (verified)
```
/home/eliot/qt_projet/cockpit_vehicule/
├── CMakeLists.txt              # Root CMake, defines app + QML module
├── src/
│   └── main.cpp                # Entry point, loads QML module
├── qml/
│   └── Main.qml                # Main window (ApplicationWindow)
├── build/                      # Build output (ignored by git)
└── notes/                      # AI notes
```

## CMake / QML / C++ Connection (verified from files)

### CMakeLists.txt key points:
- `qt_add_executable(appcockpit_vehicule src/main.cpp)` - creates executable
- `qt_add_qml_module(appcockpit_vehicule URI cockpit_vehicule QML_FILES qml/Main.qml)` - registers QML module
- Module URI: `cockpit_vehicule`
- QML files compiled into resources, loaded via `engine.loadFromModule("cockpit_vehicule", "Main")`

### main.cpp:
```cpp
QQmlApplicationEngine engine;
engine.loadFromModule("cockpit_vehicule", "Main");
```

### Main.qml:
```qml
import QtQuick
import QtQuick.Controls
ApplicationWindow { ... }
```

## Planned C++ Classes (not yet created)
- `VehicleData` (src/vehicledata.h/.cpp) - QObject with Q_PROPERTY for speed, rpm, temperature
- Will be exposed to QML via `qmlRegisterType` or `QML_ELEMENT` + `qt_add_qml_module` SOURCES

## Build System
- Qt 6.12, CMake 3.16+
- qt_standard_project_setup(REQUIRES 6.10)
- Uses Qt6::Quick
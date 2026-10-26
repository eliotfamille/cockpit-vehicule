# Architecture - cockpit_vehicule

## Project Structure (verified)
```
/home/eliot/qt_projet/cockpit_vehicule/
├── CMakeLists.txt              # Root CMake, defines app + QML module
├── src/
│   ├── main.cpp                # Entry point, loads QML module
│   ├── VehicleData.h           # QObject with Q_PROPERTY (speed, rpm, temperature)
│   └── VehicleData.cpp         # Implementation with clamp + emit signals
├── qml/
│   └── Main.qml                # Main window (ApplicationWindow)
├── build/                      # Build output (ignored by git)
└── notes/                      # AI notes
```

## CMake / QML / C++ Connection (verified from files)

### CMakeLists.txt key points:
- `qt_add_executable(appcockpit_vehicule src/main.cpp)` - creates executable
- `qt_add_qml_module(appcockpit_vehicule URI cockpit_vehicule VERSION 1.0 QML_FILES qml/Main.qml SOURCES src/VehicleData.h src/VehicleData.cpp)` - registers QML module + C++ types
- Module URI: `cockpit_vehicule`
- QML files compiled into resources, loaded via `engine.loadFromModule("cockpit_vehicule", "Main")`

### main.cpp (current - test mode):
```cpp
QCoreApplication app(argc, argv);
VehicleData data;
// qDebug tests...
return 0;
```

### Main.qml:
```qml
import QtQuick
import QtQuick.Controls
ApplicationWindow { ... }
```

## C++ Classes (verified)
- `VehicleData` (src/VehicleData.h/.cpp)
  - Inherits QObject, Q_OBJECT macro
  - Properties: speed (0-300), rpm (0-8000), temperature (-40-150)
  - Each: Q_PROPERTY with READ/WRITE/NOTIFY, getter const, setter with clamp + emit
  - Registered in CMake SOURCES for MOC

## Build System
- Qt 6.12, CMake 3.16+
- qt_standard_project_setup(REQUIRES 6.10)
- Uses Qt6::Quick
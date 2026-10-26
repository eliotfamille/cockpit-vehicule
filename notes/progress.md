# Progress - cockpit_vehicule

## Done (verified)
- [x] Project skeleton created (CMakeLists.txt, main.cpp, Main.qml)
- [x] QML window opens with light/dark toggle
- [x] CMake builds successfully (fixed absolute path issue)
- [x] **S2: VehicleData class complete**
  - `src/VehicleData.h` + `src/VehicleData.cpp` with Q_PROPERTY (speed, rpm, temperature)
  - Q_PROPERTY with READ/WRITE/NOTIFY, getters const, setters with clamp + emit
  - Added to CMakeLists.txt SOURCES in qt_add_qml_module
  - Tested with qDebug (QCoreApplication) - clamp verified: 0-300, 0-8000, -40-150

## Current Task: S3 - QML UI integration
- Add qmlRegisterType in main.cpp
- Create QML gauges binding to VehicleData
- Simulate live data with QTimer

## Next Steps (S3+)
- QML gauges (speedometer, tachometer, temperature)
- Warning lights (oil, battery, check-engine)
- Animation/timer backend for live simulation
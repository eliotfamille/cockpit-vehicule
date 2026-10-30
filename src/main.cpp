#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "VehicleData.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    VehicleData car;
    car.setSpeed(65);
    engine.rootContext()->setContextProperty("car", &car);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("cockpit_vehicule", "Main");

    return QGuiApplication::exec();
}
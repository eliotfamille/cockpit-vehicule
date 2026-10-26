#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "VehicleData.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    VehicleData data;

    qDebug() << "=== TEST VehicleData ===";
    qDebug() << "Initial:" << data.speed() << data.rpm() << data.temperature();

    data.setSpeed(50);
    data.setRpm(3000);
    data.setTemperature(90);
    qDebug() << "Après set:" << data.speed() << data.rpm() << data.temperature();

    data.setSpeed(999);    // clamp 300
    data.setRpm(-100);     // clamp 0
    data.setTemperature(200); // clamp 150
    qDebug() << "Après clamp:" << data.speed() << data.rpm() << data.temperature();

    qDebug() << "=== TEST OK ===";

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("cockpit_vehicule", "Main");

    return QGuiApplication::exec();
}
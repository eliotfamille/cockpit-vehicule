#ifndef VEHICLEDATA_H
#define VEHICLEDATA_H

#include <QObject>
#include <QtQml>

class VehicleData : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit VehicleData(QObject* parent = nullptr);

    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged);
    Q_PROPERTY(int rpm READ rpm WRITE setRpm NOTIFY rpmChanged);
    Q_PROPERTY(int temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged);

    int speed() const;
    void setSpeed(int n_speed);

    int rpm() const;
    void setRpm(int n_rpm);

    int temperature() const;
    void setTemperature(int n_temperature);

private:
    int m_speed=0;
    int m_rpm=0;
    int m_temperature=0;

signals:
    void speedChanged();
    void rpmChanged();
    void temperatureChanged();

};

#endif // VehicleData_H

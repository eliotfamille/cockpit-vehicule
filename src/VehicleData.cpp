#include "VehicleData.h"

VehicleData::VehicleData(QObject* parent): QObject(parent) {}

int VehicleData::speed() const {return m_speed;}
void VehicleData::setSpeed(int n_speed){
    if (n_speed < 0) n_speed=0;
    if (n_speed > 300) n_speed=300;
    if (m_speed == n_speed) return;
    m_speed = n_speed;
    emit speedChanged();
}

int VehicleData::rpm() const {return m_rpm;}
void VehicleData::setRpm(int n_rpm){
    if (n_rpm < 0) n_rpm = 0;
    if (n_rpm > 8000) n_rpm = 8000;
    if (m_rpm == n_rpm) return;
    m_rpm = n_rpm;
    emit rpmChanged();
}

int VehicleData::temperature() const {return m_temperature;}
void VehicleData::setTemperature(int n_temperature){
    if (n_temperature < -40) n_temperature = -40;
    if (n_temperature > 150) n_temperature = 150;
    if (m_temperature == n_temperature) return;
    m_temperature = n_temperature;
    emit temperatureChanged();
}

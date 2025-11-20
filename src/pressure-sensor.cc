#include "pressure-sensor.h"

int PressureSensor::_idCounter = 0;

PressureSensor::PressureSensor() : Sensor(SENSOR_TYPE::PRESSURE),
                                   _id(_idCounter++) {}

std::unique_ptr<Measurement> PressureSensor::read() const
{
    std::unique_ptr<Measurement> measurement = std::make_unique<Measurement>(); // create on heap so we can return pointer only
    measurement->reading = ::randomFloat(0.f, 400.f);
    measurement->type = Sensor::type();
    measurement->timeStamp = ::localTime().c_str();
    return measurement;
}
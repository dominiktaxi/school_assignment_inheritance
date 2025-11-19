#include "temperature-sensor.h"

int TemperatureSensor::_idCounter = 0;

TemperatureSensor::TemperatureSensor() : Sensor(SENSOR_TYPE::TEMPERATURE),
                                         _id(_idCounter++) {}

std::unique_ptr<Measurement> TemperatureSensor::read() const
{
    std::unique_ptr<Measurement> measurement = std::make_unique<Measurement>();
    measurement->reading = ::randomFloat(-20.f, 69.9f);
    measurement->type = Sensor::type();
    measurement->timeStamp = ::localTime();
    return measurement;
}
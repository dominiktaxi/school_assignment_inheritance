#include "humidity-sensor.h"

int HumiditySensor::_idCounter = 0;

HumiditySensor::HumiditySensor() : Sensor(SENSOR_TYPE::HUMIDITY), _id(_idCounter++)
{
}

std::unique_ptr<Measurement> HumiditySensor::read() const
{
    std::string t = ::localTime();
    std::unique_ptr<Measurement> measurement = std::make_unique<Measurement>();
    measurement->reading = ::randomFloat(0.f, 100.f);
    measurement->type = Sensor::type();
    measurement->timeStamp = ::localTime();
    measurement->id = _id;
    return measurement;
}

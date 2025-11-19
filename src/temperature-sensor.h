#pragma once
#include "sensor.h"

class TemperatureSensor : public Sensor
{
public:
    TemperatureSensor();
    std::unique_ptr<Measurement> read() const override;

private:
    static int _idCounter;
    int _id;
};
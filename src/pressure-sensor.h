#pragma once

#include "sensor.h"

class PressureSensor : public Sensor
{
public:
    PressureSensor();
    std::unique_ptr<Measurement> read() const override;

private:
    static int _idCounter;
    int _id;
};
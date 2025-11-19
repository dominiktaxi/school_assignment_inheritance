#pragma once
#include "sensor.h"

class HumiditySensor : public Sensor
{
public:
    HumiditySensor();
    std::unique_ptr<Measurement> read() const override;

private:
    static int _idCounter;
    int _id;
};
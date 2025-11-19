#pragma once
#include <vector>
#include "humidity-sensor.h"
#include "pressure-sensor.h"
#include "temperature-sensor.h"
class SensorManager
{
public:
    SensorManager() = default;
    void addTemperatureSensor(MinMax);
    void addHumiditySensor(MinMax);
    void addPressureSensor(MinMax);
    std::vector<std::pair<MinMax, std::unique_ptr<Sensor>>> &sensors();

private:
    // std::vector<std::unique_ptr<Sensor>> _sensors;
    std::vector<std::pair<MinMax, std::unique_ptr<Sensor>>> _sensors;
};
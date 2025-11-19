#include "sensor-manager.h"

void SensorManager::addTemperatureSensor(MinMax minMax)
{
    if (minMax.minThreshold > minMax.maxThreshold)
    {
        std::swap(minMax.minThreshold, minMax.maxThreshold);
    }
    _sensors.push_back({minMax, std::make_unique<TemperatureSensor>()});
}

void SensorManager::addHumiditySensor(MinMax minMax)
{
    if (minMax.minThreshold > minMax.maxThreshold)
    {
        std::swap(minMax.minThreshold, minMax.maxThreshold);
    }
    _sensors.push_back({minMax, std::make_unique<HumiditySensor>()});
}

void SensorManager::addPressureSensor(MinMax minMax)
{
    if (minMax.minThreshold > minMax.maxThreshold)
    {
        std::swap(minMax.minThreshold, minMax.maxThreshold);
    }
    _sensors.push_back({MinMax(minMax), std::make_unique<PressureSensor>()});
}

std::vector<std::pair<MinMax, std::unique_ptr<Sensor>>> &SensorManager::sensors()
{
    return _sensors;
}
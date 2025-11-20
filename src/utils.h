#pragma once
#include <chrono>
#include <ctime>
#include <random>
#include <memory>
class Measurement;
class Sensor;

extern bool addedTemperatureSensor;
extern bool addedHumiditySensor;
extern bool addedPressureSensor;
struct MinMax
{
    float minThreshold;
    float maxThreshold;
    bool operator<(const MinMax &other) const
    {
        if (minThreshold != other.minThreshold)
            return minThreshold < other.minThreshold;
        return maxThreshold < other.maxThreshold;
    }
};

enum class SENSOR_TYPE
{
    TEMPERATURE = 1,
    HUMIDITY = 2,
    PRESSURE = 3
};

float randomFloat(float min, float max);
int randomInt(int min, int max);

std::string localTime();

float average(const std::vector<std::unique_ptr<Measurement>> &, const std::string &type);

MinMax minMax(const std::vector<std::unique_ptr<Measurement>> &measurements, const std::string &type);
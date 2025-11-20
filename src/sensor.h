#pragma once
#include <memory>
#include "measurement.h"
#include "utils.h"
class Sensor
{
public:
    Sensor(SENSOR_TYPE);
    virtual ~Sensor() = default;
    virtual std::unique_ptr<Measurement> read() const = 0;
    std::string type() const;
    SENSOR_TYPE SENSORTYPE() const;

protected:
    SENSOR_TYPE _TYPE;
    std::string _type;

private:
    const char *_typeToChars(SENSOR_TYPE);
};
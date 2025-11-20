#include "sensor.h"

Sensor::Sensor(SENSOR_TYPE TYPE) : _type(_typeToChars(TYPE)), _TYPE(TYPE) {}

std::string Sensor::type() const
{
    return _type;
}

SENSOR_TYPE Sensor::SENSORTYPE() const
{
    return _TYPE;
}

const char *Sensor::_typeToChars(SENSOR_TYPE TYPE)
{
    switch (TYPE)
    {
    case SENSOR_TYPE::TEMPERATURE:
    {
        return "Temperature";
    }
    break;
    case SENSOR_TYPE::HUMIDITY:
    {
        return "Humidity";
    }
    break;
    case SENSOR_TYPE::PRESSURE:
    {
        return "Pressure";
    }
    break;
    default:
    {
        return "";
    }
    break;
    }
}

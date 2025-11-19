#include "sensor.h"

Sensor::Sensor(SENSOR_TYPE TYPE) : _type(_typeToChars(TYPE)), _TYPE(TYPE) {}

const char *Sensor::type() const
{
    return _type;
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

SENSOR_TYPE Sensor::SENSORTYPE() const
{
    return _TYPE;
}
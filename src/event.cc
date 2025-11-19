#include "event.h"
#include "utils.h"
Event::Event(Event::TYPE TYPE, SENSOR_TYPE SENSORTYPE) : _TYPE(TYPE), _SENSOR_TYPE(SENSORTYPE) {}

Event::TYPE Event::type() const
{
    return _TYPE;
}

SENSOR_TYPE Event::sensorType() const
{
    return _SENSOR_TYPE;
}
#pragma once
#include "utils.h"

class Event
{
public:
    enum class TYPE
    {
        UNDER_THRESHOLD,
        OVER_THRESHOLD
    };
    Event(TYPE, SENSOR_TYPE);
    TYPE type() const;
    SENSOR_TYPE sensorType() const;

private:
    TYPE _TYPE;
    ::SENSOR_TYPE _SENSOR_TYPE;
};
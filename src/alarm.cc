#include <iostream>
#include "alarm.h"

void Alarm::notifyObservers(const Event &event)
{

    switch (event.type())
    {
    case Event::TYPE::OVER_THRESHOLD:
    {

        if (event.sensorType() == ::SENSOR_TYPE::TEMPERATURE)
        {
            std::cout << "ALARM: TEMPERATURE OVER THRESHOLD" << std::endl;
            _deviations.push_back({event.type(), ::SENSOR_TYPE::TEMPERATURE, ::localTime().c_str()});
        }
        else if (event.sensorType() == ::SENSOR_TYPE::HUMIDITY)
        {
            std::cout << "ALARM: HUMIDITY OVER THRESHOLD" << std::endl;
            _deviations.push_back({event.type(), ::SENSOR_TYPE::HUMIDITY, ::localTime().c_str()});
        }
        else if (event.sensorType() == ::SENSOR_TYPE::PRESSURE)
        {
            std::cout << "ALARM: PRESSURE OVER THRESHOLD" << std::endl;
            _deviations.push_back({event.type(), ::SENSOR_TYPE::PRESSURE, ::localTime().c_str()});
        }
       
    }
    break;
    case Event::TYPE::UNDER_THRESHOLD:
    {
        if (event.sensorType() == SENSOR_TYPE::TEMPERATURE)
        {
            std::cout << "ALARM: TEMPERATURE UNDER THRESHOLD" << std::endl;
            _deviations.push_back({event.type(), SENSOR_TYPE::TEMPERATURE, ::localTime().c_str()});
        }
        else if (event.sensorType() == SENSOR_TYPE::HUMIDITY)
        {
            std::cout << "ALARM: HUMIDITY UNDER THRESHOLD" << std::endl;
            _deviations.push_back({event.type(), SENSOR_TYPE::HUMIDITY, ::localTime().c_str()});
        }
        else if (event.sensorType() == SENSOR_TYPE::PRESSURE)
        {
            std::cout << "ALARM: PRESSURE UNDER THRESHOLD" << std::endl;
            _deviations.push_back({event.type(), SENSOR_TYPE::PRESSURE, ::localTime().c_str()});
        }
    }
    }
}
#include <utility>
#include <algorithm>

#include "application.h"

Application::Application() : _menu(this) {}

bool Application::run()
{
    return _menu.mainMenu();
}

MeasurementStorage *Application::measurementStorage()
{
    return &_measurementStorage;
}

bool Application::collect()
{
    // std::for_each(sensors.begin(), sensors.end(), [&](std::unique_ptr<Sensor> &s)
    //               { _measurementStorage.addMeasurement(s->read()); });               //DANIELS APPROACH
    bool success = false;
    if (_sensorManager.sensors().size() > 0)
    {
        auto &sensors = _sensorManager.sensors();
        for (auto it = sensors.begin(); it != sensors.end(); it++)
        {
            std::unique_ptr<Measurement> measurement = it->second->read();
            Sensor *sensor = it->second.get();

            if (measurement->reading > it->first.maxThreshold)
            {
                _events.push_back(Event(Event::TYPE::OVER_THRESHOLD, sensor->SENSORTYPE()));
                Printer::print("OVER THRESHOLD");
            }
            else if (measurement->reading < it->first.minThreshold)
            {
                _events.push_back(Event(Event::TYPE::UNDER_THRESHOLD, sensor->SENSORTYPE()));
                Printer::print("UNDER THRESHOLD");
            }
            _measurementStorage.addMeasurement(std::move(measurement));
        }
        success = true;
    }
    return success;
}

void Application::addSensor(const SENSOR_TYPE TYPE, MinMax &minMax)
{
    switch (TYPE)
    {
    case SENSOR_TYPE::TEMPERATURE:
    {
        _sensorManager.addTemperatureSensor(minMax);
    }
    break;
    case SENSOR_TYPE::HUMIDITY:
    {
        _sensorManager.addHumiditySensor(minMax);
    }
    break;
    case SENSOR_TYPE::PRESSURE:
    {
        _sensorManager.addPressureSensor(minMax);
    }
    break;
    }
}

void Application::printAmountOfSensors()
{
    Printer::print(_sensorManager.sensors().size());
}

void Application::printMeasurements() const
{
    Printer::clearTerminal();
    for (const auto &measurement : _measurementStorage.measurements())
    {
        Printer::print(measurement->type);
        Printer::print(measurement->reading);
        Printer::print(measurement->timeStamp);
        Printer::newLine();
    }
}

void Application::attachObserver(Observer *observer)
{
    _observers.push_back(observer);
}

void Application::notifyObservers() const
{
    for (const auto &observer : _observers)
    {
        for (const auto &event : _events)
        {
            observer->notifyObservers(event);
        }
    }
}

void Application::clearEvents()
{
    _events.clear();
}

void Application::removeStoredData()
{
    _measurementStorage.clearMeasurementsHDD();
    _measurementStorage.clearMeasurementsHeap();
}

void Application::storeToHDD()
{
    _measurementStorage.storeToHDD();
}

void Application::loadFromHDD()
{
    _measurementStorage.loadFromHDD();
}
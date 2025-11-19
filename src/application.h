#pragma once
#include "sensor-manager.h"
#include "measurement-storage.h"
#include "printer.h"
#include "event.h"
#include "observer.h"
#include "menu.h"

class Application
{
public:
    Application();
    bool run();
    MeasurementStorage *measurementStorage();
    bool collect();
    void addSensor(const SENSOR_TYPE, MinMax &);
    void printAmountOfSensors();
    void printMeasurements() const;
    void attachObserver(Observer *);
    void notifyObservers() const;
    void clearEvents();

private:
    SensorManager _sensorManager;
    MeasurementStorage _measurementStorage;
    Menu _menu;
    std::vector<Observer *> _observers;
    std::vector<Event> _events;
};
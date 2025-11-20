#include <iostream>
#include <limits>

#include "menu.h"
#include "application.h"
Menu::Menu(Application *application) : _application(application) {}

bool Menu::mainMenu()
{
    int choice = 0;
    Printer::print("Amount of sensors: ");
    _application->printAmountOfSensors();
    Printer::print("1.Add sensor");
    Printer::print("2.Collect data from all sensors");
    Printer::print("3.Print all collected data");
    Printer::print("4.Remove stored data");
    Printer::print("9.Exit");
    Printer::newLine();
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (!(std::cin >> choice) || choice < 0 && choice != 9 || choice > 4 && choice != 9)
    {
        Printer::print("Please enter a valid number");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    switch (choice)
    {
    case 1:
    {
        setupSensor(chooseSensor());
    }
    break;
    case 2:
    {
        Printer::clearTerminal();
        if (!_application->collect())
        {
            Printer::print("No sensors registered");
        }
    }
    break;
    case 3:
    {
        _application->printMeasurements();
    }
    break;
    case 4:
    {
        _application->removeStoredData();
    }
    break;
    case 9:
    {
        return false;
    }
    break;
    }
    return true;
}

int Menu::chooseSensor()
{
    int choice = 0;
    Printer::clearTerminal();
    Printer::print("1.Add temperature sensor");
    Printer::print("2.Add humuidity sensor");
    Printer::print("3.Add pressure sensor");
    Printer::newLine();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (!(std::cin >> choice) || choice < 1 || choice > 3)
    {
        std::cout << "Please enter a valid number" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return choice;
}

void Menu::setupSensor(int choice)
{
    MinMax minMax;
    SENSOR_TYPE TYPE = static_cast<SENSOR_TYPE>(choice);
    switch (TYPE)
    {
    case SENSOR_TYPE::TEMPERATURE:
    {
        if (!::addedTemperatureSensor)
        {
            Printer::print("Set a minumum threshold value for temperature sensor(celsius): ");
            std::cin >> minMax.minThreshold;
            Printer::print("Set a maximum threshold value for temperature sensor(celsius): ");
            Printer::newLine();
            std::cin >> minMax.maxThreshold;
            _application->addSensor(TYPE, minMax);
            ::addedTemperatureSensor = true;
        }
        else
        {
            Printer::print("Temperature sensor already addded");
        }
    }
    break;
    case SENSOR_TYPE::HUMIDITY:
    {
        if (!::addedHumiditySensor)
        {
            std::cout << "Set a minumum threshold value for humidity sensor(%): " << std::endl;
            std::cin >> minMax.minThreshold;
            std::cout << "Set a maximum threshold value for humidity sensor(%): " << std::endl;
            std::cin >> minMax.maxThreshold;
            _application->addSensor(TYPE, minMax);
            ::addedHumiditySensor = true;
        }
        else
        {
            Printer::print("Humidity sensor already added");
        }
    }
    break;
    case SENSOR_TYPE::PRESSURE:
    {
        if (!::addedPressureSensor)
        {
            std::cout << "Set a minumum value for pressure sensor(BAR) sensor: " << std::endl;
            std::cin >> minMax.minThreshold;
            std::cout << "Set a maximum value for pressure sensor(BAR) sensor: " << std::endl;
            std::cin >> minMax.maxThreshold;
            _application->addSensor(TYPE, minMax);
            ::addedPressureSensor = true;
        }
        else
        {
            Printer::print("Pressure sensor already added");
        }
    }
    break;
    }
}
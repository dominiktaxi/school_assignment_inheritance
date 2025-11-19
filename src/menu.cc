#include <iostream>
#include <limits>

#include "menu.h"
#include "application.h"
Menu::Menu(Application *application) : _application(application) {}

void Menu::mainMenu()
{
    int choice = 0;
    Printer::print("Amount of sensors: ");
    _application->printAmountOfSensors();
    Printer::print("1.Add sensor");
    Printer::print("2.Collect data from all sensors");
    Printer::print("3.Print all collected data");
    Printer::print("4.Remove stored data");
    Printer::newLine();
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (!(std::cin >> choice) || choice < 0 || choice > 4)
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
    }
    break;
    }
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
        Printer::print("Set a minumum value for temperature sensor(celsius): ");
        std::cin >> minMax.minThreshold;
        Printer::print("Set a maximum value for temperature sensor(celsius): ");
        Printer::newLine();
        std::cin >> minMax.maxThreshold;
        _application->addSensor(TYPE, minMax);
    }
    break;
    case SENSOR_TYPE::HUMIDITY:
    {
        std::cout << "Set a minumum value for humidity sensor(%): " << std::endl;
        std::cin >> minMax.minThreshold;
        std::cout << "Set a maximum value for humidity sensor(%): " << std::endl;
        std::cin >> minMax.maxThreshold;
        _application->addSensor(TYPE, minMax);
    }
    break;
    case SENSOR_TYPE::PRESSURE:
    {
        std::cout << "Set a minumum value for pressure sensor(BAR) sensor: " << std::endl;
        std::cin >> minMax.minThreshold;
        std::cout << "Set a maximum value for pressure sensor(BAR) sensor: " << std::endl;
        std::cin >> minMax.maxThreshold;
        _application->addSensor(TYPE, minMax);
    }
    break;
    }
}
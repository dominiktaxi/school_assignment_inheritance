#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include "measurement-storage.h"
#include "printer.h"

void MeasurementStorage::addMeasurement(std::unique_ptr<Measurement> measurement)
{
    _measurements.push_back(std::move(measurement));
}

void MeasurementStorage::storeToHDD()
{
    if (_measurements.size() > 0)
    {
        std::ofstream temperature("measurements/temperature.txt");
        std::ofstream humidity("measurements/humidity.txt");
        std::ofstream pressure("measurements/pressure.txt");

        if (!temperature || !humidity || !pressure)
        {
            std::cerr << "Problem with creation of save files" << std::endl;
            return;
        }
        for (const auto &measurement : _measurements)
        {
            if (measurement->type == "Temperature")
            {
                temperature << measurement->type << "," << measurement->reading << "," << measurement->timeStamp;
            }
            else if (measurement->type == "Humidity")
            {
                humidity << measurement->type << "," << measurement->reading << "," << measurement->timeStamp;
            }
            else if (measurement->type == "Pressure")
            {
                pressure << measurement->type << "," << measurement->reading << "," << measurement->timeStamp;
            }
        }
        temperature.close();
        humidity.close();
        pressure.close();
    }
}

void MeasurementStorage::loadFromHDD()
{
}

void MeasurementStorage::clearMeasurementsHeap()
{
    Printer::print("Are you sure? Y/N");
    char choice;
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        _measurements.clear();
    }
    else
    {
        return;
    }
}

void MeasurementStorage::clearMeasurementsHDD()
{
    remove("measurements/temperature.txt");
    remove("measurements/humidity.txt");
    remove("measurements/pressure.txt");
}

const std::vector<std::unique_ptr<Measurement>> &MeasurementStorage::measurements() const
{
    return _measurements;
}
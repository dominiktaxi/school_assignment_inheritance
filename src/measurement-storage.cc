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
                temperature << measurement->type << "," << measurement->reading << "," << measurement->timeStamp << "\n";
            }
            else if (measurement->type == "Humidity")
            {
                humidity << measurement->type << "," << measurement->reading << "," << measurement->timeStamp << "\n";
            }
            else if (measurement->type == "Pressure")
            {
                pressure << measurement->type << "," << measurement->reading << "," << measurement->timeStamp << "\n";
            }
        }
        temperature.close();
        humidity.close();
        pressure.close();
    }
}

void MeasurementStorage::loadFromHDD()
{
    std::ifstream temperature("measurements/temperature.txt", std::ios::app);
    std::ifstream humidity("measurements/humidity.txt", std::ios::app);
    std::ifstream pressure("measurements/pressure.txt", std::ios::app);
    if (!temperature.is_open())
    {
        Printer::cerr("temperature.txt could not open");
    }
    if (!humidity.is_open())
    {
        Printer::cerr("humidity.txt could not open");
    }
    if (!pressure.is_open())
    {
        Printer::cerr("pressure.txt could not open");
    }

    std::string line;
    while (getline(temperature, line, '\n'))
    {
        std::stringstream ss(line);
        std::string type, reading, timeStamp;
        getline(ss, type, ',');
        getline(ss, reading, ',');
        getline(ss, timeStamp, ',');
        std::unique_ptr<Measurement> measurement = std::make_unique<Measurement>();
        measurement->reading = std::stof(reading);
        measurement->type = type.c_str();
        measurement->timeStamp = timeStamp;
        _measurements.push_back(std::move(measurement));
    }
}

void MeasurementStorage::clearMeasurementsHeap()
{
    _measurements.clear();
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
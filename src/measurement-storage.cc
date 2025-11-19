#include <iostream>
#include <fstream>
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
        }
    }
    // if(_measurements.size() > 0)
    // {
    //     std::ofstream humidityReadings ("measurements/humidityReadings.txt", std::ios::app);
    //     std::ofstream temperatureReadings ("measurements/temperatureReadings.txt", std::ios::app);
    //     if(!humidityReadings || !temperatureReadings)
    //     {
    //         std::cerr << "Failed to create file" << std::endl;
    //         return;
    //     }
    //     for (const auto& measurement : _measurements)
    //     {
    //         if ( measurement->TYPE == Sensor::TYPE::HUMIDITY)
    //         {
    //             humidityReadings << measurement->reading << "," << measurement->unit << "," << measurement->timeStamp << ","
    //             << static_cast<int>(measurement->TYPE) << "," << measurement->type << "," << measurement->overThreshold << "\n";
    //         }
    //         else if(measurement->TYPE == Sensor::TYPE::TEMPERATURE)
    //         {
    //             temperatureReadings << measurement->reading << "," << measurement->unit << "," << measurement->timeStamp << ","
    //             << static_cast<int>(measurement->TYPE) << "," << measurement->type << "," << measurement->overThreshold << "\n";
    //         }
    //     }
    //     temperatureReadings.close();
    //     humidityReadings.close();
    // }
    // else {std::cout << "No data was saved" << std::endl;}
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
}

const std::vector<std::unique_ptr<Measurement>> &MeasurementStorage::measurements() const
{
    return _measurements;
}
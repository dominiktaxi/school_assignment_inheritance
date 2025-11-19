#pragma once
#include <vector>
#include <memory>
#include "measurement.h"
class MeasurementStorage
{
public:
    void addMeasurement(std::unique_ptr<Measurement>);
    void storeToHDD();
    void clearMeasurementsHeap();
    void clearMeasurementsHDD();
    const std::vector<std::unique_ptr<Measurement>> &measurements() const;

private:
    std::vector<std::unique_ptr<Measurement>> _measurements;
};
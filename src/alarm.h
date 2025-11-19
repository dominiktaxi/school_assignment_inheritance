#pragma once
#include "observer.h"
#include "utils.h"
class Alarm : public Observer
{
public:
    void notifyObservers(const Event &) override;

    struct Deviation
    {
        Event::TYPE EVENT;
        SENSOR_TYPE TYPE;
        const char *timeStamp;
    };

private:
    std::vector<Deviation> _deviations;
};
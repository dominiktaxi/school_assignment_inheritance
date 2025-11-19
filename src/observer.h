#pragma once
#include "event.h"
#include "utils.h"
class Observer
{
public:
    virtual void notifyObservers(const Event &) = 0;
};
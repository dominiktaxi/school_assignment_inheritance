#pragma once
#include <string>
struct Measurement
{
    float reading;
    const char *type;
    std::string timeStamp;
    int id;
};
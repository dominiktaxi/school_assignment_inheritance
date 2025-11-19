#pragma once
#include <iostream>
namespace Printer
{
    template <typename T>
    void print(const T &value)
    {
        std::cout << value << std::endl;
    }

    void newLine();
    void clearTerminal();
};
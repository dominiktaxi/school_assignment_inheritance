#pragma once
#include <iostream>
namespace Printer
{
    template <typename T>
    void print(const T &value)
    {
        std::cout << value << std::endl;
    }

    template <typename T>
    void cerr(const T &value)
    {
        std::cerr << value << std::endl;
    }

    void newLine();
    void clearTerminal();
};
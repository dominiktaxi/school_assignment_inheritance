#include "printer.h"

void Printer::newLine()
{
    std::cout << std::endl;
}

void Printer::clearTerminal()
{
    system("clear");
}
#pragma once
#include "utils.h"

class Application;
class Menu
{
public:
    Menu(Application *);
    bool mainMenu();
    int chooseSensor();
    void setupSensor(int);

private:
    Application *_application;
};
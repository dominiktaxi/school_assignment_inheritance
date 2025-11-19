#pragma once
#include "utils.h"

class Application;
class Menu
{
public:
    Menu(Application *);
    void mainMenu();
    int chooseSensor();
    void setupSensor(int);

private:
    Application *_application;
};
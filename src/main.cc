#include <iostream>
#include "application.h"
#include "alarm.h"
int main()
{
    Alarm alarm;
    Application app;
    app.attachObserver(&alarm);
    while (app.run())
    {
        app.notifyObservers();
        app.clearEvents();
        std::cout << "MMMMM";
    }
    return 0;
}

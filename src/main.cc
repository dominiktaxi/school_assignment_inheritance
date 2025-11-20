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
    }
    return 0;
}

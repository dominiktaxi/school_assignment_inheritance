#include <iostream>
#include "application.h"
#include "alarm.h"
int main()
{
    Alarm alarm;
    Application app;
    app.attachObserver(&alarm);
    app.loadFromHDD();
    while (app.run())
    {
        app.notifyObservers();
        app.clearEvents();
    }
    app.storeToHDD();
    return 0;
}

Application for a multi-sensor system that reads and stores sensor measurements and types, alerts observers for measurements crossing threshold.

File contents:

alarm.cc/h                  ---> Alarm is a child class of Observer, it receives alerts when measurements cross threshold.
application.cc/h            ---> Application has SensorManager, MeasurementStorage, Menu, vector of Observer and Event, It tells SensorManager to store new sensors,
                                 MeasurementStorage to store measurements, it opens main menu etc

event.cc/h                  ---> Holds information of what kind of event and wich kind of sensor triggered the event.
Sensor.h                    ---> Mother class for all sensors, have pure virtual: virtual std::unique_ptr<Measurement> read() const = 0;
humidity-sensor.cc/h        ---> Inherits from sensor.h, returns measurement smart pointer(override)
temperature-sensor.cc/h     ---> -----------------------------||----------------------------------
pressure.sensor.cc/h        ---> -----------------------------||----------------------------------
measurement-storage.cc/h    ---> Stores to heap. Stores and loads to/from HDD. Clears/removes.
measurement.cc/h            ---> Simple struct that have: float reading, const char* type and std::string timeStamp
menu.cc/h                   ---> Menus for adding sensors, reading and storing measurements, clearing data, gets a Application* in constructor
observer.cc/h               ---> Mother class for observers, pure virtual, exists only to notify observers of events.
printer.cc/h                ---> Namespace for printing (std::cout) just a helper file.
sensor-manager.cc/h         ---> Stores a std::pair of min and max threshold values and smart pointers to sensors, responsible for adding new sensors.
utils.cc/h                  ---> Globals, helper functions and variables.

#include "LedController.hpp"
#include "../utils/Debug.hpp"
void LedController::begin()
{
    DBG("Actuator","Led Initialized");
}

void LedController::setState(const String& stateStr)
{
    String s = stateStr;
    s.toUpperCase();
    if ( s == "ON") {
        state = true;
        DBG("Led","Turn on");

    }
    else if ( s == "OFF") {
        state = false;
        DBG("Led", "Turn off");
    }
    else {
        DBG("Led", "Unknow state: %s", stateStr.c_str());
    }
}

String LedController::getName() const {
    return "Led";
}
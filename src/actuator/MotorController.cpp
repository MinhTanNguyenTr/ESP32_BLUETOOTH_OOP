#include "MotorController.hpp"
#include "../utils/Debug.hpp"
void MotorController::begin()
{
    DBG("Actuator", "Motor initialized");
}

void MotorController::setState(const String& stateStr)
{
    String s = stateStr;
    s.trim();
    if(s.startsWith("SPEED")) {
        int phd = s.substring(5).toInt();
        if(phd < 0) phd = 0;
        if(phd > 100) phd = 100;
        speed = phd;
        DBG("Motor", "Speed set to : %d", speed);
    }
    else {
        DBG("Motor", "Unknow commad: %s", stateStr.c_str());
    }
}

String MotorController::getName() const {
    return "Motor";
}
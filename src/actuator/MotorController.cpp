#include "MotorController.hpp"

void MotorController::begin()
{
    Serial.println("[Motor] ready");
}

void MotorController::setState(const String& state)
{
    if(state == "ON") {
        Serial.println("[Motor] Turn on");
    }
    else {
        Serial.println("[Motor] Turn off");
    }
}

String MotorController::getName() cosnt {
    return "Motor";
}
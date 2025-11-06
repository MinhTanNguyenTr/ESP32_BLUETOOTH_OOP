#include "LedController.hpp"

void LedController::begin()
{
    Serial.println("[Led] ready");
}

void LedController::setState(const String& state)
{
    if ( state == "ON") {
        Serial.println("[Led] Turn on");
    }
    else {
        Serial.println("[Led] Turn off");
    }
}

String LedController::getName() const {
    return "Led";
}
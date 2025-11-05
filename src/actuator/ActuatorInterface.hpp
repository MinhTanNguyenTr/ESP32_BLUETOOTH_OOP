#pragma once
#include <Arduino.h>

class ActuatorInterface {
    private:
    public:
    ActuatorInterface() = default;
    virtual void begin() {};
    virtual void setState(const String& state) {};
    virtual String getName() const {};
    virtual ~ActuatorInterface() = default;
};
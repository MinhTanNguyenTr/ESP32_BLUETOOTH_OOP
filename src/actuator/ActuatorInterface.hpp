#pragma once
#include <Arduino.h>

class ActuatorInterface {
    private:
    public:
    ActuatorInterface() = default;
    virtual void begin() = 0;
    virtual void setState(const String& state) = 0;
    virtual String getName() const = 0;
    virtual ~ActuatorInterface() = default;
};
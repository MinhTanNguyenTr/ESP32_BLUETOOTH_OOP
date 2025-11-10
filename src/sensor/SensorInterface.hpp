#pragma once
#include <Arduino.h>

class SensorInterface {
    private:
    public:
    SensorInterface() = default;
    virtual void begin() = 0;
    virtual float readValue() = 0;
    virtual String getName() const = 0;
    virtual ~SensorInterface() = default;
};
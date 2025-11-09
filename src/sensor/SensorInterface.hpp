#pragma once
#include <Arduino.h>

class SensorInterface {
    private:
    public:
    SensorInterface() = default;
    virtual void begin() {};
    virtual float readValue() {};
    virtual String getName() const{};
    virtual ~SensorInterface() = default;
};
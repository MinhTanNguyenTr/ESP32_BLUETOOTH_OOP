#pragma once
#include <Arduino.h>
struct SensorData {
    float temperature;
    float lux;
};
class SensorInterface {
    private:
    public:
    SensorInterface() = default;
    virtual void begin() {};
    virtual SensorData readValue() {};
    virtual String getName() const{};
    virtual ~SensorInterface() = default;
};
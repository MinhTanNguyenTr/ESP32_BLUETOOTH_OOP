#pragma once
#include <vector>
#include <Arduino.h>
#include "SensorInterface.hpp"

class SensorManager {
public:
    SensorManager() = default;
    ~SensorManager();
    void beginAll();
    void addSensor(SensorInterface* s);
    String collectDataJson();
private:
    std::vector<SensorInterface*> sensors;
};

#pragma once
#include <vector>
#include <Arduino.h>
#include "SensorInterface.hpp"

class SensorManager {
public:
    SensorManager();
    ~SensorManager();
    void beginAll();
    void addSensor(SensorInterface* s);
    String collectDataJson();
private:
    std::vector<SensorInterface*> sensors;
};

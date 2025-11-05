#pragma once
#include "SensorInterface.hpp"
class SensorManager {
    private:
    std::vector<SensorInterface*> _sensor;
    public:
    void beginAll();
    String collectData();
};
#pragma once
#include "SensorInterface.hpp"
class LightSensor : public SensorInterface {
    private:
    public:
    void begin() override;
    SensorData readValue() override;
    String getName() const override;
};
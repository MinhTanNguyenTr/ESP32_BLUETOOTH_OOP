#pragma once
#include "SensorInterface.hpp"

class TemperatureSensor : public SensorInterface {
    private:
    public:
    void begin() override;
    SensorData readValue() override;
    String getName() const override;
};
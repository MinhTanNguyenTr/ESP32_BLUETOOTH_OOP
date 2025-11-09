#pragma once
#include "SensorInterface.hpp"

class TemperatureSensor : public SensorInterface {
    private:
    public:
    void begin() override;
    float readValue() override;
    String getName() const override;
};
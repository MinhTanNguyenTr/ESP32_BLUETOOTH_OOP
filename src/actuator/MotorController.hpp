#pragma once
#include <Arduino.h>
#include "ActuatorInterface.hpp"

class MotorController : public ActuatorInterface {
    private:
    int speed = 0;
    public:
    MotorController() = default;
    ~MotorController() = default;
    void begin() override;
    void setState(const String& stateStr) override;
    String getName() const override;
};
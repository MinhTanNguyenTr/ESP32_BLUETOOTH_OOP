#pragma once
#include <Arduino.h>
#include "ActuatorInterface.hpp"

class MotorController : public ActuatorInterface {
    private:
    public:
    MotorController() = default;
    ~MotorController() = default;
    void begin() override;
    void setState(const String& state) override;
    String getName() const override;
};
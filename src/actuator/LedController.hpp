#pragma once
#include "ActuatorInterface.hpp"

class LedController : public ActuatorInterface {
    private:
    public:
    LedController() = default;
    void begin() override;
    void setState(const String& state) override;
    String getName() const;
};
#pragma once
#include "ActuatorInterface.hpp"

class LedController : public ActuatorInterface {
    private:
    bool state = false;
    public:
    LedController() = default;
    void begin() override;
    void setState(const String& stateStr) override;
    String getName() const;
};
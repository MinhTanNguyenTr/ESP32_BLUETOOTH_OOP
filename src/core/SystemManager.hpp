#pragma once
#include <Arduino.h>

class SystemManager {
    private:
    public:
    SystemManager() = default;
    ~SystemManager() = default;
    void begin();
    void loop();
    void handleCommand(const String& command);
};
#pragma once
#include <Arduino.h>
class CommandParser {
    private:
    public:
    CommandParser() = default;
    ~CommandParser() = default;
    void parse(const String& cmd);
};
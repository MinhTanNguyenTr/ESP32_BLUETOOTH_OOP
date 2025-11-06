#pragma once
#include <Arduino.h>

class Timer {
public:
    Timer() : last(0) {}
    bool expired(unsigned long interval_ms) {
        unsigned long now = millis();
        if (now - last >= interval_ms) {
            last = now;
            return true;
        }
        return false;
    }
    void reset() { last = millis(); }
private:
    unsigned long last;
};

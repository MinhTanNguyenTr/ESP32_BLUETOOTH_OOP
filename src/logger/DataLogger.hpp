#pragma once
#include <Arduino.h>
class DataLogger {
    private:
    public:
    void begin();
    void log(const String&);
    String getRecentLog(int count);
    void clear();
};
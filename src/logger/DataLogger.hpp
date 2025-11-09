#pragma once
#include <Arduino.h>
#include "StorageLogger.hpp"

class DataLogger {
public:
    DataLogger(StorageLogger& storage);
    void begin();
    void log(const String& msg);
    String getRecent(int count);
    void clear();
private:
    StorageLogger& storageManager;
    const String fname = "/logs";
};

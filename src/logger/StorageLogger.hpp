#pragma once
#include <Arduino.h>
class StorageLogger {
    private:
    public:
    void save(const String& fileName, const String& data);
    String read(const String& fileName);
};
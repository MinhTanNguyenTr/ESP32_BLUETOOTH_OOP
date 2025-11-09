#pragma once
#include <Arduino.h>
#include <map>
class StorageLogger {
public:
    void begin();
    void saveLine(const String& filename, const String& line);
    String readAll(const String& filename);
    void clear(const String& filename);
private:
    std::map<String, std::vector<String>> storage;
};

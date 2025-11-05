#pragma once
#include <WiFi.h>

class WifiManager {
    private:
    bool connected = false;
    unsigned long lastCheck = 0 ;
    public:
    void begin(const char* wifiID, const char* wifiPass);
    bool isConnected();
    void sendtoClound(const String& data);

};
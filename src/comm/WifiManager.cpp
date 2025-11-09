#include "WifiManager.hpp"
#include "../utils/Debug.hpp"

void WifiManager:: begin(const char* wifiID, const char* wifiPass) {
    DBG("WiFi","Connected to %s", wifiID);
    WiFi.begin(wifiID, wifiPass);
    int retry = 0;
    while(WiFi.status() != WL_CONNECTED && retry < 40)
    {
        delay(250);
        Serial.print(".");
        retry++;
    }
    if(WiFi.status() == WL_CONNECTED)
    {
        connected = true;
        DBG("WiFi", "Connect to %s success", wifiID);
    }
}
bool WifiManager:: isConnected() {
    if(WiFi.status() != WL_CONNECTED)
    {
        connected = false;
    }
    return connected;
}
void WifiManager:: sendtoClound(const String& data) {
    if(!isConnected())
    {
        DBG("WiFi","Not connected, skip upload");
        return;
    }
    DBG("WiFI", "Upload: %s ", data.c_str());
}
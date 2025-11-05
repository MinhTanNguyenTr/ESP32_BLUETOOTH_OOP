#pragma once
#include <BluetoothSerial.h>
class BluetoothManager {
    private:
    BluetoothSerial btSerial;
    public:
    BluetoothManager() = default;
    void begin(const String& deviceName);
    bool available();
    String readCommand();
    void sendResponse(const String& msg);
};
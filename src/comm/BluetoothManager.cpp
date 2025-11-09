#include "BluetoothManager.hpp"
#include "../utils/Debug.hpp"
void BluetoothManager:: begin(const String& deviceName) {
    if( !btSerial.begin(deviceName.c_str()))
    {
        DBG("Bluetooth","Fail to start bluetooth");
        return;
    }
    btSerial.setTimeout(50);
    started = true;
    DBG("Bluetooth", "Started as '%s", deviceName.c_str());
}
bool BluetoothManager::available() {
    if(!started) return false;
    return btSerial.available() > 0;
}
String BluetoothManager:: readCommand() {
    if(!started) return String();
    if(btSerial.available() == 0 ) return String();
    String line = btSerial.readStringUntil('\n');
    line.trim();
    if( line.length() == 0 ) return String();
    DBG("Bluetooth", "RX: %s", line.c_str());
    return line;
}
void BluetoothManager:: sendResponse(const String& msg) {
    if(!started) return;
    btSerial.print(msg);
    DBG("Bluetooth", "TX: %s", msg.c_str());
}
bool BluetoothManager:: connected() {
    return started;
}
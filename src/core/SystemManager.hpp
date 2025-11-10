#pragma once
#include <Arduino.h>
#include "../comm/BluetoothManager.hpp"
#include "../comm/WifiManager.hpp"
#include "../logger/DataLogger.hpp"
#include "../actuator/ActuatorInterface.hpp"
#include "../sensor/SensorManager.hpp"
#include "CommandParser.hpp"
#include "../logger/StorageLogger.hpp"
#include <vector>
class SystemManager {
    private:
    BluetoothManager bt;
    WifiManager wf;
    SensorManager senMan;
    StorageLogger storage;
    DataLogger* logger;
    std::vector<ActuatorInterface*> actuators;
    CommandParser* cmdParser;
    unsigned long lastloop = 0;
    void initActLoop();
    public:
    SystemManager();
    void begin();
    void loop();
};
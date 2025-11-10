#pragma once
#include <Arduino.h>
#include "../actuator/ActuatorInterface.hpp"
#include "../logger/DataLogger.hpp"
#include "../comm/BluetoothManager.hpp"
#include "../comm/WifiManager.hpp"
#include "../sensor/SensorManager.hpp"
class CommandParser {
    private:
    public:
    CommandParser(SensorManager& sm, std::vector<ActuatorInterface*> acts, DataLogger& logger, BluetoothManager& btSerial, WifiManager& wfMan);
    ~CommandParser() = default;
    void parseAnhExecute(const String& cmd);
    private:
    SensorManager& senMng;
    std::vector<ActuatorInterface*>& actuator;
    DataLogger& logger;
    BluetoothManager& bt;
    WifiManager& wf;
    ActuatorInterface* findActuatorName(const String& name);
};
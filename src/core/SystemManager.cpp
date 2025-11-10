#include "SystemManager.hpp"
#include "../utils/Debug.hpp"
#include "../config/AppConfig.hpp"
#include "../sensor/LightSensor.hpp"
#include "../sensor/TemperatureSensor.hpp"
#include "../actuator/LedController.hpp"
#include "../actuator/MotorController.hpp"
SystemManager::SystemManager() : logger(nullptr), cmdParser(nullptr) {}

void SystemManager::initActLoop()
{
    LedController * led = new LedController();
    MotorController * motor = new MotorController();
    actuators.push_back(led);
    actuators.push_back(motor);
}
void SystemManager::begin() 
{
    bt.begin(BT_DEVICE_NAME);
    wf.begin(WIFI_SSID, WIFI_PASS);

    senMan.addSensor(new TemperatureSensor);
    senMan.addSensor(new LightSensor);
    senMan.beginAll();

    storage.begin();

    logger = new DataLogger(storage);

    logger->begin();

    initActLoop();

    for(const auto& a:actuators)
    {
        a->begin();
    }

    cmdParser = new CommandParser(senMan, actuators, *logger, bt, wf);

    lastloop = millis();

    DBG("System", "Init done");
}
void SystemManager::loop() {
      if (bt.available()) {
        String cmd = bt.readCommand();
        if (cmd.length()) {
            cmdParser->parseAnhExecute(cmd);
        }
    }

    // periodic sensor read + send to cloud and log
    if (millis() - lastloop >= LOOP_INTERVAL_MS) {
        lastloop = millis();
        String sensorJson = senMan.collectDataJson();
        logger->log("SENSOR: " + sensorJson);
        if (wf.isConnected()) {
            wf.sendtoClound(sensorJson);
        }
        if (bt.connected()) {
            bt.sendResponse(sensorJson);
        }
    }
}
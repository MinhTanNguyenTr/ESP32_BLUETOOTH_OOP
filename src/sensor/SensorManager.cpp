#include "SensorManager.hpp"
#include "SensorInterface.hpp"
#include "../utils/Debug.hpp"
SensorManager:: ~SensorManager() {
    for(const auto& s:sensors)
    {
        delete s;
    }
    sensors.clear();
}
void SensorManager:: beginAll() {
    for(const auto& s:sensors)
    {
        s->begin();
    }
}
void SensorManager:: addSensor(SensorInterface* s) {
    sensors.push_back(s);
}
String SensorManager:: collectDataJson() {
    String out = "{";
    bool first = true;
    for(const auto& s:sensors)
    {
        float v = s->readValue();
        if(!first) out +=", ";
        out += "\"" + s->getName() + "\":" + String(v,2);
        first = false;
    }
    out += "}";
    DBG("SensorManager", "Collected: %s ", out.c_str());
    return out;
}
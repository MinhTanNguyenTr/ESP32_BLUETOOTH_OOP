#include "TemperatureSensor.hpp"
#include "../utils/Debug.hpp"

void TemperatureSensor:: begin() {
    DBG("Sensor", "Temperature sensor ready");
}
float TemperatureSensor:: readValue() {
    float v = 30.0 + (float)random(0,1500)/100.0;
    DBG("Temperature sensor","Read value: %0.02", v);
    return v;
}
String TemperatureSensor:: getName() const {
    return "Temperature sensor";
}
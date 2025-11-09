#include "LightSensor.hpp"
#include "../utils/Debug.hpp"
void LightSensor:: begin()  {
    DBG("Sensor", "Light Sensor Ready");
}
float LightSensor:: readValue()  {
    float v = 100.0 +(float)random(0,1500)/100.0;
    DBG("Light sensor", "Read value: %0.02f", v);
    return v;
}
String LightSensor:: getName() const  {
    return "Light Sensor";
}
#include <Arduino.h>
#include "core/SystemManager.hpp"

SystemManager systemCtrl;

void setup() {
    Serial.begin(115200);
    delay(200);
    Serial.println("\n=== Smart Control Hub ===");
    randomSeed(analogRead(0));
    systemCtrl.begin();
}

void loop() {
    systemCtrl.loop();
    delay(10); // small yield
}

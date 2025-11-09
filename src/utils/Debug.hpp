#pragma once
#include <Arduino.h>
#define DBG(tag, fmt, ...) Serial.printf("[%s] " fmt "\n", tag, ##__VA_ARGS__)

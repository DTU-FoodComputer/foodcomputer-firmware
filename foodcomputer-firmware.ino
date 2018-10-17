#include <Wire.h>

#include "configuration.h"

void setup() {
  init_sensors();
  Serial.begin(BAUD_RATE);
}

void loop() {
}

void init_sensors() {
  Wire.begin();
  
}



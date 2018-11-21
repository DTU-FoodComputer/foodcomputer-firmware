#include <Wire.h>
#include "configuration.h"

String cmd_string;

void setup() {
  cmd_string = "";
  init_sensors();
  init_actuators();
  Serial.begin(BAUD_RATE);
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\n') {
      if (interpret_command(cmd_string)) {
        Serial.print(cmd_string);
        Serial.print(": ");
        Serial.println("ok");
      } else {
        Serial.print("Unknown command: ");
        Serial.println(cmd_string);
      }
      cmd_string = "";
    } else {
      cmd_string = cmd_string + c;
    }
  }

  loop_sensors();
  loop_actuators();
}

void init_sensors() {
  //Wire.begin();
  init_water_level();
  init_am2315();
}

void init_actuators(){
  init_lights();
}

void loop_sensors() {
  update_water_level();
  update_am2315();
}

void loop_actuators() {
  // loop through actuators here
}


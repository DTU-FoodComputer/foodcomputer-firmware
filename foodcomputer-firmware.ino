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
  init_pumps();
  init_fans();
  init_heater();
  init_timer(12L*60L*60L, 18L*60L*60L, 6L*60L*60L, true); // 18 hours on, 6 hours off, turned on 12 hours into cycle
}

void loop_sensors() {
  update_water_level();
  update_am2315();
}

void loop_actuators() {
  // loop through actuators here
  update_timer();
}


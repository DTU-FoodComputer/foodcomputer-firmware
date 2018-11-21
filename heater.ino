#include "configuration.h"
#include "pins.h"

void init_heater(){
  pinMode(HEATER_1_PIN, OUTPUT);
  pinMode(HEATER_2_PIN, OUTPUT);
  digitalWrite(HEATER_1_PIN, HIGH);
  digitalWrite(HEATER_2_PIN, HIGH);
}

void start_heater(){
  digitalWrite(HEATER_1_PIN, LOW);
  digitalWrite(HEATER_2_PIN, LOW);
}

void stop_heater(){
  digitalWrite(HEATER_1_PIN, HIGH);
  digitalWrite(HEATER_2_PIN, HIGH);
}


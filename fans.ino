#include "configuration.h"
#include "pins.h"

void init_fans(){
  pinMode(FAN_FLUSH_PIN, OUTPUT);
  pinMode(FAN_HEAT_PIN, OUTPUT);
  digitalWrite(FAN_FLUSH_PIN, HIGH);
  digitalWrite(FAN_HEAT_PIN, HIGH);
}

void start_fan_flush(){
  digitalWrite(FAN_FLUSH_PIN, LOW);
}

void stop_fan_flush(){
  digitalWrite(FAN_FLUSH_PIN, HIGH);
}

void start_fan_heat(){
  digitalWrite(FAN_HEAT_PIN, LOW);
}

void stop_fan_heat(){
  digitalWrite(FAN_HEAT_PIN, HIGH);
}

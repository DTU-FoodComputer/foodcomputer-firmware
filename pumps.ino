#include "configuration.h"
#include "pins.h"

void init_nutrient_pumps(){
  pinMode(NUTRIENT_A_PIN, OUTPUT);
  pinMode(NUTRIENT_B_PIN, OUTPUT);
  digitalWrite(NUTRIENT_A_PIN, HIGH);  
  digitalWrite(NUTRIENT_B_PIN, HIGH);
}

void start_nutrient_a(){
  digitalWrite(NUTRIENT_A_PIN, LOW);
}

void stop_nutrient_a(){
  digitalWrite(NUTRIENT_A_PIN, HIGH);
}

void start_nutrient_b(){
  digitalWrite(NUTRIENT_B_PIN, LOW);
}

void stop_nutrient_b(){
  digitalWrite(NUTRIENT_B_PIN, HIGH);
}

void init_ph_pumps(){
  pinMode(PH_PLUS_PIN, OUTPUT);
  pinMode(PH_MINUS_PIN, OUTPUT);
  digitalWrite(PH_PLUS_PIN, HIGH);  
  digitalWrite(PH_MINUS_PIN, HIGH);
}

void start_ph_plus(){
  digitalWrite(PH_PLUS_PIN, LOW);
}

void stop_ph_plus(){
  digitalWrite(PH_PLUS_PIN, HIGH);
}

void start_ph_minus(){
  digitalWrite(PH_MINUS_PIN, LOW);
}

void stop_ph_minus(){
  digitalWrite(PH_MINUS_PIN, HIGH);
}

void init_water_pump(){
  pinMode(WATER_PUMP_PIN, OUTPUT);
  digitalWrite(WATER_PUMP_PIN, HIGH);
}

void start_water_pump(){
  digitalWrite(WATER_PUMP_PIN, LOW);
}

void stop_water_pump(){
  digitalWrite(WATER_PUMP_PIN, HIGH);
}

void init_air_pump(){
  pinMode(AIR_PUMP_PIN, OUTPUT);
  digitalWrite(AIR_PUMP_PIN, HIGH);
}

void start_air_pump(){
  digitalWrite(AIR_PUMP_PIN, LOW);
}

void stop_air_pump(){
  digitalWrite(AIR_PUMP_PIN, HIGH);
}

void init_cir_pump(){
  pinMode(CIR_PUMP_PIN, OUTPUT);
  digitalWrite(CIR_PUMP_PIN, HIGH);
}

void start_cir_pump(){
  digitalWrite(CIR_PUMP_PIN, LOW);
}

void stop_cir_pump(){
  digitalWrite(CIR_PUMP_PIN, HIGH);
}

void init_pumps(){
  init_ph_pumps();
  init_nutrient_pumps();
  init_water_pump();
  init_air_pump();
  init_cir_pump();
}


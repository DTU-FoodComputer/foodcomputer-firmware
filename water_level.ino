#include "configuration.h"
#include "pins.h"

int water_level;
unsigned long water_level_time_of_last_update;

int wmin;
int wmax;

void init_water_level(){
  pinMode(WATER_MIN_PIN, INPUT);
  pinMode(WATER_MAX_PIN, INPUT);

  wmin = HIGH;
  wmax = HIGH;
  water_level = 0;
  water_level_time_of_last_update = 0;
}

void update_water_level(){
  if (millis() - water_level_time_of_last_update > WATER_LEVEL_UPDATE_INTERVAL) {
    water_level_time_of_last_update = millis();
    wmin = digitalRead(WATER_MIN_PIN);
    wmax = digitalRead(WATER_MAX_PIN);
    water_level = 0;
    if (wmin == LOW){
      water_level++;
    }
    if (wmax == LOW){
      water_level++;
    }
  }
}

int get_water_level(){
  return water_level;
}

int get_water_level_min(){
  return wmin;
}

int get_water_level_max(){
  return wmax;
}


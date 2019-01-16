#include "configuration.h"

unsigned long timer_time_of_last_update;
unsigned long seconds_elapsed;
unsigned long time_on_seconds;
unsigned long time_off_seconds;
boolean timer_on;

void init_timer(unsigned long start_time, unsigned long on_time, unsigned long off_time, boolean start_state){
  seconds_elapsed = start_time;
  timer_time_of_last_update = 0;
  time_on_seconds = on_time;
  time_off_seconds = off_time;
  timer_on = start_state;

  trigger_timer();
}

void update_timer(){
  unsigned long time_delta = millis() - timer_time_of_last_update;
  if (time_delta >= 1000L) {
    timer_time_of_last_update = millis();
    seconds_elapsed++;

    if (timer_on && seconds_elapsed >= time_on_seconds){
      seconds_elapsed = 0;
      timer_on = false;
      trigger_timer();
    } else if (!timer_on && seconds_elapsed >= time_off_seconds){
      seconds_elapsed = 0;
      timer_on = true;
      trigger_timer();
    }
  }
}

void trigger_timer(){
  if (timer_on){
    set_white_light_int(100.0f);
    set_red_light_int(100.0f);
    set_blue_light_int(100.0f);
  } else {
    set_white_light_int(0.0f);
    set_red_light_int(0.0f);
    set_blue_light_int(0.0f);
  }
}


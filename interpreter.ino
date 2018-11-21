#include "configuration.h"
#include "pins.h"

boolean interpret_command(String cmd) {
  cmd.trim();
  int spaces = count_char(cmd, ' '); //counts number of spaces in command to check if command includes parameters
  String command_verb = "";
  String command_subject = "";
  String command_value = "";

  if (spaces == 0) {
    command_verb = cmd;
    command_subject = "";
  } else {
    int to_ind = cmd.indexOf(' ');
    command_verb = cmd.substring(0, to_ind);
    command_subject = cmd.substring(to_ind + 1);
    if (count_char(command_subject, ' ') > 0){
      to_ind = command_subject.indexOf(' ');
      command_value = command_subject.substring(to_ind+1);
      command_subject = command_subject.substring(0, to_ind);
    }
  }

  if (command_verb.equals("read")){
    return read_values(command_subject);
  } else if (command_verb.equals("set")){
    return set_values(command_subject, command_value);
  } else if (command_verb.equals("get")){
    return get_values(command_subject);
  } else if (command_verb.equals("start")){
    return start_actuators(command_subject);
  } else if (command_verb.equals("stop")){
    return stop_actuators(command_subject);
  }

  return false;
}

boolean read_values(String subject){
  if (subject.equals("water_level")){
    Serial.println(get_water_level());
    return true;
  } else if(subject.equals("water_level_status")){
    Serial.print("Water level min sensor on pin ");
    Serial.print(WATER_MIN_PIN);
    Serial.print(": ");
    Serial.print(get_water_level_min());
    Serial.print(", water level max sensor on pin ");
    Serial.print(WATER_MAX_PIN);
    Serial.print(": ");
    Serial.println(get_water_level_max());
    return true;
  } else if(subject.equals("humidity")){
    Serial.println(get_am2315_humidity());
    return true;
  } else if(subject.equals("air_temperature")){
    Serial.println(get_am2315_temperature());
    return true;
  }
  return false;
}

boolean set_values(String subject, String value){
  if (!string_is_float(value)){
    return false;
  }
  
  if (subject.equals("blue_light_int")){
    float intensity = value.toFloat();
    set_blue_light_int(intensity);
    return true;
  } else if (subject.equals("red_light_int")){
    float intensity = value.toFloat();
    set_red_light_int(intensity);
    return true;
  } else if (subject.equals("white_light_int")){
    float intensity = value.toFloat();
    set_white_light_int(intensity);
    return true;
  }
  
  return false;
}

boolean get_values(String subject){
  if (subject.equals("blue_light_int")){
    Serial.println(get_blue_light_int());
    return true;
  } else if (subject.equals("red_light_int")){
    Serial.println(get_red_light_int());
    return true;
  } else if (subject.equals("white_light_int")){
    Serial.println(get_white_light_int());
    return true;
  }
  return false;
}

boolean start_actuators(String subject){
  if (subject.equals("ph_plus")){
    start_ph_plus();
    stop_ph_minus();
    return true;
  } else if (subject.equals("ph_minus")){
    start_ph_minus();
    stop_ph_plus();
    return true;
  } else if (subject.equals("pump_a")){
    start_nutrient_a();
    return true;
  } else if (subject.equals("pump_b")){
    start_nutrient_b();
    return true;
  } else if (subject.equals("h2o_pump")){
    start_water_pump();
    return true;
  } else if (subject.equals("fan_flush")){
    start_fan_flush();
    return true;
  } else if (subject.equals("heater")){
    start_heater();
    start_fan_heat();
    return true;
  } else if (subject.equals("air_pump")){
    start_air_pump();
    return true;
  } else if (subject.equals("cir_pump")){
    start_cir_pump();
    return true;
  }
  
  return false;
}

boolean stop_actuators(String subject){
  if (subject.equals("ph")){
    stop_ph_plus();
    stop_ph_minus();
    return true;
  } else if (subject.equals("pump_a")){
    stop_nutrient_a();
    return true;
  } else if (subject.equals("pump_b")){
    stop_nutrient_b();
    return true;
  } else if (subject.equals("h2o_pump")){
    stop_water_pump();
    return true;
  } else if (subject.equals("fan_flush")){
    stop_fan_flush();
    return true;
  } else if (subject.equals("heater")){
    stop_heater();
    stop_fan_heat();
    return true;
  } else if (subject.equals("air_pump")){
    stop_air_pump();
    return true;
  } else if (subject.equals("cir_pump")){
    stop_cir_pump();
    return true;
  }
  
  return false;
}


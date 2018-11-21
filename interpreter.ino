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
  }

  if (command_verb.equals("set")){
    return set_values(command_subject, command_value);
  }

  if (command_verb.equals("get")){
    return get_values(command_subject);
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


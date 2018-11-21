// control of the 3 LED channels

int blue_light_state;
int red_light_state;
int white_light_state;

float blue_light_int;
float red_light_int;
float white_light_int;

void init_lights(){
  blue_light_state = LIGHT_OFF;
  red_light_state = LIGHT_OFF;
  white_light_state = LIGHT_OFF;

  blue_light_int = 0.0f;
  red_light_int = 0.0f;
  white_light_int = 0.0f;

  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(WHITE_LED_PIN, OUTPUT);
  
  digitalWrite(BLUE_LED_PIN, blue_light_state);
  digitalWrite(RED_LED_PIN, red_light_state);
  digitalWrite(WHITE_LED_PIN, white_light_state);
}

void set_blue_light_int(float intensity){
  blue_light_int = min(max(intensity, 0.0f), 100.0f); 
  if(blue_light_int >= 50.0f){
    blue_light_state = LIGHT_ON;
  } else {
    blue_light_state = LIGHT_OFF;
  }
  digitalWrite(BLUE_LED_PIN, blue_light_state);
}

void set_red_light_int(float intensity){
  red_light_int = min(max(intensity, 0.0f), 100.0f);
  if(red_light_int >= 50.0f){
    red_light_state = LIGHT_ON;
  } else {
    red_light_state = LIGHT_OFF;
  }
  digitalWrite(RED_LED_PIN, red_light_state);
}

void set_white_light_int(float intensity){
  white_light_int = min(max(intensity, 0.0f), 100.0f);
  if(white_light_int >= 50.0f){
    white_light_state = LIGHT_ON;
  } else {
    white_light_state = LIGHT_OFF;
  }
  digitalWrite(WHITE_LED_PIN, white_light_state);
}

float get_blue_light_int(){
  return blue_light_int;
}

float get_red_light_int(){
  return red_light_int;
}

float get_white_light_int(){
  return white_light_int;
}


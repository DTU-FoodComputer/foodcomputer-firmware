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


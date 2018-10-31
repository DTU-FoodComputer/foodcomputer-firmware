// Water electrical conductivity sensor 

/*#include "configuration.h"

int atlas_ec_addr;
boolean atlas_ec_waiting_for_response;
unsigned long atlas_ec_time_of_last_query;
float atlas_ec_water_electrical_conductivity;

byte atlas_ec_status_level;
byte atlas_ec_status_code;
String atlas_ec_msg;

byte atlas_ec_init(int i2c_addr) {
  atlas_ec_addr = i2c_addr;
  atlas_ec_waiting_for_response = false;
  atlas_ec_time_of_last_query = 0;
  atlas_ec_water_electrical_conductivity = -1.0;

  atlas_ec_status_level = STATUS_OK;
  atlas_ec_status_code = CODE_OK;
  atlas_ec_msg = "";
  return atlas_ec_status_level;
}

byte atlas_ec_update() {
  if (atlas_ec_waiting_for_response) {
    if (millis() - atlas_ec_time_of_last_query > 1400) {
      Serial.println("Reading response: ");
      atlas_ec_read_response();
    }
  } else if (millis() - atlas_ec_time_of_last_query > ATLAS_EC_MIN_UPDATE_INTERVAL) {
    Serial.println("Sending query...");
    atlas_ec_send_query();
  }
  return atlas_ec_status_level;
}

float atlas_ec_get_water_electrical_conductivity() {
  return atlas_ec_water_electrical_conductivity;
}

void atlas_ec_set_dry_calibration() {
  Wire.beginTransmission(atlas_ec_addr);
  Wire.print("Cal,dry");
  Wire.endTransmission();
}

void atlas_ec_set_single_calibration(double msg) {
  char buf[17];
  sprintf(buf, "Cal,one,%.2f", msg);
  Wire.beginTransmission(atlas_ec_addr);
  Wire.print(buf);
  Wire.endTransmission();
}

void atlas_ec_set_lowpoint_calibration(double msg) {
  char buf[17];
  sprintf(buf, "Cal,low,%.2f", msg);
  Wire.beginTransmission(atlas_ec_addr);
  Wire.print(buf);
  Wire.endTransmission();
}

void atlas_ec_set_highpoint_calibration(double msg) {
  char buf[17];
  sprintf(buf, "Cal,high,%.2f", msg);
  Wire.beginTransmission(atlas_ec_addr);
  Wire.print(buf);
  Wire.endTransmission();
}

void atlas_ec_send_query() {
  atlas_ec_time_of_last_query = millis();
  Wire.beginTransmission(atlas_ec_addr);
  Wire.print("r");
  Wire.endTransmission();
  atlas_ec_waiting_for_response = true;
  Serial.println("Query sent!");
}

void atlas_ec_read_response() {
  Wire.requestFrom(atlas_ec_addr, 20, 1);
  byte response;
  String string = "1000";
  if (Wire.available()) {
    response = Wire.read();
  }

  // check for failure
  if (response == 255) {
    atlas_ec_status_level = STATUS_ERROR;
    atlas_ec_status_code = CODE_NO_RESPONSE;
    atlas_ec_msg = "No response";
    Serial.println(atlas_ec_msg);
    atlas_ec_waiting_for_response = false;
  } else if (response == 254) {
    // Request hasn't been processed yet
    return;
  } else if (response == 2) {
    atlas_ec_status_level = STATUS_ERROR;
    atlas_ec_status_code = CODE_REQUEST_FAILED;
    atlas_ec_msg = "Request failed";
    Serial.println(atlas_ec_msg);
    atlas_ec_waiting_for_response = false;
  } else if ( response == 1) {
    string = Wire.readStringUntil(0);
    atlas_ec_status_level = STATUS_OK;
    atlas_ec_status_code = CODE_OK;
    atlas_ec_msg = "";
    atlas_ec_water_electrical_conductivity = string.toFloat() / 1000;
    Serial.println(atlas_ec_water_electrical_conductivity);
    atlas_ec_waiting_for_response = false;
  } else {
    atlas_ec_status_level = STATUS_ERROR;
    atlas_ec_status_code = CODE_UNKNOWN_ERROR;
    atlas_ec_msg = "Unknown error";
    Serial.println(atlas_ec_msg);
  }
}

String atlas_ec_get_msg(){
  return atlas_ec_msg;
}*/


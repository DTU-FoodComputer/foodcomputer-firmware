// Temperature and humidity sensor

#include <Wire.h>
#include <Adafruit_AM2315.h>

float air_temperature;
float air_humidity;

boolean am2315_started = false;
unsigned long am2315_time_of_last_update;

Adafruit_AM2315 am2315;

void init_am2315() {
  am2315_time_of_last_update = 0;
  am2315_started = am2315.begin();
  air_humidity = 0.0;
  air_temperature = 0.0;
}

void update_am2315() {
  if (millis() - am2315_time_of_last_update > AM2315_UPDATE_INTERVAL) {
    am2315_time_of_last_update = millis();
    if (am2315_started) {
      air_humidity = am2315.readHumidity();
      air_temperature = am2315.readTemperature();
    }
  }
}

float get_am2315_temperature() {
  return air_temperature;
}

float get_am2315_humidity() {
  return air_humidity;
}


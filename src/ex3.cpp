


#include "Arduino.h"


#define LIGHT_SENSOR_PIN 33
#define ALERT_ON_LEVEL 3000
#define ALERT_OFF_LEVEL 2500

bool alertActive = false;


/****************************************************/
void setup() {
  Serial.begin(115200);

  pinMode(LIGHT_SENSOR_PIN, INPUT);
}

/****************************************************/
void loop() {
  int value = analogRead(LIGHT_SENSOR_PIN);

  if (!alertActive && value > ALERT_ON_LEVEL) {
    alertActive = true;
    Serial.println("ALERT=1");
  } else if (alertActive && value < ALERT_OFF_LEVEL) {
    alertActive = false;
    Serial.println("ALERT=0");
  }

  delay(300);
}

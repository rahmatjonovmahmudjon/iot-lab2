
#include <Arduino.h>

#define LIGHT_SENSOR_PIN 33

#define SAMPLE_COUNT 10


/****************************************************/
void setup() {

  Serial.begin(115200);

  pinMode(LIGHT_SENSOR_PIN, INPUT);

}

/****************************************************/
void loop() {
  int minValue = 4095;
  int maxValue = 0;
  long sum = 0;

  for (int i = 0; i < SAMPLE_COUNT; i++) {

    int value = analogRead(LIGHT_SENSOR_PIN);

    minValue = min(minValue, value);
    maxValue = max(maxValue, value);

    sum += value;
  }

  int avg = sum / SAMPLE_COUNT;

  Serial.print("min=");
  Serial.print(minValue);

  Serial.print(" max=");
  Serial.print(maxValue);
  
  Serial.print(" avg=");
  Serial.println(avg);

  delay(1000);

}

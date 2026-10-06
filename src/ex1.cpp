#include <Arduino.h>

#define RED_LED_PIN 26
#define GREEN_LED_PIN 27
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN 14

const char* ledNames[6] = {"RED", "GREEN", "YELLOW", "BLUE", "YELLOW", "GREEN"};
int chaseOrder[6] = {RED_LED_PIN, GREEN_LED_PIN, YELLOW_LED_PIN, BLUE_LED_PIN, YELLOW_LED_PIN, GREEN_LED_PIN};
int step = 0;


/****************************************************/
void setup() {
  Serial.begin(115200);

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

/****************************************************/
void loop() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(chaseOrder[i], LOW);
  }

  digitalWrite(chaseOrder[step], HIGH);

  Serial.print("chase=");
  Serial.println(ledNames[step]);

  Serial.print("step=");
  Serial.println(step);

  step = (step + 1) % 6;

  delay(150);
}

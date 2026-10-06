

#include "Arduino.h"


#define RED_LED_PIN 26
#define GREEN_LED_PIN 27
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN 14

#define BUTTON_PIN 25

int ledPins[4] = {RED_LED_PIN, GREEN_LED_PIN, YELLOW_LED_PIN, BLUE_LED_PIN};
int pressCount = 0;
int lastButtonState = LOW;


/****************************************************/
void setup() {
  
    Serial.begin(115200);

    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);

}

/****************************************************/
void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH && lastButtonState == LOW) {
    pressCount = (pressCount + 1) % 5;

    Serial.print("count=");
    Serial.println(pressCount);

    for (int i = 0; i < 4; i++) {
      if (i < pressCount) {
        digitalWrite(ledPins[i], HIGH);
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    }
  }

  lastButtonState = buttonState;

  delay(20);
}

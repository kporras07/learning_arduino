#include "SR04.h"

#define TRIG_PIN 12
#define ECHO_PIN 11
#define BUZZER 8
#define MIN_DISTANCE 15

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long cm;

void setup() {
  Serial.begin (9600);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  cm = sr04.Distance();
  //Print distance
  Serial.println(cm);

  if (cm <= MIN_DISTANCE) {
    digitalWrite(BUZZER, HIGH);
    delay(1000);
  }
  digitalWrite(BUZZER, LOW);
  delay(500);

}

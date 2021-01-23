#include "SR04.h"

#define TRIG_PIN 12
#define ECHO_PIN 11 

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long cm;
int height = 20; //define depth of tank in cm
int firstLED = 4;
int secondLED = 5;
int thirdLED = 6;
int fourthLED = 7;

void setup() {
  Serial.begin (9600);
  pinMode(firstLED, OUTPUT);
  pinMode(secondLED, OUTPUT);
  pinMode(thirdLED, OUTPUT);
  pinMode(fourthLED, OUTPUT);
}

void loop() {

  cm = sr04.Distance();
  //Print distance
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  // Empty.
  if (cm >= height) {
    digitalWrite(firstLED, LOW);
    digitalWrite(secondLED, LOW);
    digitalWrite(thirdLED, LOW);
    digitalWrite(fourthLED, LOW);
  }
  // > 1/4
  else if (cm >= (3*height/4)) {
   digitalWrite(firstLED, HIGH);
   digitalWrite(secondLED, LOW);
   digitalWrite(thirdLED, LOW);
   digitalWrite(fourthLED, LOW);
  }
  // > 2/4 (1/20
  else if (cm >= (2*height/4)) {
   digitalWrite(firstLED, HIGH);
   digitalWrite(secondLED, HIGH);
   digitalWrite(thirdLED, LOW);
   digitalWrite(fourthLED, LOW);
  }
  // > 3/4
  else if (cm >= (1*height/4)) {
   digitalWrite(firstLED, HIGH);
   digitalWrite(secondLED, HIGH);
   digitalWrite(thirdLED, HIGH);
   digitalWrite(fourthLED, LOW);
  }
  else {
   digitalWrite(firstLED, HIGH);
   digitalWrite(secondLED, HIGH);
   digitalWrite(thirdLED, HIGH);
   digitalWrite(fourthLED, HIGH);
  }
}

#include "pitches.h"

int buzzer = 8;

int quaver = 500;
int semiQuaver = 250;
int black = 1000;
int white = 2000;
int rounded = 4000;

int tempo = 500;

float realTempo = float(tempo) / float(1000);

int melody[24][2] = {
  { NOTE_C5, black },
  { NOTE_D5, black },
  { NOTE_E5, black },
  { NOTE_F5, black },
  { NOTE_G5, black },
  { NOTE_G5, black },
  { NOTE_A5, quaver },
  { NOTE_A5, quaver },
  { NOTE_A5, quaver },
  { NOTE_A5, quaver },
  { NOTE_G5, white },
  { NOTE_G5, white },
  { NOTE_F5, quaver },
  { NOTE_F5, quaver },
  { NOTE_F5, quaver },
  { NOTE_F5, quaver },
  { NOTE_E5, white },
  { NOTE_E5, white },
  { NOTE_D5, quaver },
  { NOTE_D5, quaver },
  { NOTE_D5, quaver },
  { NOTE_D5, quaver },
  { NOTE_C5, white },
  { NOTE_C5, white }
};

void setup() {
  Serial.begin(9600);
}
 
void loop() {
  for (int thisNote = 0; thisNote < 24; thisNote++) {
    float noteSpeed = float(melody[thisNote][1]) * float(realTempo);
    tone(buzzer, melody[thisNote][0], noteSpeed);
    // Output the voice after several minutes
    float delayTime = 200 + noteSpeed;
    delay(delayTime);
  }
   
  // restart after two seconds 
  delay(2000);
}

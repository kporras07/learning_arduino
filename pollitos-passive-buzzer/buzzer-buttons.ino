#include "pitches.h"


int quaver = 500;
int semiQuaver = 250;
int black = 1000;
int white = 2000;
int rounded = 4000;

int tempo = 500;

float realTempo = float(tempo) / float(1000);

int buzzer = 9;
int buttonApin = 8;
int buttonBpin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);
}

void playHappyBirthday() {
  int melody[25][2] = {
    { NOTE_C5, quaver },
    { NOTE_C5, quaver },
    { NOTE_D5, black },
    { NOTE_C5, black },
    { NOTE_F5, black },
    { NOTE_E5, white },
    { NOTE_C5, quaver },
    { NOTE_C5, quaver },
    { NOTE_D5, black },
    { NOTE_C5, black },
    { NOTE_G5, black },
    { NOTE_F5, white },
    { NOTE_C5, quaver },
    { NOTE_C5, quaver },
    { NOTE_C6, black },
    { NOTE_A5, black },
    { NOTE_F5, black },
    { NOTE_E5, black },
    { NOTE_D5, white },
    { NOTE_AS5, quaver },
    { NOTE_AS5, quaver },
    { NOTE_A5, black },
    { NOTE_F5, black },
    { NOTE_G5, black },
    { NOTE_F5, white }
  };

  playSong(melody, 25);
}

void playPollitos() {
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

  playSong(melody, 24);
}

void playSong(int[] melody, int notesAmount) {
  for (int thisNote = 0; thisNote < notesAmount; thisNote++) {
    float noteSpeed = float(melody[thisNote][1]) * float(realTempo);
    tone(buzzer, melody[thisNote][0], noteSpeed);
    // Output the voice after several minutes
    float delayTime = 200 + noteSpeed;
    delay(delayTime);
  }
}
 
void loop() {

  if (digitalRead(buttonApin) == LOW)
  {
    playPollitos();
  }
  if (digitalRead(buttonBpin) == LOW)
  {
    playHappyBirthday();
  }
   
  // restart after two seconds 
  delay(2000);
}

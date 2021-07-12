#include "pitches.h"
#include "IRremote.h"
#include "IR.h"

// Actual code starts here.

int quaver = 500;
int semiQuaver = 250;
int black = 1000;
int white = 2000;
int rounded = 4000;

int tempo = 500;

int tempoValues[] = {500, 600, 700, 800, 900, 1000, 100, 200, 300, 400};
int currentTempo = 0;

float realTempo = float(tempo) / float(1000);

int buzzer = 11;
int buttonApin = 8;
int buttonBpin = 7;
int buttonCpin = 6;
int ledRed = 5;
int ledGreen = 4;
int ledBlue = 3;

int receiver = 9;

char inputByte;

IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'

void setup() {
  Serial.begin(9600);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);
  pinMode(buttonCpin, INPUT_PULLUP);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver.
}

void playSong(int melody[][2], int notesAmount) {
  int currentLed = 5;
  for (int thisNote = 0; thisNote < notesAmount; thisNote++) {
    float noteSpeed = float(melody[thisNote][1]) * float(realTempo);
    if (!melody[thisNote][0] == false) {
      tone(buzzer, melody[thisNote][0], noteSpeed);
      digitalWrite(currentLed, HIGH);
      delay(noteSpeed);
      digitalWrite(currentLed, LOW);
      if (currentLed == 3) {
        currentLed = 5;
      }
      else {
        currentLed -= 1;
      }
    }
    delay(200);
  }
}

void playBohemianRhapsody() {
  int melody[][2] = {
    { NOTE_D5, quaver },
    { NOTE_D5, black + black / 2},
    { false, black },
    { false, quaver },
    { NOTE_AS4, quaver },
    { NOTE_C5, quaver },
    { NOTE_D5, semiQuaver },
    { NOTE_D5, semiQuaver + black },
    { false, black },
    { false, quaver },
    { NOTE_D5, semiQuaver },
    { NOTE_D5, semiQuaver },
    { NOTE_DS5, semiQuaver },
    { NOTE_F5, quaver },
    { NOTE_DS5, semiQuaver + semiQuaver },
    { NOTE_D5, quaver },
    { NOTE_C5, semiQuaver + quaver },
    { false, quaver },
    { NOTE_C5, quaver },
    { NOTE_D5, quaver },
    { NOTE_DS5, semiQuaver },
    { NOTE_F5, quaver },
    { NOTE_DS5, semiQuaver + semiQuaver },
    { NOTE_D5, quaver },
    { NOTE_C5, semiQuaver + quaver },
    { false, black },
    { NOTE_D5, quaver },
    { NOTE_D5, black + quaver },
    { false, black },
    { NOTE_D5, quaver },
    { NOTE_F5, quaver },
    { NOTE_A5, quaver + semiQuaver },
    { NOTE_G5, semiQuaver },
    { NOTE_G5, white },
    { false, quaver },
    { NOTE_G5, quaver },
    { NOTE_AS5, quaver },
    { NOTE_AS5, quaver },
    { NOTE_AS5, quaver },
    { NOTE_AS5, quaver },
    { NOTE_AS5, quaver },
    { NOTE_G5, quaver },
    { NOTE_DS5, semiQuaver },
    { NOTE_D5, quaver },
    { NOTE_C5, white + black },
    { false, black },
    { NOTE_G5, quaver },
    { NOTE_G5, white + quaver },
    { NOTE_F5, quaver },
    { NOTE_G5, semiQuaver },
    { NOTE_GS5, semiQuaver },
    { NOTE_G5, white + black },
    { false, black + semiQuaver },
    { NOTE_GS5, quaver },
    { NOTE_G5, semiQuaver },
    { NOTE_G5, quaver },
    { NOTE_F5, quaver },
    { NOTE_F5, black + quaver },
    { false, semiQuaver },
    { NOTE_AS4, semiQuaver },
    { NOTE_AS4, quaver },
    { NOTE_F5, quaver },
    { NOTE_F5, quaver },
    { NOTE_G5, semiQuaver },
    { NOTE_G5, semiQuaver },
    { NOTE_GS5, quaver },
    { NOTE_GS5, quaver },
    { NOTE_GS5, quaver },
    { NOTE_AS5, quaver },
    { NOTE_GS5, quaver },
    { NOTE_G5, black },
    { NOTE_F5, quaver },
    { NOTE_DS5, quaver },
    { NOTE_AS5, black },
    { NOTE_G5, quaver },
    { NOTE_AS5, black },
    { NOTE_C6, black + quaver },
    { NOTE_G5, black },
    { NOTE_C6, quaver },
    { NOTE_D6, semiQuaver },
    { NOTE_DS6, quaver },
    { NOTE_C6, quaver },
    { NOTE_D6, semiQuaver },
    { NOTE_DS6, quaver },
    { NOTE_F6, white }
  };

  int arraySize = sizeof(melody) / sizeof(melody[0]);
  Serial.println(arraySize);

  playSong(melody, arraySize);
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
 
void loop() {

  if (digitalRead(buttonApin) == LOW)
  {
    playPollitos();
  }
  if (digitalRead(buttonBpin) == LOW)
  {
    playHappyBirthday();
  }
  if (digitalRead(buttonCpin) == LOW)
  {
    playBohemianRhapsody();
  }
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    if (results.value == KEY_1) {
      playBohemianRhapsody();
    }
    if (results.value == KEY_2) {
      playHappyBirthday();
    }
    if (results.value == KEY_3) {
      playPollitos();
    }
    irrecv.resume();
  }

  if (Serial.available() > 0) {
    inputByte= Serial.read();
    if (inputByte == 'Z') {
      playBohemianRhapsody();
    }
    if (inputByte == 'Y') {
      playHappyBirthday();
    }
    if (inputByte == 'W') {
      playPollitos();
    }
  }
   
  // restart after two seconds 
  delay(500);
}

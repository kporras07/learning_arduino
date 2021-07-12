/*
  MC-38 Magnetic Sensor Anti-Theft Alarm
  modified on 26 Sep 2020
  by Mohammad Reza Akbari @ Electropeak
  https://electropeak.com/learn/
*/


const int magnet_switch = 2;     // Magnet switch
const int buzzerPin =  4;      // Buzzer pin

void setup() {
  // initialize the buzzer pin as an output:
  pinMode(buzzerPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(magnet_switch, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(magnet_switch) == HIGH) {
    Serial.println("Switch open");
    digitalWrite(buzzerPin, HIGH);
    while (digitalRead(magnet_switch) == HIGH) {}
    
  }
  else {
    digitalWrite(buzzerPin, LOW);
    Serial.println("Switch closed");
    while (digitalRead(magnet_switch) == LOW) {}
  }
} 

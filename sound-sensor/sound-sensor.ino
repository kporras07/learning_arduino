// Adjusted with potentiometer ~500.

// < ~510 = Sound ON
// >= ~510 = Sound OFF

const int micSensorDig = 9;
const int micSensorAn = A0;

int currentStatus = 0;
int lastRead = 0;

void setup() {
  pinMode(micSensorDig,INPUT_PULLUP);
  pinMode(micSensorAn,INPUT);

  Serial.begin(9600); //initialise serial monitor

}

void loop() {
  int thisRead = analogRead(micSensorAn);
  if (thisRead < 450) {
    if (currentStatus == 0) {
      Serial.println("TURN ON!");
      currentStatus = 1;
      delay(5000);
    }
    else {
      Serial.println("TURN OFF!");
      currentStatus = 0;
      delay(5000);
    }
  }
  delay(300);
}

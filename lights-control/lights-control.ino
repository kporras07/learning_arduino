// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
const int outputPin = 8;
const int pirSensor = 7;

// variables:
int sensorValue = 0;         // the sensor value

int pirEnabled = 0;

void setup() {
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT);
  pinMode(pirSensor, INPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println("RAW");
  Serial.println(sensorValue);

  if (sensorValue < 100) {
    pirEnabled = 1;
  }

  if (pirEnabled) {
    if (digitalRead(pirSensor) == HIGH) { 
      Serial.println("Movimiento detectado");
      digitalWrite(outputPin, HIGH);
    }
    else {
      digitalWrite(outputPin , LOW);
      Serial.println("Movimiento NO detectado");
      pirEnabled = 0;
    }
  }
  
  delay(2000);
}  

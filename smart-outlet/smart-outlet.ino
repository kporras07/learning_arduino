int pinOut = 8;

void setup(){
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop()
{
  Serial.println("Set High");
  digitalWrite(pinOut, HIGH);
  delay(2000);
  Serial.println("Set Low");
  digitalWrite(pinOut, LOW);
  delay(2000);         
}

//Ejemplo básico con el HC-SR501
 
const int sensor = 8;
const int speaker = 12;
void setup()
{
 pinMode(sensor, INPUT);
 pinMode(speaker, OUTPUT); 
 Serial.begin(9600);
}
 
void loop()
{
 if(digitalRead(sensor) == HIGH)
  { 
   Serial.println("Movimiento detectado");
   digitalWrite(speaker, HIGH);
  }
  else {
       digitalWrite(speaker , LOW);

     Serial.println("Movimiento NO detectado");
    }
       delay(500);

}

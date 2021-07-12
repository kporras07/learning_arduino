// RFID library from https://github.com/miguelbalboa/rfid

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  9    //Pin 9 para el reset del RC522
#define SS_PIN  10   //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); //Creamos el objeto para el RC522

const int magnet_switch = 2;     // Magnet switch
const int buzzerPin =  4;      // Buzzer pin

void setup() {
  Serial.begin(9600); //Iniciamos la comunicación  serial
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos  el MFRC522
  pinMode(buzzerPin, OUTPUT);
  pinMode(magnet_switch, INPUT_PULLUP);
}

byte actualUID[4]; //almacenará el código del Tag leído
byte users[][4] = {
  {0xE7, 0x7D, 0x82, 0xC8},
  {0x27, 0x2E, 0x1F, 0xD9}
};
bool accessGranted;

bool isArmed = true;

void loop() {
  isArmed = true;
  // Revisamos si hay nuevas tarjetas  presentes
  if (mfrc522.PICC_IsNewCardPresent()) {
    //Seleccionamos una tarjeta
    if ( mfrc522.PICC_ReadCardSerial()) {
      // Enviamos serialemente su UID
      Serial.print("Card UID:");
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX); 
        actualUID[i]=mfrc522.uid.uidByte[i];
      }
      Serial.println();
      accessGranted = false;

      for (int userIndex = 0; userIndex < sizeof(users); userIndex++) {
        if (compareTags(actualUID, users[userIndex])) {
          accessGranted = true;
          break;
        }
      }
      if (accessGranted) {
        isArmed = false;
      }
      // Terminamos la lectura de la tarjeta  actual
      mfrc522.PICC_HaltA();         
    }      
  }
  if (isArmed) {
    if (digitalRead(magnet_switch) == HIGH) {
      Serial.println("Switch open");
      digitalWrite(buzzerPin, HIGH);
      while (digitalRead(magnet_switch) == HIGH) {}
    }
    else {
      digitalWrite(buzzerPin, LOW);
      Serial.println("Switch closed");
    }
  }
}

boolean compareTags(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}

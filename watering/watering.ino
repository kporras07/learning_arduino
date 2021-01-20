int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

int Pin1 = A0; //模拟引脚A0连接传感器输入
int Pin2 = A1;
int Pin3 = A2;
int Pin4 = A3;

float value1 = 0;
float value2 = 0;
float value3 = 0;
float value4 = 0;

int threshold = 550;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(Pin1, INPUT);
  pinMode(Pin2, INPUT);
  pinMode(Pin3, INPUT);
  pinMode(Pin4, INPUT);

  // Using NO: High means off. Low means on.
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(5000);
}
void loop() {
  
  Serial.print("MOISTURE LEVEL:");
  value1 = analogRead(Pin1);
  Serial.println(value1);
  if(value1 < threshold)
  {
      digitalWrite(IN1, HIGH);
  }
  else
  {
      Serial.println("TURN ON PUMP1!");
      digitalWrite(IN1, LOW);
  }
    
  Serial.print("MOISTURE LEVEL:");
  value2 = analogRead(Pin2);
  Serial.println(value2);
  if(value2 < threshold)
  {
      digitalWrite(IN2, HIGH);
  }
  else
  {
      Serial.println("TURN ON PUMP 2!");
      digitalWrite(IN2, LOW);
  }

  Serial.print("MOISTURE LEVEL:");
  value3 = analogRead(Pin3);
  Serial.println(value3);
  if(value3 < threshold)
  {
      digitalWrite(IN3, HIGH);
  }
  else
  {
      Serial.println("TURN ON PUMP 3!");
      digitalWrite(IN3, LOW);
  }

  Serial.print("MOISTURE LEVEL:");
  value4 = analogRead(Pin4);
  Serial.println(value4);
  if(value4 < threshold)
  {
      digitalWrite(IN4, HIGH);
  }
  else
  {
      Serial.println("TURN ON PUMP 4!");
      digitalWrite(IN4, LOW);
  }
  Serial.println();

  delay(2000);
}

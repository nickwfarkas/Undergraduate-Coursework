int sensorReading;

void setup() 
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() 
{
  sensorReading  =  analogRead(A0);
  int  range = map(sensorReading, 0, 600, 0, 3);

  switch(range)
  {
    case 0:
      Serial.println("dark");
      digitalWrite(2, true);
      break;
    case 1:
      Serial.println("dim");
      digitalWrite(2, false);
      digitalWrite(3, true);
      break;
    case 2:
      Serial.println("medium");
      digitalWrite(3, false);
      digitalWrite(4, true);
      break;
    case 3:
      Serial.println("bright");
      digitalWrite(4, false);
      digitalWrite(5, true);
      break;
  }
 
  delay(1);

  digitalWrite(2, false);
  digitalWrite(3, false);
  digitalWrite(4, false);
  digitalWrite(5, false);
}

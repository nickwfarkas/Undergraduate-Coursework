int LEDArray[] = {5, 6, 9, 10}; 
int numOfLEDs = 4;
int pirState = LOW;
int pirVal = 0;
int pirPin = 12;

void setup() 
{
  Serial.begin(9600); 
  pinMode(pirPin, INPUT);
  int i;
  for(i = 0; i < numOfLEDs; i++) 
  {
    pinMode(LEDArray[i], OUTPUT); 
  }
}

void loop() 
{
  pirVal = digitalRead(pirPin);
  int i;
  if (pirVal == HIGH) 
  {
    for (i= 0; i < numOfLEDs; i++) 
    {
      analogWrite(LEDArray[i], 255);
      delay (1000); 
    }
    delay (1000);
    for (i= 0; i < numOfLEDs; i++) 
    {
      analogWrite(LEDArray[i], 0);
      delay (1000); 
    }
    if (pirState == LOW) 
    { 
      pirState = HIGH;
    } 
  }
  else 
  {
    analogWrite(LEDArray[0], 0); 
    analogWrite(LEDArray[1], 0); 
    analogWrite(LEDArray[2], 0); 
    analogWrite(LEDArray[3], 0); 
    if (pirState == HIGH) 
    {
      pirState = LOW; 
    }
   }
}

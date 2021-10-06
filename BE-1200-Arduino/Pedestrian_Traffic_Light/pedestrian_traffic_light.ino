int carRed = 13;
int carYellow = 12;
int carGreen = 11;
int pedRed = 3;
int pedGreen = 2;
int button = 8;
float changedTime;
int state = 0;

void setup()
{
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT);
  
  digitalWrite(carGreen, true);
  digitalWrite(pedRed, true);
}

void loop()
{
  state = digitalRead(button);

  
  if (state == HIGH)
  {
    changeLights();
  }
}

float changeLights()       
{
  delay(1000);
  digitalWrite(carGreen, false);
  digitalWrite(carYellow, true);
  delay(2000);
  
  digitalWrite(carYellow, false);
  digitalWrite(carRed, true);
  delay(1000);
  
  digitalWrite(pedRed, false);
  digitalWrite(pedGreen, true);
  delay(5000);

  for(int i = 0; i < 10; i++)
  {
    digitalWrite(pedGreen, true);
    delay(250);
    digitalWrite(pedGreen, false);
    delay(250);
  }

  digitalWrite(pedRed, true);
  delay(500);

  digitalWrite(carYellow, true);
  digitalWrite(carRed, false);
  delay(1000);

  digitalWrite(carGreen, true);
  digitalWrite(carYellow, false);

  changedTime = millis();
}

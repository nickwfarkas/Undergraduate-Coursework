int redLED = 11;
int greenLED = 10;
int blueLED = 9;

int redSwitch = 7;
int greenSwitch = 6;
int blueSwitch = 5;

int red = 0;
int blue = 0;
int green = 0;

void setup() 
{
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  pinMode(redSwitch, INPUT_PULLUP);
  pinMode(greenSwitch, INPUT_PULLUP);
  pinMode(blueSwitch, INPUT_PULLUP);
}

void loop() 
{
  if(digitalRead(redSwitch)==LOW)
  {
    red++;
    if(red > 255)
    {
      red = 0;
    }
  }
  if(digitalRead(greenSwitch)==LOW)
  {
    green++;
    if(green > 255)
    {
      green = 0;
    }
  }
  if(digitalRead(blueSwitch)==LOW)
  {
    blue++;
    if(blue > 255)
    {
      blue = 0;
    }
  }
  analogWrite(redLED, red);
  analogWrite(greenLED, green);
  analogWrite(blueLED, blue);
  //delay(10);
}

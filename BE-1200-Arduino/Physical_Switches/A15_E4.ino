int pin_LEDred= 11;\
int pin_LEDgreen= 10;
int pin_LEDblue= 9;
int pin_switch= 3;
// variables to hold the new and old switch states
int oldSwitchState= 0;
int newSwitchState= 0;
int state = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pin_LEDred, OUTPUT);    
  pinMode(pin_LEDgreen, OUTPUT);   
  pinMode(pin_LEDblue, OUTPUT);      
  pinMode(pin_switch, INPUT);
}

void loop()
{
  newSwitchState = digitalRead(pin_switch);
  if(newSwitchState!=oldSwitchState)
  {
    if(newSwitchState==HIGH)
    {
      state++;
      if (state > 3) 
      {
        state = 0;
      }
      // turn all LEDs off. 
      digitalWrite(pin_LEDred, LOW);
      digitalWrite(pin_LEDgreen, LOW);
      digitalWrite(pin_LEDblue, LOW);
      if(state == 1) 
      {
        digitalWrite(pin_LEDred, HIGH);
      }
      if(state == 2) 
      {
        digitalWrite(pin_LEDgreen, HIGH);      
      }
      if (state == 3) 
      {
        digitalWrite(pin_LEDblue, HIGH);
      }
     }
     oldSwitchState=newSwitchState;
  }  
}

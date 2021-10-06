int pinBuzzer = 6;
int pinSensorPIR = 8; 
int pinLed = 9;
int valorSensorPIR = 0;
void setup()
{ 
  pinMode(pinBuzzer,OUTPUT); 
  pinMode(pinSensorPIR,INPUT); 
  pinMode(pinLed,OUTPUT);
}

void loop() 
{
  valorSensorPIR = digitalRead(pinSensorPIR);
  if (valorSensorPIR == 1)
    { 
      ligarAlarme();
    } 
    else 
    { 
      desligarAlarme(); 
    }
}

void ligarAlarme()
{ 
  digitalWrite(pinLed,HIGH);
  tone(pinBuzzer,1500); 
  delay(2000); 
  desligarAlarme(); 
}

void desligarAlarme() 
{ 
  digitalWrite(pinLed, LOW); 
  noTone(pinBuzzer);
}

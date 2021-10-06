#include <LedControl.h>

int DIN = 12; 
int CS = 11; 
int CLK = 10;
LedControl lc=LedControl(DIN,CLK,CS,0);

void setup()
{ 
  lc.shutdown(0,false); 
  lc.setIntensity(0,15); 
  lc.clearDisplay(0); 
}

void loop()
{
  byte I[8]= {0x00,0x66,0xFF,0xFF,0x7E,0x3C,0x18,0x00,};
  byte Heart[8] = {0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xFF,0xFF,}; 
  byte U[8]= {0x3C,0x3C,0x18,0x18,0x18,0x18,0x3C,0x3C,};
  printByte(I); 
  delay(1000); 
  printByte(Heart); 
  delay(1000); 
  printByte(U); 
  delay(1000);
}
void printByte(byte character []) 
{ 
  int i=0;
  for(i=0;i<8;i++)
  { 
    lc.setRow(0,i,character[i]); 
  }
}

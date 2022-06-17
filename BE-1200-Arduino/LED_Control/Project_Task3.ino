#include <LedControl.h>

int DIN = 12;
int CS= 11;
int CLK = 10;
LedControl lc=LedControl(DIN,CLK,CS,0);
 
void setup()
{
  lc.shutdown(0,false); 
  lc.setIntensity(0,15); 
  lc.clearDisplay(0);
}
void loop(){
  byte n[8]= {0x81,0xc1,0xa1,0x91,0x89,0x85,0x83,0x81};
  byte i[8]= {0x08,0x00,0x00,0x08,0x08,0x08,0x08,0x08}; 
  byte c[8]= {0x00,0x7e,0x40,0x40,0x40,0x40,0x7e,0x00}; 
  byte k[8]= {0x00,0x48,0x50,0x60,0x60,0x50,0x48,0x00}; 
  printByte(n); 
  delay(1000); 
  printByte(i); 
  delay(1000); 
  printByte(c); 
  delay(1000); 
  printByte(k); 
  delay(1000); 
}
void printEduc8s(){}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  { 
    lc.setRow(0,i,character[i]); 
  }
}

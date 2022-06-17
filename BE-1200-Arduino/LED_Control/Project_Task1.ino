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
  byte smile[8]= {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C}; 
  byte neutral[8]={0x3C,0x42,0xA5,0x81,0xBD,0x81,0x42,0x3C}; 
  byte frown[8]= {0x3C,0x42,0xA5,0x81,0x99,0xA5,0x42,0x3C}; 
  byte E[8]= {0x7C,0x7C,0x60,0x7C,0x7C,0x60,0x7C,0x7C}; 
  byte B[8]= {0xFE,0xC6,0xC6,0xFC,0xFC,0xC6,0xC6,0xFE,};
  printByte(smile); 
  delay(1000); 
  printByte(neutral); 
  delay(1000); printByte(frown); 
  delay(1000); 
  printByte(B); 
  delay(1000); 
  printByte(E); 
  delay(1000); 
  printByte(smile); 
  delay(1000);
  lc.clearDisplay(0);
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

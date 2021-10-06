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
  byte arrow1[8]= {0xaa,0x55,0xaa,0x00,0x00,0x55,0xaa,0x55};
  byte arrow2[8]= {0x55,0xaa,0x55,0x00,0x00,0xaa,0x55,0xaa};
  
  printByte(arrow1); 
  delay(1000); 

  printByte(arrow2); 
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

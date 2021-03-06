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
void loop()
{ 
  byte arrow_up[8]= {0x18,0x3C,0x7E,0xFF,0x18,0x18,0x18,0x18}; 
  byte arrow_down[8]= {0x18,0x18,0x18,0x18,0xFF,0x7E,0x3C,0x18}; 
  byte arrow_right[8]= {0x08,0x0C,0x0E,0xFF,0xFF,0x0E,0x0C,0x08,}; 
  byte arrow_left[8]= {0x10,0x30,0x70,0xFF,0xFF,0x70,0x30,0x10,};
  
  byte d1[8]= {0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55}; 
  byte d2[8]= {0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA};
  
  byte b1[8]= {0x00,0x00,0x00,0x00,0x18,0x3C,0x18,0x3C}; 
  byte b2[8]= {0x00,0x00,0x00,0x18,0x3C,0x18,0x3C,0x00}; 
  byte b3[8]= {0x00,0x00,0x18,0x3C,0x18,0x3C,0x00,0x00}; 
  byte b4[8]= {0x00,0x18,0x3C,0x18,0x3C,0x00,0x00,0x00};
  byte b5[8]= {0x18,0x3C,0x18,0x3C,0x00,0x00,0x00,0x00}; 
  byte b6[8]= {0x3C,0x18,0x3C,0x00,0x00,0x00,0x00,0x18}; 
  byte b7[8]= {0x18,0x3C,0x00,0x00,0x00,0x00,0x18,0x3C}; 
  byte b8[8]= {0x3C,0x00,0x00,0x00,0x00,0x18,0x3C,0x18};
  
  printByte(b1); 
  delay(100); 
  printByte(b2); 
  delay(100); 
  printByte(b3); 
  delay(100); 
  printByte(b4); 
  delay(100); 
  printByte(b5); 
  delay(100); 
  printByte(b6); 
  delay(100); 
  printByte(b7); 
  delay(100); 
  printByte(b8); 
  delay(100);
  
  printByte(d1); 
  delay(100); 
  printByte(d2); 
  delay(100);
  
  printByte(arrow_up); 
  delay(500); 
  printByte(arrow_down); 
  delay(500); printByte(arrow_right); 
  delay(500); printByte(arrow_left); 
  delay(500);
}
void printByte(byte character []) 
{ 
  int i=0;
  for(i=0;i<8;i++)
  { 
    lc.setRow(0,i,character[i]);
  }
}

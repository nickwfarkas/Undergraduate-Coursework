#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte Heart[8] = {0b00000,0b01010,0b11111,0b11111,0b01110,0b00100,0b00000,0b00000 };
byte Bell[8] = { 0b00100, 0b01110, 0b01110, 0b01110, 0b11111, 0b00000, 0b00100, 0b00000 };
byte Alien[8] = { 0b11111, 0b10101, 0b11111, 0b11111, 0b01110, 0b01010, 0b11011, 0b00000 };
byte Check[8] = { 0b00000, 0b00001, 0b00011, 0b10110, 0b11100, 0b01000, 0b00000, 0b00000 };
byte Sound[8]=
{
  B00001,
  B00011,
  B11111,
  B11111,
  B11111,
  B00011,
  B00001,
  B00000
};

byte Music[8]=
{
  B00001,
  B00011,
  B00101,
  B01001,
  B01001,
  B01011,
  B11011,
  B11000
};

byte Skull[8]=
{
  B00000,
  B01110,
  B10101,
  B11011,
  B01110,
  B01110,
  B00000,
  B00000
};

byte Lock[8]=
{
  B01110,
  B10001,
  B10001,
  B11111,
  B11011,
  B11011,
  B11111,
  B00000
};

void setup()
{
  lcd.begin(16, 2);
  lcd.createChar(0, Heart); 
  lcd.createChar(1, Bell); 
  lcd.createChar(2, Alien); 
  lcd.createChar(3, Check); 
  lcd.createChar(4, Sound); 
  lcd.createChar(5, Music); 
  lcd.createChar(6, Skull); 
  lcd.createChar(7, Lock); 
  lcd.clear();
  lcd.print("Custom Character");
}

void loop()
{
  lcd.setCursor(0, 1); 
  lcd.write(byte(0));
  lcd.setCursor(2, 1); 
  lcd.write(byte(1));
  lcd.setCursor(4, 1); 
  lcd.write(byte(2));
  lcd.setCursor(6, 1); 
  lcd.write(byte(3));
  
  lcd.setCursor(8, 1); 
  lcd.write(byte(4));
  lcd.setCursor(10, 1); 
  lcd.write(byte(5));
  lcd.setCursor(12, 1); 
  lcd.write(byte(6));
  lcd.setCursor(14, 1); 
  lcd.write(byte(7));
}
 

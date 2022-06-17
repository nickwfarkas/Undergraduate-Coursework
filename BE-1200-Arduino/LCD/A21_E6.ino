#include <LiquidCrystal.h> 
// include the library code:
LiquidCrystallcd(12, 11, 5, 4, 3, 2);   
// initialize the library with the numbers of the interface pinsintthis
Char= 'a';

void setup() 
{
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);lcd.cursor();
} 
  // turn on the cursor:
void loop() 
{
  if (thisChar== 'm') 
  {
    // reverse directions at 'm':
    lcd.rightToLeft(); 
    // go right for the next letter
  }
  if (thisChar== 's') 
  {
    // reverse again at 's':
    lcd.leftToRight(); 
    // go left for the next letter
  }
  if (thisChar> 'z') 
  {
    // reset at 'z':
    lcd.home(); 
    // go to (0,0):
    thisChar= 'a'; 
    // start again at 0
  }
  lcd.write(thisChar); 
  // print the character
  delay(1000); 
  // wait a second:
  thisChar++; 
  // increment the letter:
}

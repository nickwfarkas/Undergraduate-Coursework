#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buttonPin = 6; // the number of the Start Game pushbutton pin
int RPin = 7; // select the pin for the red LED
int GPin = 8; // select the pin for the green LED
int BPin = 9; // select the pin for the blue LED
int buttonStatus = 0;

void setup() 
{
  pinMode(buttonPin, INPUT);
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  pinMode(BPin, OUTPUT);
  lcd.begin(16, 2);
}
void loop() 
{
  buttonStatus = digitalRead(buttonPin);
  if (buttonStatus == HIGH) 
  {
  lcd.clear();
  delay(500);
  for (int i=0; i <= 5; i++)
  {
  lcd.setCursor(8,0);
  lcd.print(i);
  digitalWrite(BPin, HIGH);
  digitalWrite(RPin, LOW);
  delay(500);
  digitalWrite(RPin, HIGH);
  digitalWrite(GPin, LOW);
  delay(500);
  digitalWrite(GPin, HIGH);
  digitalWrite(BPin, LOW);
  delay(500);}} else {
  digitalWrite(RPin, HIGH);
  digitalWrite(GPin, HIGH);
  digitalWrite(BPin, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Secret Word is:");
  lcd.setCursor(0, 1);
  lcd.print("I like BE1200 class"); // change secret word or phrase here! 
}}

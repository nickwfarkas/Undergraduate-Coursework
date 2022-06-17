String statement;
int pin = 10;

void setup() 
{
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Input a statement you would like to translate");
}

void loop() 
{
  if(Serial.available())
  {
    statement = String(Serial.readString());
  }
  translate();
  delay(10000);
}

//Creates Dot Output
void dot()
{
    digitalWrite(pin, true);
    delay(100);
    digitalWrite(pin, false);
    delay(500);
}

//Creates Multiple Dots
void dot(int repeat)
{
  for(int i = 0; i < repeat; i++)
  {
    dot();
  }
}

//Creates Dash Output
void dash()
{
    digitalWrite(pin, true);
    delay(800);
    digitalWrite(pin, false);
    delay(500);
}

//Creates Multiple Dashes
void dash(int repeat)
{
  for(int i = 0; i < repeat; i++)
  {
    dash();
  }
}

//Iterates over each letter in statement and translates each letter
void translate()
{
  for(int i = 0; i < statement.length(); i++)
  {
    delay(1000);
    lettersToCode(statement[i]);
  }
}

void lettersToCode(char value)
{
  switch (tolower(value))
  {
    case 'a':
      a();
      break;
    case 'b':
      b();
      break;
    case 'c':
      c();
      break;
    case 'd':
      d();
      break;
    case 'e':
      e();
      break;
    case 'f':
      f();
      break;
    case 'g':
      g();
      break;
    case 'h':
      h();
      break;
    case 'i':
      i();
      break;
    case 'j':
      j();
      break;
    case 'k':
      k();
      break;
    case 'l':
      l();
      break;
    case 'm':
      m();
      break;
    case 'n':
      n();
      break;
    case 'o':
      o();
      break;
    case 'p':
      p();
      break;
    case 'q':
      q();
      break;
    case 'r':
      r();
      break;
    case 's':
      s();
      break;
    case 't':
      t();
      break;
    case 'u':
      u();
      break;
    case 'v':
      v();
      break;
    case 'w':
      w();
      break;
    case 'x':
      x();
      break;
    case 'y':
      y();
      break;
    case 'z':
      z();
      break;
    case ' ':
      space();
      break;
    case '0':
      zero();
      break;
    case '1':
      one();
      break;
    case '2':
      two();
      break;
    case '3':
      three();
      break;
    case '4':
      four();
      break;
    case '5':
      five();
      break;
    case '6':
      six();
      break;
    case '7':
      seven();
      break;
    case '8':
      eight();
      break;
    case '9':
      nine();
      break;
  }
}

//Sets dots and dashes for each digit

void space()
{
  delay(1000);
}

void a()
{
  dot();
  dash();
  delay(1000);
}

void b()
{
  dash();
  dot(3);
  delay(1000);
}

void c()
{
  dash();
  dot();
  dash();
  dot();
}

void d()
{
  dash();
  dot(2);
}

void e()
{
  dot();
}

void f()
{
  dot(2);
  dash();
  dot();
}

void g()
{
  dash(2);
  dot();
}

void h()
{
  dot(4);
}

void i()
{
  dot(2);
}

void j()
{
  dot();
  dash(3);
}

void k()
{
  dash();
  dot();
  dash();
}

void l()
{
  dot();
  dash();
  dot(2);
}

void m()
{
  dash(2);
}

void n()
{
  dash();
  dot();
}

void o()
{
  dash(3);
}

void p()
{
  dot();
  dash(2);
  dot();
}

void q()
{
  dash(2);
  dot();
  dash();
}

void r()
{
  dot();
  dash();
  dot();
}

void s()
{
  dot(3);
}

void t()
{
  dash();
}

void u()
{
  dot(2);
  dash();
}

void v()
{
  dot(3);
  dash();
}

void w()
{
  dot();
  dash(2);
}

void x()
{
  dash();
  dot(2);
  dash();
}

void y()
{
  dash();
  dot();
  dash(2);
}

void z()
{
  dash(2);
  dot(2);
}

void one()
{
  dot();
  dash(4);
}

void two()
{
  dot(2);
  dash(3);
}

void three()
{
  dot(3);
  dash(2);
}

void four()
{
  dot(4);
  dash();
}

void five()
{
  dot(5);
}

void six()
{
  dash();
  dot(4);
}

void seven()
{
  dash(2);
  dot(3);
}

void eight()
{
  dash(3);
  dot(2);
}

void nine()
{
  dash(4);
  dot();
}

void zero()
{
  dash(5);
}

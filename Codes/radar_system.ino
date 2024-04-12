#include <LiquidCrystal_I2C.h>


//Omkar Anand Iyer
// C++ code
//
int pir1Pin = 13;
int trig1Pin = 7;
int echo1Pin = 6;
int pir1Val;

int pir2Pin = 12;
int trig2Pin = 5;
int echo2Pin = 4;
int pir2Val;

int pir3Pin = 11;
int trig3Pin = 3;
int echo3Pin = 2;
int pir3Val;

int pir4Pin = 10;
int trig4Pin = 9;
int echo4Pin = 8;
int pir4Val;

int ptt;
float dist ;

LiquidCrystal_I2C lcd(0x20,16,2);

void setup()
{
  pinMode(pir1Pin, INPUT);
  pinMode(trig1Pin, OUTPUT);
  pinMode(echo1Pin, INPUT);
  
  pinMode(pir2Pin, INPUT);
  pinMode(trig2Pin, OUTPUT);
  pinMode(echo2Pin, INPUT);
  
  pinMode(pir3Pin, INPUT);
  pinMode(trig3Pin, OUTPUT);
  pinMode(echo3Pin, INPUT);
  
  pinMode(pir4Pin, INPUT);
  pinMode(trig4Pin, OUTPUT);
  pinMode(echo4Pin, INPUT);
  
  lcd.init();
  //lcd.begin();
  lcd.backlight();
  
  Serial.begin(9600);
}

void loop()
{
  pir1Val = digitalRead(pir1Pin);
  pir2Val = digitalRead(pir2Pin);
  pir3Val = digitalRead(pir3Pin);
  pir4Val = digitalRead(pir4Pin);
  
  if(pir1Val == 1)
  {
    lcd.clear();
    digitalWrite(trig1Pin,LOW);
    delayMicroseconds(10);
    digitalWrite(trig1Pin ,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig1Pin,LOW);
    ptt = pulseIn(echo1Pin, HIGH);
    dist = ptt*(330.0/20000.0);
    Serial.println(dist);
    lcd.setCursor(0,0);
    lcd.print("Object detected");
    lcd.setCursor(0,1);
    lcd.print(dist);
    lcd.print(" mm North");
    delay(100);
  }
  else if(pir2Val == 1)
  {
    lcd.clear();
    digitalWrite(trig2Pin,LOW);
    delayMicroseconds(10);
    digitalWrite(trig2Pin ,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig2Pin,LOW);
    ptt = pulseIn(echo2Pin, HIGH);
    dist = ptt*(330.0/20000.0);
    Serial.println(dist);
    lcd.setCursor(0,0);
    lcd.print("Object detected");
    lcd.setCursor(0,1);
    lcd.print(dist);
    lcd.print(" mm West");
    delay(100);
  }
  else if(pir3Val == 1)
  {
    lcd.clear();
    digitalWrite(trig3Pin,LOW);
    delayMicroseconds(10);
    digitalWrite(trig3Pin ,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig3Pin,LOW);
    ptt = pulseIn(echo3Pin, HIGH);
    dist = ptt*(330.0/20000.0);
    Serial.println(dist);
    lcd.setCursor(0,0);
    lcd.print("Object detected");
    lcd.setCursor(0,1);
    lcd.print(dist);
    lcd.print(" mm South");
    delay(100);
  }
  else if(pir4Val == 1)
  {
    lcd.clear();
    digitalWrite(trig4Pin,LOW);
    delayMicroseconds(10);
    digitalWrite(trig4Pin ,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig4Pin,LOW);
    ptt = pulseIn(echo4Pin, HIGH);
    dist = ptt*(330.0/20000.0);
    lcd.setCursor(0,0);
    lcd.print("Object detected at: ");
    lcd.print(dist);
    lcd.setCursor(0,1);
    lcd.print(dist);
    lcd.print(" mm East");
    delay(100);
  }
  //Serial.println
}
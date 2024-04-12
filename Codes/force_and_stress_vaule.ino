#include <LiquidCrystal_I2C.h>
//Omkar Anand Iyer
// C++ code
//
#include<math.h>
# define PI 3.14159265358979323846
int flexPin = A3;
int forcePin = A2;
int forceVal = 0;
int flexVal = 0;
float angle;
float force;
float strain;
LiquidCrystal_I2C lcd(0x20,16,2);
void setup()
{
  pinMode(flexPin, INPUT);
  pinMode(forcePin, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  
  flexVal = analogRead(flexPin);
  forceVal = analogRead(forcePin);
  angle = -(PI/197)*(flexVal - 59)+PI;
  force = (10.0/914.0)*forceVal;
  strain = (1.0/cos(angle/2.0));
  Serial.println(strain);
  lcd.setCursor(0,0);
  lcd.print("Strain = ");
  lcd.print(strain);
  lcd.setCursor(0,1);
  lcd.print("Force = ");
  lcd.print(force);
  delay(1000);
  lcd.clear();
}
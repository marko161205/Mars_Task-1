// C++ code
//Omkar Anand Iyer
#include<math.h>
int tmpPin = A2;
int gasPin = A0;
int tmpVal;
int gasVal;
int buzzPin = 4;
int tempC;
void setup()
{
  pinMode(tmpPin, INPUT);
  pinMode(gasPin, INPUT);
  pinMode(buzzPin , OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  tmpVal = analogRead(tmpPin);
  gasVal = analogRead(gasPin);
  tempC = round((165.0/338.0)*(tmpVal-20)-40);
  Serial.println(gasVal);
  if(gasVal>400)
  {
    if(tempC>100)
    {
     tone(buzzPin, 200, 500);
     delay(500);
      
    }
    else
    {
     tone(buzzPin, 200, 500);
     delay(1000);
    }
  }
}
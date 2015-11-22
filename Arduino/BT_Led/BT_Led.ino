char command;
String string;
#define led 5

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  LEDOn();
  delay(1000);
  LEDOff();
  delay(1000);
}
 
 void LEDOn()
    { 
          digitalWrite(led, HIGH);
    }

   void LEDOff()
    {
      digitalWrite(led, LOW);
    }

#include <Servo.h>

Servo myservo; // Create servo to control a servo
int val;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:

}
void serialEvent()
{
  val = Serial.parseInt();
  if(val !=0)
  {
    myservo.write(val);
  }
}

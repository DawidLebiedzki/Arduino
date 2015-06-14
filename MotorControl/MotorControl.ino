int PP = 9;
int PT = 8;
int LP = 12;
int LT = 13;
int pwmSpeedLeft = 11;
int pwmSpeedRight = 10;


void setup() {
 Serial.begin(9600);
 pinMode (PP,OUTPUT);
 pinMode (PT,OUTPUT);
 pinMode (LP,OUTPUT);
 pinMode (LT,OUTPUT);

}

void loop() {
  int data = Serial.read(); 

  switch (data){
    case 'w':
      digitalWrite(PP,HIGH);
      digitalWrite(LP,HIGH);
      break;    
    case 's': 
      digitalWrite(PT,HIGH);
      digitalWrite(LT,HIGH);
      break;    
    case 'a': 
      digitalWrite(PP,HIGH);
      digitalWrite(LT,HIGH);
      break;
    case 'd': 
      digitalWrite(PT,HIGH);
      digitalWrite(LP,HIGH);
      break;
  }

}

/* w przod
void wPrzod 
{
  digitalWrite(PP,HIGH);
  digitalWrite(LP,HIGH);
}
// w tyl
void wTyl 
{
  digitalWrite(PT,HIGH);
  digitalWrite(LT,HIGH);
}

// w lewo
void wLewo 
{
  digitalWrite(PP,HIGH);
  digitalWrite(LT,HIGH);
}

// w prawo
void wPrawo 
{
  digitalWrite(PT,HIGH);
  digitalWrite(LP,HIGH);
}
*/

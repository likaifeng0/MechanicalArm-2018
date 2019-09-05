#include<Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;

void setup() 
{
  myservo1.attach(3);
  myservo2.attach(5);
  myservo3.attach(6);

  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
}
void loop() 
{
  int a,b,c,d,e;
  
  a=map(analogRead(A0),0,1023,180,0);
  b=map(analogRead(A1),0,1023,180,0);
  c=map(analogRead(A2),0,1023,180,0);
  d=map(analogRead(A3),0,1023,0,180);
  e=digitalRead(A4);

  myservo1.write(a);
  myservo2.write(b);
  myservo3.write(c);
  if(d<=70)
    {
      digitalWrite(9,0);
      digitalWrite(10,1);
    }
   else if(d>70||d<110)
    {
      digitalWrite(9,0);
      digitalWrite(10,0);
    }
   else if(d>=110)
    {
     digitalWrite(9,1);
     digitalWrite(10,0);
    }
  digitalWrite(8,e);
  
  Serial.print(" a , b , c , d ,e");
  Serial.println();
  Serial.print(a);
  Serial.print(",");
  Serial.print(b);
  Serial.print(",");
  Serial.print(c);
  Serial.print(",");
  Serial.print(d);
  Serial.print(",");
  Serial.println(e);
  delay(100);
  }

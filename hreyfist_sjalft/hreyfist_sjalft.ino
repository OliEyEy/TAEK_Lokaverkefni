#include <Servo.h> //using the servo library

Servo myservo; // create an servo object
int teljari = 20;
int x=0;
void setup() {
  Serial.begin(9600);
  myservo.attach(9); 
}

void loop() {
  if(teljari==180) {
    x=1;
  }
  if(teljari==20) {
    x=0;
  }if(x==1) {
    teljari--;
  }
  if(x==0) {
    teljari++;
  }
   myservo.write(teljari);                  // sets the servo position according to the scaled value
  delay(15);//give the servomotor time to go to position 
}

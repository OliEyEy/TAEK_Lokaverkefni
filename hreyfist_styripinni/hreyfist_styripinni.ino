
#include <Servo.h> //using the servo library

Servo myservo; // create an servo object
int hreyfipinni = A0;
int hreyfipinniStada = 0;
int teljari = 20;


void setup() {
  Serial.begin(9600);
  myservo.attach(9); 
}

void loop() {
  if(teljari>180) {
    teljari=180;
  }
  if(teljari<20) {
    teljari=20;
  }
  hreyfipinniStada = analogRead(hreyfipinni);
  //hreyfipinniStada = map(hreyfipinniStada, 0, 1023, 0, 180);
  if(hreyfipinniStada==1023) {
    teljari++;
    delay(15);
  }
  if(hreyfipinniStada==0) {
    teljari--;
    delay(15);
  }
  myservo.write(teljari);
}

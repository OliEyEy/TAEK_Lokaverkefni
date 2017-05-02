
#include <Servo.h> //using the servo library

Servo myservo; // create an servo object
int hreyfipinni = A0;
int takki = 4;
int takkiStada = HIGH;
int takkiStadaAdur = LOW;
int hreyfipinniStada = 0;
int teljari = 20;
int mode = 0;
int stopp = 0;
int led = 8;
int x = 0;
const int TrigPin = 2;//Trig attach to pin2
const int EchoPin = 3;//Echo attach to pin3
float cm; // fjöldi cm sem mældir eru

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  pinMode(led,OUTPUT);
  pinMode(takki,INPUT_PULLUP);
}

void loop() {
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
  
  cm = pulseIn(EchoPin,HIGH)/58.0;  
  cm = (int(cm * 100.0))/100.0;
  if(cm <= 20) {
      digitalWrite(led,HIGH);
      stopp=1;
    }
    else if(cm > 20) {
      digitalWrite(led,LOW);
      stopp=0;
    }
  if(mode==1) {
    hreyfipinniStada = analogRead(hreyfipinni);
    Serial.print(hreyfipinniStada);
    Serial.print(" ");
    if(hreyfipinniStada>600) {
      teljari++;
    }
    if(hreyfipinniStada<400) {
      teljari--;
    }
    if(teljari<20) {
      teljari=20;
    }
    if(teljari>180) {
      teljari=180;
    }
  }
  else if(mode==0) {
    if(stopp==1) {
      teljari=teljari;
    }
    else {
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
    }
  }
  takkiStada = digitalRead(takki);
  if(takkiStada == HIGH && takkiStadaAdur == LOW) {
    if(mode==1){
      mode = 0;
    }
    else if(mode==0){
      mode=1;
    }
  }
  takkiStadaAdur = takkiStada;
  
  myservo.write(teljari);
  delay(15);
} 

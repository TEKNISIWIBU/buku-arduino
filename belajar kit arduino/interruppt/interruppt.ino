#include<TimerOne.h>
#include "Counttimer.h"
const int merah=12,hijau=11,pb=2;

void setup() {
  // put your setup code here, to run once
  pinMode(pb,INPUT);
  pinMode(merah,OUTPUT);
  pinMode(hijau,OUTPUT);
  Timer1.initialize(10000);
  Timer1.attachInterrupt(blinkMerah);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i = 1; i < 5; i++){
  digitalWrite(merah,HIGH);
  delay(1000);
  digitalWrite(merah,LOW);
  delay(1000);
 }
}
void blinkMerah(){
  if(digitalRead(pb) == HIGH){
  digitalWrite(hijau,HIGH);
 }else{
  digitalWrite(hijau,LOW);
 }
}


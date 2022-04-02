#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int pinTrigger = 9;
const int pinEcho = 8;

long duration;
int distanceCm,distanceInch;

LiquidCrystal_I2C lcd (0x27, 16 ,2);

void setup() {
  // put your setup code here, to run once:
lcd.begin();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("mengukur jarak");
lcd.setCursor(0,1);
lcd.print("Dengan Ultrasonic");
lcd.clear();
pinMode(pinTrigger,OUTPUT);
pinMode(pinEcho,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pinTrigger,LOW);
delayMicroseconds(2);

digitalWrite(pinTrigger,HIGH);
delayMicroseconds(10);
digitalWrite(pinTrigger,LOW);

duration = pulseIn(pinEcho,HIGH);
distanceCm   = duration * 0.034 / 2; // jarak dam cm
distanceInch = duration * 0,0133 / 2; // jarak dalam inch
//menampilkan jarak dalam cm

lcd.setCursor(0,0);
lcd.print("jarak: ");
lcd.print(String(distanceCm));
lcd.print(" cm");

lcd.setCursor(0,1);
lcd.print("jarak: ");
lcd.print(String(distanceInch));
lcd.print(" inch");
delay(500);
}

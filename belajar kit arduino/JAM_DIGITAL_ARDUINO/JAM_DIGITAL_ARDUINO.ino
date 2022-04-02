#include <virtuabotixRTC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27 ,16 ,2);
virtuabotixRTC myRTC(6, 7, 8); //CLK, DAT, RST

void setup() {
Serial.begin(9600); 
lcd.begin();
lcd.setCursor(00,00);
lcd.print("JAM ARDUINO");
lcd.setCursor(3,01);
lcd.print("TEKNISIWIBU");
delay(5000);
lcd.clear();
//myRTC.setDS1302Time(59,45,21,6,22,8,2021); 
}

void loop() {
myRTC.updateTime();
Serial.print("Tanggal / Waktu: ");
Serial.print(myRTC.dayofmonth); //menampilkan tanggal
Serial.print("/");
Serial.print(myRTC.month); //menampilkan bulan
Serial.print("/");
Serial.print(myRTC.year); //menampilkan tahun
Serial.print(" ");
Serial.print(myRTC.hours); //menampilkan jam
Serial.print(":");
Serial.print(myRTC.minutes); //menampilkan menit
Serial.print(":");
Serial.println(myRTC.seconds); //menampilkan detik
lcd.setCursor(00,00); lcd.print(myRTC.hours);
lcd.setCursor(2,00); lcd.print(":");
lcd.setCursor(3,00); lcd.print(myRTC.minutes);
lcd.setCursor(5,00); lcd.print(":");
lcd.setCursor(6,00); lcd.print(myRTC.seconds);
 
lcd.setCursor(00, 1);lcd.print(myRTC.dayofmonth);
lcd.setCursor(2,1); lcd.print("-");
lcd.setCursor(3,1); lcd.print(myRTC.month);
lcd.setCursor(5,1); lcd.print("-");
lcd.setCursor(6,1); lcd.print(myRTC.year);
 
/*
--- 00:59:23
--- 10-10-2017
 
 */
delay( 1000);
}

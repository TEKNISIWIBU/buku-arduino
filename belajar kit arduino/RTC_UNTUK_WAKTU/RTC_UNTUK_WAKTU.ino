#include <Wire.h> 
#include <virtuabotixRTC.h>
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x38); 
 
//Inisialisasi pin (CLK, DAT, RST)
virtuabotixRTC myRTC(6,7,8);
 
void setup(){
//Inisialisasi port serial arduino dengan komputer
Serial.begin(9600);
 
//penulisan data pertama kali dan disarankan saat transfer
//ke-2 ini tidak digunakan dikarenakan akan menghapus data
//sebelumnya
myRTC.setDS1302Time(00,59,23,6,20,10,2017);
//detik, menit, jam, hari dalam seminggu, tanggal, bulan, tahun
// 00:59:23 "Jumat" 10-Oktober-2017
 
lcd.begin(16, 2);
lcd.setBacklight(255);
lcd.home();
//menulis tulisan awal start
lcd.setCursor(00,00);
lcd.print("Trial RTC DS1302");
 
lcd.setCursor(00,01);
lcd.print("nyebarilmu.com");
delay(2000);
lcd.clear();
}
 
void loop(){
//memanggil fungsi untuk update data waktu
myRTC.updateTime();
 
//penulisan data pada serial monitor komputer
Serial.print("Current Date / Time: ");
//fungsi penulisan data untuk tanggal
Serial.print(myRTC.dayofmonth);
 
//penulisan data "/" sebagai separator
Serial.print("/");
 
//fungsi penulisan data untuk bulan
Serial.print(myRTC.month);
 
//penulisan data "/" sebagai separator
Serial.print("/");
 
//fungsi penulisan data untuk tahun
Serial.print(myRTC.year);
 
//penulisan data untuk jarak
Serial.print(" ");
 
//fungsi penulisan data untuk jam
Serial.print(myRTC.hours);
 
Serial.print(":");
 
//fungsi penulisan data untuk menit
Serial.print(myRTC.minutes);
 
Serial.print(":");
 
//fungsi penulisan data untuk detik
Serial.println(myRTC.seconds);
 
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
 
delay(1000);
 
}
 

// ----------------------------------------
// Cara menghitung jarak antara modul GPS
//   dengan Tugu Yogyakarta 
//   beserta arahnya
// ----------------------------------------

#include <SoftwareSerial.h>
#include <TinyGPS.h>

const float LINTANG_TUGU = -7.78942;  // Latitude 
const float BUJUR_TUGU = 110.363425;  // Longitude 

SoftwareSerial gpsSerial(6, 7);
TinyGPS gps;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  Serial.println("Siap menghitung jarak!");
}

void loop() { 
  if (gpsSerial.available()) {
    char karakter = gpsSerial.read();
    if (gps.encode(karakter))
      berikanInfo();
  } 
}

void berikanInfo() {
  float lintang, bujur;
  gps.f_get_position(&lintang, &bujur);
      
  float jarak_km = TinyGPS::distance_between(
        lintang, bujur, LINTANG_TUGU, BUJUR_TUGU) / 1000;
  Serial.print("Jarak : ");
  Serial.print(jarak_km, 7);
  Serial.println("km");    

  float arah = TinyGPS::course_to(
        lintang, bujur, LINTANG_TUGU, BUJUR_TUGU);
  Serial.print("Arah  : ");
  Serial.print(arah, 7);
  Serial.print(" derajat (");
  Serial.print(TinyGPS::cardinal(arah));
  Serial.println(")"); 
}


//-----------------------------------------
// Contoh pengujian modul GPS
//   untuk Skylab SKM53 atau GY-GPS6MV2 
//   dengan memanfaatkan pustaka TinyGPS
//-----------------------------------------

#include <SoftwareSerial.h>
#include <TinyGPS.h>

SoftwareSerial gpsSerial(6, 7);
TinyGPS gps;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
}

void loop() { 
  if (gpsSerial.available()) { 
    char karakter = gpsSerial.read();
   
    if (gps.encode(karakter)) {
      float lintang, bujur;

      gps.f_get_position(&lintang, &bujur);
      
      Serial.print("Posisi lintang: ");
      Serial.println(lintang, 7);

      Serial.print("Posisi Bujur  : ");
      Serial.println(bujur, 7);   

      Serial.println();
    }
  }
}


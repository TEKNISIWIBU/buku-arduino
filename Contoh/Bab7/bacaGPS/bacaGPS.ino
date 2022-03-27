//-----------------------------------------
// Contoh pengujian modul GPS
//   untuk Skylab SKM53 atau GY-GPS6MV2 
//-----------------------------------------

#include <SoftwareSerial.h>

SoftwareSerial gpsSerial(6, 7);

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
}

void loop() { 
  if (gpsSerial.available()) { 
    char karakter = gpsSerial.read();
    Serial.print(karakter); 
  }
}


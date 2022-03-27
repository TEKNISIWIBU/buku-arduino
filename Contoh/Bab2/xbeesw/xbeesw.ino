// ---------------------------------------
// Koneksi XBee menggunakan SoftwareSerial
//   Bagian pengirim
// ---------------------------------------

#include <SoftwareSerial.h>

SoftwareSerial XBee(2, 3); 

void setup() {
  Serial.begin(9600);
  XBee.begin(9600);
}

void loop() {
  static int pencacah = 1;

  Serial.println(pencacah);
  XBee.println(pencacah);
  pencacah++;
  delay(1000);
}

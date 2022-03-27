// --------------------------------------
// Untuk mengirimkan data dari sisi HC-05
// --------------------------------------

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup() {
  BTSerial.begin(9600);  
}

void loop() {
  BTSerial.write('1');
  delay(1000);
  BTSerial.write('0');
  delay(1000);
}

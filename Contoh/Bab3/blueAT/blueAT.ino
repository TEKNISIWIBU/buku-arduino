// --------------------------------
// Untuk menguji perintah AT
//   pada HC-05
// --------------------------------

const int PIN_KEY = 9;

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup() {
  pinMode(PIN_KEY, OUTPUT);    
  digitalWrite(PIN_KEY, HIGH);
  Serial.begin(9600);
  Serial.println("Ketik perintah AT dan klik SEND");
  BTSerial.begin(38400);  // Kecepatan bawaan HC-05
}

void loop() {
  // Baca data dari modul Bluetooth 
  //   dan kirim ke Serial
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Baca data dari Serial dan kirim ke Bluetooth
  if (Serial.available()) 
    BTSerial.write(Serial.read());
}

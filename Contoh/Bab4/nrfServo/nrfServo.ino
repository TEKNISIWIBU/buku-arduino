// ------------------------------------
// Penerimaan data menggunakan NRF24L01
//   untuk mengontrol servo
// ------------------------------------

#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
#include <Servo.h>

const int PIN_CE = 9;
const int PIN_CSN = 10;
const uint64_t PIPE = 0xE8E8F0F0E2LL;
const int PIN_SERVO = 4;

// Objek NRF24L01 
RF24 radio(PIN_CE, PIN_CSN);

char pesan[20]; // Penyangga pesan

Servo motorServo;

void setup() {
  motorServo.attach(PIN_SERVO);
  
  Serial.begin(9600);
  
  radio.begin();
  radio.openReadingPipe(1, PIPE);
  radio.startListening();
}
 
void loop() {
  if (radio.available()) {
    radio.read(pesan, sizeof(pesan));
    int sudut = atoi(pesan);
    Serial.println(sudut);
    motorServo.write(sudut);
  }  
}  


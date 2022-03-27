// ------------------------------------
// Penerimaan data menggunakan NRF24L01
// ------------------------------------

#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

const int PIN_CE = 9;
const int PIN_CSN = 10;
const uint64_t PIPE = 0xE8E8F0F0E2LL;

// Objek NRF24L01 
RF24 radio(PIN_CE, PIN_CSN);

char pesan[20]; // Penyangga pesan

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openReadingPipe(1, PIPE);
  radio.startListening();
  Serial.println("Siap menerima data!");
}
 
void loop() {
  if (radio.available()) {
    bool selesai = false;  
      
    while (!selesai) {
      selesai = radio.read(pesan, sizeof(pesan));
      Serial.println(pesan);
    }
  }  
}  


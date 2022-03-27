// -----------------------------------------------
// Contoh pengontrol LED.
//   Bagian pengirim perintah
// -----------------------------------------------

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

const int PIN_CE = 9;
const int PIN_CSN = 10;
const uint64_t PIPE_1 = 0xE8E8F0F0E2LL;
const uint64_t PIPE_2 = 0xE8E8F0F0E3LL;


// Objek NRF24L01 
RF24 radio(PIN_CE, PIN_CSN);

char pesan[20]; // Penyangga pesan

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(PIPE_1);

  radio.startListening();
}
 
void loop() { 
  // Baca perintah dari port serial
  if (Serial.available()) {
    // Baca perintah
    String perintah = Serial.readString();
    strcpy(pesan, perintah.c_str());
    
    bool ok = radio.write(pesan, strlen(pesan));
    if (ok) {
      Serial.print("Perintah ");
      Serial.print(pesan);
      Serial.println(" berhasil dikirim");
    }
    else {
      Serial.print("Perintah ");
      Serial.print(pesan);
      Serial.println(" gagal dikirim");
    }
      
    radio.powerDown();  
    delay(10);  
    radio.powerUp();
  }

  // Baca kiriman
  if (radio.available()) {
    radio.read(pesan, sizeof(pesan));
    Serial.println(pesan);
  }
}



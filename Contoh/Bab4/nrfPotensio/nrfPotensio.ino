// -----------------------------------------------
// Contoh pengontrol motor servo
//   dengan menggunakan NRF24L01 dan potensiometer
// -----------------------------------------------

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

const int PIN_CE = 9;
const int PIN_CSN = 10;
const uint64_t PIPE = 0xE8E8F0F0E2LL;
const int PIN_POTENSIO = A0;  // Analog 0

// Objek NRF24L01 
RF24 radio(PIN_CE, PIN_CSN);

char pesan[20]; // Penyangga pesan

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(PIPE);
}
 
void loop() { 
  int nilaiPotensio = analogRead(PIN_POTENSIO);
  int sudutServo = map(nilaiPotensio, 
                       0, 1023, 0, 180);

  itoa(sudutServo, pesan, 10);
  Serial.print(pesan);
  
  bool ok = radio.write(pesan, strlen(pesan));
  if (ok)
    Serial.println("OK");
  else
    Serial.println("Gagal");    
    
  radio.powerDown();  
  delay(50);  
  radio.powerUp();
}



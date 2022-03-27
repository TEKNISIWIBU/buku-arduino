// ------------------------------------
// Pengiriman data menggunakan NRF24L01
// ------------------------------------

//#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

const int PIN_CE = 9;
const int PIN_CSN = 10;
const uint64_t PIPE = 0xE8E8F0F0E2LL;

// Objek NRF24L01
RF24 radio(PIN_CE, PIN_CSN);

char pesan[20]; // penyangga pesan

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(PIPE);
}
 
void loop() {
  static int x = 1;  
  
  sprintf(pesan, "Pesan #%d", x);
  Serial.print(pesan);
    
  bool ok = radio.write(pesan, strlen(pesan)); 
  if (ok)
    Serial.println(" OK...");
  else
    Serial.println(" Gagal...");  

  x++;
  if (x > 500)
    x = 1;
        
  radio.powerDown();  
  delay(1000);
  radio.powerUp();    
}

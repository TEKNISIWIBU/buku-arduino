// -----------------------------
// Modul pengirim RF 315MHz 
//   untuk mengirimkan hasil 
//   deteksi gerak
// -----------------------------

#include <VirtualWire.h>

const int PIN_PIR = 8;

char teks[30] = "";
  
void setup() {
  pinMode(PIN_PIR, INPUT);
  
  // Inisialisasi transmitter
  vw_set_tx_pin(9);
  vw_setup(1000); // Penentuan laju bit

  // Inisialisasi posr serial
  Serial.begin(9600);
  Serial.println("Silakan membuat gerakan di dekat PIR");
}

void loop() {
  int pin_gerak = digitalRead(PIN_PIR);
  if (pin_gerak == HIGH) {
    Serial.println("Sesuatu bergerak!");
    sprintf(teks, "GERAK");  
    vw_send((uint8_t *) teks, strlen(teks));
    vw_wait_tx();

    delay(3000);
  }
}


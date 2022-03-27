// -----------------------------
// Contoh penggunaan tombol
//   untuk pengiriman sinyal via 
//   modul pemancar inframerah
// -----------------------------

#include "IRremote.h"

const int PIN_TOMBOL = 4;

IRsend pengirim;

void setup() {
  pinMode(PIN_TOMBOL, INPUT);
}

void loop() {
  int pin_tombol = digitalRead(PIN_TOMBOL);
  if (pin_tombol == LOW) {
    pengirim.sendRC5(0x11223344, 32);
    delay(50);
    
    pengirim.sendRC5(0xFFFFFFFF, 32);
    delay(50);
  }
}


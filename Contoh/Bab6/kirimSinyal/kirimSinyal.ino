// ----------------------------
// Contoh untuk menguji
//   pengiriman sinyal via 
//   modul pemancar inframerah
// ----------------------------

#include "IRremote.h"

IRsend pengirim;

void setup() {

}

void loop() {
  pengirim.sendSony(0xAABBCCDD, 32);
  delay(1000);
  
  pengirim.sendRC5(0xFF, 8);
  delay(1000);
   
  pengirim.sendRC5(0x21, 8);
  delay(1000);
  
  pengirim.sendRC5(0xA2, 8);
  delay(1000);
}


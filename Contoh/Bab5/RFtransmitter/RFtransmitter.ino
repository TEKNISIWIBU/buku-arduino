// -----------------------------
// Pengiriman data menggunakan 
//   modul pengirim RF 315MHz 
// -----------------------------

#include <VirtualWire.h>

char teks[30] = "";
  
void setup() {
  // Inisialisasi transmitter
  vw_set_tx_pin(9);
  vw_setup(1000); // Penentuan laju bit

  // Inisialisasi posr serial
  Serial.begin(9600);
}

void loop() {
  static int bil = 0;
  
  Serial.print("Pengiriman bilangan ");
  Serial.println(bil);

  sprintf(teks, "%d\n", bil);  
  vw_send((uint8_t *) teks, strlen(teks));
  vw_wait_tx();

  bil++;
  
  delay(1000);
}


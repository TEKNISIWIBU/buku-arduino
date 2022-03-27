// ---------------------------------------------
// Penerimaan data menggunakan 
//    modul penerima RF 315MHz 
// ---------------------------------------------

#include <VirtualWire.h>

byte penyangga[VW_MAX_MESSAGE_LEN]; 
byte panjangPesan = VW_MAX_MESSAGE_LEN;   

void setup() {
  vw_set_rx_pin(8);
  vw_setup(1000);  // bps
 
  vw_rx_start();   // Memulai penerimaan data
 
  Serial.begin(9600);
  Serial.println("Siap menerima data!");
}

void loop() {
  if (vw_get_message(penyangga, &panjangPesan)) {
    Serial.print("Data diterima: ");
    for (int j = 0; j < panjangPesan; j++)
      Serial.write(penyangga[j]);

    // Reset ke VW_MAX_MESSAGE_LEN
    panjangPesan = VW_MAX_MESSAGE_LEN;   
 
  }    
}


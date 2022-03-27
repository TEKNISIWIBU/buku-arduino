// ---------------------------------------------
// Bagian penerima RF 315MHz 
//   yang akan menyalakan LED jika terdapat
//   kiriman berupa "GERAK"
// ---------------------------------------------

#include <VirtualWire.h>

const int PIN_LED = 2;

byte penyangga[VW_MAX_MESSAGE_LEN]; 
byte panjangPesan = VW_MAX_MESSAGE_LEN;  
char teks[VW_MAX_MESSAGE_LEN + 1]; 

void setup() {
  pinMode(PIN_LED, OUTPUT);
  
  vw_set_rx_pin(8);
  vw_setup(1000);  // bps
 
  vw_rx_start();   // Memulai penerimaan data
 
  Serial.begin(9600);
  Serial.println("Siap memantau gerak!");
}

void loop() {
  if (vw_get_message(penyangga, &panjangPesan)) {
    memcpy(teks, penyangga, panjangPesan);
    teks[panjangPesan] = 0; // Terminator
    Serial.println(teks);

    if (strcmp(teks, "GERAK") == 0) {
      // Hidupkan LED 2 detik
      digitalWrite(PIN_LED, HIGH);
      delay(2000);
      digitalWrite(PIN_LED, LOW);
    }

    // Reset ke VW_MAX_MESSAGE_LEN
    panjangPesan = VW_MAX_MESSAGE_LEN;   
  }    
}


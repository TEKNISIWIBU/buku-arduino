// -------------------------------------------------
// Contoh komunikasi dua arah
//    menggunakan gelombang radio 315MHz.
//    Bagian yang  membaca perintah dari transmitter
//    guna mematikan/menghidupkan LED dan kipas
// -------------------------------------------------

#include <VirtualWire.h>

const int PIN_LED = 2;

byte penyangga[VW_MAX_MESSAGE_LEN]; 
byte panjangPesan = VW_MAX_MESSAGE_LEN; 

void setup() {
  // Atur pin
  pinMode(PIN_LED, OUTPUT);
  
  // Atur pengirim dan penerima
  vw_set_tx_pin(9);
  vw_set_rx_pin(8);
  vw_setup(1000);  // bit per detik
 
  vw_rx_start();   // Memulai penerimaan data
 
  Serial.begin(9600);
  Serial.println("Siap menerima perintah!");
}

void loop() {
  if (vw_get_message(penyangga, &panjangPesan)) {
    // Peroleh string perintah
    char perintah[VW_MAX_MESSAGE_LEN + 1];
    memcpy(perintah, penyangga, panjangPesan);
    perintah[panjangPesan] = 0; // Terminator
    
    // Proses perintah
    if (strcmp(perintah, "LED ON") == 0) {
      Serial.println("Siap untuk menghidupkan LED!");
      digitalWrite(PIN_LED, HIGH);  

      // Beritahu ke pengirim -> perintah yang didapat
      kirimTanggapan(perintah);
    }   
    else if (strcmp(perintah, "LED OFF") == 0) {
      Serial.println("Siap untuk mematikan LED!");
      digitalWrite(PIN_LED, LOW);  

      // Beritahu ke pengirim -> perintah yang didapat
      kirimTanggapan(perintah);
    }
    else {
      Serial.print("Perintah tidak dikenal: ");
      Serial.println(perintah);
    }
  }   

  // Reset ke VW_MAX_MESSAGE_LEN
  panjangPesan = VW_MAX_MESSAGE_LEN;
}

void kirimTanggapan(char *teks) {
  vw_send((uint8_t *) teks, strlen(teks));  
  vw_wait_tx();
  
  Serial.println("Kirim tanggapan balik...");
}


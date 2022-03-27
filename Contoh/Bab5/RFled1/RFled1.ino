// -----------------------------------------------
// Contoh komunikasi dua arah
//    menggunakan gelombang radio 315MHz.
//    Bagian pemberi perintah untuk 
//    mmenyalakan/mematikan LED
// -----------------------------------------------

#include <VirtualWire.h>

const int PIN_TOMBOL = 2;

byte penyangga[VW_MAX_MESSAGE_LEN]; 
byte panjangPesan = VW_MAX_MESSAGE_LEN; 

void setup() {
  pinMode(PIN_TOMBOL, INPUT);
  
  // Pengaturan pin untuk mengirim dan menerima data
  vw_set_tx_pin(9);
  vw_set_rx_pin(8);
  
  vw_setup(1000); // Kecepatan 1000 bit per detik
  vw_rx_start();  // Memulai penerimaan data
 
  // Inisialisasi port serial
  Serial.begin(9600);
}

void loop() {
  int pin_tombol = digitalRead(PIN_TOMBOL);
  if (pin_tombol == HIGH) {
    Serial.println("HIGH");
    delay(30);
  }
}

// ---------------------------------------
// Fungsi untuk mengirim perintah
//   dan memeriksa tanggapan dari penerima
//   Perintah akan diulang sekiranya
//   perintah dan tanggapan tidak sama
// ---------------------------------------
void lakukanPerintah(char *perintah)
{
  int j;
  bool ok = false;
  char pesan[VW_MAX_MESSAGE_LEN + 1];
  
  do
  {
     // Kirim pesan
     Serial.print("Perintah: ");
     Serial.println(perintah);
     vw_send((uint8_t *) perintah, strlen(perintah));
     vw_wait_tx();
  
     delay(1000);

     // Ambil perintah
     if (vw_get_message(penyangga, &panjangPesan)) 
     {
       for (j = 0; j < panjangPesan; j++)
         pesan[j] = penyangga[j];
         
       pesan[j] = 0; // Pengakhir string
       Serial.print("Tanggapan: ");
       Serial.println(pesan);
       
       // Reset ke VW_MAX_MESSAGE_LEN
       //    untuk mengatasi bug di pustaka VirtualWire
       panjangPesan = VW_MAX_MESSAGE_LEN;
     }
     
     // Cek perintah
     if (strcmp(perintah, pesan) == 0)
       ok = true; 
     else
       delay(500);  
  }  while (not ok); 
  
  delay(3000);
}


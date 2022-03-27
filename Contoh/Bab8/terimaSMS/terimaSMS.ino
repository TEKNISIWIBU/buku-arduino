//--------------------------------------
// Contoh untuk menguji penerimaan SMS
//--------------------------------------

#include <GSM.h>

#define NOMOR_PIN ""
char nomorPengirim[21];

// Objek untuk mengakses GSM dan SMS
GSM aksesGSM;
GSM_SMS sms;

void setup() {
  Serial.begin(9600);
  
  boolean terhubung = false;

  // Inisialisasi terhadap GSM dan kartu SIM
  while (! terhubung) {
    if (aksesGSM.begin(NOMOR_PIN) == GSM_READY) {
      terhubung = true;
    } 
    else {
      Serial.println("Belum terhubung...");
      delay(1000);
    }
  }

  Serial.println("Siap untuk menerima SMS!");
}

void loop() {
  char karakter;

  // Cek keberadaan SMS
  if (sms.available()) {
    Serial.println("Pesan diterima...");

    // Peroleh nomor telepon pengirim
    sms.remoteNumber(nomorPengirim, 21);
    Serial.print("Dari: ");
    Serial.println(nomorPengirim);

    // Penghapusan terhadap pesan yang berawalan #
    if (sms.peek() == '#') 
      sms.flush(); // Hapus pesan
 
    // Baca pesan
    while (karakter = sms.read()) 
      Serial.print(karakter);
 
    // Hapus pesan
    sms.flush();
  }

  delay(30);
}



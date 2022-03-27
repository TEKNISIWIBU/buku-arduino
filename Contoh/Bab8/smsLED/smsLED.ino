//--------------------------------------
// Pengendalian LED melalui SMS
//--------------------------------------

#include <GSM.h>

#define NOMOR_PIN ""

const int PIN_LED = 8;

char nomorPengirim[21];
String pesan;

// Objek untuk mengakses GSM dan SMS
GSM aksesGSM;
GSM_SMS sms;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_LED, OUTPUT);
  
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
    Serial.println("\nPesan diterima...");

    // Peroleh nomor telepon pengirim
    sms.remoteNumber(nomorPengirim, 21);
    Serial.print(nomorPengirim);
    Serial.println(": ");
    
    // Baca pesan
    pesan = "";
    while (karakter = sms.read()) {
      Serial.print(karakter);
      pesan = pesan + karakter;
    }
    
    // Hapus pesan
    sms.flush();

    // Periksa perintah untuk mengontrol LED
    if (pesan.equalsIgnoreCase("LED ON"))
      digitalWrite(PIN_LED, HIGH);
    else
      if (pesan.equalsIgnoreCase("LED OFF"))       
        digitalWrite(PIN_LED, LOW);
  }
}



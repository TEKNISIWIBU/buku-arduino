//--------------------------------------
// Contoh untuk menguji pengiriman SMS
//   dengan pemodifikasian berupa
//   pengaktifan PWR_KEY secara otomatis
//--------------------------------------

#include <GSM.h>

#define NOMOR_PIN ""

char NOMOR_TELEPON[] = "085743899660";
char pesan[40];

// Objek untuk mengakses GSM dan SMS
GSM aksesGSM;
GSM_SMS sms;

void setup() {
  Serial.begin(9600);

  turnOnGSM();
  
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

  Serial.println("Siap untuk mengirim SMS!");
}

void loop() {
  if (Serial.available()) {
    String teks = Serial.readString();
    if (teks.equalsIgnoreCase("kirim")) {
      sprintf(pesan, "Mencoba mengirim bilangan acak: %d",
              random(1000));
               
      Serial.println("Kirim SMS...");

      sms.beginSMS(NOMOR_TELEPON);
      sms.print(pesan);
      sms.endSMS();
 
      Serial.println("Selesai mengirim...\n");
    }
  }
} 

void turnOnGSM() {
  const int PIN_GSM_ON = 8;

  Serial.println("Mengaktifkan PWR_KEY...");
  
  pinMode(PIN_GSM_ON, OUTPUT);
 
  // Aktifkan modul GSM
  digitalWrite(PIN_GSM_ON, HIGH);
  delay(1500);
  digitalWrite(PIN_GSM_ON, LOW);
  delay(2000);
  digitalWrite(PIN_GSM_ON, HIGH);
  delay(3000);
}


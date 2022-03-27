//--------------------------------------
// Contoh deteksi suhu
//   dan pengiriman SMS
//--------------------------------------

#include <GSM.h>

#define NOMOR_PIN ""

const int PIN_SUHU = A0;

char NOMOR_TELEPON[] = "085743899660";
char pesan[40];

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

  Serial.println("Siap untuk mengirim SMS!");
}

void loop() {
  int suhu = 0.49 * analogRead(PIN_SUHU);
  Serial.println(suhu);
  if (suhu >= 60) {
    sprintf(pesan, 
            "Suhu ruangan abnormal: %d Celsius",
            suhu);
               
    Serial.println("Kirim SMS...");

    sms.beginSMS(NOMOR_TELEPON);
    sms.print(pesan);
    sms.endSMS();
 
    Serial.println("Selesai mengirim...\n");
    delay(60 * 60 *1000); // per jam
  }
} 
 

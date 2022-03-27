//-------------------------------------------
// Contoh untuk pengiriman data posisi lokasi
//   melalui SMS
//-------------------------------------------

#include <AltSoftSerial.h>
#include <TinyGPS.h>
#include <GSM.h>

#define NOMOR_PIN ""
char NOMOR_TELEPON[] = "085743899660";
char pesan[40];
float latitude = 0, longitude = 0;

// Objek untuk mengakses GSM dan SMS
GSM aksesGSM;
GSM_SMS sms;

AltSoftSerial gpsSerial;
TinyGPS gps;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  
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
  char strLintang[15], strBujur[15];
  
  bacaGPS();
  
  if (Serial.available()) {
    String teks = Serial.readString();
    if (teks.equalsIgnoreCase("kirim")) {
      dtostrf(latitude, 14, 8, strLintang);
      dtostrf(longitude, 14, 8, strBujur);
      sprintf(pesan, "Posisi lintang = %s, bujur = %s",
              strLintang, strBujur);
              
      Serial.println(pesan);       
      Serial.println("Kirim SMS...");

      sms.beginSMS(NOMOR_TELEPON);
      sms.print(pesan);
      sms.endSMS();
 
      Serial.println("Selesai mengirim...\n");
    }
  }
} 

void bacaGPS() {
  if (gpsSerial.available()) { 
    char karakter = gpsSerial.read();
 
    if (gps.encode(karakter)) {
      gps.f_get_position(&latitude, &longitude);
    }
  }
}



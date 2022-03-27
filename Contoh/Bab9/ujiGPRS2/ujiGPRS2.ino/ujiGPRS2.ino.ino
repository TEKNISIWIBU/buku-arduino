//-----------------------------------
// Pengujian GPRS untuk
//   mendapatkan informasi
//   dari suatu halaman web.
//   Variabel URL disertakan 
//-----------------------------------

#include <SoftwareSerial.h>

#define SITUS "ardugama.site88.net/ucapan.php"
#define VAR_URL "?teks=Tes%20tes%20123!&tebal=true"

SoftwareSerial serialGSM(2, 3);

// Penampung tanggapan perintah AT
char penyangga[128]; 
byte indeksPenyangga = 0;

void perintah(String st, unsigned long waktuTunggu,
              bool tampil = false) {
  serialGSM.println(st);

  bacaTanggapan(waktuTunggu, tampil);
}

void bacaTanggapan(long waktuTunggu, bool tampil) {
  char karakter;
  penyangga[0] = 0;
  indeksPenyangga = 0;
  
  unsigned long waktuAwal = millis();
  
  while (millis() - waktuAwal <= waktuTunggu) {
    if (serialGSM.available()) {
      karakter = serialGSM.read();
      penyangga[indeksPenyangga++] = karakter;
      penyangga[indeksPenyangga] = 0;
    }
  }

  if (tampil) 
    Serial.println(penyangga);
}

void setup()  {
  Serial.begin(9600);
  serialGSM.begin(9600);  

  Serial.println("Tunggu...");
   
  perintah("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"", 1000);
  perintah("AT+SAPBR=3,1,\"APN\",\"indosatgprs\"", 1000);
  perintah("AT+SAPBR=1,1", 1000);
  perintah("AT+HTTPINIT", 1000);
  perintah("AT+HTTPPARA=\"CID\",1", 1000);    

  char teks[100];
  sprintf(teks, "AT+HTTPPARA=\"URL\",\"%s%s\"", SITUS, VAR_URL); 
  perintah(teks, 1000);
  perintah("AT+HTTPACTION=0", 6000);
  perintah("AT+HTTPREAD", 6000, true);
}
 
void loop() {
   
}



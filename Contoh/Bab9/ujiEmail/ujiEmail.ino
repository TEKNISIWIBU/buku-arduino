//-----------------------------------
// Pengiriman email menggunakan GPRS
//-----------------------------------

#include <SoftwareSerial.h>

const char MAIL_SERVER[] = "mail.smtp2go.com";
const unsigned int SMTP_PORT = 2525;
const char NAMA_LOGIN[] = "ardugama@gmail.com"; 
const char PASSWORD_LOGIN[] = "g4b4ngo";
const char PENGIRIM[] = "ardugama@gmail.com";

// Penampung tanggapan perintah AT
char penyangga[128]; 
byte indeksPenyangga = 0;

SoftwareSerial serialGSM(2, 3);

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

void kirimEmail(char *penerima, char *subjek, 
                char *pesan) {
  char teks[128];

  Serial.println("Mengirim email...");
  perintah("ATE0", 10);
  
  perintah("AT+SAPBR=3,1,\"Contype\",\"GPRS\"", 1000);
  perintah("AT+SAPBR=3,1,\"APN\",\"indosatgprs\"", 
           1000);
  perintah("AT+SAPBR=1,1", 1000);

  perintah("AT+EMAILCID=1", 1000);
  perintah("AT+EMAILTO=120", 1000);

  sprintf(teks, "AT+SMTPSRV=\"%s\",%d", 
          MAIL_SERVER, SMTP_PORT);
  perintah(teks, 1000);

  sprintf(teks, "AT+SMTPAUTH=1,\"%s\",\"%s\"", 
          NAMA_LOGIN, PASSWORD_LOGIN);
  perintah(teks, 1000);

  sprintf(teks, "AT+SMTPFROM=\"%s\",\"Arduino\"", 
          PENGIRIM);
  perintah(teks, 1000);
  
  sprintf(teks, "AT+SMTPRCPT=0,0,\"%s\",\"\"", 
          penerima);
  perintah(teks, 1000);

  sprintf(teks, "AT+SMTPSUB=\"%s\"", subjek);
  perintah(teks, 1000);

  perintah("AT+SMTPBODY", 3000);

  sprintf(teks, "%s%c", pesan, 0x1A);
  perintah(teks, 1000);
  
  perintah("AT+SMTPSEND", 2000, true);
  if (strstr(penyangga, "+SMTPSEND") == NULL)
   for (int j = 1; j < 60; j++) {
     Serial.println("Tunggu...");
     bacaTanggapan(1000, true);
     if (strstr(penyangga, "+SMTPSEND") != NULL)
       break;
   }
 
  Serial.println("Selesai mengirim email...");
}

void setup()  {
  Serial.begin(9600);
  serialGSM.begin(9600);  

  Serial.println("Tulis pesan di Serial Monitor");
  Serial.println("Klik Send untuk mengirim email");
}
 
void loop() {
  if (Serial.available()) {
    String msg = Serial.readString();
    kirimEmail("ardualpha@gmail.com", 
               "Email Arduino", (char *) msg.c_str());
  }
}



//--------------------------------
// Contoh pengiriman SMS
//   menggunakan perintah AT
//--------------------------------

#include <SoftwareSerial.h>

SoftwareSerial serialGSM(2, 3);

String pesan;

void setup()  {
  Serial.begin(9600);
  serialGSM.begin(9600);  
    
  Serial.println("Silakan ketik pesan di Serial Monitor");
  Serial.println("untuk mengirim SMS");
}
 
void loop() {
  if (Serial.available()) {
    pesan = Serial.readString();

    kirimSMS();
  } 
}

void kirimSMS() {
  Serial.println("Sedang mengirim pesan SMS...");
  serialGSM.println("AT+CMGF=1");
  delay(1000);  

  // Gantilah nomor telepon dengan nomor Anda
  serialGSM.println("AT+CMGS=\"+6285713438644\"\r"); 
  serialGSM.println(pesan);
  delay(1000);

  // Akhiri dengan Ctrl+Z
  serialGSM.println((char)26);
  delay(1000);
  
  Serial.println ("SMS telah dikirim...");
}

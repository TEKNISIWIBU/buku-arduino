// ----------------------------------
// Pembacaan nomor seri pada tag RFID
// ----------------------------------

#include <SPI.h>
#include <MFRC522.h>

const int PIN_RST = 9;  
const int PIN_SS  = 10; // Pin SDA atau NSS 

String idTag = ""; // UID of a card

// Pembuatan objek MFRC522 
MFRC522 mfrc522(PIN_SS, PIN_RST); 

void setup() {
  Serial.begin(9600);
  SPI.begin();  
  mfrc522.PCD_Init(); 

  // Pemeriksaan versi software MFRC555
  byte versi = mfrc522.PCD_ReadRegister(
                 mfrc522.VersionReg);
  if (versi == 0x00 || versi == 0xFF) {
    Serial.println("Modul RFID tidak dikenal");
    while (true); // Abaikan perintah-2 berikutnya   
  }
    
  Serial.println("Siap untuk membaca tag");
}

void loop() {
  // Cek untuk kartu yang baru disisipkan 
  if (!mfrc522.PICC_IsNewCardPresent())
    return;

  // Jika nomor tag tidak diperoleh
  if (!mfrc522.PICC_ReadCardSerial())
    return;

  // Peroleh identitas tag
  idTag = "";
  for (byte j = 0; j < mfrc522.uid.size; j++) {
    char teksHeksa[3];
    sprintf(teksHeksa, "%02X", mfrc522.uid.uidByte[j]);
    idTag = idTag + teksHeksa;
  }
  
  Serial.print("UID: ");
  Serial.println(idTag);

  // Ubah status kartu ACTIVE ke status HALT
  mfrc522.PICC_HaltA();
}


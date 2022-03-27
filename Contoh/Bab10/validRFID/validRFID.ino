// -------------------------------------
// Contoh untuk menguji valid tidaknya
//   suatu tag
// -------------------------------------

#include <SPI.h>
#include <MFRC522.h>

const int PIN_RST = 9;  
const int PIN_SS  = 10; // Pin SDA atau NSS

String idTag = ""; // UID tag
String validUID[4] = {
  "449F14A5", // Ubah dengan UID tag Anda
  "79A3313B", // Ubah dengan UID tag Anda
  "04806CDB", // Ubah dengan UID tag Anda
  "3CC29302"  // Ubah dengan UID tag Anda
};

// Pembuatan objek MFRC522
MFRC522 mfrc522(PIN_SS, PIN_RST); 

void setup() {
  Serial.begin(9600);
  SPI.begin();  
  mfrc522.PCD_Init(); // Inisialisasi MFRC522

  // Pemeriksaan versi software MFRC555
  byte versi = mfrc522.PCD_ReadRegister(
                  mfrc522.VersionReg);
  if (versi == 0x00 or versi == 0xFF) {
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
    sprintf(teksHeksa, "%02X", 
            mfrc522.uid.uidByte[j]);
    idTag = idTag + teksHeksa;
  }
  
  // Pengujian tag
  boolean ditemukan = false;
  for (byte i = 0; i < 4; i++) {
    if (validUID[i] == idTag) {
      ditemukan = true;
      break;
    }  
  }

  Serial.print(idTag);
  Serial.print(": ");
  
  if (ditemukan)
    Serial.println("Diterima");
  else
    Serial.println("Ditolak");  
  
  // Ubah status kartu ACTIVE ke status HALT
  mfrc522.PICC_HaltA();
}


// -----------------------------------------
// Contoh untuk menuliskan data nama di tag.
//   Hanya untuk Mifare Classic 1K
// -----------------------------------------

#include <SPI.h>
#include <MFRC522.h>

const int PIN_RST = 9;  
const int PIN_SS  = 10; // Pin SDA atau NSS 

String idTag = ""; // UID Tag

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
    Serial.println(versi);
    Serial.println("Modul RFID tidak dikenal");
    while (true); // Abaikan perintah-2 berikutnya   
  }
    
  Serial.println("Siap untuk merekam data ke tag");
}

void loop() {
  mfrc522.PCD_Init(); 
  
  // Periksa tag 
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

  Serial.print("Masukkan nama untuk direkam: ");
  
  String nama;
  bool adaData = false;
  do {
     if (Serial.available()) {
       nama = Serial.readString();
       nama.trim();    
       adaData = true;
     }
  } while (!adaData);

  Serial.println(nama);
  
  // Salin string nama ke strNama
  char strNama[32];
  if (nama.length() < 32) {
    int j;
  
    for (j = 0; j < nama.length(); j++)
      strNama[j] = nama[j];

    for (j = nama.length(); j < 32; j++)
      strNama[j] = 32; // karakter spasi  
  }
  else {
    for (int j = 0; j < 32; j++)
      strNama[j] = nama[j];
  }
  
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

  byte buffer[16];
  
  // Tulis nama pada blok bernomor 1
  byte blok = 1;
  MFRC522::StatusCode status;
  status = mfrc522.PCD_Authenticate(
             MFRC522::PICC_CMD_MF_AUTH_KEY_A, 
             blok, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.println("Otentikasi gagal... ");
    return;
  }

  status = mfrc522.MIFARE_Write(blok, (byte *) strNama, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.println("Gagal merekam data... ");
    return;
  }
  
  // Tulis nama pada blok bernomor 2
  blok = 2;
  status = mfrc522.PCD_Authenticate(
             MFRC522::PICC_CMD_MF_AUTH_KEY_A, 
             blok, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.println("Otentikasi gagal... ");
    return;
  }

  status = mfrc522.MIFARE_Write(blok, 
             (byte *) strNama + 16, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.println("Gagal merekam data... ");
    return;
  }

  Serial.println("Data nama sudah direkam.\n");
}


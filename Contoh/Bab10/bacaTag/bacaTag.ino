// ----------------------------------
// Contoh untuk membaca data di tag.
//   Hanya untuk Mifare Classic 1K
// ----------------------------------

#include <SPI.h>
#include <MFRC522.h>

const int PIN_RST = 9;  
const int PIN_SS  = 10; // Pin SDA atau NSS 

String idTag = ""; // UID Tag
char teksHeksa[5];     // untuk konversi string

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
    
  Serial.println("Siap untuk membaca tag");
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

  Serial.print("Silakan untuk memasukkan nomor blok: ");
  
  int blok;
  bool adaData = false;
  do {
     if (Serial.available()) {
       blok = Serial.parseInt();    
       adaData = true;
     }
  } while (!adaData);

  Serial.println(blok);
  Serial.println();

  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
        
  MFRC522::StatusCode status;
  status = mfrc522.PCD_Authenticate(
             MFRC522::PICC_CMD_MF_AUTH_KEY_A, 
             blok, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.println("Otentikasi gagal... ");
    return;
  }
  else 
    Serial.println("Otentikasi berhasil...");

  byte buffer[18];
  byte jumByte = sizeof(buffer);

  status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(
                                   blok, buffer, &jumByte);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Gagal membaca data");
    return;
  }

  Serial.print("Isi blok ");
  Serial.print(blok);
  Serial.println(" dalam heksadesimal:");
  
  for (int j = 0; j < 16; j++) {
    sprintf(teksHeksa, "%02X ", buffer[j]);
    Serial.print(teksHeksa);
  }

  Serial.println("\n");

  Serial.print("Isi blok ");
  Serial.print(blok);
  Serial.println(" dalam karakter:");
  
  for (int j = 0; j < 16; j++) {
    if (isprint(buffer[j]))
      Serial.print((char) buffer[j]);
    else
      Serial.print(" ");  
  }

  Serial.println("\n");
}


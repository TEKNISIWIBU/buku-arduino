// -------------------------------------
// Contoh aplikasi tag untuk mengakses
//   suatu tempat
// -------------------------------------

#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int PIN_RST = 9;  
const int PIN_SS  = 10; // Pin SDA atau NSS
const int PIN_LED_HIJAU = 3;
const int PIN_LED_MERAH = 2;

String idTag = ""; // UID tag
String validUID[4] = {
  "449F14A5", // Ubah dengan UID tag Anda
  "79A3313B", // Ubah dengan UID tag Anda
  "04806CDB", // Ubah dengan UID tag Anda
  "3CC29302"  // Ubah dengan UID tag Anda
};

// Pembuatan objek MFRC522
MFRC522 mfrc522(PIN_SS, PIN_RST); 

// Pembuatan objek untuk LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  pinMode(PIN_LED_MERAH, OUTPUT);
  pinMode(PIN_LED_HIJAU, OUTPUT);
  digitalWrite(PIN_LED_MERAH, HIGH);
  digitalWrite(PIN_LED_HIJAU, LOW);
  
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
  lcd.setCursor(0, 0);
  lcd.print("Sisipkan tag... ");

  mfrc522.PCD_Init();
  
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
  
  if (ditemukan) {
    Serial.println("Diterima");

    digitalWrite(PIN_LED_MERAH, LOW);
    digitalWrite(PIN_LED_HIJAU, HIGH);

    String nama1 = bacaBlok(1);
    String nama2 = bacaBlok(2);
    lcd.setCursor(0, 0);
    lcd.print(nama1);
    lcd.setCursor(0, 1);
    lcd.print(nama2);
    delay(2000);
    
    lcd.setCursor(0, 0);
    lcd.print("Akses diterima  ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    
    delay(2000);
  }
  else {
    Serial.println("Ditolak");  
  
    lcd.setCursor(0, 0);
    lcd.print("Akses Ditolak   ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    delay(4000);
  }

  // Matikan LED hijau dan nyalakan LED merah
  digitalWrite(PIN_LED_HIJAU, LOW);
  digitalWrite(PIN_LED_MERAH, HIGH);
}

String bacaBlok(byte blok) {
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
        
  MFRC522::StatusCode status;
  status = mfrc522.PCD_Authenticate(
             MFRC522::PICC_CMD_MF_AUTH_KEY_A, 
             blok, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.println("Otentikasi gagal... ");
    return "";
  }
  else 
    Serial.println("Otentikasi berhasil...");

  byte buffer[18];
  byte jumByte = sizeof(buffer);

  status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(
                                   blok, buffer, &jumByte);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Gagal membaca data");
    return "";
  }

  String hasil = "";
  for (int j = 0; j < 16; j++)
    hasil = hasil + (char)buffer[j];

  return hasil;  
}


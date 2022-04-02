#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  9          
#define SS_PIN   10           // PIN SD DAN NSS
String idtag = "" ;
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Pembuatan objek pustaka rfid

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
SPI.begin();
mfrc522.PCD_Init();
Serial.println(F("pembacaan merekam data rfid pegawai :"));
}

void loop() {
  // put your main code here, to run repeatedly:
mfrc522.PCD_Init();
//periksa tag rfid 
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
idtag ="";
for (byte j = 0; j < mfrc522.uid.size; j++) {
  char teksHeksa[3];
  sprintf(teksHeksa,"%02x",mfrc522.uid.uidByte[j]);
}
Serial.print("UID: ");
Serial.println(idtag);
Serial.print("Masukkan nama untuk direkam: ");

String nama;
bool adaData = false;
do{
 if (Serial.available()){
   nama =Serial.readString();
   nama.trim();
   adaData = true;
    }
  } while (!adaData);
   Serial.println(nama);

// salin String nama ke strNama
char strNama[32];
if(nama.length() < 32){
 int j;
 for (j = 0; j < nama.length(); j++)
  strNama[j] = nama[j]; 

 for (j = nama.length(); j < 32; j++ )
  strNama[j] = 32; //karakter spasi 
 }else{
 for (int j = 0 ; j < 32; j++ )
   strNama[j] = nama[j];
 }

 MFRC522::MIFARE_Key key;
 for (byte i =0; i < 6 ; i++) key.keyByte[i] = 0xff;

 byte buffer[16];
 // tulis nama pada blok nomer 1
 byte blok = 1;
 MFRC522::StatusCode status;
 status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A,blok,&key,&(mfrc522.uid));
 if(status != MFRC522::STATUS_OK){
  Serial.println("otentikasi gagal..... ");
  return;
 }
 status =mfrc522.MIFARE_Write(blok,(byte*)strNama,16);
 if(status != MFRC522::STATUS_OK){
  Serial.println("gagal merekam data..... ");
  return;
  }
//tulis nama pada blok bernomor 2
blok = 2 ;
status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A,blok,&key,&(mfrc522.uid));
if(status != MFRC522::STATUS_OK){
  Serial.println("otentikasi gagal..... ");
  return;
 }
 status =mfrc522.MIFARE_Write(blok,(byte*)strNama,16);
 if(status != MFRC522::STATUS_OK){
  Serial.println("gagal merekam data..... ");
  return;
  }
 Serial.println("data nama sudah direkam ./n"); 
}

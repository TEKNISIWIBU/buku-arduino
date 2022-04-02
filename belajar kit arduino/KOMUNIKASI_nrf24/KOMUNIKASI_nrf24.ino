/*
 * komunikasi nrf24l01 sebagai transmitter/pengirim data potensio 
 * untuk mengendalikan lampu dan motor servo 
 */

// memasukkan librry 
#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <SPI.h>
//configurasi pin dan nomer komunikasi 
const int PIN_CE = 9;
const int PIN_CSN =10;
const uint64_t PIPE = 0xE8E8F0F0E2LL;
const int potensiao = A0; 
const int Button1 = 15;

//objek nrf24l01
RF24 radio(PIN_CE,PIN_CSN);
char pesan[20];//penyangga pesan komunikasi 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Button1,INPUT);
  
  radio.begin();
  radio.openWritingPipe(PIPE);
}
void loop() {
  // put your main code here, to run repeatedly:
  int nilaiPotensio = analogRead (potensiao);
  int sudutServo = map(nilaiPotensio,0,1023,0,180);

 //button pengendali 
 if(digitalRead(Button1) == HIGH){
   radio.write("A",strlen(pesan));
 }
 else if(digitalRead(Button1) == LOW){
   radio.write("B",strlen(pesan));
  }
 
  
  itoa(sudutServo,pesan,10);
  Serial.print(pesan);

  bool ok = radio.write(pesan,strlen(pesan));
  if(ok){
    Serial.println("ok");}
    else{
    Serial.println("gagal");
  }
 radio.powerDown();
 delay(50);
 radio.powerUp(); 
}

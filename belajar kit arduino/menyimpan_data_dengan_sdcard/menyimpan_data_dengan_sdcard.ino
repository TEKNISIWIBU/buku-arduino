#include<SPI.h>
#include<SD.h>

const int cs=4;
const int tombol=2;

File file;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(tombol,INPUT);
 while(!Serial){
  ;
  }
  SPI.begin();
  if(!SD.begin(cs)){
    Serial.println("SD card tidak terbaca!!");
  }else{
     Serial.println("SD card terbaca!!");
  }
  delay(10);
}

void loop() {
  // put your main code here, to run repeatedly:
bool nilaiTombol=digitalRead(tombol);
if(nilaiTombol){
 inputDataSD("Tombol ditekan"); 
 }
 delay(200);
}

void inputDataSD(String data){
  file=SD.open("data.txt",FILE_WRITE);
  if(file){
    file.println(file);
    Serial.println("data berhasil disimpan!!")
    file.close();
  }else{
    Serial.println("gagal membuka file");
  }
  file=SD.open("data.txt",);
  if (file){
    while(file.available()){
      Serial.write(file.read());
    }
    file.close();
  }else{
    Serial.println("gagal membuka file!!");
  } 
}


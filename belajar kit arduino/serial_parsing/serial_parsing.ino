#include <LiquidCrystal_I2C.h>
bool parsing = false;
String sData,data[10];
LiquidCrystal_I2C lcd (0x27,16,2);
void setup() 
{
   lcd.begin();
   lcd.setCursor(0,0);
   lcd.print("Data ditrima: ");
   Serial.begin(9600);
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(11,OUTPUT);
}
 
void loop() 
{
 while (Serial.available()){
  char inChar = Serial.read();
  sData += inChar;
  if (inChar == '$'){
    parsing = true;
  }
  if(parsing){
    int q = 0;
    for(int i = 0 ; i < sData.length(); i++){
      if(sData[i] == '#'){
      q++;
      data[q] = "";
    } else {
      data[q] += sData[i];
    }
  }//tempat untuk maenampilkan data yang diterima 
  Serial.println("DATA MASUK:" + sData);
  Serial.println("LED 1:" + data[1]);
  Serial.println("LED 2:" + data[2]);
  Serial.println("LED 3:" + data[3]);
  Serial.println("LED 4:" + data[4]);
  Serial.println();
  parsing = false;
  sData = "";
  }
 }
 //####$
 // MENYALAKAN LAMPU1
 if(data[1] == "LEDON"){
  digitalWrite(13,HIGH);
  lcd.setCursor(0,1);
  lcd.print("LED 1");
 }else if (data[1] == "LEDOFF"){
  digitalWrite(13,LOW);
  lcd.setCursor(0,1);
  lcd.print(data[1]);
 
 }
 //MENYALAKAN LAMPU2
  if(data[2] == "LEDON"){
  digitalWrite(12,HIGH);
  lcd.setCursor(0,1);
  lcd.print("LED 2");
 }else if (data[2] == "LEDOFF"){
  digitalWrite(12,LOW);
 }
 if(data[3] == "LEDON"){
  digitalWrite(11,HIGH);
 }else if (data[3] == "LEDOFF"){
  digitalWrite(11,LOW);
 }
}


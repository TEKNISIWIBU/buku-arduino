#include <LiquidCrystal_I2C.h>

#include <IRremote.h>

int pinIR = 4;
int LED1 = 3,LED2 =2; 
int tombol1 = 6,tombol2 = 7;
// pustaka untuk sensor ir remote

IRrecv penerimaIR(pinIR);
decode_results hasil;

//pustaka untuk lcdi2c
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("siap menerima");
  delay(1000);
  lcd.clear();
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(tombol1,INPUT);
pinMode(tombol2,INPUT);
penerimaIR.enableIRIn();

}
void loop() {
// put your main code here, to run repeatedly:
//pushbutton();

if(penerimaIR.decode(&hasil)){
   String KodeTombol = String(hasil.value,HEX);
   Serial.print("KODE =");
   Serial.println(KodeTombol);
   lcd.setCursor(0,0);
   lcd.print("KODE=" + KodeTombol);
  
  if(KodeTombol == "885b30d5"){
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  lcd.setCursor(0,1);
  lcd.print(" LAMPU OFF ");
  }else if(KodeTombol == "de34a18"){
   digitalWrite(LED1,HIGH);
   lcd.setCursor(0,1);
   lcd.print(" LAMPU1 ON "); 
  }else if(KodeTombol == "a34f5a01"){
   digitalWrite(LED2,HIGH);
   lcd.setCursor(0,1);
   lcd.print(" LAMPU2 ON ");
    }
   penerimaIR.resume();
 }
 delay(100);
}

  


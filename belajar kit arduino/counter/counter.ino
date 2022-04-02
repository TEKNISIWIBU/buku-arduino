#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int count = 0;
int newcount;

void setup(){
  lcd.begin();
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  }
void loop(){
    lcd.setCursor(4,0);
    lcd.print("counter");
    lcd.setCursor(0,1);
    lcd.print(">");
    lcd.print(newcount);
  if(digitalRead(2) == LOW){
    newcount = count++;
    delay(100);
  }if(digitalRead(3) == LOW){
    newcount = 0;
    count = newcount;
    lcd.clear();
  }
 }

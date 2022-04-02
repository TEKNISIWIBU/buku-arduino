#include<LiquidCrystal_I2C.h>
#include<Wire.h>
#include<Keypad.h>
#define LebarPassword 6

LiquidCrystal_I2C lcd(0x27, 16 , 2);

char Data[LebarPassword];
char Master[LebarPassword] = "26222";
byte data_count = 0,master_count = 0;
bool Password_benar;

const int buzzer = 13;

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] ={
  {'#', '0', '*', 'A'},
  {'9', '8', '7', 'B'},
  {'4', '5', '6', 'C'},
  {'3', '2', '1', 'D'}
};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys),rowPins,colPins,ROWS,COLS);

void setup() {
  // put your setup code here, to run once:
lcd.begin();
lcd.backlight();
pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
lcd.print("Password :");

char customKey = customKeypad.getKey();
if(customKey){
  Data[data_count] =customKey;
  lcd.setCursor(data_count,1);
  lcd.print(Data[data_count]);
  data_count++;
 }
 if (data_count == LebarPassword - 1){
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("password: ");

   if(strcmp(Data,Master)){
    lcd.setCursor(0,1);
    lcd.print("Password salah");
    tone(buzzer,1000);
    delay(1000);
    noTone(buzzer);
    delay(1000);
   }else{
    lcd.setCursor(0,1);
    lcd.print("Password benar");
   }
   delay(3000);
   lcd.clear();
   clearData();
 }
}
void clearData(){
 while(data_count !=0){
  Data[data_count--]=0;
 }
 return;
}


#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define tombol_1 2
#define tombol_2 3
int menu = 1;

void setup() {
  // put your setup code here, to run once:
lcd.begin();
lcd.backlight();
lcd.setCursor(2,0);
lcd.print("project menu");
delay(1000);
lcd.clear();

updateMenu();
pinMode(tombol_1,INPUT_PULLUP);
pinMode(tombol_2,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
if(!digitalRead(tombol_1)){
    menu++;
    updateMenu();
    delay(100);
    while(!digitalRead(tombol_1));
   }
if(!digitalRead(tombol_2)){
    menu--;
    updateMenu();
    delay(100);
    while(!digitalRead(tombol_2));
   }
}
void updateMenu(){ 
switch (menu){
  case 0:
       menu = 1;
       break;
  case 1:
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(">menu 1");
        lcd.setCursor(1,1);
        lcd.print("menu 2");
       
       break;
  case 2:
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("menu 1");
        lcd.setCursor(0,1);
        lcd.print(">menu 2");
       break;
   case 3:
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print(">menu 3");
         lcd.setCursor(1,1);
         lcd.print("menu 4");
       break;
    case 4:
         lcd.clear();
         lcd.setCursor(1,0);
         lcd.print("menu 3");
         lcd.setCursor(0,1);
         lcd.print(">menu 4");
       break;
     case 5:
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print(">menu 5");
       break;    
    default:
          menu = 4;
        break;
       }
    delay(100);
}

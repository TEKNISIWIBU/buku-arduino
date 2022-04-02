#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
lcd.begin();
lcd.backlight(); 
lcd.setCursor(0,0);
lcd.print("hallo ZADID");
lcd.setCursor(0,1);
lcd.print("MaumemBuatProject");
delay(1000);
lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
int potensio = map(analogRead(A0),0, 1023,0 , 255);
EEPROM.write(0,potensio);
delay(5);

int penyimpanan = EEPROM.read(0);
lcd.setCursor(0,0);
lcd.print("EEPROM = ");
lcd.setCursor(10,0);
lcd.print(penyimpanan);


}

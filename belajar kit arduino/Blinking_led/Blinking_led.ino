#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
lcd.begin();
lcd.clear();
lcd.setCursor(0,0);
lcd.print("ohayooo");
lcd.setCursor(0,1);
lcd.print("gonzaimas");
}
void loop() {
  // put your main code here, to run repeatedly:
lcd.noDisplay();
delay(500);
lcd.display();
delay(500);
}

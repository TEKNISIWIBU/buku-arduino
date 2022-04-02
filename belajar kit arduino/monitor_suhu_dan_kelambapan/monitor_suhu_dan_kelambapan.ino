#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2  
#define DHTTYPE DHT11
LiquidCrystal_I2C lcd(0x27,16,2) ;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:

lcd.begin();
lcd.setCursor(0,0);
lcd.print("monitoring");
lcd.setCursor(0,1);
lcd.print("suhuruang");
delay(1000);
dht.begin();
}
void loop() {
 float kelembapan = dht.readHumidity();
 float suhu       = dht.readTemperature();

 lcd.setCursor(0,0);  
 lcd.print("kelembapan:");
 lcd.print(kelembapan);
 lcd.setCursor(0,1);
 lcd.print("Temperature:");
 lcd.print(suhu);
  }

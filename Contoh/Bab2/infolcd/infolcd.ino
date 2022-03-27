// ---------------------------------------------
// Penyajian informasi suhu dan kelembaban udara
//   yang diterima melalui XBee ke penampil LCD
// ---------------------------------------------

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat LCD: 0x27
                                     // Mengandung 16 kolom
                                     // dan 2 baris
void setup() {
  Serial.begin(9600);
  lcd.begin(); // Inisialisasi LCD 
}

void loop() {
  if (Serial.available()) {
    String teks = Serial.readString();

    // Peroleh suhu dan kelembaban udara
    // Suhu = xx.xx, kelembaban = yy.yy
    // 01234567890123456789012345678901
  
    float suhu = teks.substring(7, 12).toFloat();
    float kelembaban = teks.substring(27, 32).toFloat();

    Serial.println(suhu);
    
    // Tampilkan informasi di LCD
    lcd.setCursor(0, 0);
    lcd.print("Suhu  : ");
    lcd.print(suhu);
    
    lcd.setCursor(0, 1);
    lcd.print("lembab: ");
    lcd.print(kelembaban);
  }
}


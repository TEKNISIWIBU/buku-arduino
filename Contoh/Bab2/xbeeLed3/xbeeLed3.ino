// --------------------------------------------------
// Contoh komunikasi dua arah pada Xbee
//   Bagian pengirim
// --------------------------------------------------

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int PIN_TOMBOL = 2;

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat LCD: 0x27
                                     // Mengandung 16 kolom
                                     // dan 2 baris
boolean ledOn = false;
int keadaanSebelum = LOW;

void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_TOMBOL, INPUT);   

  lcd.begin(); // Inisialisasi LCD 
}

void loop() 
{
  int keadaanTombol = digitalRead(PIN_TOMBOL);
  if (keadaanTombol == HIGH && keadaanTombol != keadaanSebelum)
  {
    ledOn = not ledOn;

    if (ledOn)
      Serial.println("LED ON");
    else
      Serial.println("LED OFF");

    Serial.flush();
    
    delay(30); // Menghilangkan efek pantulan
  }    
    
  keadaanSebelum = keadaanTombol; 

  // Periksa kiriman data 
  if (Serial.available()) {
    String teks = Serial.readString();

    // Tampilkan informasi di LCD
    lcd.clear();
    lcd.println(teks);
  }
}


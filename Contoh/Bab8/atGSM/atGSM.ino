//------------------------------------------
// Contoh penggunaan perintah AT
//   pada modul GSM
//------------------------------------------

#include <SoftwareSerial.h>

SoftwareSerial serialGSM(2, 3);

char karakter;

void setup()  {
  Serial.begin(9600);
  serialGSM.begin(9600);  
    
  Serial.println("Silakan untuk memberikan perintah AT!");
}
 
void loop() {
  // Baca perintah di port serial
  if (Serial.available()) {
    karakter = Serial.read();
    serialGSM.write(karakter);  
  }

  // Baca hasil dari modul GSM
  if (serialGSM.available()) {
    karakter = serialGSM.read();
    Serial.write(karakter);
  } 
}

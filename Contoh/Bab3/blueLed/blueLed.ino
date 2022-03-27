// --------------------------------------------
// Pengujian modul Bluetooth untuk menangani
//    operasi INPUT dan OUTPUT
// --------------------------------------------                                                                                                                                     

const int PIN_LED = 2;

#include <SoftwareSerial.h>

SoftwareSerial bt(9, 10); // TXD dan RXD 
                          // modul Bluetooth

void setup() {
  pinMode(PIN_LED, OUTPUT);
  
  bt.begin(9600);
  bt.println("Tekan 1 = untuk menghidupkan LED");
  bt.println("      0 = untuk mematikan LED");
}

void loop() {
  char dataBt; // Data dari Bluetooth
  
  if (bt.available()) {
    dataBt = bt.read();
    if (dataBt == '0') {   
      digitalWrite(PIN_LED, LOW);
      bt.println("LED dimatikan...");
    }
    else if (dataBt == '1') {
      digitalWrite(PIN_LED, HIGH);
      bt.println("LED dihidupkan...");
    }
  }
}


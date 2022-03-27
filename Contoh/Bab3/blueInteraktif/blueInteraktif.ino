// --------------------------------------------
// Pengujian modul Bluetooth untuk menangani
//    operasi INPUT dan OUTPUT
// --------------------------------------------                                                                                                                                     

#include <SoftwareSerial.h>

SoftwareSerial bt(9, 10); // TXD dan RXD 
                          // modul Bluetooth

void setup() {
  bt.begin(9600);
  bt.println("Ketik 0, 1, atau 2");
}

void loop() {
  char dataBt; // Data dari Bluetooth
  
  if (bt.available()) {
    dataBt = bt.read();
    if (dataBt == '0' || dataBt == '1' || dataBt == '2') {   
      bt.print("Anda baru saja menekan tombol ");
      bt.println(dataBt);
    }
  }
}


// -------------------------------------
// Sketsa dalam bahasa Processing
//   yang digunakan untuk membaca data
//   yang dikirim via modul XBee
// -------------------------------------

import processing.serial.*;
 
Serial xbee;
 
String teks;
 
void setup() {
  size(300, 300);
  println(Serial.list()); 
  
  // Ubah isi portSerial sesuai dengan COM
  //   yang digunakan oleh Explorer board
  String portSerial = "COM9";
  
  xbee = new Serial(this, portSerial, 9600);
}
 
void draw() {
  // you could map the incoming data to a graphical or 
  // text display
}
 
void serialEvent(Serial xbee) {
  // Membaca string yang diterima
  //   sampai linefeed
  teks = xbee.readStringUntil(10);
  
  if (teks != null) {
    println("Data yang diterima: " + teks);
  }
}
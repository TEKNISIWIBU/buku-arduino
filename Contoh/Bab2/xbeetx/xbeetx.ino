// ------------------------------
// Pengujian XBee
//   Bagian pengirim
// ------------------------------

void setup() {
  Serial.begin(9600);
}

void loop() {
  static int pencacah = 1;
  
  Serial.println(pencacah);
  pencacah++;
  delay(1000);
}

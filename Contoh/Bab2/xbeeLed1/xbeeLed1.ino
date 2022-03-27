// -----------------------------------------
// Pengontrolan LED secara jarak jauh
//   menggunakan XBee
// -----------------------------------------

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("LED ON");
  Serial.flush();
  delay(2000);

  Serial.println("LED OFF");
  Serial.flush();
  delay(2000);
}

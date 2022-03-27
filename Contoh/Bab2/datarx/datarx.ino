// --------------------------------------
// Contoh untuk menampilkan data suhu dan 
//   kelembaban udara yang diterima 
//   melalui XBee
// --------------------------------------

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String teks = Serial.readString();
    teks.trim();
    
    Serial.println(teks);
  }
}

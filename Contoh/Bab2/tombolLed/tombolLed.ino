// --------------------------------------------------
// Perintah untuk mengendalikan LED secara jarak jauh
//   melalui XBee
//   menggunakan tombol tekan sementara
// --------------------------------------------------

const int PIN_TOMBOL = 2;

boolean ledOn = false;
int keadaanSebelum = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TOMBOL, INPUT);   
}

void loop() {
  int keadaanTombol = digitalRead(PIN_TOMBOL);
  if (keadaanTombol == HIGH && keadaanTombol != keadaanSebelum) {
    ledOn = not ledOn;

    if (ledOn)
      Serial.println("LED ON");
    else
      Serial.println("LED OFF");

    Serial.flush();
    
    delay(30); // Menghilangkan efek pantulan
  }    
    
  keadaanSebelum = keadaanTombol; 
}


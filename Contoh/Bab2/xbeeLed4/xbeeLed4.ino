// ------------------------------------------
// Contoh komunikasi dua arah pada XBee
//   Bagian penerima
// ------------------------------------------

const int PIN_LED = 4;

void setup() {
  Serial.begin(9600);
  
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
}

void loop() {
  if (Serial.available()) {
    String teks = Serial.readString();
    teks.trim();

    if (teks.equals("LED ON")) {
      digitalWrite(PIN_LED, HIGH);
      Serial.println("LED dihidupkan! ");
      Serial.flush();
    }
    else
      if (teks.equals("LED OFF")) {
        digitalWrite(PIN_LED, LOW);
        Serial.println("LED dimatikan!  ");
        Serial.flush();
      }    
  }
}

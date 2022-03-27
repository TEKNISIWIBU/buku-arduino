//-----------------------------------------
// Contoh penggunaan remote control 315MHz
//   untuk mengendalikan satu lampu 220V
//-----------------------------------------

const int PIN_D0 = 2; // Tombol B
const int PIN_D2 = 4; // Tombol A
const int PIN_RELAI = 8;

void setup() {
  pinMode(PIN_D0, INPUT);
  pinMode(PIN_D2, INPUT);

  pinMode(PIN_RELAI, OUTPUT);
}

void loop() {
  int d0 = digitalRead(PIN_D0);
  int d2 = digitalRead(PIN_D2);
  
  if (d0 == HIGH) 
    digitalWrite(PIN_RELAI, LOW);
  
  if (d2 == HIGH) 
    digitalWrite(PIN_RELAI, HIGH);
}


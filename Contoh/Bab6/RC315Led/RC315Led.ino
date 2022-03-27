//-----------------------------------------
// Contoh penggunaan remote control 315MHz
//   untuk mengendalikan dua LED
//-----------------------------------------

const int PIN_D0 = 2; 
const int PIN_D1 = 3;
const int PIN_D2 = 4;
const int PIN_D3 = 5;
const int PIN_LED_MERAH = 8;
const int PIN_LED_HIJAU = 9;

void setup() {
  pinMode(PIN_D0, INPUT);
  pinMode(PIN_D1, INPUT);
  pinMode(PIN_D2, INPUT);
  pinMode(PIN_D3, INPUT);

  pinMode(PIN_LED_MERAH, OUTPUT);
  pinMode(PIN_LED_HIJAU, OUTPUT);
}

void loop() {
  int d0 = digitalRead(PIN_D0);
  int d1 = digitalRead(PIN_D1);
  int d2 = digitalRead(PIN_D2);
  int d3 = digitalRead(PIN_D3);
  
  if (d0 == HIGH) 
    digitalWrite(PIN_LED_MERAH, LOW);
  
  if (d1 == HIGH) 
    digitalWrite(PIN_LED_HIJAU, LOW);
  
  if (d2 == HIGH) 
    digitalWrite(PIN_LED_MERAH, HIGH);
  
  if (d3 == HIGH) 
    digitalWrite(PIN_LED_HIJAU, HIGH);
}


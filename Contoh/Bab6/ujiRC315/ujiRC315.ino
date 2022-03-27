//---------------------------------------
// Contoh pengujian remote control 315MHz
//---------------------------------------

const int PIN_D0 = 2; 
const int PIN_D1 = 3;
const int PIN_D2 = 4;
const int PIN_D3 = 5;

void setup() {
  pinMode(PIN_D0, INPUT);
  pinMode(PIN_D1, INPUT);
  pinMode(PIN_D2, INPUT);
  pinMode(PIN_D3, INPUT);
  
  Serial.begin(9600);
  Serial.println("Siap!");
}

void loop() {
  int d0 = digitalRead(PIN_D0);
  int d1 = digitalRead(PIN_D1);
  int d2 = digitalRead(PIN_D2);
  int d3 = digitalRead(PIN_D3);
  
  if (d0 == HIGH) {
    Serial.println("Tombol B ditekan...");
    delay(100);
  }   
  
  if (d1 == HIGH) {
    Serial.println("Tombol D ditekan...");
    delay(100);  
  }
  
  if (d2 == HIGH) {
    Serial.println("Tombol A ditekan..."); 
    delay(100);    
  }
  
  if (d3 == HIGH) {
    Serial.println("Tombol C ditekan...");
    delay(100);  
  }
}


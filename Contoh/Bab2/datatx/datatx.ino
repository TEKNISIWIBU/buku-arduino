// -----------------------------------------
// Pengiriman data suhu dan kelembaban udara
//   menggunakan XBee
// -----------------------------------------
#include <dht.h>

const int PIN_DHT = A0;

dht DHT;

void setup() {
  Serial.begin(9600);
}

void loop() {
  DHT.read11(PIN_DHT);
  float kelembaban = DHT.humidity;
  float suhu = DHT.temperature;

  Serial.print("Suhu = ");
  Serial.print(suhu);
  Serial.print(", kelembaban = ");
  Serial.println(kelembaban);
  Serial.flush();
  
  delay(1000);
}

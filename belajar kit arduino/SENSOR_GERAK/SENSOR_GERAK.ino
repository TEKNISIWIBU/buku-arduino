#define PIR_PIN 2
#define LED_PIN 13
 
long int
 // jeda waktu indikator hidup ketika sensor PIR mendeteksi
 // gerakan dalam milidetik
 ledOn = 10000,
 lastTime = -ledOn; // penghitung waktu (default led mati)
 
void setup(){
 Serial.begin(9600);
 pinMode(LED_PIN, OUTPUT); // Atur pin 13 menjadi mode Output
 pinMode(PIR_PIN, INPUT); // Atur pin 2 menjadi mode input
 
 digitalWrite(LED_PIN, LOW); // matikan led indikator
 
 delay(100); // Jeda sebentar
}
 
void loop(){
 if(digitalRead(PIR_PIN) == HIGH){
  lastTime = millis();
  Serial.println("Motion Detected");
  delay(100);
 }else{
  Serial.println("No Motion");
  delay(100);
 }
 
 if ((millis() - lastTime) < ledOn){
  digitalWrite(LED_PIN, HIGH);
 }else{
  digitalWrite(LED_PIN, LOW);}
}  

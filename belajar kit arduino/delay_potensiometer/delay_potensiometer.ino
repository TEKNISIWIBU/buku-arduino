#define LED1  6
#define LED2  5
#define LED3  4

int sensorPin = A0;
int sensorVlue = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorVlue =analogRead(sensorPin);
int lama = map(sensorVlue,0,1023,0,255);
Serial.print("nilai potensio = ");
Serial.println(sensorVlue);
Serial.print("waktu = ");
Serial.println(lama);

digitalWrite(LED1,HIGH);
delay(lama);
digitalWrite(LED1,LOW);
delay(lama);
//digitalWrite(LED3,LOW);
//delay(lama);

digitalWrite(LED2,HIGH);
delay(lama);
digitalWrite(LED2,LOW);
delay(lama);
//digitalWrite(LED3,LOW);
//delay(lama);

//digitalWrite(LED1,LOW);
//delay(lama);
digitalWrite(LED3,HIGH);
delay(lama);
digitalWrite(LED3,LOW);
delay(lama);
}

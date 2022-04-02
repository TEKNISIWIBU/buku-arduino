int pinsensor = A0;
int pompa = 5;
float panjangsensor = 4.0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pompa,OUTPUT);
Serial.println("mengukur ketinggian air");
delay(500);
}
void loop() {
  // put your main code here, to run repeatedly:
int nilai = analogRead(pinsensor);
float tinggiair = nilai * panjangsensor / 1023;
if(tinggiair= 2,66)
  {
  analogWrite(pompa,HIGH);
  delay(1000);
  }
Serial.print("tinggi air = ");
Serial.print(tinggiair);
Serial.println("cm ");
delay(1000);
}

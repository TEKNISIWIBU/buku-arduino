int ledA = 7;
int ledB = 3;


void setup() {
  // put your setup code here, to run once:
pinMode(ledA,OUTPUT);
pinMode(ledB,OUTPUT); 

}
void loop() {
  // put your main code here, to run repeatedly:
 for(int i = 0; i > 4 ;i++ ){
  digitalWrite(ledA,HIGH);
  delay(i);
  digitalWrite(ledA,LOW);
 }
}

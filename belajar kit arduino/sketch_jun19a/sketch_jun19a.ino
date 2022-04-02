int pinLDR = 0 ;
int pinLampu = 2;

void setup(){
  Serial.begin(9600);
 pinMode(pinLampu,OUTPUT);
 pinMode(pinLDR,INPUT);
   
}
void loop(){
  int nilaiLDR = analogRead(pinLDR);
  Serial.println(nilaiLDR);
  if(nilaiLDR <= 300){
    digitalWrite(pinLampu,LOW);
    }else{
    digitalWrite(pinLampu,HIGH);
      }
     
  }

 const int pb1  = 2 ;
 const int pb2  = 3 ;
 const int LEDA = 7 ;
 const int LEDB = 5 ;
 const int LEDC = 6 ;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDA,OUTPUT);
  pinMode(LEDB,OUTPUT);
  pinMode(LEDC,OUTPUT);
  pinMode(pb1,INPUT);
  pinMode(pb2,INPUT);
}
void loop() {
  if(digitalRead(pb1)==1 && digitalRead(pb2)==0){
    digitalWrite(LEDA,HIGH);
    }else{
    digitalWrite(LEDA,LOW);
      }
   if(digitalRead(pb1)==0 && digitalRead(pb2)==0){
    digitalWrite(LEDB,HIGH);
    }else{
    digitalWrite(LEDB,LOW);
      } 
    if(digitalRead(pb1)==0 && digitalRead(pb2)==1){
    digitalWrite(LEDC,HIGH);
    }else{
    digitalWrite(LEDC,LOW);
      }    
}

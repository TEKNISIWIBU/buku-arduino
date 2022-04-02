int status=0;
unsigned long time;
unsigned long timer =5000;
unsigned long Start;
unsigned long Stop;

void setup(){
Serial.begin(9600);
pinMode(13, OUTPUT);
}

void loop(){
time = millis();
status=analogRead(A0);

if (status>=100){
digitalWrite(13,HIGH);
Start=millis();
}

Stop=Start+timer;

if ( Stop <=time ){
digitalWrite(13,LOW);
Start=0;
}

Serial.print(status);
Serial.print(",");
Serial.print(Start);
Serial.print(",");
Serial.println(time);

}


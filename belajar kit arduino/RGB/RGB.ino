int redPin = 11;

int greenPin = 10;

int bluePin = 9;
void setup() {
  // put your setup code here, to run once:
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
setColor(255,0,0);
delay(500);// merah
setColor(0,255,0);
delay(200);//hijau
setColor(0,0,255);
delay(300);//biru
setColor(255,255,0);
delay(100);//kuning
setColor(80,0,80);
delay(100);//ungu
setColor(0,255,255);
delay(400);//aqua
}
void setColor(int red,int green,int blue)
{
analogWrite(redPin,red);
analogWrite(greenPin,green);
analogWrite(bluePin,blue);
}

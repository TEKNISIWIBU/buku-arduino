const int led1 = 2;
const int tombol = 3;

bool led_on = false;
bool button_ready = true;

void setup() {
  // put your setup code here, to run once:
pinMode(tombol, INPUT_PULLUP);
pinMode(led1, OUTPUT);
 }
void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(tombol) == LOW && button_ready){
  if(led_on){
     digitalWrite(led1,LOW);
     led_on = false;
    }else{
     digitalWrite(led1,HIGH);
     led_on = true; 
      }
      button_ready = false;
  }else if(digitalRead(tombol) == HIGH && !button_ready){
    button_ready = true;
    }
 delay(10);
}

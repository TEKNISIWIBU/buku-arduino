const int joyH = A0;
const int joyV = A1; 

int VR_x  ;  
int VR_y  ;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(joyH,INPUT);
  pinMode(joyV,INPUT);
  Serial.begin(9600);
}
 
 
void loop(){
     outputJoystick();
   VR_x = analogRead(joyH);          
   VR_y = analogRead(joyV);
    
     int nilaioutputX = map(VR_x,0,1023,0,255);
     int nilaioutputY = map(VR_y,0,1023,0,255);
    
   analogWrite(2,nilaioutputX);
   analogWrite(3,nilaioutputY);
}
 
void outputJoystick(){
 
    Serial.print(analogRead(joyH));
    Serial.print ("***"); 
    Serial.print(analogRead(joyV));
    Serial.println ("************");
}

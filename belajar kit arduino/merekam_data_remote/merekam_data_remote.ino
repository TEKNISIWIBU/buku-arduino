#include<IRremote.h>

int pinIR = 4;

IRrecv penerimaIR(pinIR);
decode_results hasil;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
penerimaIR.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
if (penerimaIR.decode(&hasil)){
   Serial.print("KODE =");
   Serial.println(hasil.value);
   penerimaIR.resume();
  }
  delay(100);
}

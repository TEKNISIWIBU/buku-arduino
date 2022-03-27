// -------------------------------
// Penentuan jenis remote control
// -------------------------------

#include "IRremote.h"

const int SENSOR_PIN = 2; 

IRrecv penerima(SENSOR_PIN);
decode_results hasil;
unsigned long kodeSebelumnya = 0;
  
void setup() {
  penerima.enableIRIn();
  
  Serial.begin(9600);
  Serial.println("Siap!");
}

void loop() {
  if (penerima.decode(&hasil)) {
    if (kodeSebelumnya == hasil.value) {
      // Peroleh nilai berikutnya
      penerima.resume(); 
      
      return;
    }
    
    kodeSebelumnya = hasil.value;
     
    if (hasil.value == 0xFFFFFFFF) {
      penerima.resume();
      return;
    }
    
    switch (hasil.decode_type) {
      case NEC:
        Serial.println("Jenis: NEC");
        break;
      case SONY:
        Serial.println("Jenis: SONY");
        break;       
      case RC5:
        Serial.println("Jenis: RC5");
        break;
      case RC6:
        Serial.println("Jenis: RC6");
        break;
      case DISH:
        Serial.println("Jenis: DISH");
        break;
      case SHARP:
        Serial.println("Jenis: SHARP");
        break;
      case PANASONIC:
        Serial.println("Jenis: PANASONIC");
        break;
      case JVC:
        Serial.println("Jenis: JVC");
        break;
      case SANYO:
        Serial.println("Jenis: SANYO");
        break;
      case MITSUBISHI:
        Serial.println("Jenis: MITSUBISHI");
        break;
      case SAMSUNG:
        Serial.println("Jenis: SAMSUNG");
        break;
      case WHYNTER:
        Serial.println("Jenis: WHYNTER");
        break;
      case AIWA_RC_T501:
        Serial.println("Jenis: AIWA_RC_T501");
        break;
      case LG:
        Serial.println("Jenis: LG");
        break;
      case DENON:
        Serial.println("Jenis: DENON");
        break;
      case PRONTO:
        Serial.println("Jenis: PRONTO");
        break;
      case LEGO_PF:
        Serial.println("Jenis: LEGO_PF");
        break;
      case UNKNOWN:  
        Serial.println("Jenis: Tak dikenal");
        break;       
      default:
        Serial.print("Jenis: ");
        Serial.println(hasil.decode_type);
        break;       
    }
    
    Serial.print("Kode: ");
    Serial.println(hasil.value, HEX);

    // Peroleh nilai berikutnya
    penerima.resume();   
  }
}


// ------------------------------------
// Contoh untuk mendapatkan informasi
//   waktu dan tinggi lokasi
// ------------------------------------

#include <SoftwareSerial.h>
#include <TinyGPS.h>

SoftwareSerial gpsSerial(6, 7);
TinyGPS gps;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  Serial.println("Siap menerima informasi!");
}

void loop() { 
  if (gpsSerial.available()) {
    char karakter = gpsSerial.read();
    if (gps.encode(karakter))
      berikanInfo();
  } 
}

void berikanInfo() {
  int tahun;
  byte bulan, tanggal, jam, menit, detik;
  gps.crack_datetime(&tahun, &bulan, &tanggal, 
                     &jam, &menit, &detik);
  
  char teks[22];
  sprintf(teks, "%02d/%02d/%04d %02d:%02d:%02d ",
                bulan, tanggal, tahun, jam, menit, detik);
  Serial.println(teks);

  float lintang, bujur;
  gps.f_get_position(&lintang, &bujur);
  Serial.print("Lintang: ");
  Serial.println(lintang, 7);
  Serial.print("Bujur  : ");
  Serial.println(bujur, 7);      
  
  long tinggi;
  tinggi = gps.f_altitude();
  Serial.print("Tinggi : ");
  Serial.print(tinggi);     
  Serial.println("m\n");
}


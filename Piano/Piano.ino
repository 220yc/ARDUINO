#include <Adafruit_CircuitPlayground.h>
uint8_t pixeln = 0;
int s = 50;//感應接觸的臨界值，數字愈小越靈敏，但越容易誤觸
int d = 50;//聲音暫停時間(ms)，數字越小停越短越靈敏，但容易有怪聲

void setup() {
  Serial.begin(960);
  CircuitPlayground.begin();
}

void loop() {
  CircuitPlayground.speaker.enable(false);
  for ( pixeln = 0 ; pixeln < 11 ; pixeln++) {
    CircuitPlayground.setPixelColor(pixeln, 0);
  }
  while (CircuitPlayground.readCap(3) > s) {
    CircuitPlayground.speaker.enable(true);
    for ( pixeln = 0 ; pixeln < 11 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(30 * 1));
      //亮出音符對應色燈
    }
     CircuitPlayground.playTone(1046 , d);
     //發出對應音頻
    Serial.print("Capsense #3: "); Serial.println(CircuitPlayground.readCap(3));
    
  }
  while (CircuitPlayground.readCap(2) > s) {
    CircuitPlayground.speaker.enable(true);
    for ( pixeln = 0 ; pixeln < 11 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(30 * 2));
      //亮出音符對應色燈
    }
    CircuitPlayground.playTone(1174 , d);
    //發出對應音頻
    Serial.print("Capsense #2: "); Serial.println(CircuitPlayground.readCap(2));
  }
  while (CircuitPlayground.readCap(0) > s) {
    CircuitPlayground.speaker.enable(true);
    for ( pixeln = 0 ; pixeln < 11 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(30 * 3));
      //亮出音符對應色燈
    }
    CircuitPlayground.playTone(1318 , d);
    //發出對應音頻
    Serial.print("Capsense #0: "); Serial.println(CircuitPlayground.readCap(0));
  }
  while (CircuitPlayground.readCap(1) > s) {
    CircuitPlayground.speaker.enable(true);
    for ( pixeln = 0 ; pixeln < 11 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(30 * 4));
      //亮出音符對應色燈
    }
    CircuitPlayground.playTone(1396 , d);
    //發出對應音頻
    Serial.print("Capsense #1: "); Serial.println(CircuitPlayground.readCap(1));
  }
  while (CircuitPlayground.readCap(12) > s) {//500為感應變化的臨界值，數字愈小越靈敏，但越容易誤觸
    CircuitPlayground.speaker.enable(true);
    for ( pixeln = 0 ; pixeln < 11 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(30 * 5));
      //亮出音符對應色燈
    }
    CircuitPlayground.playTone(1568 , d);
    //發出對應音頻
    Serial.print("Capsense #12: "); Serial.println(CircuitPlayground.readCap(12));
  }
  while (CircuitPlayground.readCap(6) > s) {
    CircuitPlayground.speaker.enable(true);
    for ( pixeln = 0 ; pixeln < 11 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(30 * 6));
      //亮出音符對應色燈
    }
    CircuitPlayground.playTone(1760 , d);
    //發出對應音頻
    Serial.print("Capsense #6: "); Serial.println(CircuitPlayground.readCap(6));
  }
  while (CircuitPlayground.readCap(9) > s) {
    CircuitPlayground.speaker.enable(true);
    for ( pixeln = 0 ; pixeln < 11 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(30 * 7));
      //亮出音符對應色燈
    }
    CircuitPlayground.playTone(1975 , d);
    //發出對應音頻
    Serial.print("Capsense #9: "); Serial.println(CircuitPlayground.readCap(9));
  }
  while (CircuitPlayground.readCap(10) > s) {
    CircuitPlayground.speaker.enable(true);
    for ( pixeln = 0 ; pixeln < 11 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(30 * 8));
      //亮出音符對應色燈
    }
    CircuitPlayground.playTone(2093 , d);
    //發出對應音頻
    Serial.print("Capsense #10: "); Serial.println(CircuitPlayground.readCap(10));
  }
}

#include <Adafruit_CircuitPlayground.h>
uint8_t pixeln = 0;
int x;
int sound_start = 70;//最小聲音數值，越大初始亮燈越少
int sound_index = 3;//聲音變化間隔，越小越容易變化

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  x = CircuitPlayground.mic.soundPressureLevel(10);
  while (x < sound_start) {
    for ( pixeln = 0 ; pixeln < 1 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    }
    x = CircuitPlayground.mic.soundPressureLevel(10);
    delay(10);
  }
  while (sound_start < x and x < sound_start+1*sound_index) {
    for ( pixeln = 0 ; pixeln < 2 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    }
    x = CircuitPlayground.mic.soundPressureLevel(10);
    delay(10);
  }
  while (sound_start+1*sound_index < x and x < sound_start+2*sound_index) {
    for ( pixeln = 0 ; pixeln < 3 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    }
    x = CircuitPlayground.mic.soundPressureLevel(10);
    delay(10);
  }
  while (sound_start+2*sound_index < x and x < sound_start+3*sound_index) {
    for ( pixeln = 0 ; pixeln < 4 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    }
    x = CircuitPlayground.mic.soundPressureLevel(10);
    delay(10);
  }
  while (sound_start+3*sound_index < x and x < sound_start+4*sound_index) {
    for ( pixeln = 0 ; pixeln < 5 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    }
    x = CircuitPlayground.mic.soundPressureLevel(10);
    delay(10);
  }
  while (sound_start+4*sound_index < x and x < sound_start+5*sound_index) {
    for ( pixeln = 0 ; pixeln < 6 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    }
    x = CircuitPlayground.mic.soundPressureLevel(10);
    delay(10);
  }
  while (sound_start+5*sound_index < x and x < sound_start+6*sound_index) {
    for ( pixeln = 0 ; pixeln < 7 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    }
    x = CircuitPlayground.mic.soundPressureLevel(10);
    delay(10);
  }
  while (sound_start+6*sound_index < x and x < sound_start+7*sound_index) {
    for ( pixeln = 0 ; pixeln < 8 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    }
    x = CircuitPlayground.mic.soundPressureLevel(10);
    delay(10);
  }
  while (sound_start+7*sound_index < x and x < sound_start+8*sound_index) {
    for ( pixeln = 0 ; pixeln < 9 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    }
    x = CircuitPlayground.mic.soundPressureLevel(10);
    delay(10);
  }
  while (sound_start+8*sound_index < x and x < sound_start+9*sound_index) {
    for ( pixeln = 0 ; pixeln < 10 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    }
    x = CircuitPlayground.mic.soundPressureLevel(10);
    delay(10);
  }
  while (sound_start+10*sound_index < x) {
    for ( pixeln = 0 ; pixeln < 11 ; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    }
    x = CircuitPlayground.mic.soundPressureLevel(10);
    delay(10);
  }
  CircuitPlayground.clearPixels();

}

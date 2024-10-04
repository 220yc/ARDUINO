#include <Adafruit_CircuitPlayground.h>
int brightness = 0;
int fadeAmount = 2;//亮度每次變化的間隔，數字越大變化越快
int delayDuration = 10;//相同亮度停留的時間，數字越大停越久
uint8_t pixeln = 0;
uint8_t x = 0;

void setup()  {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop()  {
  if (CircuitPlayground.leftButton()) {//按鈕調整顏色
    x += 1;
    delay(1000);
  }
  if (CircuitPlayground.rightButton()) {//按鈕調整顏色
    x -= 1;
    delay(1000);
  }
  if (x==8){
    x=0;
  }
  for ( pixeln = 0 ; pixeln < 11 ; pixeln++) {
    CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(30 * x));
  }
  CircuitPlayground.setBrightness(brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount ;
  }
  delay(delayDuration);
}

#include <Adafruit_CircuitPlayground.h>
uint8_t pixeln = 0;
int s = 5;//為設定傾斜亮燈的臨界值，0為水平，因此數值越大越不靈敏


void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();

}

void loop() {
  while (CircuitPlayground.motionX() < -s){
    CircuitPlayground.setPixelColor(0 , CircuitPlayground.colorWheel(25 * 0));
    CircuitPlayground.setPixelColor(1 , CircuitPlayground.colorWheel(25 * 1));
    CircuitPlayground.setPixelColor(9 , CircuitPlayground.colorWheel(25 * 9));
    CircuitPlayground.setPixelColor(8 , CircuitPlayground.colorWheel(25 * 8));
    //上四行為亮燈的模組，CircuitPlayground.setPixelColor(亮第幾顆燈 , CircuitPlayground.colorWheel(燈的顏色對應的(R,G,B)))
  }
  while (CircuitPlayground.motionX() > s){
    CircuitPlayground.setPixelColor(3 , CircuitPlayground.colorWheel(25 * 3));
    CircuitPlayground.setPixelColor(4 , CircuitPlayground.colorWheel(25 * 4));
    CircuitPlayground.setPixelColor(5 , CircuitPlayground.colorWheel(25 * 5));
    CircuitPlayground.setPixelColor(6 , CircuitPlayground.colorWheel(25 * 6));
  }
  while (CircuitPlayground.motionY() > s){
    CircuitPlayground.setPixelColor(6 , CircuitPlayground.colorWheel(25 * 6));
    CircuitPlayground.setPixelColor(7 , CircuitPlayground.colorWheel(25 * 7));
    CircuitPlayground.setPixelColor(8 , CircuitPlayground.colorWheel(25 * 8));
  }
  while (CircuitPlayground.motionY() < -s){
    CircuitPlayground.setPixelColor(1 , CircuitPlayground.colorWheel(25 * 1));
    CircuitPlayground.setPixelColor(2 , CircuitPlayground.colorWheel(25 * 2));
    CircuitPlayground.setPixelColor(3 , CircuitPlayground.colorWheel(25 * 3));
  }
  CircuitPlayground.clearPixels();

}

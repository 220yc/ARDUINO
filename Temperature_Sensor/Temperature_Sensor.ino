#include <Adafruit_CircuitPlayground.h>
uint8_t pixeln = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");
  CircuitPlayground.begin();
}

void loop() {
  Serial.print("Temperature ");
  Serial.print(CircuitPlayground.temperature());
  //CircuitPlayground.temperature()量測溫度數值
  Serial.println(" *C");
  delay(100);
}

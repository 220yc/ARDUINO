#include<Wire.h>
#include <Adafruit_MCP4725.h>
Adafruit_MCP4725 da;
float WE = 0;
float RE = 0;
float I = 0;
float END = 0;
int R = 13;
int G = 12;

void setup() {
  da.begin(0x60);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  digitalWrite(R, LOW);
}

void loop() {
  //voltage_cycle(起始電壓,結束電壓,一次電壓停留時間(ms),true=正向;false=逆向)
  voltage_cycle(0, 1200, 100, true);
  voltage_cycle(1199, -1, 100, false);
  if (END > 0.5 && 0 < END) {
    digitalWrite(R, HIGH);
  }
  for (;;);
}


//下面都不用動
void voltage_cycle(int V_start, int V_end, int T, boolean D) {
  if (D == true) {
    for (int i = V_start; i < V_end; i = i + 4) {
      da.setVoltage(i, false);
      WE = 0;
      RE = 0;
      I = 0;
      for (int x = 0; x < 3; x++) {
        WE = WE + analogRead(A0);
        RE = RE + analogRead(A2);
        I = I + analogRead(A1);
      }
      Serial.print((WE - RE) / 3.0 * 5.0 / 1024.0);
      Serial.print(",");
      Serial.println((I) / 3.0 * 5.0 / 1024.0 );
      digitalWrite(G, HIGH);
      delay(T);
      digitalWrite(G, LOW);
      delay(T);
      if (END < I) {
        END = I;
      }
    }
  }
  if (D == false) {
    for (int i = V_start; i > V_end; i = i - 4) {
      da.setVoltage(i, false);
      WE = 0;
      RE = 0;
      I = 0;
      for (int x = 0; x < 3; x++) {
        WE = WE + analogRead(A0);
        RE = RE + analogRead(A2);
        I = I + analogRead(A1);
      }
      Serial.print((WE - RE) / 3.0 * 5.0 / 1024.0);
      Serial.print(",");
      Serial.println((I) / 3.0 * 5.0 / 1024.0 );
      digitalWrite(G, HIGH);
      delay(T);
      digitalWrite(G, LOW);
      delay(T);
      if (END < I) {
        END = I;
      }
    }
  }
}

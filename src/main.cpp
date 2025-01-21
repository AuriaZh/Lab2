#include <Arduino.h>

#define VOUT1_PIN D1  // GPIO27 -> VOUT1 (J2)
#define VOUT2_PIN D2  // GPIO28 -> VOUT2 (J3)

// 参考电压和 ADC 分辨率
const float ADC_REF_VOLTAGE = 3.3;
const int ADC_MAX_VALUE = 4095;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting ADC measurement...");

  // 确保引脚模式正确
  pinMode(VOUT1_PIN, INPUT);
  pinMode(VOUT2_PIN, INPUT);

  // 设置 ADC 分辨率（ESP32 C3 具有 12 位 ADC）
  analogReadResolution(12);  // 12-bit resolution (0-4095)
}

void loop() {
  int adcVOUT1 = analogRead(VOUT1_PIN);
  int adcVOUT2 = analogRead(VOUT2_PIN);

  float voltageVOUT1 = adcVOUT1 * (ADC_REF_VOLTAGE / ADC_MAX_VALUE);
  float voltageVOUT2 = adcVOUT2 * (ADC_REF_VOLTAGE / ADC_MAX_VALUE);

  Serial.print("VOUT1 Voltage: ");
  Serial.print(voltageVOUT1, 2);
  Serial.println(" V");

  Serial.print("VOUT2 Voltage: ");
  Serial.print(voltageVOUT2, 2);
  Serial.println(" V");

  delay(2000);
}

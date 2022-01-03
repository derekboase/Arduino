#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to enable it
#endif 

#define LED_PIN 2
byte BTData;

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin();
  Serial.println("Bluetooth Started! Ready to pair...");
}

void loop() {
  if (Serial.available()){
    SerialBT.write(Serial.read());  
  }
  if (SerialBT.available()){
    Serial.write(SerialBT.read());
  }
  delay(20);
}

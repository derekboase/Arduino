#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to enable it
#endif 

#define LED_PIN 2
byte BTdata;

BluetoothSerial SerialBT;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.begin(115200);
  SerialBT.begin();
  Serial.println("Bluetooth Started! Ready to pair...");
}

void loop() {
  if (SerialBT.available()){
    BTdata = SerialBT.read();
    Serial.write(BTdata);  
  }
  
  if (BTdata == '1'){
    digitalWrite(LED_PIN, HIGH);
  }

  if (BTdata == '0'){
    digitalWrite(LED_PIN, LOW);
  }

  delay(20);
}

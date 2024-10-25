#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int lectura = 0;
float valor = 0.0;
float temp = 0.0;
int pin = 4;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  lectura = analogRead(pin);
  
  if (SerialBT.available()) {
    valor = (SerialBT.read());
    if (valor = 1) {
      temp =  (1.1 * lectura * 100.0)/1024.0;
      SerialBT.print(temp);
      Serial.println (temp);
      delay(1000);
    }
  }
}

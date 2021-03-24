#include <RFClickerLib.h>

BLEService buttonService(BUTTONSVC_UUID);
BLEByteCharacteristic buttonChar(BUTTONCHAR_UUID, BLERead | BLEWrite | BLENotify);
BLEStringCharacteristic menuChar(MENUCHAR_UUID, BLERead | BLENotify, 25);

void RFClickerLibSetup(String name, void onBLEWrite (BLEDevice, BLECharacteristic)) { //char *history) {
  BLE.begin();

  BLE.setDeviceName(name.c_str());
  BLE.setLocalName(name.c_str());
  BLE.setAppearance(APPEARANCE);
  BLE.setAdvertisedService(buttonService);
  buttonService.addCharacteristic(buttonChar);
  buttonService.addCharacteristic(menuChar);
  BLE.addService(buttonService);
  BLE.advertise();
  
  BLE.setEventHandler(BLEConnected, onBLEConnect);
  BLE.setEventHandler(BLEDisconnected, onBLEDisconnect);
  buttonChar.setEventHandler(BLEWritten, onBLEWrite);
  buttonChar.writeValue(0);
  writeMenu("L|D|R|U");
  Serial.println("Bluetooth active");
}

void onBLEConnect(BLEDevice central) {
  Serial.print("connected to ");
  Serial.println(central.address());
  digitalWrite(LED_BUILTIN, HIGH);
}

void onBLEDisconnect(BLEDevice central) {
  Serial.print("disconnected from ");
  Serial.println(central.address());
  digitalWrite(LED_BUILTIN, LOW);
}

void writeMenu(String menu) {
  menuChar.writeValue(menu);
}

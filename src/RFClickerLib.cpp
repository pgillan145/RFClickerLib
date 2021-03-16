/*
#include <RFClickerLib.h>

BLEService buttonService("1101");
BLEByteCharacteristic buttonChar("2101", BLERead | BLEWrite);

void RFClickerSetup() { //char *history) {
  BLE.begin();
  BLE.scanForName("RFClicker");
  //arrayFill(0, history, HISTORY_LENGTH);

  BLE.setDeviceName("DEVICENAME");
  BLE.setLocalName("LOCALNAME");
  BLE.setAdvertisedService(buttonService);
  buttonService.addCharacteristic(buttonChar);
  BLE.addService(buttonService);
  BLE.setEventHandler(BLEConnected, onConnect);
  BLE.setEventHandler(BLEDisconnected, onDisconnect);
  buttonChar.setEventHandler(BLEWritten, RFClickerButtonClick);
  buttonChar.setValue(0);
  BLE.advertise();
  Serial.println("Bluetooth device active, waiting for connections...");
}

void onConnect(BLEDevice central) {
  Serial.print("connected to ");
  Serial.println(central.address());
  digitalWrite(LED_BUILTIN, HIGH);
}

void onDisconnect(BLEDevice central) {
  Serial.print("disconnected from ");
  Serial.println(central.address());
  digitalWrite(LED_BUILTIN, LOW);
}
*/

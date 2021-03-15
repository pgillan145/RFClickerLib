#include <RFClickerLib.h>

//BLEDevice clicker;

BLEDevice clicker;
char ble_history[HISTORY_LENGTH*2];
char temp_ble[HISTORY_LENGTH*2];
uint8_t ble_id = 0;
uint32_t last_scan = 0;

void RFClickerSetup(char *history) {
  BLE.begin();
  BLE.scanForName("RFClicker");
  last_scan = millis();
  arrayFill(0, history, HISTORY_LENGTH);
}

void getClickerHistory(char* history) {
  uint32_t now = millis();
  //Serial.print("free memory:");
  //Serial.println(freeMemory());
  //Serial.print("now:");
  //Serial.println(now);
  //Serial.println("Zeroing out array.");
  arrayFill(0, history, HISTORY_LENGTH);
  //Serial.println("Zeroed out array.");
  if (!clicker.connected()) {
    //Serial.println("Clicker is not connected.");
    //Serial.print("last scan:");
    //Serial.println(last_scan);
    if (last_scan && now > last_scan + 60000) {
        //Serial.println("stopping old scan");
        BLE.stopScan();
        last_scan = 0;
        return;
    }
    else if (last_scan == 0) {
      //Serial.println("starting new scan");
      BLE.scanForName("RFClicker");
      last_scan = now;
      return;
    }

    clicker = BLE.available();
    if (clicker) {
      Serial.print("Found ");
      Serial.print(clicker.address());
      Serial.print(" '");
      Serial.print(clicker.localName());
      Serial.print("' ");
      Serial.print(clicker.advertisedServiceUuid());
      Serial.println();

      if (clicker.localName() == "RFClicker") {
        //Serial.println("found clicker");
        BLE.stopScan();
        last_scan = 0;
        bleConn(clicker);
      }
    }
    else {
      //Serial.println("  done -- nothing.");
      return;
    }
  }

  if (!clicker.connected()) {
    //Serial.println("Clicker is *still* not connected.");
    return;
  }

  //Serial.println("Doing stuff");
  uint8_t ble_pos = 0;
  getBLEValue(clicker, temp_ble, HISTORY_LENGTH*2);
  if (arrayCompare(temp_ble, ble_history, HISTORY_LENGTH*2)) {
    return;
  }
  arrayCopy(temp_ble, ble_history, HISTORY_LENGTH*2);
  for (uint8_t i = 1; i <= HISTORY_LENGTH; i++) {
    uint8_t id = ble_history[(i-1)*2];
    if (id == ble_id) {
      ble_pos = i;
      break;
    }
  }

  if (ble_pos >= HISTORY_LENGTH) {
      return;
  }
  for (uint8_t i = ble_pos + 1; i <= HISTORY_LENGTH; i++) {
    uint8_t id = ble_history[(i-1)*2];
    uint8_t ble_buttons = ble_history[((i-1)*2)+1];
    arrayPush(ble_buttons, history, HISTORY_LENGTH);
    ble_id = id;  
  }
}

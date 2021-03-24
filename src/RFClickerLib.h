/* 
 * Includes
 */
#include <ArduinoBLE.h>

/*
 * Variables & Data Structures
 */

#define HISTORY_LENGTH  10 
#define BUTTONSVC_UUID  "1110"
#define BUTTONCHAR_UUID "1111"
#define MENUCHAR_UUID   "1112"
#define AUDIOSVC_UUID   "2110"
#define VOLUMECHAR_UUID "2111"
#define APPEARANCE      0
#define MENU_DELIM      '|'
#define MENU_MAX_CHARS  5
#define BUTTON1         1
#define BUTTON2         2
#define BUTTON3         4
#define BUTTON4         8
#define BUTTON5         16
#define BUTTON6         32

#define ADDBUTTON(x,y)  x |= y
#define CLRBUTTON(x,y)  x &= ~y
#define TSTBUTTON(x,y)  x & y


/*
 * Functions
 */
void RFClickerLibSetup(String name, void onBLEWrite (BLEDevice, BLECharacteristic));
void writeMenu(String menu);
void onBLEConnect(BLEDevice central);
void onBLEDisconnect(BLEDevice central);


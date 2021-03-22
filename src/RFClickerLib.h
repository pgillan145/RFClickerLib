/* 
 * Includes
 */
//#include <PGardLib.h>
//#include <ArduinoBLE.h>

/*
 * Variables & Data Structures
 */

#define HISTORY_LENGTH  10 
#define BUTTONSVC_UUID  "1110"
#define BUTTONCHAR_UUID "1111"
#define MENUCHAR_UUID   "1112"
#define AUDIOSVC_UUID   "2110"
#define VOLUMECHAR_UUID "2111"
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
BLEDevice clicker;
char ble_history[HISTORY_LENGTH*2];
char temp_ble[HISTORY_LENGTH*2];
uint32_t last_ble = 0;
uint8_t ble_id = 0;
*/
//BLEService buttonService;
//BLECharacteristic buttonChar;


/*
 * Functions
 */
//void getClickerHistory(char* history);
/*
void RFClickerSetup();
void onConnect(BLEDevice central);
void onDisconnect(BLEDevice central);
extern void RFClickerButtonClick(BLEDevice central, BLECharacteristic characteristic);
*/
//BLEService buttonService("1101");
//BLEByteCharacteristic buttonChar("2101", BLERead | BLEWrite);


#pragma once
/* 
 * Includes
 */

#define BLUETOOTH

#include <PGardLib.h>

/*
 * Variables & Data Structures
 */

#define HISTORY_LENGTH  10 
#define BUTTON1(x)      x & 1 << 0
#define BUTTON2(x)      x & 1 << 1
#define BUTTON3(x)      x & 1 << 2
#define BUTTON4(x)      x & 1 << 3

/*
BLEDevice clicker;
char ble_history[HISTORY_LENGTH*2];
char temp_ble[HISTORY_LENGTH*2];
uint32_t last_ble = 0;
uint8_t ble_id = 0;
*/

/*
 * Functions
 */
void getClickerHistory(char* history);
void RFClickerSetup(char *history);


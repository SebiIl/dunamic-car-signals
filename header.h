#ifndef LED_FUNCTIONS_H
#define LED_FUNCTIONS_H
#include <Arduino.h>
#include "data_types.h"

/*defining delay const*/
#define DYNAMIC 95     /*wait time between LED's*/
#define BLINKSHADE 150 /*wait time for on/off states*/
#define LOOPDELAY 100  /*wait time for loop function*/
#define NODELAY 0      /*delay used in function ledState to turn on/off with no delay*/

/*contact simulation*/
#define LEFTBLINKER 13 /*PIN to simulate left signal*/
#define BRAKEPIN 7     /*PIN to simulate brake signal*/
#define RIGHTBLINKER 2 /*PIN to simulate right signal*/

/*brake control PIN*/
#define BRAKE 8

/*right control PIN's*/
#define RIGHTBLINKER_1 3 /*LED 1 right side*/
#define RIGHTBLINKER_2 4 /*LED 2 right side*/
#define RIGHTBLINKER_3 5 /*LED 3 right side*/
#define RIGHTBLINKER_4 6 /*LED 4 right side*/

/*left control PIN's*/
#define LEFTBLINKER_1 9  /*LED 1 left side*/
#define LEFTBLINKER_2 10 /*LED 1 left side*/
#define LEFTBLINKER_3 11 /*LED 1 left side*/
#define LEFTBLINKER_4 12 /*LED 1 left side*/

/*enum to use in switch cases*/
enum Cases
{
   LEFTUNIT = 1,
   RIGHTUNIT,
   BRAKEUNIT,
   EMERGENCYUNIT,
   HAZARDUNIT
};

/*functions prototype*/
void ledSetState(uint8 pinNr, uint8 state, uint8 delayVal);
void blinkerSideSelect(uint8 blinkerSide);
void offLED(uint8 signalSide);
void onLED(uint8 signalOnSide);
void rightTurnInterrupt();

#endif
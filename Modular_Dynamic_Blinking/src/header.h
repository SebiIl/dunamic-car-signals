#ifndef LED_FUNCTIONS_H
#define LED_FUNCTIONS_H
#include <Arduino.h>

// definire Delay
#define DYNAMIC 95      // timp de asteptare aprindere leduri la semnalizare
#define EMBRAKE 100     // timp de asteptare pentru frana
#define BLINKDSHADE 150 // timpul de asteptare intre semnalizari, din momentul in care se sting led-urile si incep iar
#define LOOPDELAY 100   // timpul de asteptare al functiei loop
#define NODELAY 0       // TIMP PENTRU INCHIS LED-URI

// definire contacte
#define LEFTBLINKER 13 // constante pentru simularea de contacte, pentru semnalizare stanga
#define BRAKE 8        // pentru frana
#define RIGHTBLINKER 2 // pentru semnalizare dreapta

// define semnal dreapta
#define RIGHTBLINKER_1 3 // LED 1 partea dreapta    LED-urile se numara de jos in sus
#define RIGHTBLINKER_2 4 // LED 2 partea dreapta
#define RIGHTBLINKER_3 5 // LED 3 partea dreapta
#define RIGHTBLINKER_4 6 // LED 4 partea dreapta

// definire semnal stanga
#define LEFTBLINKER_1 9  // LED 1 partea stanga     LED-urile se numara de jos in sus
#define LEFTBLINKER_2 10 // LED 1 partea stanga
#define LEFTBLINKER_3 11 // LED 1 partea stanga
#define LEFTBLINKER_4 12 // LED 1 partea stanga

// definire frana
#define BRAKEPIN 7 // LED-ul utilizat pentru frana

void ledCommand(int pinNr, int state, int delayVal); 
//void readPin(int pinNr);
void signalState(int blinkerSide);
void offLED(int signalSide); 
void onLED(int signalOnSide); 


#endif
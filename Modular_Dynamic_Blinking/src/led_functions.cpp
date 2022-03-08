#include "header.h"

int blinkerArr[2][4] = {{LEFTBLINKER_1, LEFTBLINKER_2, LEFTBLINKER_3, LEFTBLINKER_4},
                        {RIGHTBLINKER_1, RIGHTBLINKER_2, RIGHTBLINKER_3, RIGHTBLINKER_4}};

// functii de comanda LED-uri:
// functie ce scrie stari pe pini
void ledCommand(int pinNr, int state, int delayVal)
{
  digitalWrite(pinNr, state);
  delay(delayVal);
}

/*
 * Function used to .. de completat
 * Input:
 * Outout:
 */
void signalState(int blinkerSide)
{
  for (int i = 0; i < 4; i++)
  {
    ledCommand(blinkerArr[blinkerSide][i], HIGH, DYNAMIC);
  }

  for (int i = 0; i < 4; i++)
  {
    ledCommand(blinkerArr[blinkerSide][i], LOW, NODELAY);
  }

  delay(BLINKDSHADE);
}

void offLED(int signalSide)
{
  for (int i = 0; i < 4; i++)
  {
    ledCommand(blinkerArr[signalSide][i], LOW, NODELAY);
  }
}

void onLED(int signalOnSide)
{
  int secondRowOn = 1;
  for (int i = 0; i < 4; i++)
  {
    ledCommand(blinkerArr[signalOnSide][i], HIGH, NODELAY);
    ledCommand(blinkerArr[secondRowOn][i], HIGH, NODELAY);
    delay(DYNAMIC);
  }
}
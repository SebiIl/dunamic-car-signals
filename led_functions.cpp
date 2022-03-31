#include "header.h"
#include "data_types.h"

uint16 blinkerArr[2][4] = {{LEFTBLINKER_1, LEFTBLINKER_2, LEFTBLINKER_3, LEFTBLINKER_4},
                           {RIGHTBLINKER_1, RIGHTBLINKER_2, RIGHTBLINKER_3, RIGHTBLINKER_4}};

uint32 rightTurnONTime = 0;
uint32 rightTurnOFFTime = 0;
uint32 rightTurnTimeDifference = 0;

/*
 * Function replace digital write and apply delay to certain pins
 * Input: it has the number of the pin which has to be switched and the state in which has to go
 * Outout: as output it gives nothing since it's a void type
 */
void ledSetState(uint8 pinNr, uint8 state, uint8 delayVal)
{
  digitalWrite(pinNr, state);
  delay(delayVal);
}

/*
 * Function used to automatically select which side of the blinker is used
 * Input: as input it has either left or right side of the blinker
 * Outout: as output it gives nothing since it's a void type
 */
void blinkerSideSelect(uint8 blinkerSide)
{
  uint8 i = 0;

  for (i = 0; i < 4; i++)
  {
    ledSetState(blinkerArr[blinkerSide][i], HIGH, DYNAMIC);
  }

  for (i = 0; i < 4; i++)
  {
    ledSetState(blinkerArr[blinkerSide][i], LOW, NODELAY);
  }

  delay(BLINKSHADE);
}

/*
 * Function used to switch off LED's
 * Input: as input it has the side of the unnit in which the change has to happen
 * Outout: as output it gives nothing since it's a void type
 */
void offLED(uint8 signalSide)
{
  uint8 i = 0;
  for (i = 0; i < 4; i++)
  {
    ledSetState(blinkerArr[signalSide][i], LOW, NODELAY);
  }
}

/*
 * Function used to switch on LED's
 * Input: as input it has the side of the unnit in which the change has to happen
 * Outout: as output it gives nothing since it's a void type
 */
void onLED(uint8 signalOnSide)
{
  uint8 secondRowOn = 1;
  uint8 i = 0;
  for (i = 0; i < 4; i++)
  {
    ledSetState(blinkerArr[signalOnSide][i], HIGH, NODELAY);
    ledSetState(blinkerArr[secondRowOn][i], HIGH, NODELAY);
    delay(DYNAMIC);
  }
}

/*
 * Function used to switch on LED's 3 times if the turn signal is pressed for ledd than 1 sec
 * and if pressed to blink until not pressed anymore
 * Input: 
 * Outout: 
 * Still in work. 
 */
void rightTurnInterrupt()
{
  int rightTurnRead = 0; 

  rightTurnRead = digitalRead(RIGHTBLINKER); 

  if (rightTurnRead == HIGH)
  {
    rightTurnONTime = millis();
    Serial.println(digitalRead(RIGHTBLINKER));
  }
  else if (rightTurnRead == LOW)
  {
    rightTurnOFFTime = millis();
    rightTurnTimeDifference = rightTurnOFFTime - rightTurnONTime;

    Serial.print("Difference time = ");
    Serial.println(rightTurnTimeDifference);
  }
}
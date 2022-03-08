#include <Arduino.h>
#include "header.h"

/*
 * Varibles Area
 */

// setare variabile pentru pinii de input
// in aceste var. vom memora starea contactelor pe parcursul programului
int leftBlinkerVal = 0;
int brakeVal = 0;
int rightBlinkerVal = 0;

// variabile switch
int switchIn;

/*
 * End of variables area
 */

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  // setare pini se semnal ca INPUT
  pinMode(LEFTBLINKER, INPUT);
  pinMode(BRAKE, INPUT);
  pinMode(RIGHTBLINKER, INPUT);

  // setare pini ca OUTPUT semnal stanga
  pinMode(LEFTBLINKER_1, OUTPUT);
  pinMode(LEFTBLINKER_2, OUTPUT);
  pinMode(LEFTBLINKER_3, OUTPUT);
  pinMode(LEFTBLINKER_4, OUTPUT);

  // setare pin frana
  pinMode(BRAKEPIN, OUTPUT);

  // setare pini dreapta
  pinMode(RIGHTBLINKER_1, OUTPUT);
  pinMode(RIGHTBLINKER_2, OUTPUT);
  pinMode(RIGHTBLINKER_3, OUTPUT);
  pinMode(RIGHTBLINKER_4, OUTPUT);
}

void loop()
{
  // resetare pini pe 0
  if (brakeVal == LOW)
  {
    ledCommand(BRAKEPIN, LOW, NODELAY);
  }
  offLED(0);
  offLED(1); 
  delay(BLINKDSHADE);

  // aprindere LED uri in functie de semnalul primit
  leftBlinkerVal = digitalRead(LEFTBLINKER);   // asignare variabilei left blinker inputul de la pinul digital de read
  brakeVal = digitalRead(BRAKE);               // la fel ca sus, numai ca pentru frana
  rightBlinkerVal = digitalRead(RIGHTBLINKER); // la fel, dar pentru partea dreapta

  // verificare pentru hazard si frana de urgenta
  if ((brakeVal == HIGH) && (leftBlinkerVal == HIGH) && (rightBlinkerVal == HIGH))
  {
    Serial.println("We are in case 4!");
    switchIn = 4;
  }
  // verificare pentru hazard
  else if ((leftBlinkerVal == HIGH) && (rightBlinkerVal == HIGH) && (brakeVal == LOW))
  {
    switchIn = 5;
    Serial.println("We are in case 5!");
  }
  // verificam daca este circuitul inchis si setavariabila pe 1
  else if (leftBlinkerVal == HIGH)
  {
    switchIn = 1;
  }
  // verificam circuitul pentru dreapta
  else if (rightBlinkerVal == HIGH)
  {
    switchIn = 2;
  }
  // verificam circuitul pentru frana
  else if (brakeVal == HIGH)
  {
    switchIn = 3;
  }

  switch (switchIn)
  {
  // pentru partea stanga
  case 1:
    signalState(0); // 0 reprezinta prima linie din matrice
    delay(BLINKDSHADE);
    break;

  // pentru partea dreapta
  case 2:
    signalState(1); // 1 reprezinta linia 2 din matrice
    delay(BLINKDSHADE);
    break;

  // pentru frana
  case 3:
    digitalWrite(BRAKEPIN, brakeVal); //brake pin ON 
    break;

  // pentru hazard si frana intermitenta
  case 4:
    onLED(0); // turn on led's with onLED function
    digitalWrite(BRAKEPIN, HIGH); // brake light ON
    delay(BLINKDSHADE); // delay set between HIGH&LOW
    break;

  // pentru hazard
  case 5:
    onLED(0);// turn on led's with onLED function
    delay(BLINKDSHADE);// delay set between HIGH&LOW   
    break;

  default:
    Serial.println("Default case, nothing happens!");
  }

  switchIn = 0; //switch var reset to avoid infinite loop in same case

  delay(LOOPDELAY);
}
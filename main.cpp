/**
 ********************************************************************************
 * @file    ${Modular_Dynamic_Blinking}
 * @author  ${Ilienescu Sebastian}
 * @date    ${08.03.2022}
 * @brief	The scope of the project is to simulate different dynamic light modes
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <Arduino.h>
#include "header.h"
#include "data_types.h"

/************************************
 * GLOBAL VARIABLES
 ************************************/
/**
 * variables for passing the values from READ pins
 */
uint8 leftBlinkerVal = 0;
uint8 brakeVal = 0;
uint8 rightBlinkerVal = 0;

/************************************
 * SETUP
 ************************************/
void setup()
{
	Serial.begin(9600);
	// set pins as INPUT
	pinMode(LEFTBLINKER, INPUT);
	pinMode(BRAKE, INPUT);
	pinMode(RIGHTBLINKER, INPUT);
	attachInterrupt(digitalPinToInterrupt(RIGHTBLINKER), rightTurnInterrupt, CHANGE);

	// set pins as OUTPUT for LEFT side of the unit
	pinMode(LEFTBLINKER_1, OUTPUT);
	pinMode(LEFTBLINKER_2, OUTPUT);
	pinMode(LEFTBLINKER_3, OUTPUT);
	pinMode(LEFTBLINKER_4, OUTPUT);

	// set pin as OUTPUT for BRAKE
	pinMode(BRAKEPIN, OUTPUT);

	// set pins as OUTPUT for RIGHT side of the unit
	pinMode(RIGHTBLINKER_1, OUTPUT);
	pinMode(RIGHTBLINKER_2, OUTPUT);
	pinMode(RIGHTBLINKER_3, OUTPUT);
	pinMode(RIGHTBLINKER_4, OUTPUT);
}

/************************************
 * MAIN Loop
 ************************************/
void loop()
{
	/**
	 * variables for switch statement
	 * emergencyUnit = hazard light + brake
	 */
	uint8 switchIn;

	/*make sure that all pins are set on 0*/
	if (brakeVal == LOW)
	{
		ledSetState(BRAKEPIN, LOW, NODELAY);
	}
	offLED(0);
	offLED(1);
	delay(BLINKSHADE);

	leftBlinkerVal = digitalRead(LEFTBLINKER);	/*assign value READ from PIN 13*/
	brakeVal = digitalRead(BRAKE);					/*assign value READ from PIN 8*/
	rightBlinkerVal = digitalRead(RIGHTBLINKER); /*assign value READ from PIN 2*/

	

	/*if all conditions are met, HAZARD lighs and brakes will be ON*/
	if ((brakeVal == HIGH) && (leftBlinkerVal == HIGH) && (rightBlinkerVal == HIGH))
	{
		Serial.println("We are in case 4!");
		switchIn = EMERGENCYUNIT;
	}
	/*if all conditions are met, HAZARD lighs will be ON*/
	else if ((leftBlinkerVal == HIGH) && (rightBlinkerVal == HIGH) && (brakeVal == LOW))
	{
		switchIn = HAZARDUNIT;
		Serial.println("We are in case 5!");
	}
	/*if this condition is met, the LEFT blinker will be ON*/
	else if (leftBlinkerVal == HIGH)
	{
		switchIn = LEFTUNIT;
	}
	/*if this condition is met, the RIGHT blinker will be ON*/
	else if (rightBlinkerVal == HIGH)
	{
		switchIn = RIGHTUNIT;
	}
	/*if this condition is met, the brake will be ON*/
	else if (brakeVal == HIGH)
	{
		switchIn = BRAKEUNIT;
	}

	switch (switchIn)
	{
	/*case for LEFT blinker*/
	case LEFTUNIT:
		blinkerSideSelect(0); /*Argument 0 represents the index for blinkerArr variable*/
		delay(BLINKSHADE);
		break;

	/*case for RIGHT blinker*/
	case RIGHTUNIT:
		blinkerSideSelect(1); /*Argument 1 represents the index for blinkerArr variable*/
		delay(BLINKSHADE);
		break;

	/*case for BRAKE*/
	case BRAKEUNIT:
		digitalWrite(BRAKEPIN, brakeVal); /*brake pin ON*/
		break;

	/*case for HAZARD lights and brake*/
	case EMERGENCYUNIT:
		onLED(0);							/*turn on led's with onLED function*/
		digitalWrite(BRAKEPIN, HIGH); /*brake light ON*/
		delay(BLINKSHADE);				/*delay set between HIGH&LOW*/
		break;

	/*case for HAZARD lights*/
	case HAZARDUNIT:
		onLED(0);			 /*turn on led's with onLED function*/
		delay(BLINKSHADE); /*delay set between HIGH&LOW*/
		break;

	default:
		//Serial.println("Default case, nothing happens!");
		break;
	}

	switchIn = 0; /*switch var reset to avoid infinite loop stucked in a random case*/

	delay(LOOPDELAY);
}
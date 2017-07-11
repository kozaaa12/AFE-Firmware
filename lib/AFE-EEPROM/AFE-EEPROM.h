/*
   EEPROM component
   AFE Firmware for smart home devices build on ESP8266
   More info: https://github.com/tschaban/AFE-Firmware
   LICENCE: http://opensource.org/licenses/MIT
 */

#ifndef _AFE_EEPROM_h
#define _AFE_EEPROM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include <EEPROM.h>

#define EEPROM_SIZE 512

class AFEEEPROM
{
private:

public:
AFEEEPROM();

/* it stories String in EEPROM starting from position of input parameter size */
void write(uint16_t address, uint16_t size, uint8_t in);
void write(uint16_t address, uint16_t size, String in);
void write(uint16_t address, uint16_t size, long in);
void write(uint16_t address, uint16_t size, float in);
void write(uint16_t address, boolean in);

/* Returns string from EEPORM starting from position of input parameter address of length defined by input parameter size */
String  read(uint16_t address, uint16_t size);
boolean read(uint16_t address);
char readByte(uint16_t address);

/* It clears EEPROM from position starting from address and size long
 */
void clear(uint16_t address, uint16_t size);

/* It erase entire EEPROM */
void erase();

};
#endif
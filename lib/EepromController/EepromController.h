#ifndef EepromController_h
#define EepromController_h

#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "pins_arduino.h"
	#include "WConstants.h"
#endif
#include <EEPROM.h>
#include <Enums.h>


class EepromController {
	
	void initSettings();

	public:
		EepromController();

		void init();

		void setPower(bool power);
		void setColor1(uint32_t color);
		void setColor2(uint32_t color);
		void setMode(uint8_t m);
		void setSetting(Settings s, uint8_t v);
		
		bool isSideSet();

		bool getPower();
		uint32_t getColor1();
		uint32_t getColor2();
		
		uint8_t getMode();
		uint8_t getSetting(Settings s);
};

#endif
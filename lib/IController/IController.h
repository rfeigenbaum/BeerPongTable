#ifndef Controller_h
#define Controller_h

#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "pins_arduino.h"
	#include "WConstants.h"
#endif

class SerialController;

class Controller {
	virtual void checkSerial() = 0;
	
	public:
		virtual void run();

		virtual void setMode(uint8_t m) = 0;
		virtual void setColor1(uint32_t color) = 0;
		virtual void setColor2(uint32_t color) = 0;
		virtual void setSetting(uint8_t s, uint8_t v) = 0;

		virtual void setScore1(uint8_t s) = 0;
		virtual void setScore2(uint8_t s) = 0;
};

#endif
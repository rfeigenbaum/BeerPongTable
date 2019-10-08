#include <SerialController.h>
#include <IController.h>
#include <EepromController.h>
#include <Enums.h>
#include <Arduino.h>
#include <FastLED.h>
#include <stdint.h>
#include "Rings.h"

class RingController : public Controller
{
	CRGB *_leds;
	CFastLED *_controller;
	Rings _rings;
	SerialController *_serial;
	EepromController _eeprom;

	uint8_t side = 1;
	CRGB color1, color2;

	//Private Methods
	void runScore();
	void checkSerial();
	void initSettings();

  public:
	RingController(CFastLED *controller, CRGB *leds, uint8_t m = 0, uint8_t ledsPerRing = 24, uint8_t numRings = 10);

	void run();

	void setMode(uint8_t m);
	void setSetting(uint8_t s, uint8_t v);
	void setColor1(uint32_t color);
	void setColor2(uint32_t color);
	void setColor1(CRGB color);
	void setColor2(CRGB color);

	void setScore1(uint8_t s);
	void setScore2(uint8_t s);
};
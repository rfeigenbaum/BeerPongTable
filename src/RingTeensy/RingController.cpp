#include "RingController.h"

RingController::RingController(CFastLED *controller, CRGB *leds, uint8_t m, uint8_t ledsPerRing, uint8_t numRings)
    : _rings(), _eeprom()
{
    _serial = new SerialController(&Serial1, this);
    _leds = leds;
    _controller = controller;
	_rings.init(controller, leds);

    _eeprom.init();
	_rings.setMode(_eeprom.getMode());
	_rings.setColor1(CRGB(_eeprom.getColor1()));
	_rings.setColor2(CRGB(_eeprom.getColor2()));
	
}

/* Interface Methods */
void RingController::run()
{
	runScore();
	checkSerial();
}

void RingController::checkSerial()
{
	_serial->checkSerial();
}

void RingController::setMode(uint8_t m)
{
	#if DEBUG == TRUE
		Serial.println(m);
	#endif
	_rings.setMode(m);
	_eeprom.setMode(m);
	_controller->show();
}
void RingController::setSetting(uint8_t s, uint8_t v)
{
	switch ((Settings)s)
	{
	case Settings::Brightness:
		FastLED.setBrightness(v);
		break;
	}
	_eeprom.setSetting((Settings) s, v);
	_controller->show();
}
void RingController::setColor1(uint32_t color)
{
	#if DEBUG == TRUE
		Serial.println(color);
	#endif
	color1 = CRGB(color);
	_rings.setColor1(color);
	_eeprom.setColor1(color);
	_controller->show();
}
void RingController::setColor2(uint32_t color)
{
	#if DEBUG == TRUE
		Serial.println(color);
	#endif
	color2 = CRGB(color);
	_rings.setColor2(color);
	_eeprom.setColor2(color);
	_controller->show();
}
void RingController::setColor1(CRGB color)
{
	color1 = color;
	_rings.setColor1(color);
}
void RingController::setColor2(CRGB color)
{
	color2 = color;
	_rings.setColor2(color);
}

void RingController::setScore1(uint8_t s) {}
void RingController::setScore2(uint8_t s) {}

/* Private Methods */
void RingController::runScore()
{
	if (_rings.isScoreDifferent())
	{
		_serial->sendScore(_rings.getScore());
	}
}

#ifndef Application_h
#define Application_h

#include <FastLED.h>
#include <Enums.h>
#include <MatrixHelpers.h>

class Application {
    uint8_t AppTypeId;
    bool hasChanged;
	CRGB *leds;
  public:
    Application(){}

	virtual void init() = 0;
	virtual void drawFrame() = 0;

	virtual uint8_t getAppTypeId() = 0;
	virtual uint32_t getValue(uint8_t valueTypeId) = 0;

	virtual void changeValue(uint8_t valueTypeId, uint32_t value) = 0;
	virtual void setMatrixOutputArray(CRGB *matrix) = 0;
};

#endif
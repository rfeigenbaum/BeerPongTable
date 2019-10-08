#ifndef HelperFunctions_h
#define HelperFunctions_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif
#include <Enums.h>


namespace ColorFunctions
{
	void HexToRgb(uint32_t color, uint8_t rgb[3]);
	uint32_t RgbToHex(uint8_t rgb[3]);
	uint32_t RgbToHex(uint8_t r, uint8_t g, uint8_t b);
} // namespace ColorFunctions

#endif
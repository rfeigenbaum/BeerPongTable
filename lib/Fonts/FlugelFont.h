#ifndef FlugelFont_h
#define FlugelFont_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif

#include <FastLED.h>
#include "FontHelpers.h"
#include <MatrixHelpers.h>

namespace LegacyFonts
{
    class FlugelFont {
		static const int8_t characterHeight = 8;
		static const int8_t characterWidth = -1; //Dynamic
		public: 
            static uint8_t Font[96][6];
			static int8_t getCharacterHeight();
        	static int8_t getCharacterWidth();
            static int8_t getCharacterWidth(char c);
            static void printCharacter(CRGB *leds, CRGB color, int x, int y, char c);
	};
}

#endif
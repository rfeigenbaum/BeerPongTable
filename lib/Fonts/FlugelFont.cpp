#include "FlugelFont.h"


namespace LegacyFonts
{
    int8_t FlugelFont::getCharacterHeight() {
        return characterHeight;
	}
	int8_t FlugelFont::getCharacterWidth() {
		return characterWidth;
	}
	int8_t FlugelFont::getCharacterWidth(char c) {
		return 5;
	}
	void FlugelFont::printCharacter(CRGB *leds, CRGB color, int x, int y, char c) {
        
	}
} // LegacyFonts

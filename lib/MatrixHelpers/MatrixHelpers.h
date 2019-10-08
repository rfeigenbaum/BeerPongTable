#ifndef MatrixHelpers_h
#define MatrixHelpers_h

#include <FastLED.h>

namespace MatrixHelpers {
    int xy(uint8_t x, uint8_t y);
    void BlankSection(CRGB * matrix, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
}

namespace MatrixShapes
{
	void DrawBox(CRGB* matrix, CRGB color, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool fill = false);
} // MatrixShapes

#endif
#include "MatrixHelpers.h"


namespace MatrixHelpers {
    int xy(uint8_t x, uint8_t y) {
        if ((y & 1) == 0) {
            return y * LED_WIDTH + x;
        } else {
            return y * LED_WIDTH + LED_WIDTH - 1 - x;
        }
    }

    void BlankSection(CRGB * matrix, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
        for(uint8_t x = x1; x < x2; x++) {
            for(uint8_t y = y1; y < y2; y++) {
                matrix[xy(x,y)] = CRGB::Black;
            }
        }
    }
}

namespace MatrixShapes
{
	void DrawBox(CRGB* matrix, CRGB color, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool fill) {
        for(uint8_t x = x1; x <= x2; x++) {
            matrix[MatrixHelpers::xy(x, y1)] = color;
            matrix[MatrixHelpers::xy(x, y2)] = color;
        }
        for(uint8_t y = y1; y <= y2; y++) {
            matrix[MatrixHelpers::xy(x1, y)] = color;
            matrix[MatrixHelpers::xy(x2, y)] = color;
        }
        if(fill == true && (x2-x1 > 1 && y2-y1 > 1)) {
            DrawBox(matrix, color, x1+1, y1+1, x2-1, y2-1, fill);
        }
    }
} // MatrixShapes


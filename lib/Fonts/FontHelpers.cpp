#include "FontHelpers.h"

namespace FontHelpers
{
    bool getBit(unsigned char byte, int position) 
    {
        return (byte >> position) & 0x1;
    }
    uint8_t getNumDigits(int8_t num) {
        uint8_t digits = 0;
        while (num)
        {
            num /= 10;
            digits++;
        }
        return digits;
    }
}

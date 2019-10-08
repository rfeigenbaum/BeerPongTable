#ifndef FontHelpers_h
#define FontHelpers_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif
#include <Enums.h>
#include <FastLED.h>
#include "MatrixHelpers.h"


namespace FontHelpers
{

    bool getBit(unsigned char byte, int position);
    uint8_t getNumDigits(int8_t num);
}

#endif
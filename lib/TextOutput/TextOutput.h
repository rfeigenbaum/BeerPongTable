#ifndef TextOutput_h
#define TextOutput_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif

#include <FastLED.h>

#include <FlugelFont.h>
#include <LargeFont.h>

namespace TextOutput {
    namespace {
        template<class T>
        uint16_t getStringPixelLength(char * str) {
            uint8_t size = strlen(str);
            uint8_t length = 0;
            for(int i = 0; i < size; i++) {
                length += T::getCharacterWidth(str[i]);
            }
            return length;
        }
    }

    template<class T = LegacyFonts::LargeFont>
    void displayNumber(CRGB * leds, int num, int x, int y, CRGB color) {
        int digits = num == 0 ? 1 : FontHelpers::getNumDigits(num);
        int digitWidth = T::getCharacterWidth();
        for (int i = 0; i < digits; i++)
        {
            int digit = num / (int)pow(10, (digits-i-1)) % 10;
            char cDigit = '0' + digit;

            T::printCharacter(leds, color, x, y, cDigit); 
            x += (digitWidth == -1) ? T::getCharacterWidth(cDigit) : digitWidth;
        }
    }
    template<class T = LegacyFonts::LargeFont>
    void centerNumberInBox(CRGB * leds, int num, int x1, int y1, int x2, int y2, CRGB color) {
        int nDigits = num == 0 ? 1 : FontHelpers::getNumDigits(num);
        int digitWidth = T::getCharacterWidth();

        int baseY = (y2 - y1)/2.0 - T::getCharacterHeight()/2;
        int startX = (x2-x1)/2.0 + x1 - nDigits*digitWidth/2.0;
        if(digitWidth == -1) {
            char digits[nDigits];
            itoa(num, digits, 10);
            Serial.println(digits);
            startX = (x2-x1)/2.0 + x1 - getStringPixelLength<T>(digits)/2.0;
        }

        for (int i = 0; i < nDigits; i++)
        {
            int digit = num / (int)pow(10, (nDigits-i-1)) % 10;
            char cDigit = '0' + digit;
            T::printCharacter(leds, color, startX, baseY, cDigit); 
            startX += (digitWidth == -1) ? T::getCharacterWidth(cDigit) : digitWidth;
        }
    }
}

#endif
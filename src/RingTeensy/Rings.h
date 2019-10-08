#include <vector>
#include <Enums.h>
#include "Ring.h"

#ifndef Rings_h
#define Rings_h


class Rings {
  std::vector<Ring> _rings;

  CFastLED * controller;
  uint8_t prevScore;

  CRGB color1, color2;
  
  public: 
    Rings();

    void init(CFastLED * c, CRGB * leds, uint8_t ledsPerRing = 24);
    
    bool isScoreDifferent();
    uint8_t getScore();
    uint8_t runSensorSensitiveRings();

    void setColors(CRGB c1, CRGB c2);
    void setColor1(CRGB c1);
    void setColor2(CRGB c2);
    void setMode(uint8_t m);
    
};
#endif

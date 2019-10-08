#include "Sensor.h"
#include "Enums.h"
#include <FastLED.h>

#ifndef  Ring_h
#define  Ring_h

class Ring {
  CRGB * _leds;

  //Core Info
  uint8_t ringNumber, numLeds; 
  uint16_t ringStartIndex, ringEndIndex;
  Sensor sensor;
  bool cupDetected;

  //Colors
  CRGB color1Rgb, color2Rgb;
  CHSV color1, color2;
 
  //Animation Variables
  uint8_t frameRate, effectMode;
  uint16_t currentFrame, updateRandomsOnFrames;
  long previousMillis = 0;
  long interval;  

  //Setting Flags
  bool flipped = false;

  void glow(CHSV color);
  void alternate(CHSV color);
  void colorGlows(CHSV color);
  
  CHSV getEffectiveColor1();
  CHSV getEffectiveColor2();

  public:
    Ring(CRGB * led, uint8_t ringIndex, uint8_t mode = (uint8_t)RingModes::Solid, uint8_t num_leds = 24);

    void setColors(CRGB c1, CRGB c2);
    void setColor1(CRGB c1);
    void setColor2(CRGB c2);
    void setMode(RingModes mode);
    void flipRings();

    bool run(bool update = false);
    bool sensorIsTripped();
    bool sensorHasChanged();
 };

 #endif

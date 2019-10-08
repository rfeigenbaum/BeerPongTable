#define USE_OCTOWS2811
#include <OctoWS2811.h>
#include <FastLED.h>

#define NUM_LEDS_PER_STRIP 240
#define NUM_STRIPS 8
#include "MatrixController.h"


CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];

MatrixController controller;
//SerialController serialController(&Serial, &controller);

// Pin layouts on the teensy 3:
// OctoWS2811: 2,14,7,8,6,20,21,5

void setup() {
  LEDS.addLeds<OCTOWS2811>(leds, NUM_LEDS_PER_STRIP);
  LEDS.setBrightness(32);
  Serial.begin(9600);

  controller.init(&LEDS, leds);
  LEDS.show();
  //controller.setSerial(&serialController);
}

void loop() {
  controller.run();
}
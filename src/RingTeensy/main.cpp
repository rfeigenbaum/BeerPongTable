#include <Arduino.h>
#include <FastLED.h>
#include "RingController.h"

#define NUM_LEDS 240
#define DATA_PIN 2

CRGB leds[NUM_LEDS];

RingController controller(&LEDS, leds);

void setup()
{
	int total = 0;
	for (int i = A0; i <= A9; i++)
	{
		total += analogRead(i);
	}
	randomSeed(total);

	Serial.begin(9600);
	FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
	FastLED.setBrightness(160);
	FastLED.show();
}

void loop()
{
	controller.run();
}
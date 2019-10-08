#include "Ring.h"

Ring::Ring(CRGB * led, uint8_t ringIndex, uint8_t mode, uint8_t num_leds) : sensor(ringIndex)
{
	_leds = led;
	ringNumber = ringIndex;
	numLeds = num_leds;
	effectMode = mode;

	ringStartIndex = ringNumber * numLeds;
	ringEndIndex = ringStartIndex + numLeds;

	currentFrame = random(0, 1000);
	interval = random(10, 25);
	updateRandomsOnFrames = random(1000);
	cupDetected = false;
}

#pragma region [Setters]
void Ring::setColors(CRGB c1, CRGB c2)
{
	setColor1(c1);
	setColor2(c2);
}
void Ring::setColor1(CRGB c1)
{
	color1Rgb = c1;
	color1 = rgb2hsv_approximate(c1);
}
void Ring::setColor2(CRGB c2)
{
	color2Rgb = c2;
	color2 = rgb2hsv_approximate(c2);
}
void Ring::setMode(RingModes mode)
{
	switch (mode)
	{
	case RingModes::Solid:
		break;
	case RingModes::Glow:
	case RingModes::ColorGlows:
		interval = random(5, 15);
		break;
	case RingModes::Alternate:
		interval = random(65, 95);
		break;
	}
	effectMode = (uint8_t)mode;
}

void Ring::flipRings() {
	flipped = !flipped;
}
#pragma endregion

bool Ring::sensorIsTripped()
{
	return sensor.checkSensorDetection();
}
bool Ring::sensorHasChanged()
{
	return sensor.checkForSensorChange();
}

bool Ring::run(bool update)
{
	long currentMillis = millis();

	if (((RingModes)effectMode != RingModes::Solid && (currentMillis - previousMillis) > interval) || (RingModes)effectMode == RingModes::Solid || update)
	{
		CHSV color = sensor.checkSensorDetection() ? getEffectiveColor1() : getEffectiveColor2();
		
		if((RingModes)effectMode != RingModes::Solid) {
			previousMillis = currentMillis;
			currentFrame++;
		}

		switch ((RingModes)effectMode)
		{
		case RingModes::Solid:
			if(_leds[ringStartIndex] != color || _leds[ringStartIndex+1] != color )
				fill_solid(&(_leds[ringStartIndex]), numLeds, color);
			break;
		case RingModes::Glow:
			glow(color);
			break;
		case RingModes::Alternate:
			alternate(color);
			break;
		case RingModes::ColorGlows:
			colorGlows(color);
			break;
		}
		return true;
	}
	return false;
}

/* Animation Functions */
void Ring::glow(CHSV color)
{
	uint8_t range = 210;
	uint8_t lowerBound = 15;
	uint8_t scaleFactor = 250;
	if ((currentFrame / range) % 2 == 0)
	{
		scaleFactor = lowerBound + currentFrame % range;
	}
	else
	{
		scaleFactor = lowerBound + range - currentFrame % range;
	}
	if (currentFrame / range == 2)
	{
		currentFrame = 0;
	}
	fill_solid(&(_leds[ringStartIndex]), numLeds, CRGB(color).nscale8(scaleFactor));
}
void Ring::alternate(CHSV color)
{
	CHSV color2 = color;
	color.h -= 50;
	color2.h += 50;

	bool alternateFromFrame = currentFrame % 2 == 0;

	for (uint16_t i = ringStartIndex; i < ringEndIndex; i++)
	{
		if ((i % 2 == 0 && alternateFromFrame) || (i % 2 != 0 && !alternateFromFrame))
		{
			_leds[i] = color;
		}
		else
		{
			_leds[i] = color2;
		}
	}
	if (currentFrame % 3 == 0)
	{
		currentFrame = 0;
	}
}
void Ring::colorGlows(CHSV color)
{
	uint8_t range = 30;
	uint8_t hue = color.h;
	if ((currentFrame / range) % 2 == 0)
	{
		hue = color.h + (currentFrame % range) - (range / 2);
	}
	else
	{
		hue = color.h - (currentFrame % range) + (range / 2);
	}
	if (currentFrame / range == 2)
	{
		currentFrame = 0;
	}
	color.h = hue;
	fill_solid(&(_leds[ringStartIndex]), numLeds, color);
}

#pragma region [PrivateMethods]

CHSV Ring::getEffectiveColor1()
{
	if ((DeviceType)DEVICE == DeviceType::LeftRingTeensy && !flipped)
	{
		return color1;
	}
	else
	{
		return color2;
	}
}
CHSV Ring::getEffectiveColor2()
{
	if ((DeviceType)DEVICE == DeviceType::LeftRingTeensy && !flipped)
	{
		return color2;
	}
	else
	{
		return color1;
	}
}
#pragma endregion
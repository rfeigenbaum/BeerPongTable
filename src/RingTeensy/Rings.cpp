#include "Rings.h"

Rings::Rings() {}

void Rings::init(CFastLED * c, CRGB * leds, uint8_t ledsPerRing) {
	controller = c;
	for(int i = 0; i < 10; i++) {
		_rings.push_back(Ring(leds, i) );
	}

	prevScore = 10;
}

void Rings::setColors(CRGB c1, CRGB c2) {
	setColor1(c1);
	setColor2(c2);
}
void Rings::setColor1(CRGB c1) {
	color1 = c1;
	for(std::size_t i = 0; i < _rings.size(); i++) {
		_rings[i].setColor1(c1);
		_rings[i].run(true);
	}
}
void Rings::setColor2(CRGB c2) {
	color2 = c2;
	for(std::size_t i = 0; i < _rings.size(); i++) {
		_rings[i].setColor2(c2);
		_rings[i].run(true);
	}
}
void Rings::setMode(uint8_t m) {
	for(std::size_t i = 0; i < _rings.size(); i++) {
		_rings[i].setMode((RingModes)m);
		_rings[i].run(true);
	}
}


bool Rings::isScoreDifferent() {
	uint8_t score = runSensorSensitiveRings();
	if(prevScore != score) {
		prevScore = score;
		return true;
	}
	return false;
}
uint8_t Rings::getScore() {
	return runSensorSensitiveRings();
}

uint8_t Rings::runSensorSensitiveRings() {
	uint8_t sum = 0;
	bool update = false;
	for(uint8_t i = 0; i < _rings.size(); i++) {
		if(_rings[i].sensorIsTripped()) {
			sum++;
		}
		update |= _rings[i].run();
		/*else {
			update |= _rings[i].run();
		}*/
		
	}
	if(update) {
		controller->show();
	}
	return sum;
}

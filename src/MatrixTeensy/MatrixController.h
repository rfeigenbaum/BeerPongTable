#include <Arduino.h>
#include <FastLED.h>
#include <stdint.h>

#include <IController.h>

class SerialController;

#include "SerialController.h"
#include "ApplicationManager.h"
#include "ScoreBoard/ScoreBoard.h"

class MatrixController : public Controller
{
	CRGB *_leds;
	CFastLED *_controller;
	ApplicationManager appManager;
	SerialController *_serial;

	uint8_t mode, matrixWidth, matrixHeight;
	uint8_t prevLeftScore, prevRightScore;
	CRGB color1, color2;

	//Private Methods
	void initModeItem(uint8_t mode);
	void deletePreviousModeItem(uint8_t mode);
	void checkSerial();

  public:
	MatrixController();

	void init(CFastLED *controller, CRGB *leds, uint8_t m = 1, uint8_t width = 60, uint8_t height = 32);
	void run();

	uint8_t getSide();

	void setSerial(SerialController *sc);
	void setMode(uint8_t m);
	void setColor1(uint32_t color);
	void setColor2(uint32_t color);
	void setSetting(uint8_t s, uint8_t v);

	void setScore1(uint8_t s);
	void setScore2(uint8_t s);
};
#include "../Application.h"
#include <TextOutput.h>
#include <FlugelFont.h>
#include <LargeFont.h>

enum class ScoreBoardOptions
{
	Score1 = 1,
	Score2 = 2
};

class ScoreBoard : public Application
{
	uint8_t AppId;
	uint8_t AppTypeId = (uint8_t)MatrixModes::ScoreBoard;
	bool hasChanged, bypassing, initialized, animateStartup;

	uint8_t lPrev, rPrev;
	CRGB player1, player2;

	CRGB *leds;

	uint16_t animationFrame;

	void drawFrame();

  public:
	ScoreBoard(CRGB p1, CRGB p2, uint8_t player1Score = 10, uint8_t player2Score = 10);

	void init(bool animate = false);
	void run();
	void setAppId(uint8_t appId);
	uint8_t getAppId();
	uint8_t getAppTypeId();

	void changeValue(uint8_t valueId, uint8_t value);
	void setColor1(uint32_t color);
	void setColor2(uint32_t color);
	void bypassAppMatrix(CRGB *matrix);
	void resetBypass();

	bool matrixHasChanged();
	void resetMatrixChanged();
	bool isUsingMainMatrix();
	CRGB *getMatrix();
};
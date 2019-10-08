#include "../Application.h"
#include <TextOutput.h>
#include <FlugelFont.h>
#include <LargeFont.h>

enum class ScoreBoardOptions
{
	Score1 = 1,
	Score2 = 2,
	Color1 = 3,
	Color2 = 4
};

class ScoreBoard : public Application
{
	uint8_t AppTypeId = (uint8_t)MatrixModes::ScoreBoard;
	bool hasChanged;

	uint8_t lPrev, rPrev;
	CRGB player1, player2;

	CRGB *leds;

  public:
	ScoreBoard(CRGB *matrix, CRGB p1, CRGB p2, uint8_t player1Score = 10, uint8_t player2Score = 10);

	void init();
	void drawFrame();

	uint8_t getAppTypeId();
	uint32_t getValue(uint8_t valueTypeId);

	void changeValue(uint8_t valueTypeId, uint32_t value);
	void setMatrixOutputArray(CRGB *matrix);
};
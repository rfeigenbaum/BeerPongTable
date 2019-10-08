#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(CRGB* matrix, CRGB p1, CRGB p2, uint8_t player1Score, uint8_t player2Score) {
    lPrev = player1Score;
    rPrev = player2Score;

    player1 = p1;
    player2 = p2;

    leds = matrix;
    fill_solid(leds, LED_HEIGHT*LED_WIDTH, CRGB::Black);
}

void ScoreBoard::init() {
}
void ScoreBoard::drawFrame() {

}
uint8_t ScoreBoard::getAppTypeId() {
    return AppTypeId;
}

void ScoreBoard::changeValue(uint8_t valueTypeId, uint32_t value) {
    Serial.println("value change");
    Serial.println(value);
    switch((ScoreBoardOptions)valueTypeId) {
        case ScoreBoardOptions::Score1:
            lPrev = value;
            MatrixHelpers::BlankSection(leds, 1, 1, LED_WIDTH/2-2, LED_HEIGHT-2);
            TextOutput::centerNumberInBox<LegacyFonts::LargeFont>(leds, value, 0, 0, LED_WIDTH/2-1, LED_HEIGHT-1, player1);
            hasChanged = true;
            break;
        case ScoreBoardOptions::Score2:
            rPrev = value;
            MatrixHelpers::BlankSection(leds, LED_WIDTH/2 + 1, 1, LED_WIDTH-2, LED_HEIGHT-2);
            TextOutput::centerNumberInBox<LegacyFonts::LargeFont>(leds, value, LED_WIDTH/2, 0, LED_WIDTH-1, LED_HEIGHT-1, player2);
            hasChanged = true;
            break;
		case ScoreBoardOptions::Color1: 
			player1 = value;
			MatrixShapes::DrawBox(leds, player1, 0, 0, LED_WIDTH/2-1, LED_HEIGHT-1);
			TextOutput::centerNumberInBox<LegacyFonts::LargeFont>(leds, lPrev, 0, 0, LED_WIDTH/2-1, LED_HEIGHT-1, player1);
			hasChanged = true;
		case ScoreBoardOptions::Color2:
			player2 = value;
			MatrixShapes::DrawBox(leds, player2, LED_WIDTH/2, 0, LED_WIDTH-1, LED_HEIGHT-1);
			TextOutput::centerNumberInBox<LegacyFonts::LargeFont>(leds, rPrev, LED_WIDTH/2, 0, LED_WIDTH-1, LED_HEIGHT-1, player2);
			hasChanged = true;
    }
}
uint32_t ScoreBoard::getValue(uint8_t valueTypeId) {

}
void ScoreBoard::setMatrixOutputArray(CRGB *matrix) {
    leds = matrix;
}
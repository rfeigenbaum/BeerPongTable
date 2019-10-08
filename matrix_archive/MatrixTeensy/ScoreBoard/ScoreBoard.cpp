#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(CRGB p1, CRGB p2, uint8_t player1Score, uint8_t player2Score) {
    lPrev = player1Score;
    rPrev = player2Score;

    player1 = p1;
    player2 = p2;

    bypassing = false;
    leds = new CRGB[LED_HEIGHT*LED_WIDTH];
    fill_solid( leds, LED_HEIGHT*LED_WIDTH, CRGB::Black );
    initialized = false;
}

void ScoreBoard::init(bool animate) {
    animateStartup = animate;
    animationFrame = 0;
}
void ScoreBoard::run() {
    if(animateStartup && !initialized) {
        
        //Run animation frame
    }
    else if(!animateStartup && !initialized) {
        MatrixShapes::DrawBox(leds, player1, 0, 0, LED_WIDTH/2-1, LED_HEIGHT-1);
        MatrixShapes::DrawBox(leds, player2, LED_WIDTH/2, 0, LED_WIDTH-1, LED_HEIGHT-1);
        TextOutput::centerNumberInBox<LegacyFonts::LargeFont>(leds, lPrev, 0, 0, LED_WIDTH/2-1, LED_HEIGHT-1, player1);
        TextOutput::centerNumberInBox<LegacyFonts::LargeFont>(leds, rPrev, LED_WIDTH/2, 0, LED_WIDTH-1, LED_HEIGHT-1, player2);

        initialized = true;
        hasChanged = true;
    }
    else {
        //Update score?
    }

}
void ScoreBoard::setAppId(uint8_t appId) {
    AppId = appId;
}
uint8_t ScoreBoard::getAppId() {
    return AppId;
}
uint8_t ScoreBoard::getAppTypeId() {
    return AppTypeId;
}

void ScoreBoard::changeValue(uint8_t valueId, uint8_t value) {
    Serial.println("new score");
    Serial.println(value);
    switch((ScoreBoardOptions)valueId) {
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
    }
}
void ScoreBoard::setColor1(uint32_t color) {
    player1 = color;
    MatrixShapes::DrawBox(leds, player1, 0, 0, LED_WIDTH/2-1, LED_HEIGHT-1);
    TextOutput::centerNumberInBox<LegacyFonts::LargeFont>(leds, lPrev, 0, 0, LED_WIDTH/2-1, LED_HEIGHT-1, player1);
    hasChanged = true;
}
void ScoreBoard::setColor2(uint32_t color) {
    player2 = color;
    MatrixShapes::DrawBox(leds, player2, LED_WIDTH/2, 0, LED_WIDTH-1, LED_HEIGHT-1);
    TextOutput::centerNumberInBox<LegacyFonts::LargeFont>(leds, rPrev, LED_WIDTH/2, 0, LED_WIDTH-1, LED_HEIGHT-1, player2);
    hasChanged = true;
}
void ScoreBoard::bypassAppMatrix(CRGB *matrix) {
    delete leds;
    leds = matrix;
}
void ScoreBoard::resetBypass() {
    leds = new CRGB[LED_HEIGHT * LED_WIDTH];
    fill_solid( leds, LED_HEIGHT*LED_WIDTH, CRGB::Black );
    initialized = false;
}

bool ScoreBoard::matrixHasChanged() {
    return hasChanged;
}
void ScoreBoard::resetMatrixChanged() {
    hasChanged = false;
}
bool ScoreBoard::isUsingMainMatrix() {
    return bypassing;
}
CRGB* ScoreBoard::getMatrix() {
    return leds;
}

/*void ScoreBoard::drawFrame() {
    for()
}*/
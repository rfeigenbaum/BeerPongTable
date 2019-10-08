#include "MatrixController.h"

MatrixController::MatrixController() {
    _serial = new SerialController(&Serial4, this);
}

void MatrixController::init(CFastLED * controller, CRGB * leds, uint8_t m, uint8_t width, uint8_t height) {
    _controller = controller;
    _leds = leds;
    fill_solid( _leds, LED_HEIGHT*LED_WIDTH, CRGB::Black );
    _controller->show();
    appManager.init(_leds);
    appManager.startApp(new ScoreBoard(CRGB::Red, CRGB::Blue));
}
    
void MatrixController::run() {
    appManager.run();
    appManager.draw();
    _controller->show();
    checkSerial();
}

void MatrixController::checkSerial() {
    _serial->checkSerial();
}

uint8_t MatrixController::getSide() {
    return 1;
}

void MatrixController::setSerial(SerialController * sc) {}
void MatrixController::setMode(uint8_t m) {
    
}
void MatrixController::setColor1(uint32_t color) {
    appManager.setColor1(color);
}
void MatrixController::setColor2(uint32_t color) {
    appManager.setColor2(color);
}
void MatrixController::setSetting(uint8_t s, uint8_t v) {

}

void MatrixController::setScore1(uint8_t s) {
    Serial.println("score 1");
    Application * temp = appManager.getAppOfType((uint8_t)MatrixModes::ScoreBoard);
    if(temp) {
        temp->changeValue((uint8_t)ScoreBoardOptions::Score1, s);
    }
}
void MatrixController::setScore2(uint8_t s) {
    Serial.println("score 2");
    Application * temp = appManager.getAppOfType((uint8_t)MatrixModes::ScoreBoard);
    if(temp) {
        temp->changeValue((uint8_t)ScoreBoardOptions::Score2, s);
    }
}
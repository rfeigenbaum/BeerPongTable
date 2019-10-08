#include "BlynkController.h"

void BlynkController::run() {
    checkSerial();
}
void BlynkController::init() {
	_matrixSerial = new SerialController(&Serial2, this);
	_leftRingsSerial = new SerialController(&Serial3, this);
	_rightRingsSerial = new SerialController(&Serial4, this);
}
void BlynkController::setSerials(Stream * leftSerial) {
	//_leftRingsSerial = new SerialController(leftSerial, this);
}
#pragma region [PlatformSpecific]
void BlynkController::sendMode(DeviceType d, uint8_t m) {
	switch(d){
		case DeviceType::LeftRingTeensy : 
			_leftRingsSerial->sendMode(m);
			break;
		case DeviceType::RightRingTeensy : 
			_rightRingsSerial->sendMode(m);
			break;
		case DeviceType::MatrixTeensy : 
			_matrixSerial->sendMode(m);
			break;
		case DeviceType::BlynkController :
			break;
	}
}
void BlynkController::sendColor1(uint32_t color) {
	_leftRingsSerial->sendColor1(color);
	_rightRingsSerial->sendColor1(color);
	_matrixSerial->sendColor1(color);
}
void BlynkController::sendColor2(uint32_t color) {
	_leftRingsSerial->sendColor2(color);
	_rightRingsSerial->sendColor2(color);
	_matrixSerial->sendColor2(color);
}

#pragma endregion

#pragma region[ NotUsed ]
void BlynkController::setMode(uint8_t m) {}
void BlynkController::setColor1(uint32_t color) {}
void BlynkController::setColor2(uint32_t color) {}
void BlynkController::setSetting(uint8_t s, uint8_t v) {}
#pragma endregion

void BlynkController::setScore1(uint8_t score) {
    _matrixSerial->forwardScore(DeviceType::LeftRingTeensy, score);
}
void BlynkController::setScore2(uint8_t score) {
	_matrixSerial->forwardScore(DeviceType::RightRingTeensy, score);
}

void BlynkController::checkSerial() {
    _matrixSerial->checkSerial();
    _leftRingsSerial->checkSerial();
	//temp->write('a');
    _rightRingsSerial->checkSerial();
}
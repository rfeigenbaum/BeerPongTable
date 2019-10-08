#include "EepromController.h"

EepromController::EepromController() {}

void EepromController::init() {
    if(EEPROM.read((int)EepromLocations::Version) != VERSION) {
        initSettings();
    }
    #if RESET == TRUE 
        initSettings();
    #endif
}

/* Setter Methods */
void EepromController::setColor1(uint32_t color) {
    uint8_t r = color >> 16; 
    uint8_t g = (color & 0x00FF00) >> 8;
    uint8_t b = (color & 0x0000FF); 

    EEPROM.update((int)EepromLocations::Color1, r);
    EEPROM.update((int)EepromLocations::Color1 + 1, g);
    EEPROM.update((int)EepromLocations::Color1 + 2, b);
}
void EepromController::setColor2(uint32_t color) {
    uint8_t r = color >> 16; 
    uint8_t g = (color & 0x00FF00) >> 8;
    uint8_t b = (color & 0x0000FF);
    
    EEPROM.update((int)EepromLocations::Color2, r);
    EEPROM.update((int)EepromLocations::Color2 + 1, g);
    EEPROM.update((int)EepromLocations::Color2 + 2, b);
}
void EepromController::setMode(uint8_t m) {
    EEPROM.update((int)EepromLocations::Mode, m);
}
void EepromController::setSetting(Settings s, uint8_t v) {
    EEPROM.update((int)s + (int)EepromLocations::Settings, v);
}


/* Getter Methods */
bool EepromController::getPower() {
    return (bool)EEPROM.read((int)EepromLocations::Power);
}
uint32_t EepromController::getColor1() {
    uint8_t r = EEPROM.read((int)EepromLocations::Color1);
    uint8_t g = EEPROM.read((int)EepromLocations::Color1 + 1);
    uint8_t b = EEPROM.read((int)EepromLocations::Color1 + 2);
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}
uint32_t EepromController::getColor2() {
    uint8_t r = EEPROM.read((int)EepromLocations::Color2);
    uint8_t g = EEPROM.read((int)EepromLocations::Color2 + 1);
    uint8_t b = EEPROM.read((int)EepromLocations::Color2 + 2);
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

uint8_t EepromController::getMode() {
    return (uint8_t)EEPROM.read((int)EepromLocations::Mode);
}
uint8_t EepromController::getSetting(Settings s) {
    return (uint8_t)EEPROM.read((int)EepromLocations::Settings+(int)s);
}


/*Private Functions*/

void EepromController::initSettings() {
    //setPower(true);
    setMode(1);
    setColor1(COLOR1);
    setColor2(COLOR2);
    for (int i =  (int)EepromLocations::Settings; i < EEPROM.length() ; i++) {
        EEPROM.update(i, 0xFF);
    }
    setSetting(Settings::Brightness, BRIGHTNESS);
}
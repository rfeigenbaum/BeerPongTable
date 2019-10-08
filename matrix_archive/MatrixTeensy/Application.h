#ifndef Application_h
#define Application_h

#include <FastLED.h>
#include <Enums.h>
#include <MatrixHelpers.h>

class Application {
    uint8_t AppId, AppTypeId;
    bool hasChanged, bypassing;
  public:
    Application(){}

    virtual void init(bool animate = false) = 0;
    virtual void run() = 0;
    virtual void setAppId(uint8_t appId) = 0;
    virtual uint8_t getAppId() = 0;
    virtual uint8_t getAppTypeId() = 0;
    
    virtual void changeValue(uint8_t valueId, uint8_t value) = 0;
    virtual void setColor1(uint32_t color) = 0;
    virtual void setColor2(uint32_t color) = 0;
    virtual void bypassAppMatrix(CRGB *matrix) = 0;
    virtual void resetBypass() = 0;

    virtual bool matrixHasChanged() = 0;
    virtual void resetMatrixChanged() = 0;
    virtual bool isUsingMainMatrix() = 0;
    virtual CRGB* getMatrix() = 0;
};

#endif
#include "Application.h"
#include <vector>

#ifndef ApplicationManager_h
#define ApplicationManager_h

class ApplicationManager {
    std::vector<Application *> apps;
    CRGB * _leds;
  public:
    ApplicationManager(){}

    void init(CRGB * leds);
    void run();
    void draw();
    void startApp(Application *app);
    void closeApp(uint8_t appId);

    void setColor1(uint32_t color);
    void setColor2(uint32_t color);
    Application* getAppOfType(uint8_t appTypeId);
};

#endif
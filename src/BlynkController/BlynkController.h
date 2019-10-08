#include <SerialController.h>
#include <IController.h>
#include <Enums.h>
#include <Arduino.h>

class  BlynkController : public  Controller {
    SerialController * _matrixSerial;
    SerialController * _leftRingsSerial;
    SerialController * _rightRingsSerial;

    SoftwareSerial * temp;

    void checkSerial();

    public:
        BlynkController() {}

        void init();
        void setSerials(Stream * leftSerial);
        void run();

		void setMode(uint8_t m);
		void setColor1(uint32_t color);
		void setColor2(uint32_t color);
        void setSetting(uint8_t s, uint8_t v);

		void setScore1(uint8_t s);
		void setScore2(uint8_t s);
        

        void sendMode(DeviceType d, uint8_t m);
        void sendColor1(uint32_t color);
        void sendColor2(uint32_t color);
};
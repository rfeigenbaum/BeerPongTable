#include <Arduino.h>
#include <HardwareSerial.h>
#include <SoftwareSerial.h>

class BlynkWifiModule : public Stream {
    Stream * blynkCommunication;
    Stream * wifiControls;
    bool connected;

    public:
        BlynkWifiModule();

        void begin(HardwareSerial * blynk, HardwareSerial * wifi);
        void begin(HardwareSerial * blynk, SoftwareSerial * wifi);

        Stream * getBlynkStream();

        bool isConnected();
        

};
#include "BlynkWifiModule.h"

BlynkWifiModule::BlynkWifiModule(){
    connected = false;
}

void BlynkWifiModule::begin(HardwareSerial * blynk, HardwareSerial * wifi) {
    blynk->begin(38400);
    wifi->begin(38400);

    blynkCommunication = blynk;
    wifiControls = wifi;
}

void BlynkWifiModule::begin(HardwareSerial * blynk, HardwareSerial * wifi) {
    blynk->begin(38400);
    wifi->begin(38400);

    blynkCommunication = blynk;
    wifiControls = wifi;
}

Stream * BlynkWifiModule::getBlynkStream() {
    return blynkCommunication;
}
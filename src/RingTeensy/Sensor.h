#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

#ifndef Sensor_h
#define Sensor_h

class Sensor {
  bool detected;
  uint8_t sensorAnalogPin;

  public: 
    Sensor() {
      detected = false;
      sensorAnalogPin = 0;
    }
    Sensor(uint8_t pin) {
      detected = false;
      sensorAnalogPin = pin;
    }

    void setSensorPin(uint8_t pin);

    bool checkSensorDetection();
    bool checkForSensorChange();
};

#endif

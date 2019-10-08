#include "Sensor.h"

bool Sensor::checkSensorDetection() {
  return analogRead(sensorAnalogPin) <= 100;
}

/* Check For Sensor Change
 *  If sensor detection has changed return true
 */
bool Sensor::checkForSensorChange() {
  bool temp = analogRead(sensorAnalogPin) <= 100;
  if(temp == detected) {
    return false;
  }
  detected = temp;
  return true;
}

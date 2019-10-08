#ifndef SerialController_h
#define SerialController_h

#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "pins_arduino.h"
	#include "WConstants.h"
#endif

#include <IController.h>
#include <Enums.h>
#include <HardwareSerial.h>
#include <SoftwareSerial.h>
#include <HelperFunctions.h>



class SerialController {
	Stream * _serial;
	Controller * _controller;

	//Private Methods
	void setColor(uint8_t side, byte b1, byte b2, byte b3);
	void sendPacket(byte packet[PACKETSIZE-1]);
	void printReadable(byte *packet);

	public:
		SerialController(Controller * controller) : _controller(controller) {
			_serial = &Serial;
		}
		SerialController(Stream * serial, Controller * controller) : _controller(controller) {
			_serial = serial;
		}
		SerialController(HardwareSerial * serial, Controller * controller) : _controller(controller) {
			serial->begin(38400);
			_serial = serial;
		}
		SerialController(SoftwareSerial * serial, Controller * controller) : _controller(controller) {
			serial->begin(38400);
			_serial = serial;
		}
		void sendScore(uint8_t score);

		void checkSerial();
		
		
		//BlynkController Methods
		void forwardPacket(byte *packet);
		void forwardScore(DeviceType sender, uint8_t score);
		void sendMode(uint8_t mode);
		void sendColor1(uint32_t color);
		void sendColor2(uint32_t color);
		void sendSetting(uint8_t s, uint8_t v);

};

#endif
#include "SerialController.h"

/* TODO:
Finish updating methods to use PACKETSIZE to be dynamic 
Update Packet to include size
*/


void SerialController::sendScore(uint8_t score) {
	byte out[]  = {(byte)(uint8_t) MessageHeaders::Score, (byte)0x00, (byte)0x00, (byte)score};
	sendPacket(out);
}

void SerialController::checkSerial() {
	byte incoming[5];
	
	
	if( _serial->available() > 0) {
		//Serial.println(_serial->available());
		_serial->readBytes(incoming, 5);
		#if DEBUG == TRUE
			Serial.println("incoming packet");
			printReadable(incoming);
		#endif

		DeviceType sendingDevice = (DeviceType)incoming[0];
		MessageHeaders messageType = (MessageHeaders)incoming[1];
		byte * data = &(incoming[2]);

		switch(messageType) {
			case MessageHeaders::Mode: 
				_controller->setMode((uint8_t)data[2]);
				break;
			case MessageHeaders::RgbColor1: 
				_controller->setColor1(ColorFunctions::RgbToHex(data[0], data[1], data[2]));
				break;
			case MessageHeaders::RgbColor2: 
				_controller->setColor2(ColorFunctions::RgbToHex(data[0], data[1], data[2]));
				break;
			case MessageHeaders::Score:
				if(sendingDevice == DeviceType::LeftRingTeensy) {
					_controller->setScore1((uint8_t)data[2]);
				}
				if(sendingDevice == DeviceType::RightRingTeensy) {
					_controller->setScore2((uint8_t)data[2]);
				}
				break;
			case MessageHeaders::Setting: 
				_controller->setSetting((uint8_t)data[0],(uint8_t)data[2]);
				break;
			case MessageHeaders::Text:
				
				break;
			
			
		}
	}
}

void SerialController::setColor(uint8_t colorNumber, byte b1, byte b2, byte b3) {
	uint32_t color = (((uint8_t)b1 & 0xff) << 16) + (((uint8_t)b2 & 0xff) << 8) + ((uint8_t)b3 & 0xff);
	if(colorNumber == 1) {
		_controller->setColor1(color);
	}
	if(colorNumber == 2) {
		_controller->setColor2(color);
	}
}


void SerialController::sendPacket(byte packet[PACKETSIZE-1]) {
	byte out[PACKETSIZE];
	out[0] = (byte)DEVICE;
	memcpy(out+1, packet, PACKETSIZE-1);

	#if DEBUG == TRUE 
		Serial.println("Sending");
		printReadable(out);
	#endif
	_serial->write(out, PACKETSIZE);
}
void SerialController::forwardPacket(byte *packet) {
	_serial->write(packet, PACKETSIZE);
	#if DEBUG == TRUE
		Serial.println("Sending");
		printReadable(packet);
	#endif
}
void SerialController::printReadable(byte *packet) {
	Serial.println("");
	for(uint8_t i = 0; i < PACKETSIZE; i++) {
		Serial.print((uint8_t) packet[i]);
		Serial.print("\t");
	}
	Serial.println("");
}
void SerialController::forwardScore(DeviceType sender, uint8_t score) {
	byte out[]  = {(byte)sender, (byte)(uint8_t) MessageHeaders::Score, (byte)0x00, (byte)0x00, (byte)score};
	forwardPacket(out);
}
void SerialController::sendMode(uint8_t mode) {
	byte out[] = {(byte)(uint8_t) MessageHeaders::Mode, (byte)0, (byte)0, (byte)mode};
	sendPacket(out);
}
void SerialController::sendColor1(uint32_t color) {
	uint8_t r = color >> 16; 
    uint8_t g = (color & 0x00FF00) >> 8;
    uint8_t b = (color & 0x0000FF);
	uint8_t rgb[3];
	ColorFunctions::HexToRgb(color, rgb);
	Serial.println(rgb[0]);
	Serial.println(rgb[1]);
	Serial.println(rgb[2]);
	byte out[] = {(byte)(uint8_t) MessageHeaders::RgbColor1, (byte)r, (byte)g, (byte)b};
	sendPacket(out);
}
void SerialController::sendColor2(uint32_t color) {
	uint8_t rgb[3];
	ColorFunctions::HexToRgb(color, rgb);
	uint8_t r = color >> 16; 
    uint8_t g = (color & 0x00FF00) >> 8;
    uint8_t b = (color & 0x0000FF);
	byte out[] = {(byte)(uint8_t) MessageHeaders::RgbColor2, (byte)r, (byte)g, (byte)b};
	sendPacket(out);
}
void SerialController::sendSetting(uint8_t s, uint8_t v) {

}
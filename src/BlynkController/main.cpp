#include <Arduino.h>

#include <Adafruit_BLE.h>
#include <Adafruit_BluefruitLE_SPI.h>
#include <Adafruit_BluefruitLE_UART.h>

#include <SoftwareSerial.h>

#include <BlynkSimpleSerialBLE.h>

#include "BlynkController.h"

char auth[] = "1595acc38f764dde83e01165541e15d5";


#define BLUEFRUIT_HWSERIAL_NAME      Serial1
#define BLUEFRUIT_UART_MODE_PIN        12 
Adafruit_BluefruitLE_UART ble(BLUEFRUIT_HWSERIAL_NAME, BLUEFRUIT_UART_MODE_PIN);

BlynkController controller;
void setup()
{
	/*Serial.begin(9600);

	blePeripheral.setLocalName("Beer Pong");
	blePeripheral.setDeviceName("Beer Pong");
	blePeripheral.setAppearance(384);
	Blynk.begin(blePeripheral, auth);
	blePeripheral.begin();

	Serial.println("Waiting for connections...");*/
	Serial.begin(9600);
	Serial.println("Setting up...");
	
	if ( !ble.begin(false) )
	{
		Serial.println(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
	}

	if (! ble.sendCommandCheckOK(F("AT+GAPDEVNAME=Beer Pong Table")) ) {
		Serial.println(F("Could not set device name?"));
	}
	ble.reset();
	ble.setMode(BLUEFRUIT_MODE_DATA); 
	Serial.println("Bluetooth ready...");
	Blynk.config(ble, auth);
	//Blynk.begin(ble, auth);
	Blynk.connect();
	Serial.println("Waiting for connections...");
	pinMode(13, OUTPUT);
	digitalWrite(13, HIGH);
	controller.init();
	Serial.println("Setup!");
	//test.begin(9600);
	//controller.setSerials(&test);
	//controller.init(new SerialController(&matrixMode, &controller), new SerialController(&leftRings, &controller), new SerialController(&rightRings, &controller));
}

void loop()
{
	Blynk.run();
	controller.run();
}


BLYNK_WRITE(V0)
{
	//Matrix Mode
	//Serial.println(request.pin);
	controller.sendMode(DeviceType::MatrixTeensy, param.asInt());
}
BLYNK_WRITE(V1)
{
	//Left Rings Mode
	controller.sendMode(DeviceType::LeftRingTeensy, param.asInt());
}
BLYNK_WRITE(V2)
{
	//Right Rings Mode
	controller.sendMode(DeviceType::RightRingTeensy, param.asInt());
}
BLYNK_WRITE(V21)
{
	//Color 1
	controller.sendColor1( ((param[0].asInt() & 0xff) << 16) + ((param[1].asInt() & 0xff) << 8) + (param[2].asInt() & 0xff) );
}
BLYNK_WRITE(V22)
{
	//Color 2
	controller.sendColor2( ((param[0].asInt() & 0xff) << 16) + ((param[1].asInt() & 0xff) << 8) + (param[2].asInt() & 0xff) );
}
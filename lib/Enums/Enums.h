#ifndef Enums_h
#define Enums_h

enum class MessageHeaders {
	Mode = 0x00,
	Setting = 0x02,
	Score = 0x10,
	RgbColor1 = 0x21,
	RgbColor2 = 0x22,
	Text = 0xFF
};

enum class DeviceType {
	LeftRingTeensy = 1,
	RightRingTeensy = 2,
	MatrixTeensy = 3,
	BlynkController = 4
};

enum class MatrixModes {
	ScoreBoard = 1
};

enum class RingModes {
	Solid = 1,
	Glow,
	Alternate,
	ColorGlows
};

enum class Settings {
	//Power = 0x0,
	Brightness = 0x1,
};

enum class EepromLocations {
	Version = 0x00,
	Power = 0x01,
	Color1 = 0x02, //2,3,4
	Color2 = 0x05, //5,6,7
	Mode = 0x08,
	Settings = 0x10 //0x10+
};

#endif
#include "HelperFunctions.h"

namespace ColorFunctions
{
	void HexToRgb(uint32_t color, uint8_t rgb[3])
	{
		uint8_t r = color >> 16;
		uint8_t g = (color & 0x00FF00) >> 8;
		uint8_t b = (color & 0x0000FF);
		rgb[0] = r;
		rgb[1] = g;
		rgb[2] = b;
	}
	uint32_t RgbToHex(uint8_t rgb[3])
	{
		return (((uint8_t)rgb[0] & 0xff) << 16) + (((uint8_t)rgb[1] & 0xff) << 8) + ((uint8_t)rgb[2] & 0xff);
	}
	uint32_t RgbToHex(uint8_t r, uint8_t g, uint8_t b)
	{
		return (((uint8_t)r & 0xff) << 16) + (((uint8_t)g & 0xff) << 8) + ((uint8_t)b & 0xff);
	}
} // namespace ColorFunctions
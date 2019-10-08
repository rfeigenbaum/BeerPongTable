#include "ApplicationManager.h"

void ApplicationManager::init(CRGB *leds)
{
	_leds = leds;
}
void ApplicationManager::run()
{
	for (int i = 0; i < apps.size(); i++)
	{
		apps[i]->run();
	}
}
void ApplicationManager::draw()
{
	for (int i = 0; i < apps.size(); i++)
	{
		if (apps[i]->matrixHasChanged())
		{
			for (int c = 0; c < LED_HEIGHT * LED_WIDTH; c++)
			{
				_leds[c] = apps[i]->getMatrix()[c];
				//Serial.println(apps[i]->getMatrix()[c].r);
			}
			apps[i]->resetMatrixChanged();
		}
	}
	delay(100);
	//Serial.println(apps[0]->getAppId());
	//_leds[0] = CRGB::Red;
}
void ApplicationManager::startApp(Application *app)
{
	apps.push_back(app);
	app->setAppId(apps.size());
	app->init();
	//app->bypassAppMatrix(_leds);
}
void ApplicationManager::closeApp(uint8_t appId)
{
	bool appIdFound = false;
	for (uint8_t i = 0; i < apps.size() && appIdFound == false; i++)
	{
		if (appId == apps[i]->getAppId())
		{
			appIdFound = true;
			delete apps[i];
			apps.erase(apps.begin() + i);
		}
	}
}
void ApplicationManager::setColor1(uint32_t color)
{
	for (int i = 0; i < apps.size(); i++)
	{
		apps[i]->setColor1(color);
		for(int c = 0; c < LED_HEIGHT * LED_WIDTH; c++)
		{
			_leds[c] = apps[i]->getMatrix()[c];
		}
		apps[i]->resetMatrixChanged();
	}
}
void ApplicationManager::setColor2(uint32_t color)
{
	for (int i = 0; i < apps.size(); i++)
	{
		apps[i]->setColor2(color);
		for(int c = 0; c < LED_HEIGHT * LED_WIDTH; c++)
		{
			_leds[c] = apps[i]->getMatrix()[c];
		}
		apps[i]->resetMatrixChanged();
	}
}
Application *ApplicationManager::getAppOfType(uint8_t appTypeId)
{
	for (uint8_t i = 0; i < apps.size(); i++)
	{
		if (appTypeId == apps[i]->getAppTypeId())
		{
			return apps[i];
		}
	}
	return nullptr;
}
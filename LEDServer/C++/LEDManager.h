#pragma once

#include <vector>
#include <map>

#include "LED.h"

class LEDManager
{
public:
	LEDManager(void);
	~LEDManager(void);

	void addLED(LED*, unsigned char);
	std::vector<unsigned char> getAllIntensities();
	float fahrenheitToCelsius(float);

private:
	std::vector<LED*> leds;
	std::map<std::string, unsigned char> ledMapping;
};


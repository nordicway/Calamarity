#include "stdafx.h"
#include "LEDManager.h"


#include "LED.h"


LEDManager::LEDManager(void)
{
	
}


LEDManager::~LEDManager(void)
{
}

void LEDManager::addLED(LED* led, unsigned char startPin) {
	this->leds.push_back(led);
}

std::vector<unsigned char> LEDManager::getAllIntensities() {
	std::vector<unsigned char> intensities;
	for(std::vector<int>::size_type i = 0; i != this->leds.size(); i++) {
		/* std::cout << someVector[i]; ... */
		std::vector<unsigned char> curIntensities = this->leds[i]->getIntensities();
		intensities.insert(intensities.end(), curIntensities.begin(), curIntensities.end());
	}
	return intensities;
}

float LEDManager::fahrenheitToCelsius(float fahrenheit)
{
	return ( (fahrenheit-32.0) / 1.8 );
}
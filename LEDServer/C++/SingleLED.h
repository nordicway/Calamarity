#pragma once
#include "led.h"
class SingleLED :
	public LED
{
public:
	SingleLED(void);
	~SingleLED(void);
	
	std::vector<unsigned char> getIntensities();
};


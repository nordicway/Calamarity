#pragma once
#include "ColorCalculator.h"

class TireTempsColorCalculator :
	public ColorCalculator
{
public:
	TireTempsColorCalculator(void);
	~TireTempsColorCalculator(void);

	std::vector<unsigned char> calc(RGBLED* rgbLED, float value);
};


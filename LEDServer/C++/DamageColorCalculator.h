#pragma once
#include "ColorCalculator.h"

class DamageColorCalculator : public ColorCalculator
{
public:
	DamageColorCalculator(void);
	~DamageColorCalculator(void);

	std::vector<unsigned char> calc(RGBLED* rgbLED, float value);
};


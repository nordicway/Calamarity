#include "stdafx.h"
#include "DamageColorCalculator.h"


DamageColorCalculator::DamageColorCalculator(void)
{
}


DamageColorCalculator::~DamageColorCalculator(void)
{
}

std::vector<unsigned char> DamageColorCalculator::calc(RGBLED* rgbLED, float value)
{
	printf("damagecalc: %f", value);
	if (value<10.0)
	{
		rgbLED->setIntensities(0,255,0);
	}
	else if (value<70.0)
	{
		rgbLED->setIntensities(255,255,0);
	} else {
		rgbLED->setIntensities(100,0,0);
	}
	std::vector<unsigned char> uc;
	return uc;
}
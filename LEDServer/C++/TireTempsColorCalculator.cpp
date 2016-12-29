#include "stdafx.h"
#include "TireTempsColorCalculator.h"
#include <math.h>


TireTempsColorCalculator::TireTempsColorCalculator(void)
{
}


TireTempsColorCalculator::~TireTempsColorCalculator(void)
{
}

std::vector<unsigned char> TireTempsColorCalculator::calc(RGBLED* rgbLED, float value)
{
	if (value < 80.0) {
		rgbLED->setIntensities(0,0,255-3*(80-value));
	}
	else if (value < 95.0) {
		rgbLED->setIntensities(0,255-25*(95-value),0+10*(95-value));
	//} else if (value < 95.0) {
	//	rgbLED->setIntensities(0,255-2*(value-95),0+4*(115-value));
	} else if (value < 115.0) {
		rgbLED->setIntensities(255-5*(115-value),0 + 10*(115-value),0);
	} else {
		rgbLED->setIntensities(std::max(150 + (int(value)-115),255),0,0);
	}
	return std::vector<unsigned char>();
}

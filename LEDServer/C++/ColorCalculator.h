#pragma once
#include <vector>

#include "RGBLED.h"

#ifndef __COLORCALCULATOR_H
#define __COLORCALCULATOR_H

class ColorCalculator
{
public:
	ColorCalculator(void);
	~ColorCalculator(void);

	virtual std::vector<unsigned char> calc(RGBLED* rgbLED, float value);
};

#endif
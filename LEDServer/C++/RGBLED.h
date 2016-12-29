
#include "led.h"


#ifndef __RGBLED_H
#define __RGBLED_H

class ColorCalculator;

class RGBLED :
	public LED
{
public:
	RGBLED(void);
	~RGBLED(void);

	void setCalculator(ColorCalculator* calculator);
	void setIntensities(unsigned char, unsigned char, unsigned char);
	void setIntensitiesRandom();
	
	unsigned char getIntensity(int);
	std::vector<unsigned char> getIntensities();
	void calculateColor();
	void setValue(float);

protected:
	ColorCalculator* calculator;

	LED* red;
	LED* green;
	LED* blue;

	
};

#endif
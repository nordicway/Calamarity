#include "stdafx.h"
#include "SingleLED.h"


SingleLED::SingleLED(void)
{
}


SingleLED::~SingleLED(void)
{
}



std::vector<unsigned char> SingleLED::getIntensities() {
	std::vector<unsigned char> intensities;
	intensities.push_back(this->intensity);
	return intensities;
}
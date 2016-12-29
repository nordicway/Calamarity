#include "stdafx.h"

#include "RGBLED.h"
#include <assert.h>
#include "SingleLED.h"

#include "ColorCalculator.h"


RGBLED::RGBLED(void)
{
	this->setSize(3);
	this->red = new SingleLED();
	this->green = new SingleLED();
	this->blue = new SingleLED();

	this->calculator = NULL;
}


RGBLED::~RGBLED(void)
{
}

void RGBLED::setIntensitiesRandom() {
	this->red->setIntensity(rand() % 255);
	this->green->setIntensity(rand() % 255);
	this->blue->setIntensity(rand() % 255);
}

void RGBLED::setIntensities(unsigned char r, unsigned char g, unsigned char b) {
	this->red->setIntensity(r);
	this->green->setIntensity(g);
	this->blue->setIntensity(b);
}

unsigned char RGBLED::getIntensity(int which) {
	unsigned char intensity;
	switch(which) {
	case 0: intensity = this->red->getIntensity(); break;
	case 1: intensity = this->green->getIntensity(); break;
	case 2: intensity = this->blue->getIntensity(); break;
	default: assert(false);
	}
	return intensity;
}

std::vector<unsigned char> RGBLED::getIntensities() {
	std::vector<unsigned char> intensities;
	intensities.push_back(this->getIntensity(0));
	intensities.push_back(this->getIntensity(1));
	intensities.push_back(this->getIntensity(2));
	return intensities;
}

void RGBLED::setCalculator(ColorCalculator* calc) {
	this->calculator = calc;
}

void RGBLED::setValue(float val) {
	this->calculator->calc(this, val);
}

void RGBLED::calculateColor() {
	std::vector<unsigned char> intensities;
	intensities = this->calculator->calc(this, 0.5f);
	//this->red->setIntensity(intensities.at(0));
	//this->green->setIntensity(intensities.at(1));
	//this->blue->setIntensity(intensities.at(2));
}
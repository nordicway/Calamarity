#include "stdafx.h"
#include "LED.h"

#include <vector>

LED::LED(void)
{
	this->setSize(1);
	this->intensity=0;
}


LED::~LED(void)
{
}


void LED::setIntensity(unsigned char i) {
	this->intensity=i;
}

unsigned char LED::getIntensity() {
	return this->intensity;
}

short LED::getSize() {
	return this->size;
}

void LED::setSize(short n) {
	this->size=n;
}
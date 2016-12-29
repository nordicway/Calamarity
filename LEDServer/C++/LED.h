#pragma once

#include <vector>

class LED
{
public:
	LED(void);
	~LED(void);

	short getSize();
	void setSize(short);

	void setIntensity(unsigned char);
	unsigned char getIntensity();
	virtual std::vector<unsigned char> getIntensities() = 0;

protected:
	short size;
	unsigned char intensity;
};


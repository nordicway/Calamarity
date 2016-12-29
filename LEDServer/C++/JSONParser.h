#pragma once

#include "rapidjson/document.h"
#include "Telemetry.h"

#ifndef __JSONPARSER_H
#define __JSONPARSER_H

class JSONParser
{
public:
	JSONParser(void);
	~JSONParser(void);

	Telemetry parse(char[]);
private:

};

#endif
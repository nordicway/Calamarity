
#include "stdafx.h"
//#pragma once
#include "JSONParser.h"
#include <iostream>


JSONParser::JSONParser(void)
{
}


JSONParser::~JSONParser(void)
{
}

Telemetry JSONParser::parse(char json[])
{
	Telemetry tel;
	printf(json);

    rapidjson::Document d;
    d.Parse<0>(json);

	printf("%d", d["gear"].GetInt() );

	tel.gear = d["gear"].GetInt();

	if (d["tire1"].IsDouble()) { tel.tire1 = d["tire1"].GetDouble(); }
	if (d["tire2"].IsDouble()) { tel.tire2 = d["tire2"].GetDouble(); }
	if (d["tire3"].IsDouble()) { tel.tire3 = d["tire3"].GetDouble(); }
	if (d["tire4"].IsDouble()) { tel.tire4 = d["tire4"].GetDouble(); }

	if (d["damage"].IsArray()) {
		tel.damage1 = d["damage"][0u].GetInt();
		tel.damage2 = d["damage"][1].GetInt();
		tel.damage3 = d["damage"][2].GetInt();
		tel.damage4 = d["damage"][3].GetInt();
		tel.damage5 = d["damage"][4].GetInt();
		tel.damage6 = d["damage"][5].GetInt();
		tel.damage7 = d["damage"][6].GetInt();
		tel.damage8 = d["damage"][7].GetInt();
	}

	return tel;

    //printf("%s\n", d["hello"].GetString());

	
}
// PacDrive.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include "UDPServer.h"

#include "PacDrive.h"

#include "stdio.h"
#include "stdlib.h"
//#include <cstdio>
#include "Telemetry.h"

#include "LEDManager.h"
#include "RGBLED.h"
#include "TireTempsColorCalculator.h"
#include "DamageColorCalculator.h"
#include "JSONParser.h"

int main(int argc, char* argv[])
{
	LEDManager* ledMan = new LEDManager();

	short brightness;
	short numDevices;
	short initDelay = 3;
	short tries = 10;
	Telemetry telemetry;
	JSONParser* jsonParser = new JSONParser();
	UDPServer* udpServer = new UDPServer();
	char* json = new char[8192];
	TireTempsColorCalculator* tt = new TireTempsColorCalculator();
	DamageColorCalculator* da = new DamageColorCalculator();





	numDevices = PacInitialize();
	while (numDevices < 1 && tries <= 10) {
			printf("No LED controller found. Trying again in %d seconds.\n", initDelay);
			Sleep((int)initDelay*1000);
			tries++;
	}

	RGBLED* rearWing = new RGBLED(); //0, 1, 2
	rearWing->setCalculator(da);
	ledMan->addLED(rearWing, 0);

	RGBLED* tireRB = new RGBLED(); //3, 4, 5
	tireRB->setIntensitiesRandom();
	tireRB->setCalculator(tt);
	ledMan->addLED(tireRB, 0);

	RGBLED* tireRF = new RGBLED(); //6, 7, 8
	tireRF->setCalculator(tt);
	ledMan->addLED(tireRF, 1);

	RGBLED* engine = new RGBLED(); //9, 10, 11
	ledMan->addLED(engine, 1);

	RGBLED* frontWing = new RGBLED(); //12, 13, 14
	ledMan->addLED(frontWing, 1);
	frontWing->setCalculator(da);
	
	RGBLED* tireLB = new RGBLED(); //15, 16, 17
	tireLB->setCalculator(tt);
	ledMan->addLED(tireLB, 1);

	RGBLED* tireLF = new RGBLED(); //18, 19, 20
	tireLF->setCalculator(tt);
	ledMan->addLED(tireLF, 1);

	RGBLED* button32 = new RGBLED(); //21, 22, 23
	ledMan->addLED(button32, 1);


	
	

	printf("%d devices found\n", numDevices);

	Pac64SetLEDIntensity(0, -1, 0);


	std::vector<unsigned char> ledIntensities;
	if (udpServer->init() )
	{
		printf("Socket initialized");
		while (json = udpServer->receive() )
		{
			printf(json);
			telemetry = jsonParser->parse(json);
			//printf("Gear: %d", telemetry.gear);
			//

			//printf("Damage1: %d ", telemetry.damage1);
			//printf("Damage2: %d ", telemetry.damage2);
			//printf("Damage3: %d ", telemetry.damage3);
			//printf("Damage4: %d ", telemetry.damage4);
			//printf("Damage5: %d ", telemetry.damage5);
			//printf("Damage6: %d ", telemetry.damage6);
			//printf("Damage7: %d ", telemetry.damage7);
			//printf("Damage8: %d ", telemetry.damage8);

			tireLF->setValue(telemetry.tire4);
			tireRF->setValue(telemetry.tire3);
			tireLB->setValue(telemetry.tire2);
			tireRB->setValue(telemetry.tire1);
			//TODO switch these when turning panel around
			frontWing->setValue((float)telemetry.damage5);
			rearWing->setValue((float)telemetry.damage1);

			//tireLF->setValue(60.0);
			//tireRF->setValue(90.0);
			//tireLB->setValue(110.0);
			//tireRB->setValue(100.0);

			ledIntensities = ledMan->getAllIntensities();
			for(std::vector<int>::size_type i = 0; i != ledIntensities.size(); ++i) {
				Pac64SetLEDIntensity(0, i, ledIntensities[i]);
			}
		}
		printf("Stopped receiving.");
	}
	Sleep(1000);

	
	Sleep(5000);
	exit(0);




	Sleep(5000);

	/*for(int j=0; j < 40; j++) {
	for (int i=0; i < (8*3); i++) {
		brightness = rand() % 255;
		printf("Testing. Current ID: %d\n", i);
		Pac64SetLEDIntensity(0, i, brightness);
		//PacSetLEDStates(0, 0xFFFF);
		Sleep(30);
	}

	}*/
	

	for(;;) {
		for(std::vector<int>::size_type i = 0; i != ledMan->getAllIntensities().size(); ++i) {
			tireRB->setIntensitiesRandom();
			//rearWing->calculateColor();

			Pac64SetLEDIntensity(0, i, (int)ledMan->getAllIntensities()[i]);
			printf("%d : %d\n", i, (int)ledMan->getAllIntensities()[i]);
			Sleep(100);
		}
	}
	



	Pac64SetLEDIntensity(0, -1, 0);
	//Pac64SetLEDState(0, 8, 7, false);

	

	PacShutdown();

	return 0;
}

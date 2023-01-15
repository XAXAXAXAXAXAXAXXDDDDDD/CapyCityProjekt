#pragma once
#include "main.h"
#include "Building.h"
class Windkraftwerk :
	public Building
{
public:
	Windkraftwerk(int x, int y, int width, int height, double gP = 500) : Building(x, y, width, height) {
		// initialize materials based on size of building
		/*Building::materialien = vector<Material*>(height * width * 4);*/
		for (int i = 0; i < height * width; i++) {
			Building::materialien.push_back(new Metall());
			Building::materialien.push_back(new Metall());
			Building::materialien.push_back(new Kunststoff());
			Building::materialien.push_back(new Kunststoff());
		};
		// set other members
		Building::grundPreis = gP;
		Building::label = WIND_LABEL;
	}
};


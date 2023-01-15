#pragma once
#include "Building.h"

class Wasserkraftwerk :
	public Building
{
public:
	Wasserkraftwerk(int x, int y, int width, int height, double gP = 1000) : Building(x, y, width, height) {
		// initialize materials based on size of building
	/*	Building::materialien = vector<Material*>(height * width * 7);*/
		for (int i = 0; i < height * width; i++) {
			Building::materialien.push_back(new Holz());
			Building::materialien.push_back(new Holz());
			Building::materialien.push_back(new Holz());
			Building::materialien.push_back(new Metall());
			Building::materialien.push_back(new Metall());
			Building::materialien.push_back(new Metall());
			Building::materialien.push_back(new Kunststoff());
		};
		// set other members
		Building::grundPreis = gP;
		Building::label = WASSER_LABEL;
	}

};


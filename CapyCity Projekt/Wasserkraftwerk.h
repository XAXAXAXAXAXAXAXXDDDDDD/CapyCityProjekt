#pragma once
#include "Building.h"

class Wasserkraftwerk :
	public Building
{
public:
	Wasserkraftwerk(double gP = 1000) : Building(gP, "Wasserkraftwerk") {
		Building::materialien = { new Holz(), new Holz(), new Holz(), new Metall(), new Metall(), new Metall(), new Kunststoff()};
	}
};


#pragma once
#include "main.h"
#include "Building.h"
class Windkraftwerk :
	public Building
{
public:
	Windkraftwerk(double gP = 500) : Building(gP, "Windkraftwerk") {
		Building::materialien = { new Metall(), new Metall(), new Kunststoff(), new Kunststoff() };
	}
};


#pragma once
#include "Building.h"
class Solarpanel :
    public Building
{
public:
	Solarpanel(double gP = 50) : Building(gP, "Solarpanel") {
		Building::materialien = { new Metall(), new Metall(), new Kunststoff() };
	}
};

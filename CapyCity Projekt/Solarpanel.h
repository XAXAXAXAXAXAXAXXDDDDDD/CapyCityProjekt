#pragma once
#include "Building.h"
class Solarpanel :
	public Building
{
public:
	Solarpanel(double gP = 50) : Building(gP, "Solarpanel", 75.0) {
		Building::materialien = new Materialverwaltung();
		materialien->addMaterial(Materialverwaltung::Material_Metall);
		materialien->addMaterial(Materialverwaltung::Material_Metall);
		materialien->addMaterial(Materialverwaltung::Material_Kunststoff);
	}
};

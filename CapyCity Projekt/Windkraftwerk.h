#pragma once
#include "main.h"
#include "Building.h"
class Windkraftwerk :
	public Building
{
public:
	Windkraftwerk(double gP = 500) : Building(gP, "Windkraftwerk", 150.0) {
		Building::materialien = new Materialverwaltung();
		materialien->addMaterial(Materialverwaltung::Material_Metall);
		materialien->addMaterial(Materialverwaltung::Material_Metall);
		materialien->addMaterial(Materialverwaltung::Material_Kunststoff);
		materialien->addMaterial(Materialverwaltung::Material_Kunststoff);
	}
};


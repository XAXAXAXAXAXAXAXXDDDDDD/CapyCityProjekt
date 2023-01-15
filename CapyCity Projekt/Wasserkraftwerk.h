#pragma once
#include "Building.h"

class Wasserkraftwerk :
	public Building
{
public:
	Wasserkraftwerk(double gP = 1000) : Building(gP, "Wasserkraftwerk") {
		Building::materialien = new Materialverwaltung();
		materialien->addMaterial(Materialverwaltung::Material_Holz);
		materialien->addMaterial(Materialverwaltung::Material_Holz);
		materialien->addMaterial(Materialverwaltung::Material_Holz);
		materialien->addMaterial(Materialverwaltung::Material_Metall);
		materialien->addMaterial(Materialverwaltung::Material_Metall);
		materialien->addMaterial(Materialverwaltung::Material_Kunststoff);
	}
};


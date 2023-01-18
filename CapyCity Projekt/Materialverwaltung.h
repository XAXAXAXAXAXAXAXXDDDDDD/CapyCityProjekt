#pragma once
#pragma once
#include "Material.h"
#include <map>
#include <vector>

using namespace std;

class Materialverwaltung
{
private:
	map<string, int> materialsToCount;

public:
	static const string Material_Holz;
	static const string Material_Metall;
	static const string Material_Kunststoff;
	static map<string, int> material_to_Price;

	Materialverwaltung() : materialsToCount(map<string, int>()) { }

	bool addMaterial(string m);
	bool removeMaterial(string m);
	int getPreisOfMaterials();
	void ausgeben();
}; 


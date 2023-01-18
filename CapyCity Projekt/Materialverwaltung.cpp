#include "Materialverwaltung.h"

const string Materialverwaltung::Material_Holz = "Holz";
const string Materialverwaltung::Material_Metall = "Metall";
const string Materialverwaltung::Material_Kunststoff = "Kunststoff";

map<string, int> Materialverwaltung::material_to_Price = { {Materialverwaltung::Material_Holz, 10}, {Materialverwaltung::Material_Kunststoff, 2}, {Materialverwaltung::Material_Metall, 50} };

bool Materialverwaltung::addMaterial(string m) {
	if (materialsToCount.count(m) == 0) {
		materialsToCount.emplace(m, 1);
	}
	else {
		materialsToCount[m]++;
	}
	return true;
}

bool Materialverwaltung::removeMaterial(string m) {
	if (materialsToCount.find(m) != materialsToCount.end()) {
		if (materialsToCount[m] > 0) {
			materialsToCount[m]--;
			return true;
		}
	}

	return false;
}

int Materialverwaltung::getPreisOfMaterials() {
	int preis = 0;
	for (auto& material : materialsToCount) {
		preis += material_to_Price[material.first] * material.second;
	}

	return preis;
}

void Materialverwaltung::ausgeben() {
	for (auto& material : materialsToCount) {
		cout << material.second << "x " << material.first << " | ";
	}
}

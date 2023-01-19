#include "Building.h"

Building::Building(const Building& other) : grundPreis(other.grundPreis), label(other.label), materialien(vector<Material*>(other.materialien.size())) {
	for (int i = 0; i < other.materialien.size(); i++) {
		if (dynamic_cast<Holz*>(other.materialien[i]) != nullptr) {
			materialien[i] = new Holz();
		}
		else if (dynamic_cast<Metall*>(other.materialien[i]) != nullptr) {
			materialien[i] = new Metall();
		}
		else if (dynamic_cast<Kunststoff*>(other.materialien[i]) != nullptr) {
			materialien[i] = new Kunststoff();
		}
		else {
			materialien[i] = new Material(0);
		}
	}
}

void Building::swap(Building& other) {
	std::swap(other.materialien, materialien);
	grundPreis = other.grundPreis;
	label = other.label;
}

string Building::getLabel() const {
	return label;
}

void Building::ausgeben() {
	cout << "| " + label + " ";
}

int Building::getPreis() {
	int materialKosten = 0;
	for (auto material : materialien) {
		materialKosten += material->getPreis();
	}

	return grundPreis + materialKosten;
}

void Building::materialAusgeben() {
	for (auto material : materialien) {
		material->ausgeben();
		cout << " ";
	}
}

const string Building::EMPTY_LABEL = "Empty";
const string Building::SOLAR_LABEL = "Solarpanel";
const string Building::WIND_LABEL = "Windkraftwerk";
const string Building::WASSER_LABEL = "Wasserkraftwerk";
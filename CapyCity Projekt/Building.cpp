#include "Building.h"

void Building::swap(Building& other) {
	std::swap(other.materialien, materialien);
	grundPreis = other.grundPreis;
	label = other.label;
}

string Building::getLabel() {
	return label;
}

void Building::ausgeben() {
	cout << "| " + label + " ";
}

int Building::getPreis() {
	return grundPreis + materialien->getPreisOfMaterials();
}

void Building::materialienAusgeben() {
	materialien->ausgeben();
}

const string Building::EMPTY_LABEL = "Empty";
const string Building::SOLAR_LABEL = "Solarpanel";
const string Building::WIND_LABEL = "Windkraftwerk";
const string Building::WASSER_LABEL = "Wasserkraftwerk";
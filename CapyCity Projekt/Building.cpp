#include "Building.h"

void Building::swap(Building& other) {
	std::swap(other.materialien, materialien);
	grundPreis = other.grundPreis;
	label = other.label;
	leistung = other.leistung;
}

string Building::getLabel() const {
	return label;
}

void Building::ausgeben() {
	cout << "| " + label + " ";
}

int Building::getPreis() {
	return grundPreis + ((materialien == nullptr) ? 0 : materialien->getPreisOfMaterials());
}

int Building::getLeistung() const {
	return leistung;
}

void Building::materialienAusgeben() {
	materialien->ausgeben();
}

const string Building::EMPTY_LABEL = "Empty";
const string Building::SOLAR_LABEL = "Solarpanel";
const string Building::WIND_LABEL = "Windkraftwerk";
const string Building::WASSER_LABEL = "Wasserkraftwerk";
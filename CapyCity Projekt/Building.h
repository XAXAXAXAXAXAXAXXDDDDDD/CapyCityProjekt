#pragma once
#include <string>
#include <vector>
#include "Material.h"
#include "Holz.h"
#include "Kunststoff.h"
#include "Metall.h"
#include "Materialverwaltung.h"
#include <typeinfo>
#include <iostream>

using namespace std;

class Building
{
protected:
	double grundPreis;
	string label;
	Materialverwaltung* materialien;
	double leistung;
public:
	Building() : grundPreis(0), label("Empty"), materialien(nullptr), leistung(0.0) { };
	Building(double gP, string l, double leistung) : grundPreis(gP), label(l), leistung(leistung), materialien(new Materialverwaltung()) { }
	Building(const Building& other) : grundPreis(other.grundPreis), label(other.label), leistung(other.leistung), materialien(new Materialverwaltung()) {
		if (other.materialien != nullptr) {
			*materialien = *other.materialien;
		}
		else {
			materialien = nullptr;
		}
	}
	~Building() {
		delete materialien;
	};

	Building& operator=(Building other) {
		swap(other);
		return *this;
	}

	void swap(Building& other) {
		std::swap(other.materialien, materialien);
		grundPreis = other.grundPreis;
		label = other.label;
		leistung = other.leistung;
	}

	string getLabel() const {
		return label;
	}

	void ausgeben() {
		cout << "| " + label + " ";
	}

	int getPreis() {
		return grundPreis + ((materialien == nullptr) ? 0 : materialien->getPreisOfMaterials());
	}

	int getLeistung() const {
		return leistung;
	}

	void materialienAusgeben() {
		materialien->ausgeben();
	}
};


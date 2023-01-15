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
public:
	Building() : grundPreis(0), label("Empty"), materialien(nullptr) { };
	Building(double gP, string l) : grundPreis(gP), label(l), materialien(new Materialverwaltung()) { }
	Building(const Building& other) : grundPreis(other.grundPreis), label(other.label), materialien(new Materialverwaltung()) {		
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
	}

	string getLabel() const {
		return label;
	}

	void ausgeben() {
		cout << "| " + label + " ";
	}

	int getPreis() {
		return grundPreis + materialien->getPreisOfMaterials();
	}

	void materialienAusgeben() {
		materialien->ausgeben();
	}
};


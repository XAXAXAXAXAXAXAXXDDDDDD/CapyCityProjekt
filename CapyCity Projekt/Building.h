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
	static const string EMPTY_LABEL;
	static const string SOLAR_LABEL;
	static const string WIND_LABEL;
	static const string WASSER_LABEL;

	Building() : grundPreis(0), label(EMPTY_LABEL), materialien(nullptr), leistung(0.0) { };
	Building(double gP, string l, double leistung) : grundPreis(gP), label(l), leistung(leistung), materialien(new Materialverwaltung()) { }
	Building(const Building& other) : grundPreis(other.grundPreis), label(other.label), leistung(other.leistung) {
		if (other.materialien != nullptr) {
			materialien = new Materialverwaltung();
			*materialien = *other.materialien;
		}
		else {
			materialien = nullptr;
		}
	};
		~Building() {
		delete materialien;
	};

	Building& operator=(Building other) {
		swap(other);
		return *this;
	}
	void swap(Building& other);

	string getLabel() const;
	int getPreis();
	int getLeistung() const;

	void ausgeben();
	void materialienAusgeben();

};


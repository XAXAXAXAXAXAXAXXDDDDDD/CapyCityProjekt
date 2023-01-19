#pragma once
#include <string>
#include <vector>
#include "Material.h"
#include "Holz.h"
#include "Kunststoff.h"
#include "Metall.h"
#include <typeinfo>
#include <iostream>

using namespace std;

class Building
{
protected:
	double grundPreis;
	string label;
	vector<Material*> materialien;
public:
	static const string EMPTY_LABEL;
	static const string SOLAR_LABEL;
	static const string WIND_LABEL;
	static const string WASSER_LABEL;

	Building() : grundPreis(0), label(EMPTY_LABEL), materialien(vector<Material*>()) { };
	Building(double gP, string l) : grundPreis(gP), label(l), materialien(vector<Material*>()) { }
	Building(const Building& other);
	~Building() {
		for (int i = 0; i < materialien.size(); i++) {
			delete materialien[i];
			materialien[i] = nullptr;
		}
	};

	Building& operator=(Building other) {
		swap(other);
		return *this;
	}
	void swap(Building& other);

	string getLabel() const;
	int getPreis();

	void ausgeben();
	void materialAusgeben();
};


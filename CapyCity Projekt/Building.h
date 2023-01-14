#pragma once
#include <string>
#include <vector>
#include "Material.h"
#include "Holz.h"
#include "Kunststoff.h"
#include "Metall.h"

using namespace std;

class Building
{
protected:
	double grundPreis;
	string label;
	vector<Material*> materialien;
public:
	Building() : grundPreis(0), label("Empty"), materialien(vector<Material*>()) { };
	Building(double gP, string l) : grundPreis(gP), label(l), materialien(vector<Material*>()) { }
	~Building() {
		for (int i = 0; i < materialien.size(); i++) {
			delete materialien[i];
			materialien[i] = nullptr;
		}
	};

	string getLabel() const {
		return label;
	}
};


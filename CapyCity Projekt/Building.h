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
	Building() : grundPreis(0), label("Empty"), materialien(vector<Material*>()) { };
	Building(double gP, string l) : grundPreis(gP), label(l), materialien(vector<Material*>()) { }
	Building(const Building& other) : grundPreis(other.grundPreis), label(other.label), materialien(vector<Material*>(other.materialien.size())) {
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
		int materialKosten = 0;
		for (auto material : materialien) {
			materialKosten += material->getPreis();
		}

		return grundPreis + materialKosten;
	}

	void materialAusgeben() {
		for (auto material : materialien) {
			material->ausgeben();
			cout << " ";
		}
	}
};


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
	int height;
	int width;
	int x;
	int y;
	double grundPreis;
	string label;
	vector<Material*> materialien;
public:
	static const string EMPTY_LABEL;
	static const string SOLAR_LABEL;
	static const string WIND_LABEL;
	static const string WASSER_LABEL;

	//Building() : grundPreis(0), label(EMPTY_LABEL), materialien(vector<Material*>()) { };
	Building(int x, int y, int width, int height) : grundPreis(0), label(EMPTY_LABEL), materialien(vector<Material*>()), x(x), y(y), width(width), height(height) { };
	//Building(int x, int y, int width, int height, double gP, string l) : grundPreis(gP), label(l), materialien(vector<Material*>()) { }
	Building(const Building& other);
	~Building();

	string getLabel() const {
		return label;
	}

	Building& operator=(Building other);

	void swap(Building& other);
	void ausgeben();
	int getPreis();
	void materialAusgeben();
	bool decX();
	bool decY();
};

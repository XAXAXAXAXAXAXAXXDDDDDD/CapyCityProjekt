#pragma once
#include "Building.h"
#include "Solarpanel.h"
#include "Wasserkraftwerk.h"
#include "Windkraftwerk.h"
#include <iostream>

using namespace std;

class Blueprint
{
private:
	int height;
	int width;
	Building** plan;

public:
	Blueprint(int w, int h) : height(h), width(w), plan(new Building* [width]) {
		cout << "Erstelleung eines Bauplans der Groesse: " << width << "x" << height << endl;
		for (int i = 0; i < width; i++) {
			plan[i] = new Building[height];
		}
	};

	int getHeight()const { return height; };
	int getWidth() const { return width; };

	void displayBuildings();
	void displayPlan();
	void balkenAusgeben(int count);
	void deleteBuildings(int xPosition, int yPosition, int widthOfArea, int heightOfArea);
	void placeBuildings(int xPosition, int yPosition, int widthOfBuilding, int heightOfBuilding, Building* type);
	bool findOverlappingBuildings(int x, int y, int width, int height);
	double calculateKennzahl();

	// Functor
	class CheckEqual;
};

class Blueprint::CheckEqual {
private:
	Blueprint& currBlueprint;

public:

	CheckEqual(Blueprint& bp) : currBlueprint(bp) { };

	bool operator()(Blueprint& otherPlan) {
		if (currBlueprint.height != otherPlan.height || currBlueprint.width != otherPlan.width) {
			return false;
		}

		for (int i = 0; i < currBlueprint.width; i++) {
			for (int j = 0; j < currBlueprint.height; j++) {
				if (currBlueprint.plan[i][j].getLabel() != otherPlan.plan[i][j].getLabel()) {
					return false;
				}
			}
		}

		if (currBlueprint.calculateKennzahl() != otherPlan.calculateKennzahl()) {
			return false;
		}

		return true;
	};
};
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
	Blueprint(const Blueprint& other) : height(other.height), width(other.width) {

		if (other.plan != nullptr) {
			plan = new Building * [other.width];
			for (int i = 0; i < other.width; i++) {
				plan[i] = new Building[other.height];
				for (int j = 0; j < height; j++) {
					plan[i][j] = other.plan[i][j];
				}
			}

			//std::copy(&(other.plan[0][0]), &(other.plan[0][0]) + width * height, &plan[0][0]);
		}
		else {
			plan = nullptr;
		}


	};
	Blueprint(Blueprint&& other) noexcept : height(0), width(0), plan(nullptr) {

		height = other.height;
		width = other.width;

		if (other.plan != nullptr) {
			plan = other.plan;
			other.plan = nullptr;
		}

		other.width = 0;
		other.height = 0;

	};
	~Blueprint() {

		for (int i = 0; i < width; i++) {
			delete[] plan[i];
			plan[i] = nullptr;
		}
		delete[] plan;
		plan = nullptr;

	};

	Blueprint& operator=(const Blueprint& other) {

		if (this != &other) {
			for (int i = 0; i < width; i++) {
				delete[] plan[i];
				plan[i] = nullptr;
			}
			delete[] plan;
			plan = nullptr;

			height = other.height;
			width = other.width;
			plan = new Building * [other.width];
			for (int i = 0; i < other.width; i++) {
				plan[i] = new Building[other.height];
			}

			std::copy(&other.plan[0][0], &other.plan[0][0] + width * height, &plan[0][0]);
		}

		return *this;
	}

	Blueprint& operator=(Blueprint&& other) noexcept {

		if (this != &other) {
			for (int i = 0; i < width; i++) {
				delete[] plan[i];
				plan[i] = nullptr;
			}
			delete[] plan;
			plan = nullptr;

			height = other.height;
			width = other.width;
			plan = other.plan;

			other.plan = nullptr;
			other.height = 0;
			other.width = 0;
		}

		return *this;
	}

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
#pragma once
#include "Building.h"
#include "Solarpanel.h"
#include "Wasserkraftwerk.h"
#include "Windkraftwerk.h"
#include <iostream>

using namespace std;

class CapycitySim
{
private:
	int height;
	int width;
	Building*** plan;
	vector<Building*> buildings;
	Building* emptyDummyBuilding;
public:
	enum Action { Place, Delete, Displays, Exit, Wrong };

	CapycitySim(int h, int w) : height(h), width(w), plan(new Building** [width]), buildings(vector<Building*>()), emptyDummyBuilding(new Building(0, 0, 1, 1)) {
		cout << "Erstelleung eines Bauplans der Groesse: " << width << "x" << height << endl;
		for (int i = 0; i < width; i++) {
			plan[i] = new Building*[height];
			for (int j = 0; j < height; j++) {
				plan[i][j] = emptyDummyBuilding;
			}
		}
	};

#pragma region Interaction
	Action ShowMenu();
	void HandleAction(Action action);
#pragma endregion

#pragma region Handle Action Methods
	bool Display();
	bool DeleteArea();
	bool PlaceBuilding();
#pragma endregion

#pragma region Helper Methods
	bool FindOverlappingBuildings(int x, int y, int width, int height);
	void balkenAusgeben(int count);
	void DisplayPlan();
	void DisplayBuildings();
	bool checkBounds();
#pragma endregion

};


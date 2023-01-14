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
	Building** plan;
public:
	enum Action { Place, Delete, Displays, Exit, Wrong };

	CapycitySim(int h, int w) : height(h), width(w), plan(new Building* [width]) {
		cout << "Erstelleung eines Bauplans der Groesse: " << width << "x" << height << endl;
		for (int i = 0; i < width; i++) {
			plan[i] = new Building[height];
		}
	};

#pragma region Interaction
	Action ShowMenu();
	void HandleAction(Action action);
#pragma endregion

#pragma region Handle Action Methods
	bool Display();
	bool DeleteBuilding();
	bool PlaceBuilding();
#pragma endregion

#pragma region Helper Methods
	bool FindOverlappingBuildings(int x, int y, int width, int height);
	void balkenAusgeben(int count);
	void DisplayPlan();
	void DisplayBuildings();
#pragma endregion

};


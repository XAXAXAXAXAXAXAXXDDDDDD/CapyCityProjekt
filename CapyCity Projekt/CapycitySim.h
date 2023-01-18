#pragma once
#include "Building.h"
#include "Solarpanel.h"
#include "Wasserkraftwerk.h"
#include "Windkraftwerk.h"
#include "Blueprint.h"
#include <iostream>
#include <algorithm>

using namespace std;

class CapycitySim
{
private:
	vector<Blueprint> blueprints;
	Blueprint* currentBlueprint;
public:
	enum Action { Place, Delete, Displays, Exit, Wrong, NewPlan, DisplayAll };

	CapycitySim() : blueprints(vector<Blueprint>()), currentBlueprint(nullptr) { };

#pragma region Interaction
	Action ShowMenu();
	void HandleAction(Action action);
#pragma endregion

#pragma region Handle Action Methods
	bool display();
	bool deleteBuilding();
	bool placeBuilding();
	bool creatNewPlan();
	bool creatNewPlan(int width, int height);
	bool displayAll();
#pragma endregion

#pragma region Helper Methods
	tuple<bool, int, int, int, int> checkBounds();
#pragma endregion

};


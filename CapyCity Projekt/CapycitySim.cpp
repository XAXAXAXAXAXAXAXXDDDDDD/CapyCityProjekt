#include "CapycitySim.h"
#include <map>


/// <summary>
/// Shows the menu for users to choose action.
/// </summary>
/// <returns></returns>
CapycitySim::Action CapycitySim::ShowMenu() {
	string menu = "Menue: \nDruecke 's' um Gebauede zu setzen\nDruecke 'l' um Bereich zu loeschen\nDruecke 'a' um Plan auszugeben\nDruecke 'e' um Programm zu beenden\nDruecke 'n' um neuen Plan zu erstellen\nDruecke 'all' um alle Plaene auszugeben";
	cout << menu << endl;
	// read user input
	string input;
	cin >> input;

	// return corresponding action
	if (input._Equal("s")) {
		return Place;
	}
	else if (input._Equal("l")) {
		return Delete;
	}
	else if (input._Equal("a")) {
		return Displays;
	}
	else if (input._Equal("e")) {
		return Exit;
	}
	else if (input._Equal("n")) {
		return NewPlan;
	}
	else if (input._Equal("all")) {
		return DisplayAll;
	}
	else {
		return Wrong;
	}
}

bool CapycitySim::creatNewPlan() {
	Blueprint::CheckEqual checkEquality(*currentBlueprint);
	bool equalPlanFound = false;
	for (auto it = ++blueprints.rbegin(); it != blueprints.rend(); ++it) {
		equalPlanFound = checkEquality(*it);
	}

	if (equalPlanFound) {
		// nicht popback sondern remove currentBlueprint --> sortierung in ausgabe!
		blueprints.pop_back();
		cout << "Letzter Plan wurde geloescht! Es existiert bereits ein identischer." << endl;
	}

	int width = 0;
	int height = 0;

	cout << "Breite des neuen Baufeldes: " << endl;
	cin >> width;
	if (width <= 0) return false;
	cout << "Hoehe des neuen Baufeldes: " << endl;
	cin >> height;
	if (height <= 0) return false;

	return creatNewPlan(width, height);
}

bool CapycitySim::creatNewPlan(int width, int height) {

	Blueprint* newPlan = new Blueprint(width, height);
	blueprints.push_back(*newPlan);
	currentBlueprint = newPlan;

	return true;
}


/// <summary>
/// Action Place Building.
/// </summary>
/// <returns>Bool determining whether placement was successful.</returns>
bool CapycitySim::placeBuilding() {
	Building* type;
	string typeString;

	cout << "Art des Gebaeudes (Solarpanel, Windkraftwerk, Wasserkraftwerk): " << endl;
	cin >> typeString;
	if (typeString._Equal("Solarpanel")) {
		type = new Solarpanel();
	}
	else if (typeString._Equal("Windkraftwerk")) {
		type = new Windkraftwerk();
	}
	else if (typeString._Equal("Wasserkraftwerk")) {
		type = new Wasserkraftwerk();
	}
	else {
		return false;
	}

	auto userInput = checkBounds();

	if (!get<0>(userInput)) return false;

	// check if there are already other buildings in the area
	if (currentBlueprint->findOverlappingBuildings(get<1>(userInput), get<2>(userInput), get<3>(userInput), get<4>(userInput))) {
		cout << "Kann kein Gebaeude setzen! Es existiert bereits eins an dieser Stelle!" << endl;
		return false;
	}

	currentBlueprint->placeBuildings(get<1>(userInput), get<2>(userInput), get<3>(userInput), get<4>(userInput), type);

	// return success
	return true;
}

/// <summary>
/// Action Delete Building.
/// </summary>
/// <returns></returns>
bool CapycitySim::deleteBuilding() {
	auto userInput = checkBounds();

	if (!get<0>(userInput)) return false;

	currentBlueprint->deleteBuildings(get<1>(userInput), get<2>(userInput), get<3>(userInput), get<4>(userInput));

	return true;
}

/// <summary>
/// Action Display Building. Prints current Building Plan.
/// </summary>
/// <returns></returns>
bool CapycitySim::display() {
	currentBlueprint->displayPlan();

	currentBlueprint->displayBuildings();

	return true;
}



/// <summary>
/// Starts execution of user action.
/// </summary>
/// <param name="action">The given Action.</param>
void CapycitySim::HandleAction(Action action) {
	if (action == Place) {
		if (placeBuilding()) {
			cout << "Gebaeude erfolgreich gesetzt!" << endl;
		}
	}
	else if (action == Delete) {
		if (deleteBuilding()) {
			cout << "Bereich erfolgreich geloescht!" << endl;
		}
	}
	else if (action == NewPlan) {
		if (creatNewPlan()) {
			cout << "Neuer Plan erfolgreich erstellt!" << endl;
		}
	}
	else if (action == DisplayAll) {
		displayAll();
	}
	else {
		display();
	}
}

tuple<bool, int, int, int, int> CapycitySim::checkBounds() {
	int heightOfArea;
	int widthOfArea;
	int xPosition;
	int yPosition;

	// read and check width input
	cout << "Breite: " << endl;
	cin >> widthOfArea;
	if (widthOfArea < 0 || widthOfArea > currentBlueprint->getWidth()) {
		cout << "Ups! Breite ist zu klein oder zu gross." << endl;
		return tuple<bool, int, int, int, int>(false, -1, -1, -1, -1);
	}

	// read and check height input
	cout << "Hoehe: " << endl;
	cin >> heightOfArea;
	if (heightOfArea < 0 || heightOfArea > currentBlueprint->getHeight()) {
		cout << "Ups! Hoehe ist zu klein oder zu gross." << endl;
		return tuple<bool, int, int, int, int>(false, -1, -1, -1, -1);
	}

	// read and check x coordinate input
	cout << "x-Koordinate: " << endl;
	cin >> xPosition;
	if (xPosition < 0 || xPosition + widthOfArea > currentBlueprint->getWidth()) {
		cout << "Ups! Der zu loeschende Radius ragt ueber die verfuegbare Flaeche hinaus." << endl;
		return tuple<bool, int, int, int, int>(false, -1, -1, -1, -1);
	}

	// read and check y coordinate input
	cout << "y-Koordinate: " << endl;
	cin >> yPosition;
	if (yPosition < 0 || yPosition + heightOfArea > currentBlueprint->getHeight()) {
		cout << "Ups! Der zu loeschende Radius ragt ueber die verfuegbare Flaeche hinaus." << endl;
		return tuple<bool, int, int, int, int>(false, -1, -1, -1, -1);
	}

	return tuple<bool, int, int, int, int>(true, xPosition, yPosition, widthOfArea, heightOfArea);
}


bool CapycitySim::displayAll() {
	sort(blueprints.begin(), blueprints.end(), [](Blueprint bp1, Blueprint bp2) -> bool {return bp1.calculateKennzahl() > bp2.calculateKennzahl(); });

	for_each(blueprints.begin(), blueprints.end(), [](Blueprint bp) {bp.displayPlan(); bp.displayBuildings(); });

	return true;
}
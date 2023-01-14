#include "CapycitySim.h"


///// <summary>
///// Mapping enum value to string.
///// </summary>
//string buildings[] = { "Empty", "House", "Farm" };

///// <summary>
///// Mapping the Building name to its enum value.
///// </summary>
//static std::unordered_map<std::string, Building> const table = { {"Empty", Empty}, {"House", House}, {"Farm", Farm} };
//

/// <summary>
/// Shows the menu for users to choose action.
/// </summary>
/// <returns></returns>
CapycitySim::Action CapycitySim::ShowMenu() {
	string menu = "Menue: \nDruecke 's' um Gebauede zu setzen\nDruecke 'l' um Bereich zu loeschen\nDruecke 'a' um Plan auszugeben\nDruecke 'e' um Programm zu beenden";
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
		return Display;
	}
	else if (input._Equal("e")) {
		return Exit;
	}
	else {
		return Wrong;
	}
}

/// <summary>
/// Helper method for finding overlapping buildings in the given square.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
/// <returns></returns>
bool CapycitySim::FindOverlappingBuildings(int x, int y, int width, int height) {

	// iterate through part of plan array 
	for (int i = x; i < x + width; i++) {
		for (int j = y; j < y + height; j++) {
			if (plan[i][j].getLabel() != "Empty") {
				return true;
			}
		}
	}
	return false;
}

/// <summary>
/// Action Place Building.
/// </summary>
/// <returns>Bool determining whether placement was successful.</returns>
bool CapycitySim::PlaceBuilding() {
	int heightOfBuilding;
	int widthOfBuilding;
	int xPosition;
	int yPosition;
	Building type;
	string typeString;

	/*printf("Art (%s, %s): ", );*/
	cin >> typeString;
	if (typeString._Equal("Solarpanel")) {
		type = Solarpanel();
	}
	else if (typeString._Equal("Windkraftwerk")) {
		type = Windkraftwerk();
	}
	else if (typeString._Equal("Wasserkraftwerk")) {
		type = Wasserkraftwerk();
	}
	else {
		return false;
	}

	// read and check width input
	cout << "Breite: " << endl;
	cin >> widthOfBuilding;
	if (widthOfBuilding < 0 || widthOfBuilding > width) {
		cout << "Ups! Breite ist zu klein oder zu gross." << endl;
		return false;
	}

	// read and check height input
	cout << "Hoehe: " << endl;
	cin >> heightOfBuilding;
	if (heightOfBuilding < 0 || heightOfBuilding > height) {
		cout << "Ups! Hoehe ist zu klein oder zu gross." << endl;
		return false;
	}

	// read and check x coordinate input
	cout << "x-Koordinate: " << endl;
	cin >> xPosition;
	if (xPosition < 0 || xPosition + widthOfBuilding > width) {
		cout << "Ups! Das Gebaeude ragt ueber die verfuegbare Flaeche hinaus." << endl;
		return false;
	}

	// read and check y coordinate input
	cout << "y-Koordinate: " << endl;
	cin >> yPosition;
	if (yPosition < 0 || yPosition + heightOfBuilding > height) {
		cout << "Ups! Das Gebaeude ragt ueber die verfuegbare Flaeche hinaus." << endl;
		return false;
	}

	// check if there are already other buildings in the area
	if (FindOverlappingBuildings(xPosition, yPosition, widthOfBuilding, heightOfBuilding)) {
		cout << "Kann kein Gebaeude setzen! Es existiert bereits eins an dieser Stelle!" << endl;
		return false;
	}

	// setting new building is allowed
	// set new building
	for (int i = xPosition; i < xPosition + widthOfBuilding; i++) {
		for (int j = yPosition; j < yPosition + heightOfBuilding; j++) {
			plan[i][j] = type;
		}
	}

	// return success
	return true;
}

/// <summary>
/// Action Delete Building.
/// </summary>
/// <returns></returns>
bool CapycitySim::DeleteBuilding() {
	int heightOfBuilding;
	int widthOfBuilding;
	int xPosition;
	int yPosition;

	// read and check width input
	cout << "Breite: " << endl;
	cin >> widthOfBuilding;
	if (widthOfBuilding < 0 || widthOfBuilding > width) {
		cout << "Ups! Breite ist zu klein oder zu gross." << endl;
		return false;
	}

	// read and check height input
	cout << "Hoehe: " << endl;
	cin >> heightOfBuilding;
	if (heightOfBuilding < 0 || heightOfBuilding > height) {
		cout << "Ups! Hoehe ist zu klein oder zu gross." << endl;
		return false;
	}

	// read and check x coordinate input
	cout << "x-Koordinate: " << endl;
	cin >> xPosition;
	if (xPosition < 0 || xPosition + widthOfBuilding > width) {
		cout << "Ups! Der zu loeschende Radius ragt ueber die verfuegbare Flaeche hinaus." << endl;
		return false;
	}

	// read and check y coordinate input
	cout << "y-Koordinate: " << endl;
	cin >> yPosition;
	if (yPosition < 0 || yPosition + heightOfBuilding > height) {
		cout << "Ups! Der zu loeschende Radius ragt ueber die verfuegbare Flaeche hinaus." << endl;
		return false;
	}

	for (int i = xPosition; i < xPosition + widthOfBuilding; i++) {
		for (int j = yPosition; j < yPosition + heightOfBuilding; j++) {
			plan[i][j] = Building();
		}
	}

	return true;
}

/// <summary>
/// Action Display Building. Prints current Building Plan.
/// </summary>
/// <returns></returns>
bool CapycitySim::DisplayBuilding() {
	for (int i = 0; i < width; i++) {
		cout << " -------";
	}
	cout << endl;

	for (int i = 0; i < height; i++) {
		cout << "| ";
		for (int j = 0; j < width; j++) {
			cout << plan[j][i].getLabel() + " | ";
		}
		cout << endl;
		for (int j = 0; j < width; j++) {
			cout << " -------";
		}
		cout << endl;
	}
	return true;
}

/// <summary>
/// Starts execution of user action.
/// </summary>
/// <param name="action">The given Action.</param>
void CapycitySim::HandleAction(Action action) {
	if (action == Place) {
		if (PlaceBuilding()) {
			cout << "Gebaeude erfolgreich gesetzt!" << endl;
		}
	}
	else if (action == Delete) {
		if (DeleteBuilding()) {
			cout << "Bereich erfolgreich geloescht!" << endl;
		}
	}
	else {
		DisplayBuilding();
	}
}
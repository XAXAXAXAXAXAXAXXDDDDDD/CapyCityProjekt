// Test.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "main.h"
#include <unordered_map>

using namespace std;

enum Building { Empty, House, Farm };
enum Action { Place, Delete, Display, Exit, Wrong };
string buildings[] = { "Empty", "House", "Farm" };

int Height;
int Width;
Building** plan;

static std::unordered_map<std::string, Building> const table = { {"Empty", Empty}, {"House", House}, {"Farm", Farm} };

Action ShowMenu() {
	string menu = "Menue: \nDruecke 's' um Gebauede zu setzen\nDruecke 'l' um Bereich zu loeschen\nDruecke 'a' um Plan auszugeben\nDruecke 'e' um Programm zu beenden";
	cout << menu << endl;
	string input;
	cin >> input;

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


bool FindOverlappingBuildings(int x, int y, int width, int height) {
	for (int i = x; i < x + width; i++) {
		for (int j = y; j < y + height; j++) {
			if (plan[i][j] != Empty) {
				cout << "Kann kein Gebäude setzen! Es existiert bereits eins an dieser Stelle!" << endl;
				return true;
			}
		}
	}
	return false;
}

bool PlaceBuilding() {
	int heightOfBuilding;
	int widthOfBuilding;
	int xPosition;
	int yPosition;
	Building type;
	string typeString;
	printf("Art (%s, %s, %s): ", buildings[Empty].c_str(), buildings[House].c_str(), buildings[Farm].c_str());
	cin >> typeString;
	auto it = table.find(typeString);
	if (it != table.end()) {
		type = it->second;
	}
	else {
		return false;
	}

	cout << "Hoehe: " << endl;
	cin >> heightOfBuilding;
	if (heightOfBuilding <= 0 || heightOfBuilding >= sizeof(plan[0])) {
		return false;
	}
	cout << "Breite: " << endl;
	cin >> widthOfBuilding;
	if (widthOfBuilding <= 0 || widthOfBuilding >= sizeof(plan)) {
		return false;
	}
	cout << "x-Koordinate: " << endl;
	cin >> xPosition;
	if (xPosition <= 0 || xPosition >= sizeof(plan)) {
		return false;
	}
	cout << "y-Koordinate: " << endl;
	cin >> yPosition;
	// test of size of:
	//cout << sizeof(plan) << endl;
	//cout << sizeof(plan[0]) << endl;
	//cout << (sizeof(plan) / sizeof(plan[0])) << endl;
	//cout << (sizeof(plan[0]) / sizeof(plan[0][0])) << endl;
	if (yPosition <= 0 || yPosition >= sizeof(plan[0])) {
		return false;
	}

	if (FindOverlappingBuildings(xPosition, yPosition, widthOfBuilding, heightOfBuilding)) {
		return false;
	}

	for (int i = xPosition; i < xPosition + widthOfBuilding; i++) {
		for (int j = yPosition; j < yPosition + heightOfBuilding; j++) {
			plan[i][j] = type;
		}
	}

	return true;
}

bool DeleteBuilding() {
	return false;
}

bool DisplayBuilding() {
	return false;
}

void HandleAction(Action action) {
	if (action == Place) {
		if (PlaceBuilding()) {
			cout << "Gebaeude erfolgreich gesetzt!" << endl;
		} 
	}
	else if (action == Delete) {
		DeleteBuilding();
	}
	else {
		DisplayBuilding();
	}
}


int main(int argc, char** argv)
{
	/*std::cout << "Hello World!" << std::endl;
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << std::endl;*/

	if (argc != 3)
		return INT32_MAX;

	char* ptr;
	Height = strtol(argv[1], &ptr, 10);
	Width = strtol(argv[2], &ptr, 10);

	cout << "Erstelleung eines Bauplans der Groesse: " << Height << "x" << Width << endl;

	plan = new Building * [Width];

	for (int i = 0; i < Width; i++) {
		plan[i] = new Building[Height];
		for (int j = 0; j < Height; j++) {
			plan[i][j] = Empty;
		}
	}

	while (1) {
		Action nextAction = ShowMenu();
		if (nextAction == Exit) {
			return 0;
		}
		else if (nextAction == Wrong) {
			continue;
		}

		HandleAction(nextAction);
	}

}


// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.

// Test.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

using namespace std;

enum Building { Empty, House, Farm };
enum Action { Place, Delete, Display, Exit, Wrong };

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

int main(int argc, char** argv)
{
	/*std::cout << "Hello World!" << std::endl;
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << std::endl;*/

	if (argc != 3)
		return INT32_MAX;

	char* ptr;
	long height = strtol(argv[1], &ptr, 10);
	long width = strtol(argv[2], &ptr, 10);

	cout << "Erstelleung eines Bauplans der Groesse: " << height << "x" << width << endl;

	Building** plan = new Building * [width];

	for (int i = 0; i < width; i++) {
		plan[i] = new Building[height];
		for (int j = 0; j < height; j++) {
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

		//HandleAction(nextAction);
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

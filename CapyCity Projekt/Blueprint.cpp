#include "Blueprint.h"

void Blueprint::displayBuildings() {
	cout << endl << "Gebaeude: " << endl;
	map<string, int> buildingToCount;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			string currLabel = plan[i][j].getLabel();
			if (currLabel == "Empty") continue;

			if (buildingToCount.count(currLabel) == 0) {
				buildingToCount.emplace(currLabel, 1);
			}
			else {
				buildingToCount[currLabel]++;
			}
		}
	}

	map<string, Building> labelToDummy = { {"Empty", Building()}, {"Solarpanel", Solarpanel()}, {"Windkraftwerk", Windkraftwerk()}, {"Wasserkraftwerk", Wasserkraftwerk()} };

	int gesamtpreisPlan = 0;

	for (auto& pair : buildingToCount) {
		cout << pair.first << ": " << pair.second << " Felder" << endl << " - - - Einzelpreis pro Baufeld: " << labelToDummy[pair.first].getPreis() << endl << " - - - Benoetigte Materialien pro Baufeld: ";
		labelToDummy[pair.first].materialienAusgeben();
		cout << endl;

		gesamtpreisPlan += labelToDummy[pair.first].getPreis() * pair.second;
	}

	cout << "Gesamtpreis fuer alle Gebaeude und Baufelder des Plans: " << gesamtpreisPlan << endl;
	cout << "Kennzahl des Plans: " << calculateKennzahl() << endl;
}

void Blueprint::displayPlan() {
	cout << endl << endl << "Plan: " << endl;

	cout << " ";
	for (int j = 0; j < width; j++) {
		balkenAusgeben(plan[j][0].getLabel().size());
	}
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			plan[j][i].ausgeben();
		}
		cout << "|" << endl << " ";
		for (int j = 0; j < width; j++) {
			balkenAusgeben(plan[j][i].getLabel().size());
		}
		cout << endl;
	}
}

void Blueprint::balkenAusgeben(int count) {
	for (int i = 0; i <= count; i++) {
		cout << "-";
	}
	cout << "- ";
};

void Blueprint::deleteBuildings(int xPosition, int yPosition, int widthOfArea, int heightOfArea) {
	for (int i = xPosition; i < xPosition + widthOfArea; i++) {
		for (int j = yPosition; j < yPosition + heightOfArea; j++) {
			plan[i][j] = Building();
		}
	}
}

void Blueprint::placeBuildings(int xPosition, int yPosition, int widthOfBuilding, int heightOfBuilding, Building* type) {
	// setting new building is allowed
	// set new building
	for (int i = xPosition; i < xPosition + widthOfBuilding; i++) {
		for (int j = yPosition; j < yPosition + heightOfBuilding; j++) {
			plan[i][j] = *type;
		}
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
bool Blueprint::findOverlappingBuildings(int x, int y, int width, int height) {

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


double Blueprint::calculateKennzahl() {
	double gesamtLeistung = 0.0;
	long gesamtPreis = 0;
	int flaeche = width * height;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			gesamtLeistung += plan[i][j].getLeistung();
			gesamtPreis += plan[i][j].getPreis();
		}
	}

	if (gesamtPreis == 0 || flaeche == 0) return 0;

	return gesamtLeistung / (gesamtPreis * flaeche);
}
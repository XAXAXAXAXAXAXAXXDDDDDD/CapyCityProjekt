#include <iostream>
#include "main.h"
#include <unordered_map>

using namespace std;

#include "CapycitySim.h"

int main(int argc, char** argv)
{

	if (argc != 3) return INT32_MAX;

	int width = strtol(argv[1], argv + 1, 10);
	int height = strtol(argv[2], argv + 2, 10);

	CapycitySim* sim = new CapycitySim(width, height);

	// start user interaction
	while (1) {

		CapycitySim::Action nextAction = sim->ShowMenu();

		if (nextAction == CapycitySim::Exit) {
			return 0;
		}
		else if (nextAction == CapycitySim::Wrong) {
			continue;
		}
		else {
			sim->HandleAction(nextAction);
		}

	}

}
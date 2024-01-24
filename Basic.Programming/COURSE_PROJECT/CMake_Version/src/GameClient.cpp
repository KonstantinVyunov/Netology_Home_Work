#include <iostream>
#include <string>

#include "Functions.h"
#include "Race.h"

#include "Vehicle.h"
#include "GroundVehicle.h"
#include "Camel.h"
#include "Horse.h"
#include "Centaur.h"
#include "Boots.h"

#include "AirVehicle.h"
#include "FlyingCarpet.h"
#include "Eagle.h"
#include "Broom.h"

int main(int argc, char** argv) {
	Race race;
	Camel camel; Horse horse; Centaur centaur; Boots boots;
	FlyingCarpet flying_carpet; Eagle eagle; Broom broom;
	race.all_participants = { &camel, &horse, &centaur, &boots, &flying_carpet, &eagle, &broom };

	std::cout << "\nWELCOME!\n" << std::endl;
	bool game_repeater = true;
	while (game_repeater) {
		std::cout << "Toaday we are racing:" << std::endl;
		printRaceTypes();
		std::cout << "Select the Race type: ";
		race.type = selectRaceType(race);
		std::cout << std::endl;
		std::cout << "Enter the Race distance: ";
		race.distance = enterRaceDistance(race);
		std::cout << std::endl;
		selectionMenu(race);
		std::cout << std::endl;
		race.race_participants.clear();
		std::cout << "Do you want to play one more time?\n"
				  << "1. Yes\n"
				  << "2. Press any key to exit\n" << std::endl;
		std::cout << "Selection: ";
		game_repeater = isGameContinue();
	}
	std::cout << "\nGAME OVER\n";
	return EXIT_SUCCESS;
}
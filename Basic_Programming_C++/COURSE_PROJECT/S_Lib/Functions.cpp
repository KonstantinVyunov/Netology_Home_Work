#include "Functions.h"
#include <algorithm>

void printRaceTypes() {
	std::cout << "1. Ground Race\n"
		<< "2. Air Race\n"
		<< "3. Mixed Race\n" << std::endl;
	return;
}

Type selectRaceType(Race& race) {
	int choice = 0;
	do {
		std::cin >> choice;
		switch (static_cast<Type>(choice)) {
		case Type::ground:
			race.type = Type::ground;
			break;
		case Type::air:
			race.type = Type::air;
			break;
		case Type::mixed:
			race.type = Type::mixed;
			break;
		default:
			std::cout << "Wrong Race type!\nSelect again: ";
			break;
		}
	} while (choice != (int)Type::ground && choice != (int)Type::air && choice != (int)Type::mixed);
	return race.type;
}

int enterRaceDistance(Race& race) {
	do {
		std::cin >> race.distance;
		if (race.distance <= 0) {
			std::cout << "Error! Must be a positive value: ";
		}
	} while (race.distance <= 0);
	return race.distance;
}

void printParticipantsList(const Type& type) {
	if (type == Type::ground) {
		std::cout << "1. Camel" << std::endl;
		std::cout << "2. Horse" << std::endl;
		std::cout << "3. Centaur" << std::endl;
		std::cout << "4. Boots" << std::endl;
		std::cout << "0. To finish selection" << std::endl;
	}
	else if (type == Type::air) {
		std::cout << "1. FlyingCarpet" << std::endl;
		std::cout << "2. Eagle" << std::endl;
		std::cout << "3. Broom" << std::endl;
		std::cout << "0. To finish selection" << std::endl;
	}
	else if (type == Type::mixed) {
		std::cout << "1. Camel" << std::endl;
		std::cout << "2. Horse" << std::endl;
		std::cout << "3. Centaur" << std::endl;
		std::cout << "4. Boots" << std::endl;
		std::cout << "5. FlyingCarpet" << std::endl;
		std::cout << "6. Eagle" << std::endl;
		std::cout << "7. Broom" << std::endl;
		std::cout << "0. To finish selection" << std::endl;
	}
}

bool isAvailable(Race& race, std::string name) {
	if (!race.race_participants.empty()) {
		for (size_t i = 0; i < race.race_participants.size(); ++i) {
			if (race.race_participants[i]->getName() == name) {
				return false;
			}
		}
	}
	return true;
}

std::vector<Vehicle*> selectParticipants(Race& race) {
	int choise = NULL;
	if (race.type == Type::ground) {
		while (std::cout << "Select a participant: " && std::cin >> choise && choise != 0) {
			if (static_cast<GroundVehiclesList>(choise) == GroundVehiclesList::Camel) {
				if (isAvailable(race, "Camel")) {
					std::cout << "Camel is selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::Camel]);
				}
				else {
					std::cout << "Only one camel is allowed!" << std::endl;
				}
			}
			else if (static_cast<GroundVehiclesList>(choise) == GroundVehiclesList::Horse) {
				if (isAvailable(race, "Horse")) {
					std::cout << "Horse is selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::Horse]);
				}
				else {
					std::cout << "Only one horse is allowed!" << std::endl;
				}
			}
			else if (static_cast<GroundVehiclesList>(choise) == GroundVehiclesList::Centaur) {
				if (isAvailable(race, "Centaur")) {
					std::cout << "Centaur is selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::Centaur]);
				}
				else {
					std::cout << "Only one centaur is allowed!" << std::endl;
				}
			}
			else if (static_cast<GroundVehiclesList>(choise) == GroundVehiclesList::Boots) {
				if (isAvailable(race, "Boots")) {
					std::cout << "Boots are selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::Boots]);
				}
				else {
					std::cout << "Only one boots is allowed!" << std::endl;
				}
			}
			else {
				std::cout << "Wrong selection, no such participant on the list!" << std::endl;
			}
		}
		std::cout << std::endl;
	}
	else if (race.type == Type::air) {
		while (std::cout << "Enter your choice here: " && std::cin >> choise && choise != 0) {
			if (static_cast<AirVehiclesList>(choise) == AirVehiclesList::FlyingCarpet) {
				if (isAvailable(race, "FlyingCarpet")) {
					std::cout << "FlyingCarpet is selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::FlyingCarpet]);
				}
				else {
					std::cout << "Only one flying carpet is allowed!" << std::endl;
				}
			}
			else if (static_cast<AirVehiclesList>(choise) == AirVehiclesList::Eagle) {
				if (isAvailable(race, "Eagle")) {
					std::cout << "Eagle is selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::Eagle]);
				}
				else {
					std::cout << "Only one eagle is allowed!" << std::endl;
				}
			}
			else if (static_cast<AirVehiclesList>(choise) == AirVehiclesList::Broom) {
				if (isAvailable(race, "Broom")) {
					std::cout << "Broom is selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::Broom]);
				}
				else {
					std::cout << "Only one broom is allowed!" << std::endl;
				}
			}
			else {
				std::cout << "Wrong selection, no such participant on the list!" << std::endl;
			}
		}
		std::cout << std::endl;
	}
	else if (race.type == Type::mixed) {
		while (std::cout << "Enter your choice here: " && std::cin >> choise && choise != 0) {
			if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::Camel) {
				if (isAvailable(race, "Camel")) {
					std::cout << "Camel is selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::Camel]);
				}
				else {
					std::cout << "Only one camel is allowed!" << std::endl;
				}
			}
			else if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::Horse) {
				if (isAvailable(race, "Horse")) {
					std::cout << "Horse is selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::Horse]);
				}
				else {
					std::cout << "Only one horse is allowed!" << std::endl;
				}
			}
			else if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::Centaur) {
				if (isAvailable(race, "Centaur")) {
					std::cout << "Centaur is selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::Centaur]);
				}
				else {
					std::cout << "Only one centaur is allowed!" << std::endl;
				}
			}
			else if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::Boots) {
				if (isAvailable(race, "Boots")) {
					std::cout << "Boots are selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::Boots]);
				}
				else {
					std::cout << "Only one boots is allowed!" << std::endl;
				}
			}
			else if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::FlyingCarpet) {
				if (isAvailable(race, "FlyingCarpet")) {
					std::cout << "FlyingCarpet is selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::FlyingCarpet]);
				}
				else {
					std::cout << "Only one flying carpet is allowed!" << std::endl;
				}
			}
			else if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::Eagle) {
				if (isAvailable(race, "Eagle")) {
					std::cout << "Eagle is selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::Eagle]);
				}
				else {
					std::cout << "Only one eagle is allowed!" << std::endl;
				}
			}
			else if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::Broom) {
				if (isAvailable(race, "Broom")) {
					std::cout << "Broom is selected." << std::endl;
					race.race_participants.push_back(race.all_participants[(int)Participant::Broom]);
				}
				else {
					std::cout << "Only one broom is allowed!" << std::endl;
				}
			}
			else {
				std::cout << "Wrong selection, no such participant on the list!" << std::endl;
			}
		}
		std::cout << std::endl;
	}
	return race.race_participants;
}

std::vector<std::pair<std::string, double>> sortListResults(std::vector<std::pair<std::string, double>>& results_list) {
	sort(results_list.begin(), results_list.end(),
		[](const std::pair<std::string, double>& lhs, const std::pair<std::string, double>& rhs) {
			return (lhs.second < rhs.second);
		});
	return results_list;
}

std::vector<std::pair<std::string, double>> makeListResults(std::vector<Vehicle*> race_participants, int distance) {
	std::vector<std::pair<std::string, double>> list_resultrs;
	for (const auto& participant : race_participants) {
		list_resultrs.push_back({ participant->getName(), participant->calcTime(distance) });
	}
	return sortListResults(list_resultrs);
}

void printListResults(std::vector<std::pair<std::string, double>> list_resultrs) {
	int place = 0;
	for (const auto& elm : list_resultrs) {
		std::cout << ++place << ". " << elm.first << ". Time: " << elm.second << " hours." << std::endl;
	}
	return;
}

void selectionMenu(Race& race) {
	int selection = 0;
	do {
		std::cout << "SELECTION MENU:\n"
			<< "1. Register Race participants\n"
			<< "2. Start the Race\n" << std::endl;
		std::cout << "Selection: ";
		while (std::cin >> selection && (selection != 1 && selection != 2)) {
			std::cout << "Wrong selection, repeate: ";
		}
		std::cout << std::endl;
		if (selection == 1) {
			std::cout << "Select the Race participants (at least two):" << std::endl;
			printParticipantsList(race.type);
			std::cout << std::endl;
			race.race_participants = selectParticipants(race);
		}
		else if (selection == 2) {
			if (race.race_participants.size() < 2) { // 2 определить как global const min_participants_required
				std::cout << "Not enough participants to start the Race, must be at least two!\n" << std::endl;
			}
			else {
				std::cout << "Race results: " << std::endl;
				std::vector<std::pair<std::string, double>> list_resultrs = makeListResults(race.race_participants, race.distance);
				printListResults(list_resultrs);
				return;
			}
		}
	} while (selection == 2 || selection == 1);
}

bool isGameContinue() {
	int selection = 0;
	std::cin >> selection;
	if (selection == 1) {
		return true;
	}
	else {
		return false;
	}
}
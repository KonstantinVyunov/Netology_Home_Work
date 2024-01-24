#pragma once

#include "Vehicle.h"
#include "Race.h"
//#include <iostream>
//#include <vector>

enum class GroundVehiclesList { Camel = 1, Horse, Centaur, Boots };
enum class AirVehiclesList { FlyingCarpet = 1, Eagle, Broom };
enum class MixedVehiclesList { Camel = 1, Horse, Centaur, Boots, FlyingCarpet, Eagle, Broom };
enum class Participant { Camel, Horse, Centaur, Boots, FlyingCarpet, Eagle, Broom };

void printRaceTypes();

Type selectRaceType(Race& race);

int enterRaceDistance(Race& race);

void printParticipantsList(const Type& type);

bool isAvailable(Race& race, std::string name);

std::vector<Vehicle*> selectParticipants(Race& race);

std::vector<std::pair<std::string, double>> sortListResults(std::vector<std::pair<std::string, double>>& results_list);

std::vector<std::pair<std::string, double>> makeListResults(std::vector<Vehicle*> race_participants, int distance);

void printListResults(std::vector<std::pair<std::string, double>> list_resultrs);

void selectionMenu(Race& race);

bool isGameContinue();
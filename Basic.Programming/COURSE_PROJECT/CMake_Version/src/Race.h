#pragma once

#include <vector>
#include "Vehicle.h"

enum class Type { ground = 1, air = 2, mixed = 3 };

struct Race {
	Type type = {};
	int distance = NULL;
	std::vector<Vehicle*> race_participants = {};
	std::vector<Vehicle*> all_participants = {};
};
#include "Eagle.h"

Eagle::Eagle() : AirVehicle("Eagle", 8) {
	this->distance_reduction_factor = 0.06;
}

double Eagle::calcTime(int distance) {
	return (distance * (1 - distance_reduction_factor) / getSpeed());
};

Eagle::~Eagle() = default;
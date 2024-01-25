#include "Broom.h"

Broom::Broom() : AirVehicle("Broom", 20) {
	this->distance_reduction_factor_each_1000 = 0.01;
}

double Broom::calcTime(int distance) {
	const double overall_distance_reduction_factor = (1 - (trunc(distance / 1000) * distance_reduction_factor_each_1000));
	return (distance * overall_distance_reduction_factor) / getSpeed();
};

Broom::~Broom() = default;
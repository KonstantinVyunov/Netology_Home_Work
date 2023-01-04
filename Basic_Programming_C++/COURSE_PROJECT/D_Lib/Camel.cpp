#include "Camel.h"

Camel::Camel(std::string name, double speed, double moving_time) : GroundVehicle(name, speed, moving_time) {
	this->first_resting_time = 5;
	this->other_resting_time = 8;
}

Camel::Camel() : Camel("Camel", 10, 30) {}

double Camel::calcTime(int distance) {
	double one_range_time = distance / getSpeed();
	if (one_range_time <= getMovingTime()) {
		return one_range_time;
	}
	else if ((one_range_time > getMovingTime()) && (one_range_time <= (2 * getMovingTime()))) {
		return (one_range_time + first_resting_time);
	}
	else {
		return (one_range_time + other_resting_time * (ceil(one_range_time / getMovingTime()) - 2) + first_resting_time);
	}
};

Camel::~Camel() = default;
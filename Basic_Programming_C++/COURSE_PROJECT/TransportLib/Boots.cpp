#include "Boots.h"

Boots::Boots(std::string name, double speed, double moving_time) : GroundVehicle(name, speed, moving_time) {
	this->first_resting_time = 10;
	this->other_resting_time = 5;
}

Boots::Boots() : Boots("Boots", 6, 60) {}

double Boots::calcTime(int distance) {
	double one_range_time = distance / getSpeed();
	if (one_range_time <= getMovingTime()) {
		return one_range_time;
	}
	else if ((one_range_time > getMovingTime()) && (one_range_time <= (2 * getMovingTime()))) {
		return (one_range_time + first_resting_time);
	}
	else {
		return (one_range_time + first_resting_time + other_resting_time * (ceil(distance / (getSpeed() * getMovingTime())) - 2));
	}
};

Boots::~Boots() = default;
#include "Horse.h"

Horse::Horse(std::string name, double speed, double moving_time) : GroundVehicle(name, speed, moving_time) {
	this->first_resting_time = 5;
	this->second_resting_time = 6.5;
	this->other_resting_time = 8;
}

Horse::Horse() : Horse("Horse", 40, 10) {}

double Horse::calcTime(int distance) {
	double one_range_time = distance / getSpeed();
	if (one_range_time <= getMovingTime()) {
		return one_range_time;
	}
	else if ((one_range_time > getMovingTime()) && (one_range_time <= (2 * getMovingTime()))) {
		return (one_range_time + first_resting_time);
	}
	else if ((one_range_time > (2 * getMovingTime())) && (one_range_time <= (3 * getMovingTime()))) {
		return (one_range_time + first_resting_time + second_resting_time);
	}
	else {
		return (one_range_time + first_resting_time + second_resting_time + other_resting_time * (ceil(distance / (getSpeed() * getMovingTime())) - 3));
	}
};

Horse::~Horse() = default;
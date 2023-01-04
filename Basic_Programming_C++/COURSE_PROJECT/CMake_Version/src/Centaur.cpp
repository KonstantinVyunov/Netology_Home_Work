#include "Centaur.h"

Centaur::Centaur(std::string name, double speed, double moving_time) : GroundVehicle(name, speed, moving_time) {
	this->resting_time = 2;
}

Centaur::Centaur() : Centaur("Centaur", 15, 8) {}

double Centaur::calcTime(int distance) {
	double one_range_time = distance / getSpeed();
	if (one_range_time <= getMovingTime()) {
		return one_range_time;
	}
	else {
		return one_range_time + resting_time * (one_range_time / getMovingTime() - 1);
	}
};

Centaur::~Centaur() = default;
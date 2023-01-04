#include "Vehicle.h"

Vehicle::Vehicle(std::string name, double speed) {
	this->name = name;
	this->speed = speed;
}

Vehicle::Vehicle() : Vehicle("Vehicle", NULL) {}

std::string Vehicle::getName() const { return name; }

double Vehicle::getSpeed() const { return speed; }

double Vehicle::calcTime(int distance) { return 0; };

Vehicle::~Vehicle() = default;
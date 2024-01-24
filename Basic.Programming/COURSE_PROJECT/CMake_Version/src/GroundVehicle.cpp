#include "GroundVehicle.h"

GroundVehicle::GroundVehicle(std::string name, double speed, double moving_time) : Vehicle(name, speed) {
	this->moving_time = moving_time;
}

GroundVehicle::GroundVehicle() : GroundVehicle("GroundVehicle", 0, 0) {}

double GroundVehicle::getMovingTime() const { return this->moving_time; }

double GroundVehicle::calcTime(int distance) { return 0; };

GroundVehicle::~GroundVehicle() = default;
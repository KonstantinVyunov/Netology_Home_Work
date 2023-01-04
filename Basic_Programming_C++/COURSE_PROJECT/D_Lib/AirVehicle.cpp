#include "AirVehicle.h"

AirVehicle::AirVehicle(std::string name, double speed) : Vehicle(name, speed) {}

AirVehicle::AirVehicle() : AirVehicle("AirVehicle", 0) {};

double AirVehicle::calcTime(int distance) { return 0; };

AirVehicle::~AirVehicle() = default;
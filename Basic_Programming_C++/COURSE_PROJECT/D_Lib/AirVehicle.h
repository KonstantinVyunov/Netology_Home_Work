#pragma once

#include "Vehicle.h"

class AirVehicle : public Vehicle {
private:

protected:
	AirVehicle(std::string name, double speed);
public:
	LIBRARY_API AirVehicle();

	LIBRARY_API double calcTime(int distance) override;

	virtual ~AirVehicle();
};
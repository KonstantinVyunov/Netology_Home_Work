#pragma once

#include "GroundVehicle.h"

class Centaur : public GroundVehicle {
private:
public:
	double resting_time;
protected:
	Centaur(std::string name, double speed, double moving_time);
public:
	LIBRARY_API Centaur();

	LIBRARY_API double calcTime(int distance) override;

	LIBRARY_API virtual ~Centaur();
};
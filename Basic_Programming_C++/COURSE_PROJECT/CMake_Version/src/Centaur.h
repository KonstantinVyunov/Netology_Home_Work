#pragma once

#include "GroundVehicle.h"

class Centaur : public GroundVehicle {
private:
public:
	double resting_time;
protected:
	Centaur(std::string name, double speed, double moving_time);
public:
	DYNAMICLIB_API Centaur();

	DYNAMICLIB_API double calcTime(int distance) override;

	DYNAMICLIB_API virtual ~Centaur();
};
#pragma once

#include "GroundVehicle.h"

class Camel : public GroundVehicle {
private:
public:
	double first_resting_time;
	double other_resting_time;
protected:
	Camel(std::string name, double speed, double moving_time);
public:
	DYNAMICLIB_API Camel();

	DYNAMICLIB_API double calcTime(int distance) override;

	DYNAMICLIB_API virtual ~Camel();
};
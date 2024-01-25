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
	LIBRARY_API Camel();

	LIBRARY_API double calcTime(int distance) override;

	LIBRARY_API virtual ~Camel();
};
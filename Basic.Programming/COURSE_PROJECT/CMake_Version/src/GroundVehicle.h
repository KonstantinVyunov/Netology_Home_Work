#pragma once

#include "Vehicle.h"

class GroundVehicle : public Vehicle {
private:
	double moving_time = NULL;
protected:
	GroundVehicle(std::string name, double speed, double moving_time);
public:
	DYNAMICLIB_API GroundVehicle();

	double getMovingTime() const;

	DYNAMICLIB_API double calcTime(int distance) override;

	virtual ~GroundVehicle();
};
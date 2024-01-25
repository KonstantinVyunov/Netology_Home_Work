#pragma once

#include "AirVehicle.h"

class Eagle : public AirVehicle {
private:
public:
	double distance_reduction_factor;
public:
	DYNAMICLIB_API Eagle();

	DYNAMICLIB_API double calcTime(int distance) override;

	DYNAMICLIB_API virtual ~Eagle();
};
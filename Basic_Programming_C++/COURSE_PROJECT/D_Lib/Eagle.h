#pragma once

#include "AirVehicle.h"

class Eagle : public AirVehicle {
private:
public:
	double distance_reduction_factor;
public:
	LIBRARY_API Eagle();

	LIBRARY_API double calcTime(int distance) override;

	LIBRARY_API virtual ~Eagle();
};
#pragma once

#include "AirVehicle.h"

class Broom : public AirVehicle {
private:
public:
	double distance_reduction_factor_each_1000;
public:
	LIBRARY_API Broom();

	LIBRARY_API double calcTime(int distance) override;

	LIBRARY_API virtual ~Broom();
};
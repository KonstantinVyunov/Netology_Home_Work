#pragma once

#include "AirVehicle.h"

class Broom : public AirVehicle { // Метла
private:
public:
	double distance_reduction_factor_each_1000;
public:
	DYNAMICLIB_API Broom();

	DYNAMICLIB_API double calcTime(int distance) override;

	DYNAMICLIB_API virtual ~Broom();
};
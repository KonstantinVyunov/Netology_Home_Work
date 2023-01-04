#pragma once

#include "AirVehicle.h"

class FlyingCarpet : public AirVehicle {
private:
public:
	double distance_reduction_factor_less_1000;
	double distance_reduction_factor_less_5000;
	double distance_reduction_factor_less_10000;
	double distance_reduction_factor_more_10000;
public:
	LIBRARY_API FlyingCarpet();

	LIBRARY_API double calcTime(int distance) override;

	LIBRARY_API virtual ~FlyingCarpet();
};
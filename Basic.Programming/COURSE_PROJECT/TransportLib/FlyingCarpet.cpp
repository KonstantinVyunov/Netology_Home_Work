#include "FlyingCarpet.h"

FlyingCarpet::FlyingCarpet() : AirVehicle("FlyingCarpet", 10) {
	this->distance_reduction_factor_less_1000 = 1;
	this->distance_reduction_factor_less_5000 = 0.03;
	this->distance_reduction_factor_less_10000 = 0.1;
	this->distance_reduction_factor_more_10000 = 0.05;
}

double FlyingCarpet::calcTime(int distance) {
	if (distance < 1000) {
		return ((distance * distance_reduction_factor_less_1000) / getSpeed());
	}
	else if (distance >= 1000 && distance < 5000) {
		return (distance * (1 - distance_reduction_factor_less_5000) / getSpeed());
	}
	else if (distance >= 5000 && distance < 10000) {
		return (distance * (1 - distance_reduction_factor_less_10000) / getSpeed());
	}
	else {
		return (distance * (1 - distance_reduction_factor_more_10000) / getSpeed());
	}
};

FlyingCarpet::~FlyingCarpet() = default;
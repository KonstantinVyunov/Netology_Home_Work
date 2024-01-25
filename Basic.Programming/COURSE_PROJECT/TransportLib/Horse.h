#pragma once

#include "GroundVehicle.h"

class Horse : public GroundVehicle { // Скоростной Верблюд
private:
public:
	double first_resting_time;
	double second_resting_time;
	double other_resting_time;
protected:
	Horse(std::string name, double speed, double moving_time);
public:
	LIBRARY_API Horse();

	LIBRARY_API double calcTime(int distance) override;

	LIBRARY_API virtual ~Horse();
};
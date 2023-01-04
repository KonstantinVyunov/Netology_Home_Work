#pragma once

#include "GroundVehicle.h"

class Boots : public GroundVehicle { // Сапоги Скороходы
private:
public:
	double first_resting_time;
	double other_resting_time;
protected:
	Boots(std::string name, double speed, double moving_time);
public:
	LIBRARY_API Boots();

	LIBRARY_API double calcTime(int distance) override;

	LIBRARY_API virtual ~Boots();
};
#pragma once

#include "GroundVehicle.h"

class Boots : public GroundVehicle { // ������ ���������
private:
public:
	double first_resting_time;
	double other_resting_time;
protected:
	Boots(std::string name, double speed, double moving_time);
public:
	DYNAMICLIB_API Boots();

	DYNAMICLIB_API double calcTime(int distance) override;

	DYNAMICLIB_API virtual ~Boots();
};
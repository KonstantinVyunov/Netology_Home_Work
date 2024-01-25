#pragma once

#ifdef DYNAMIC_LIB_EXPORT
	#define DYNAMICLIB_API __declspec(dllexport)
#else
	#define DYNAMICLIB_API __declspec(dllimport)
#endif

#include <cmath>
#include <iostream>

class Vehicle {
private:
	std::string name = {};
	double speed = NULL;
protected:
	Vehicle(std::string name, double speed);
public:
	DYNAMICLIB_API Vehicle();

	DYNAMICLIB_API std::string getName() const;

	double getSpeed() const;

	DYNAMICLIB_API virtual double calcTime(int distance);

	virtual ~Vehicle();
};
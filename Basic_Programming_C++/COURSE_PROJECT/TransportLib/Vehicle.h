#pragma once

#include <cmath>
#include <iostream>

#ifdef LIBRARY_DYNAMIC_EXPORTS
	#define LIBRARY_API __declspec(dllexport)
#else
	#define LIBRARY_API __declspec(dllimport)
#endif

class Vehicle {
private:
	std::string name = {};
	double speed = NULL;
protected:
	Vehicle(std::string name, double speed);
public:
	LIBRARY_API Vehicle();

	LIBRARY_API std::string getName() const;

	double getSpeed() const;

	LIBRARY_API virtual double calcTime(int distance);

	virtual ~Vehicle();
};
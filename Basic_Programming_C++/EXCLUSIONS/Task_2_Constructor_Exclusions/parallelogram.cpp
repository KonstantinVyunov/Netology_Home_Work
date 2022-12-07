#include "ParallelogramError.h"
#include "Parallelogram.h"
#include <iostream>

Parallelogram::Parallelogram(
		int length_a, int length_b, int length_c, int length_d,
		int angle_A, int angle_B, int angle_C, int angle_D)
		: Quadrangle(
			length_a, length_b, length_c, length_d,
			angle_A, angle_B, angle_C, angle_D)
{
	setFigureName("Parallelogram");
	if (!((getLengthA() == getLengthC() && getLengthB() == getLengthD())
		&& (getAngleA() == getAngleC() && getAngleB() == getAngleD())))
	{
		std::cout << getFigureName()
			<< " (sides " << getNumSides() << " - " << getLengthA() << ", " << getLengthB()
			<< ", " << getLengthC() << ", " << getLengthD() << "; "
			<< "angles " << getNumAngles() << " - " << getAngleA() << ", " << getAngleB()
			<< ", " << getAngleC() << ", " << getAngleD() << ") is NOT created. ";
		throw ParallelogramError();
	}
}
Parallelogram::~Parallelogram() = default;
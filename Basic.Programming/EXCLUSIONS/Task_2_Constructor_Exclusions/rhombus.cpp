#include "RhombusError.h"
#include "Rhombus.h"
#include <iostream>

Rhombus::Rhombus(
		int length_a, int length_b, int length_c, int length_d,
		int angle_A, int angle_B, int angle_C, int angle_D)
		: Parallelogram(
			length_a, length_b, length_c, length_d,
			angle_A, angle_B, angle_C, angle_D)
{
	setFigureName("Rhombus");
	if (!((getLengthA() == getLengthB() && getLengthC() == getLengthD() && getLengthA() == getLengthC())
		&& ((getAngleA() == getAngleC()) && (getAngleB() == getAngleD())))) {
		std::cout << Rhombus::getFigureName()
			<< " (sides " << getNumSides() << " - " << ' ' << getLengthA() << ", " << getLengthB()
			<< ", " << getLengthC() << ", " << getLengthD() << "; "
			<< "angles " << getNumAngles() << " - " << ' ' << getAngleA() << ", " << getAngleB()
			<< ", " << getAngleC() << ", " << getAngleD() << ") is NOT created. ";
			throw RhombusError();
	}
}

Rhombus::~Rhombus() = default;
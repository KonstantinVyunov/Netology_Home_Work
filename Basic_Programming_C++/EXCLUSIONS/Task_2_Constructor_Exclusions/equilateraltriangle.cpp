#include "EquilateralTriangleError.h"
#include "EquilateralTriangle.h"
#include <iostream>

EquilateralTriangle::EquilateralTriangle(
		int length_a, int length_b, int length_c,
		int angle_A, int angle_B, int angle_C)
		: IsoscelesTriangle(
			length_a, length_b, length_c,
			angle_A, angle_B, angle_C)
{
	setFigureName("EquilateralTriangle");
	if (!(((getAngleA() == getAngleB()) && (getAngleA() == getAngleC())) &&
		((getLengthA() == getLengthB()) && (getLengthA() == getLengthC())))) {
		std::cout << getFigureName()
			<< " (sides " << getLengthA() << ", " << getLengthB() << ", " << getLengthC() << "; "
			<< "angles " << getAngleA() << ", " << getAngleB() << ", " << getAngleC() << ") is NOT created. ";
		throw EquilateralTriangleError();
	}
}

EquilateralTriangle::~EquilateralTriangle() = default;
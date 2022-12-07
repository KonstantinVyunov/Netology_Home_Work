#include "IsoscelesTriangleError.h"
#include "IsoscelesTriangle.h"
#include <iostream>

IsoscelesTriangle::IsoscelesTriangle(
		int length_a, int length_b, int length_c,
		int angle_A, int angle_B, int angle_C)
		: Triangle(
			length_a, length_b, length_c,
			angle_A, angle_B, angle_C)
{
	setFigureName("IsoscelesTriangle");
	if (!((getAngleA() == getAngleC()) && (getLengthA() == getLengthC()))) {
		std::cout << getFigureName()
			<< " (sides " << getLengthA() << ", " << getLengthB() << ", " << getLengthC() << "; "
			<< "angles " << getAngleA() << ", " << getAngleB() << ", " << getAngleC() << ") is NOT created. ";
		throw IsoscelesTriangleError();
	}
}

IsoscelesTriangle::~IsoscelesTriangle() = default;
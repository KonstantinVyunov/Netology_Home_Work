#include "SquareError.h"
#include "Square.h"
#include <iostream>

Square::Square(
		int length_a, int length_b, int length_c, int length_d,
		int angle_A, int angle_B, int angle_C, int angle_D)
		: Rectangle(
			length_a, length_b, length_c, length_d,
			angle_A, angle_B, angle_C, angle_D)
{
	setFigureName("Square");
	if (!((getLengthA() == getLengthB() || getLengthC() == getLengthD() || getLengthA() == getLengthC())
		|| (getAngleA() == getAngleB() || getAngleC() == getAngleD() || getAngleA() == getAngleC()))) {
		std::cout << getFigureName()
			<< " (sides " << getNumSides() << " - " << getLengthA() << ", " << getLengthB()
			<< ", " << getLengthC() << ", " << getLengthD() << "; "
			<< "angles " << getNumAngles() << " - " << getAngleA() << ", " << getAngleB()
			<< ", " << getAngleC() << ", " << getAngleD() << ") is NOT created. ";
		throw SquareError();
	}
}
Square::~Square() = default;
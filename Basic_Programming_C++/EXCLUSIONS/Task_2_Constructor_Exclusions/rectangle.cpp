#include "RectangleError.h"
#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(
		int length_a, int length_b, int length_c, int length_d,
		int angle_A, int angle_B, int angle_C, int angle_D)
		: Parallelogram(
			length_a, length_b, length_c, length_d,
			angle_A, angle_B, angle_C, angle_D)
	{
		setFigureName("Rectangle");
		if ((getLengthA() != getLengthC() || getLengthB() != getLengthD()) ||
			getAngleA() != 90 || getAngleB() != 90 || getAngleC() != 90 || getAngleD() != 90) {
			std::cout << getFigureName()
				<< " (sides " << getNumSides() << " - " << getLengthA() << ", " << getLengthB()
				<< ", " << getLengthC() << ", " << getLengthD() << "; "
				<< "angles " << getNumAngles() << " - " << getAngleA() << ", " << getAngleB()
				<< ", " << getAngleC() << ", " << getAngleD() << ") is NOT created. ";
			throw RectangleError();
		}
	}
Rectangle::~Rectangle() = default;
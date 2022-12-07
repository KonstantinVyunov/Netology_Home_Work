#include "TriangleError.h"
#include "Triangle.h"
#include <iostream>

Triangle::Triangle(
	int length_a, int length_b, int length_c,
	int angle_A, int angle_B, int angle_C)
	{
		setFigureName("Triangle");
		setNumSides(3);
		setNumAngles(3);
		setLengthA(length_a);
		setLengthB(length_b);
		setLengthC(length_c);
		setAngleA(angle_A);
		setAngleB(angle_B);
		setAngleC(angle_C);
		if ((angle_A + angle_B + angle_C) != 180) {
			std::cout << getFigureName()
				<< " (sides " << ' ' << getNumSides() << " - " << getLengthA() << ", " << getLengthB() << ", " << getLengthC() << "; "
				<< "angles " << getNumAngles() << " - " << getAngleA() << ", " << getAngleB() << ", " << getAngleC() << ") is NOT created. ";
			throw TriangleError();
		}
	}

	int Triangle::getLengthA() const { return this->length_a; }
	int Triangle::getLengthB() const { return this->length_b; }
	int Triangle::getLengthC() const { return this->length_c; }
	int Triangle::getAngleA() const { return this->angle_A; }
	int Triangle::getAngleB() const { return this->angle_B; }
	int Triangle::getAngleC() const { return this->angle_C; }

	const void Triangle::setLengthA(int length_a_) { this->length_a = length_a_; }
	const void Triangle::setLengthB(int length_b_) { this->length_b = length_b_; }
	const void Triangle::setLengthC(int length_c_) { this->length_c = length_c_; }
	const void Triangle::setAngleA(int angle_A_) { this->angle_A = angle_A_; }
	const void Triangle::setAngleB(int angle_B_) { this->angle_B = angle_B_; }
	const void Triangle::setAngleC(int angle_C_) { this->angle_C = angle_C_; }

	void Triangle::printSides() const {
		std::cout << getNumSides() << " - " << getLengthA() << ", " << getLengthB() << ", " << getLengthC();
	}
	void Triangle::printAngles() const {
		std::cout << getNumAngles() << " - " << getAngleA() << ", " << getAngleB() << ", " << getAngleC();
	}

Triangle::~Triangle() = default;
#include "QuadrangleError.h"
#include "Quadrangle.h"
#include <iostream>

Quadrangle::Quadrangle(
		int length_a, int length_b, int length_c, int length_d,
		int angle_A, int angle_B, int angle_C, int angle_D)
	{
		setFigureName("Quadrangle");
		setNumSides(4);
		setNumAngles(4);
		setLengthA(length_a);
		setLengthB(length_b);
		setLengthC(length_c);
		setLengthD(length_d);
		setAngleA(angle_A);
		setAngleB(angle_B);
		setAngleC(angle_C);
		setAngleD(angle_D);
		if ((getAngleA() + getAngleB() + getAngleC() + getAngleD()) != 360) {
			std::cout << getFigureName()
				<< " (sides " << getNumSides() << " - " << getLengthA() << ", " << getLengthB()
				<< ", " << getLengthC() << ", " << getLengthD() << "; "
				<< "angles " << getNumAngles() << " - " << getAngleA() << ", " << getAngleB()
				<< ", " << getAngleC() << ", " << getAngleD() << ") is NOT created. ";
			throw QuadrangleError();
		}
	}
	int Quadrangle::getLengthA() const { return this->length_a; }
	int Quadrangle::getLengthB() const { return this->length_b; }
	int Quadrangle::getLengthC() const { return this->length_c; }
	int Quadrangle::getLengthD() const { return this->length_d; }
	int Quadrangle::getAngleA()  const { return this->angle_A; }
	int Quadrangle::getAngleB()  const { return this->angle_B; }
	int Quadrangle::getAngleC()  const { return this->angle_C; }
	int Quadrangle::getAngleD()  const { return this->angle_D; }

	const void Quadrangle::setLengthA(int length_a_) { this->length_a = length_a_; }
	const void Quadrangle::setLengthB(int length_b_) { this->length_b = length_b_; }
	const void Quadrangle::setLengthC(int length_c_) { this->length_c = length_c_; }
	const void Quadrangle::setLengthD(int length_d_) { this->length_d = length_d_; }
	const void Quadrangle::setAngleA(int angle_A_) { this->angle_A = angle_A_; }
	const void Quadrangle::setAngleB(int angle_B_) { this->angle_B = angle_B_; }
	const void Quadrangle::setAngleC(int angle_C_) { this->angle_C = angle_C_; }
	const void Quadrangle::setAngleD(int angle_D_) { this->angle_D = angle_D_; }

	void Quadrangle::printSides() const {
		std::cout << getNumSides() << " - " << getLengthA() << ", " << getLengthB() << ", "
			<< getLengthC() << ", " << getLengthD();
	}
	void Quadrangle::printAngles() const {
		std::cout << getNumAngles() << " - " << getAngleA() << ", " << getAngleB() << ", "
			<< getAngleC() << ", " << getAngleD();
	}

Quadrangle::~Quadrangle() = default;
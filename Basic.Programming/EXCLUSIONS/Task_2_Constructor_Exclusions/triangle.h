#pragma once
#include "Figure.h"

class Triangle : public Figure {
private:
	int length_a{ 0 }, length_b{ 0 }, length_c{ 0 };
	int angle_A{ 0 }, angle_B{ 0 }, angle_C{ 0 };
public:
	Triangle
			(
			int length_a, int length_b, int length_c,
			int angle_A, int angle_B, int angle_C
			);

	int getLengthA() const;
	int getLengthB() const;
	int getLengthC() const;
	int getAngleA() const;
	int getAngleB() const;
	int getAngleC() const;

	const void setLengthA(int length_a_);
	const void setLengthB(int length_b_);
	const void setLengthC(int length_c_);
	const void setAngleA(int angle_A_);
	const void setAngleB(int angle_B_);
	const void setAngleC(int angle_C_);

	void printSides() const override;
	void printAngles() const override;

	~Triangle();
};
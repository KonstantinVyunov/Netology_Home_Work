#pragma once
#include "IsoscelesTriangle.h"

class EquilateralTriangle : public IsoscelesTriangle {
public:
	EquilateralTriangle(
		int length_a, int length_b, int length_c,
		int angle_A, int angle_B, int angle_C);

	~EquilateralTriangle();
};
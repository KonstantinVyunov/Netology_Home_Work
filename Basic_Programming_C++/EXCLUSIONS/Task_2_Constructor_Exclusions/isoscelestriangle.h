#pragma once
#include "Triangle.h"

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(
		int length_a, int length_b, int length_c,
		int angle_A, int angle_B, int angle_C);

	~IsoscelesTriangle();
};
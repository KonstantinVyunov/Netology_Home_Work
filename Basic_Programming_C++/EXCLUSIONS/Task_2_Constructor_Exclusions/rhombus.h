#pragma once
#include "Parallelogram.h"

class Rhombus : public Parallelogram {
public:
	Rhombus(
		int length_a, int length_b, int length_c, int length_d,
		int angle_A, int angle_B, int angle_C, int angle_D);

	~Rhombus();
};
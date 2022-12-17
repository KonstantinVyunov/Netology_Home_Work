#pragma once
#include "parallelogram.h"

class Rectangle : public Parallelogram {
protected:
	Rectangle(
		std::string figure_name,
		int length_a, int length_b, int length_c, int length_d,
		int angl_A, int angl_B, int angl_C, int angl_D);
public:
	HIERARCHYDYNAMICLIB_API Rectangle(
		int length_a, int length_b, int length_c, int length_d,
		int angl_A, int angl_B, int angl_C, int angl_D);
};
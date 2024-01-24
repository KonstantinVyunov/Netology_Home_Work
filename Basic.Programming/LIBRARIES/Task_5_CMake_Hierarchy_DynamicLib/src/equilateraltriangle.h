#pragma once
#include "isoscelestriangle.h"

class EquilateralTriangle : public IsoscelesTriangle {
protected:
	EquilateralTriangle(
		std::string figure_name,
		int length_a, int length_b, int length_c,
		int angl_A, int angl_B, int angl_C);
public:
	HIERARCHYDYNAMICLIB_API EquilateralTriangle(
		int length_a, int length_b, int length_c,
		int angl_A, int angl_B, int angl_C);
};
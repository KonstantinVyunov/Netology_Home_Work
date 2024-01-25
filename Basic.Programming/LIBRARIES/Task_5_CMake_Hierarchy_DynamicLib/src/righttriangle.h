#pragma once
#include "triangle.h"

class RightTriangle : public Triangle {
protected:
	RightTriangle(
		std::string figure_name,
		int length_a, int length_b, int length_c,
		int angl_A, int angl_B, int angl_C);
public:
	HIERARCHYDYNAMICLIB_API RightTriangle(
		int length_a, int length_b, int length_c,
		int angl_A, int angl_B, int angl_C);
};
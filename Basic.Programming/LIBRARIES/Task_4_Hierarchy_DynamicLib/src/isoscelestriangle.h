#pragma once

#include "triangle.h"

class IsoscelesTriangle : public Triangle {
protected:
	IsoscelesTriangle(
		std::string figure_name,
		int length_a, int length_b, int length_c,
		int angl_A, int angl_B, int angl_C);
public:
	HIERARCHYDYNAMICLIB_API IsoscelesTriangle(
		int length_a, int length_b, int length_c,
		int angl_A, int angl_B, int angl_C);
};
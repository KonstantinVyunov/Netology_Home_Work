#include "equilateraltriangle.h"
#include "isoscelestriangle.h"

EquilateralTriangle::EquilateralTriangle(
	std::string figure_name,
	int length_a, int length_b, int length_c,
	int angl_A, int angl_B, int angl_C)
	: IsoscelesTriangle(
		figure_name,
		length_a, length_b, length_c,
		angl_A, angl_B, angl_C)
{}

EquilateralTriangle::EquilateralTriangle(
	int length_a, int length_b, int length_c,
	int angl_A, int angl_B, int angl_C)
	: EquilateralTriangle(
		"Equilateraltriangle",
		length_a, length_b, length_c,
		angl_A, angl_B, angl_C)
{}
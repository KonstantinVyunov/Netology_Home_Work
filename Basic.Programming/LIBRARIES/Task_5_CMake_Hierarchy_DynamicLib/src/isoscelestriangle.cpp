#include "isoscelestriangle.h"
#include "triangle.h"

IsoscelesTriangle::IsoscelesTriangle(
	std::string figure_name,
	int length_a, int length_b, int length_c,
	int angl_A, int angl_B, int angl_C)
	: Triangle(
		figure_name, length_a, length_b,
		length_c, angl_A, angl_B, angl_C)
{}

IsoscelesTriangle::IsoscelesTriangle(
	int length_a, int length_b, int length_c,
	int angl_A, int angl_B, int angl_C)
	: IsoscelesTriangle(
		"Isoscelestriangle",
		length_a, length_b, length_c,
		angl_A, angl_B, angl_C)
{}
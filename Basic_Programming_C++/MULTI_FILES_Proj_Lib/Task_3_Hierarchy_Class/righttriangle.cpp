#include "righttriangle.h"

RightTriangle::RightTriangle(
	std::string figure_name,
	int length_a, int length_b, int length_c,
	int angl_A, int angl_B, int angl_C)
	: Triangle(
		figure_name,
		length_a, length_b, length_c,
		angl_A, angl_B, angl_C)
{}

RightTriangle::RightTriangle(
	int length_a, int length_b, int length_c,
	int angl_A, int angl_B, int angl_C)
	: RightTriangle(
		"RightTriangle",
		length_a, length_b, length_c,
		angl_A, angl_B, angl_C)
{}
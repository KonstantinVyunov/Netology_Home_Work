#include "parallelogram.h"


Parallelogram::Parallelogram(
	std::string figure_name,
	int length_a, int length_b, int length_c, int length_d,
	int angl_A, int angl_B, int angl_C, int angl_D)
	: Quadrangle(
		figure_name,
		length_a, length_b, length_c, length_d,
		angl_A, angl_B, angl_C, angl_D)
{}

Parallelogram::Parallelogram(
	int length_a, int length_b, int length_c, int length_d,
	int angl_A, int angl_B, int angl_C, int angl_D)
	: Parallelogram(
		"Parallelogram",
		length_a, length_b, length_c, length_d,
		angl_A, angl_B, angl_C, angl_D)
{}
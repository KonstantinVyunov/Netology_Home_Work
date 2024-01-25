#pragma once

#include "square.h"

class Rhombus : public Square {
protected:
	Rhombus(
		std::string figure_name,
		int length_a, int length_b, int length_c, int length_d,
		int angl_A, int angl_B, int angl_C, int angl_D);
public:
	Rhombus(
		int length_a, int length_b, int length_c, int length_d,
		int angl_A, int angl_B, int angl_C, int angl_D);
};
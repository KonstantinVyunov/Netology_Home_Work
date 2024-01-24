#pragma once

#include "quadrangle.h"

class Square : public Quadrangle {
protected:
	Square(
		std::string figure_name,
		int length_a, int length_b, int length_c, int length_d,
		int angl_A, int angl_B, int angl_C, int angl_D);
public:
	Square(
		int length_a, int length_b, int length_c, int length_d,
		int angl_A, int angl_B, int angl_C, int angl_D);
};
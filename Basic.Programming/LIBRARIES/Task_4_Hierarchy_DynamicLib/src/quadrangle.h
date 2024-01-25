#pragma once

#include "figure.h"

class Quadrangle : public Figure {
private:
	int length_a{ 0 }, length_b{ 0 }, length_c{ 0 }, length_d{ 0 };
	int angl_A{ 0 }, angl_B{ 0 }, angl_C{ 0 }, angl_D{ 0 };
protected:
	Quadrangle(
		std::string figure_name,
		int length_a, int length_b, int length_c, int length_d,
		int angl_A, int angl_B, int angl_C, int angl_D);
	std::string printSides() const override;
	std::string printAngles() const override;
public:
	HIERARCHYDYNAMICLIB_API Quadrangle(
		int length_a, int length_b, int length_c, int length_d,
		int angl_A, int angl_B, int angl_C, int angl_D);

	int get_length_a() const;
	int get_length_b() const;
	int get_length_c() const;
	int get_length_d() const;
	int get_angle_A() const;
	int get_angle_B() const;
	int get_angle_C() const;
	int get_angle_D() const;
};
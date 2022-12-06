#pragma once
#include "figure.h"

class Triangle : public Figure {
private:
	int length_a{ 0 }, length_b{ 0 }, length_c{ 0 };
	int angle_A{ 0 }, angle_B{ 0 }, angle_C{ 0 };
protected:
	Triangle(
		std::string figure_name,
		int length_a, int length_b, int length_c,
		int angl_A, int angl_B, int angl_C);

	std::string printSides() const override;
	std::string printAngles() const override;
public:

	Triangle(
		int length_a, int length_b, int length_c,
		int angl_A, int angl_B, int angl_C);

	int get_length_a() const;
	int get_length_b() const;
	int get_length_c() const;
	int get_angle_A() const;
	int get_angle_B() const;
	int get_angle_C() const;
};
#include <string>
#include "triangle.h"
#include "figure.h"

int length_a{ 0 }, length_b{ 0 }, length_c{ 0 };
int angle_A{ 0 }, angle_B{ 0 }, angle_C{ 0 };

Triangle::Triangle(
	std::string figure_name,
	int length_a, int length_b, int length_c,
	int angl_A, int angl_B, int angl_C)
{
	this->Triangle::setFigureName(figure_name);
	this->length_a = length_a;
	this->length_b = length_b;
	this->length_c = length_c;
	this->angle_A = angl_A;
	this->angle_B = angl_B;
	this->angle_C = angl_C;
}

Triangle::Triangle(
	int length_a, int length_b, int length_c,
	int angl_A, int angl_B, int angl_C)
	: Triangle(
		"Triangle",
		length_a, length_b, length_c,
		angl_A, angl_B, angl_C)
{}

std::string Triangle::printSides() const {
	return std::to_string(Triangle::get_length_a()) + ' '
		 + std::to_string(Triangle::get_length_b()) + ' '
		 + std::to_string(Triangle::get_length_c());
}

std::string Triangle::printAngles() const {
	return std::to_string(Triangle::get_angle_A()) + ' '
		 + std::to_string(Triangle::get_angle_B()) + ' '
		 + std::to_string(Triangle::get_angle_C());
}

int Triangle::get_length_a() const {
	return this->length_a;
}

int Triangle::get_length_b() const {
	return this->length_b;
}

int Triangle::get_length_c() const {
	return this->length_c;
}

int Triangle::get_angle_A() const {
	return this->angle_A;
}

int Triangle::get_angle_B() const {
	return this->angle_B;
}

int Triangle::get_angle_C() const {
	return this->angle_C;
}
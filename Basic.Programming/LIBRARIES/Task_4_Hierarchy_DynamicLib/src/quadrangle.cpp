#include <string>
#include "quadrangle.h"
#include "figure.h"

Quadrangle::Quadrangle(
	std::string figure_name,
	int length_a, int length_b, int length_c, int length_d,
	int angl_A, int angl_B, int angl_C, int angl_D)
{
	this->Quadrangle::setFigureName(figure_name);
	this->length_a = length_a;
	this->length_b = length_b;
	this->length_c = length_c;
	this->length_d = length_d;
	this->angl_A = angl_A;
	this->angl_B = angl_B;
	this->angl_C = angl_C;
	this->angl_D = angl_D;
}

std::string Quadrangle::printSides() const /*override*/ {
	return std::to_string(get_length_a()) + ' ' + std::to_string(get_length_b()) + ' ' + std::to_string(get_length_c()) + ' ' + std::to_string(get_length_d());
}

std::string Quadrangle::printAngles() const /*override*/ {
	return std::to_string(get_angle_A()) + ' ' + std::to_string(get_angle_B()) + ' ' + std::to_string(get_angle_C()) + ' ' + std::to_string(get_angle_D());
}

Quadrangle::Quadrangle(
	int length_a, int length_b, int length_c, int length_d,
	int angl_A, int angl_B, int angl_C, int angl_D)
	: Quadrangle(
		"Quadrangle",
		length_a, length_b, length_c, length_d,
		angl_A, angl_B, angl_C, angl_D)
{}

int Quadrangle::get_length_a() const {
	return this->length_a;
}

int Quadrangle::get_length_b() const {
	return this->length_b;
}

int Quadrangle::get_length_c() const {
	return this->length_c;
}

int Quadrangle::get_length_d() const {
	return this->length_d;
}

int Quadrangle::get_angle_A() const {
	return this->angl_A;
}

int Quadrangle::get_angle_B() const {
	return this->angl_B;
}

int Quadrangle::get_angle_C() const {
	return this->angl_C;
}

int Quadrangle::get_angle_D() const {
	return this->angl_D;
}
//Task: Design and realize classes that describ the subject area.

#include <string>
#include <iostream>
#include "figure.h"
#include "triangle.h"
#include "righttriangle.h"
#include "isoscelestriangle.h"
#include "equilateraltriangle.h"
#include "quadrangle.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "square.h"
#include "rhombus.h"

using namespace std;

//class Figure {
//private:
//	std::string figure_name = "undefined figure";
//protected:
//	void setFigureName(string name) {
//		this->figure_name = name;
//		return;
//	}
//	virtual std::string getFigureName() const {
//		return this->figure_name;
//	}
//	virtual std::string printSides() const { return {}; }
//	virtual std::string printAngles() const { return {}; }
//public:
//	Figure() = default;
//	void print_figure_info(Figure *figure) {
//		cout << "Figure: " << figure->getFigureName() << endl;
//		cout << "Sides: " << figure->printSides() << endl;
//		cout << "Angles: " << figure->printAngles() << endl;
//		return;
//	}
//};
// треугольник
//class Triangle : public Figure {
//private:
//	int length_a{ 0 }, length_b{ 0 }, length_c{ 0 };
//	int angle_A{ 0 }, angle_B{ 0 }, angle_C{ 0 };
//protected:
//	Triangle(
//		std::string figure_name,
//		int length_a, int length_b, int length_c,
//		int angl_A, int angl_B, int angl_C)
//	{
//		this->setFigureName(figure_name);
//		this->length_a = length_a;
//		this->length_b = length_b;
//		this->length_c = length_c;
//		this->angle_A = angl_A;
//		this->angle_B = angl_B;
//		this->angle_C = angl_C;
//	}
//	std::string printSides() const override {
//		return to_string(get_length_a()) + ' ' + to_string(get_length_b()) + ' ' + to_string(get_length_c());
//	}
//	std::string printAngles() const override {
//		return to_string(get_angle_A()) + ' ' + to_string(get_angle_B()) + ' ' + to_string(get_angle_C());
//	}
//public:
//	Triangle(
//		int length_a, int length_b, int length_c,
//		int angl_A, int angl_B, int angl_C)
//		: Triangle(
//			"Triangle",
//			length_a, length_b, length_c,
//			angl_A, angl_B, angl_C)
//	{}
//	int get_length_a() const {
//		return this->length_a;
//	}
//	int get_length_b() const {
//		return this->length_b;
//	}
//	int get_length_c() const {
//		return this->length_c;
//	}
//	int get_angle_A() const {
//		return this->angle_A;
//	}
//	int get_angle_B() const {
//		return this->angle_B;
//	}
//	int get_angle_C() const {
//		return this->angle_C;
//	}
//};
// прямоугольный треугольник
//class RightTriangle : public Triangle {
//protected:
//	RightTriangle(
//		std::string figure_name,
//		int length_a, int length_b, int length_c,
//		int angl_A, int angl_B, int angl_C)
//		: Triangle(
//			figure_name,
//			length_a, length_b, length_c,
//			angl_A, angl_B, angl_C)
//	{}
//public:
//	RightTriangle(
//		int length_a, int length_b, int length_c,
//		int angl_A, int angl_B, int angl_C)
//		: RightTriangle(
//			"RightTriangle",
//			length_a, length_b, length_c,
//			angl_A, angl_B, angl_C)
//	{}
//};
// равнобедренный треугольник
//class IsoscelesTriangle : public Triangle {
//protected:
//	IsoscelesTriangle(
//		std::string figure_name,
//		int length_a, int length_b, int length_c,
//		int angl_A, int angl_B, int angl_C)
//		: Triangle(
//			figure_name, length_a, length_b,
//			length_c, angl_A, angl_B, angl_C)
//	{}
//public:
//	IsoscelesTriangle(
//		int length_a, int length_b, int length_c,
//		int angl_A, int angl_B, int angl_C)
//		: IsoscelesTriangle(
//			"Isoscelestriangle",
//			length_a, length_b, length_c,
//			angl_A, angl_B, angl_C)
//	{}
//};
// равносторонний треугольник
//class EquilateralTriangle : public IsoscelesTriangle {
//protected:
//	EquilateralTriangle(
//		std::string figure_name,
//		int length_a, int length_b, int length_c,
//		int angl_A, int angl_B, int angl_C)
//		: IsoscelesTriangle(
//			figure_name,
//			length_a, length_b, length_c,
//			angl_A, angl_B, angl_C)
//	{}
//public:
//	EquilateralTriangle(
//		int length_a, int length_b, int length_c,
//		int angl_A, int angl_B, int angl_C)
//		: EquilateralTriangle(
//			"Equilateraltriangle",
//			length_a, length_b, length_c,
//			angl_A, angl_B, angl_C)
//	{}
//};
// четырёхугольник
//class Quadrangle : public Figure {
//private:
//	int length_a{ 0 }, length_b{ 0 }, length_c{ 0 }, length_d{ 0 };
//	int angl_A{ 0 }, angl_B{ 0 }, angl_C{ 0 }, angl_D{ 0 };
//protected:
//	Quadrangle(
//		std::string figure_name,
//		int length_a, int length_b, int length_c, int length_d,
//		int angl_A, int angl_B, int angl_C, int angl_D)
//	{
//		this->setFigureName(figure_name);
//		this->length_a = length_a;
//		this->length_b = length_b;
//		this->length_c = length_c;
//		this->length_d = length_d;
//		this->angl_A = angl_A;
//		this->angl_B = angl_B;
//		this->angl_C = angl_C;
//		this->angl_D = angl_D;
//	}
//	std::string printSides() const override {
//		return to_string(get_length_a()) + ' ' + to_string(get_length_b()) + ' ' + to_string(get_length_c()) + ' ' + to_string(get_length_d());
//	}
//	std::string printAngles() const override {
//		return to_string(get_angle_A()) + ' ' + to_string(get_angle_B()) + ' ' + to_string(get_angle_C()) + ' ' + to_string(get_angle_D());
//	}
//public:
//	Quadrangle(
//		int length_a, int length_b, int length_c, int length_d,
//		int angl_A, int angl_B, int angl_C, int angl_D)
//		: Quadrangle(
//			"Quadrangle",
//			length_a, length_b, length_c, length_d,
//			angl_A, angl_B, angl_C, angl_D)
//	{}
//	int get_length_a() const {
//		return this->length_a;
//	}
//	int get_length_b() const {
//		return this->length_b;
//	}
//	int get_length_c() const {
//		return this->length_c;
//	}
//	int get_length_d() const {
//		return this->length_d;
//	}
//	int get_angle_A() const {
//		return this->angl_A;
//	}
//	int get_angle_B() const {
//		return this->angl_B;
//	}
//	int get_angle_C() const {
//		return this->angl_C;
//	}
//	int get_angle_D() const {
//		return this->angl_D;
//	}
//};
// параллелограмм
//class Parallelogram : public Quadrangle {
//protected:
//	Parallelogram(
//		std::string figure_name,
//		int length_a, int length_b, int length_c, int length_d,
//		int angl_A, int angl_B, int angl_C, int angl_D)
//		: Quadrangle(
//			figure_name,
//			length_a, length_b, length_c, length_d,
//			angl_A, angl_B, angl_C, angl_D)
//	{}
//public:
//	Parallelogram(
//		int length_a, int length_b, int length_c, int length_d,
//		int angl_A, int angl_B, int angl_C, int angl_D)
//		: Parallelogram(
//			"Parallelogram",
//			length_a, length_b, length_c, length_d,
//			angl_A, angl_B, angl_C, angl_D)
//	{}
//};
// прямоугольник
//class Rectangle : public Parallelogram {
//protected:
//	Rectangle(
//		std::string figure_name,
//		int length_a, int length_b, int length_c, int length_d,
//		int angl_A, int angl_B, int angl_C, int angl_D)
//		: Parallelogram(
//			figure_name,
//			length_a, length_b, length_c, length_d,
//			angl_A, angl_B, angl_C, angl_D)
//	{}
//public:
//	Rectangle(
//		int length_a, int length_b, int length_c, int length_d,
//		int angl_A, int angl_B, int angl_C, int angl_D)
//		: Rectangle(
//			"Rectangle",
//			length_a, length_b, length_c, length_d,
//			angl_A, angl_B, angl_C, angl_D)
//	{}
//};
// квадрат
//class Square : public Quadrangle {
//protected:
//	Square(
//		std::string figure_name,
//		int length_a, int length_b, int length_c, int length_d,
//		int angl_A, int angl_B, int angl_C, int angl_D)
//		: Quadrangle(figure_name,
//			length_a, length_b, length_c, length_d,
//			angl_A, angl_B, angl_C, angl_D)
//	{}
//public:
//	Square(
//		int length_a, int length_b, int length_c, int length_d,
//		int angl_A, int angl_B, int angl_C, int angl_D)
//		: Square(
//			"Square",
//			length_a, length_b, length_c, length_d,
//			angl_A, angl_B, angl_C, angl_D)
//	{}
//};
// ромб
//class Rhombus : public Square {
//protected:
//	Rhombus(
//		std::string figure_name,
//		int length_a, int length_b, int length_c, int length_d,
//		int angl_A, int angl_B, int angl_C, int angl_D)
//		: Square(
//			figure_name,
//			length_a, length_b, length_c, length_d,
//			angl_A, angl_B, angl_C, angl_D)
//	{}
//public:
//	Rhombus(
//		int length_a, int length_b, int length_c, int length_d,
//		int angl_A, int angl_B, int angl_C, int angl_D)
//		: Rhombus(
//			"Rhombus",
//			length_a, length_b, length_c, length_d,
//			angl_A, angl_B, angl_C, angl_D)
//	{}
//};

int main(int argc, char** argv) {
	Figure figure_;
	Triangle triangle_{ 10, 20, 30, 50, 60, 70 };
	RightTriangle right_triangle_{ 11, 21, 31, 51, 61, 91 };
	IsoscelesTriangle isosceles_triangle_{ 12, 22, 12, 52, 62, 52 };
	EquilateralTriangle equilateral_triangle_{ 14, 14, 14, 54, 54, 54 };
	Parallelogram parallelogram_{ 15, 25, 15, 25, 55, 65, 55, 65 };
	Rectangle rectangle_{ 35, 45, 35, 45, 91, 91, 91, 91 };
	Square square_{ 55, 55, 55, 55, 91, 91, 91, 91 };
	Rhombus rhombus_{ 55, 55, 55, 55, 30, 60, 30, 60 };

	figure_.print_figure_info(&triangle_);
	std::cout << std::endl;
	figure_.print_figure_info(&right_triangle_);
	std::cout << std::endl;
	figure_.print_figure_info(&isosceles_triangle_);
	std::cout << std::endl;
	figure_.print_figure_info(&equilateral_triangle_);
	std::cout << std::endl;
	figure_.print_figure_info(&parallelogram_);
	std::cout << std::endl;
	figure_.print_figure_info(&rectangle_);
	std::cout << std::endl;
	figure_.print_figure_info(&square_);
	std::cout << std::endl;
	figure_.print_figure_info(&rhombus_);

	return 0;
}
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
	system("pause");
	return 0;
}
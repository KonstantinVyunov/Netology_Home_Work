#include <exception>
#include <iostream>
#include <string>

#include "GenericError.h"
#include "TriangleError.h"
#include "RightTriangleError.h"
#include "IsoscelesTriangleError.h"
#include "EquilateralTriangleError.h"
#include "QuadrangleError.h"
#include "RectangleError.h"
#include "SquareError.h"
#include "ParallelogramError.h"
#include "RhombusError.h"

#include "Figure.h"
#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrangle.h"
#include "Parallelogram.h"
#include "Rhombus.h"
#include "Rectangle.h"
#include "Square.h"

void printInfo(Figure *figure) {
	std::cout << figure->getFigureName() << " (" << "sides ";
	figure->printSides();
	std::cout << "; " << "angles ";
	figure->printAngles();
	std::cout << ") was created.";
}

int main(int argc, char** argv) {
	try {
		Figure figure_{};
		printInfo(&figure_);
		std::cout << std::endl;
	}
	catch (const GenericError& error) {
		std::cerr << "Reason: " << error.what() << std::endl;
	}
	try {
		Triangle triangle_{10, 20, 30, 50, 60, 70};
		printInfo(&triangle_);
		std::cout << std::endl;
	} catch (const GenericError &error) {
		std::cerr << "Reason: " << error.what() << std::endl;
	}
	try {
		RightTriangle right_triangle_{ 10, 20, 30, 30, 60, 90 };
		printInfo(&right_triangle_);
		std::cout << std::endl;
	} catch (const GenericError& error) {
		std::cerr << "Reason: " << error.what() << std::endl;
	}
	try {
		IsoscelesTriangle isosceles_triangle_{ 10, 20, 10, 50, 80, 50 };
		printInfo(&isosceles_triangle_);
		std::cout << std::endl;
	} catch (const GenericError& error) {
		std::cerr << "Reason: " << error.what() << std::endl;
	}
	try {
		EquilateralTriangle equilateral_triangle_{ 30, 30, 30, 60, 60, 60 };
		printInfo(&equilateral_triangle_);
		std::cout << std::endl;
	} catch (const GenericError& error) {
		std::cerr << "Reason: " << error.what() << std::endl;
	}
	try {
		Quadrangle quadrangle_{10, 20, 30, 40, 100, 60, 120, 80};
		printInfo(&quadrangle_);
		std::cout << std::endl;
	}
	catch (const GenericError& error) {
		std::cerr << "Reason: " << error.what() << std::endl;
	}
	try {
		Rectangle rectangle_{ 10, 20, 10, 20, 90, 90, 90, 90 };
		printInfo(&rectangle_);
		std::cout << std::endl;
	}
	catch (const GenericError& error) {
		std::cerr << "Reason: " << error.what() << std::endl;
	}
	try {
		Square square_{ 20, 20, 20, 20, 90, 90, 90, 90 };
		printInfo(&square_);
		std::cout << std::endl;
	}
	catch (const GenericError& error) {
		std::cerr << "Reason: " << error.what() << std::endl;
	}
	try {
		Parallelogram parallelogram_{ 20, 30, 20, 30, 60, 120, 60, 120 };
		printInfo(&parallelogram_);
		std::cout << std::endl;
	}
	catch (const GenericError& error) {
		std::cerr << "Reason: " << error.what() << std::endl;
	}
	try {
		Rhombus rhombus_{ 30, 30, 30, 30, 60, 120, 60, 120 };
		printInfo(&rhombus_);
		std::cout << std::endl;
	}
	catch (const GenericError& error) {
		std::cerr << "Reason: " << error.what() << std::endl;
	}
	return 0;
}
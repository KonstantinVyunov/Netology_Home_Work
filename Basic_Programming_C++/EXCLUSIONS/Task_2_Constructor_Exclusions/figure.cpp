#include <iostream>
#include <string>
#include "figure.h"

void Figure::setFigureName(std::string name) {
	this->figure_name = name;
	return;
}

std::string Figure::getFigureName() const {
	return this->figure_name;
}

std::string Figure::printSides() const { return "0"; }
std::string Figure::printAngles() const { return "0"; }

Figure::Figure() = default;

void Figure::print_figure_info(Figure* figure) {
	std::cout << "Figure: " << figure->getFigureName() << std::endl;
	std::cout << "Sides: " << figure->printSides() << std::endl;
	std::cout << "Angles: " << figure->printAngles() << std::endl;
	return;
}
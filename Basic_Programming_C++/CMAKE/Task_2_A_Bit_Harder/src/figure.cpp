#include <iostream>
#include <string>
#include "figure.h"

std::string figure_name = "UNDEFINED";

void Figure::setFigureName(std::string name) {
	this->figure_name = name;
	return;
}

std::string Figure::getFigureName() const {
	return this->figure_name;
}

std::string Figure::printSides() const { return { "N/A" }; }
std::string Figure::printAngles() const { return { "N/A" }; }

Figure::Figure() = default;

void Figure::print_figure_info(Figure* figure) {
	std::cout << "Figure: " << figure->getFigureName() << std::endl;
	std::cout << "Sides: " << figure->printSides() << std::endl;
	std::cout << "Angles: " << figure->printAngles() << std::endl;
	return;
}
#include <iostream>
#include <string>
#include "figure.h"

std::string figure_name = "undefined figure";

void Figure::setFigureName(std::string name) {
	this->figure_name = name;
	return;
}

std::string Figure::getFigureName() const {
	return this->figure_name;
}

std::string Figure::printSides() const { return {}; }
std::string Figure::printAngles() const { return {}; }

Figure::Figure() = default;

void Figure::print_figure_info(Figure* figure) {
	std::cout << "Figure: " << figure->Figure::getFigureName() << std::endl;
	std::cout << "Sides: " << figure->Figure::printSides() << std::endl;
	std::cout << "Angles: " << figure->Figure::printAngles() << std::endl;
	return;
}
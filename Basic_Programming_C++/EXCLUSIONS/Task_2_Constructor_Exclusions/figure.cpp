#include "Figure.h"
#include <iostream>

Figure::Figure() = default;

const void Figure::setFigureName(std::string name) { this->figure_name = name; }
std::string Figure::getFigureName() const { return this->figure_name; }

const void Figure::setNumSides(int num_sides) { this->num_sides = num_sides; }
int Figure::getNumSides() const { return this->num_sides; }

const void Figure::setNumAngles(int num_angles) { this->num_angles = num_angles; }
int Figure::getNumAngles() const { return this->num_angles; }

void Figure::printSides() const { std::cout << num_sides; }
void Figure::printAngles() const { std::cout << num_angles; }

Figure::~Figure() = default;
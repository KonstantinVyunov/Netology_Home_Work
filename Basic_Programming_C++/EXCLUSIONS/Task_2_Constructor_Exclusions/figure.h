#pragma once
#include <string>

class Figure {
private:
	std::string figure_name = "Figure";
	int num_sides = 0, num_angles = 0;
public:
	Figure();

	const void setFigureName(std::string name);
	std::string getFigureName() const;

	const void setNumSides(int num_sides);
	int getNumSides() const;

	const void setNumAngles(int num_angles);
	int getNumAngles() const;

	virtual void printSides() const;
	virtual void printAngles() const;

	~Figure();
};
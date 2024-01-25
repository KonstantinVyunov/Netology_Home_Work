#pragma once

#include <iostream>
#include <string>

class Figure {
private:
	std::string figure_name;
protected:
	void setFigureName(std::string name);
public:
	Figure();
	virtual std::string getFigureName() const;
	virtual std::string printSides() const;
	virtual std::string printAngles() const;
	void print_figure_info(Figure* figure);
};
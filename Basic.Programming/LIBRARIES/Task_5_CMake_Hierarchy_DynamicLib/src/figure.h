#pragma once

#ifdef DYNAMICLIB_EXPORTS
	#define HIERARCHYDYNAMICLIB_API __declspec(dllexport)
#else
	#define HIERARCHYDYNAMICLIB_API __declspec(dllimport)
#endif

#include <iostream>
#include <string>

class Figure {
private:
	std::string figure_name;
protected:
	void setFigureName(std::string name);
public:
	HIERARCHYDYNAMICLIB_API Figure();
	virtual std::string getFigureName() const;
	virtual std::string printSides() const;
	virtual std::string printAngles() const;
	HIERARCHYDYNAMICLIB_API void print_figure_info(Figure* figure);
};
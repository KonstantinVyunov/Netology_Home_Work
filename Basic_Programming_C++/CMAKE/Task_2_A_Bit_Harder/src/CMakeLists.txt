cmake_minimum_required(VERSION 3.22.0)

project(source_files VERSION 0.0.1)

set (HEADERs
			figure.h 
			rectangle.h 
			rectangle.h 
			righttriangle.h 
			isoscelestriangle.h 
			quadrangle.h 
			parallelogram.h 
			rhombus.h 
			square.h 
			triangle.h
)		

set (CPPs
			Hierarchy_Class.cpp 
			figure.cpp 
			rectangle.cpp 
			righttriangle.cpp 
			equilateraltriangle.cpp 
			isoscelestriangle.cpp 
			quadrangle.cpp 
			parallelogram.cpp 
			rhombus.cpp 
			square.cpp 
			triangle.cpp 
)

add_executable(figures ${HEADERs} ${CPPs})
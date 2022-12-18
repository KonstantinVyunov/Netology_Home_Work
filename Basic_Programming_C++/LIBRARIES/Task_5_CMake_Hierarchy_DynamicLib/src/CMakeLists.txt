cmake_minimum_required (VERSION 3.22.0)

project (hierarchy VERSION 0.0.1)

set (libraries 
		figure.cpp figure.h 
		triangle.cpp triangle.h 
		rectangle.cpp rectangle.h 
		equilateraltriangle.cpp equilateraltriangle.h 
		isoscelestriangle.cpp isoscelestriangle.h 
		righttriangle.cpp righttriangle.h 
		quadrangle.cpp quadrangle.h 
		parallelogram.cpp parallelogram.h 
		rhombus.cpp rhombus.h 
		square.cpp square.h
)

add_library (Lib SHARED ${libraries})

add_executable (Exe HierarchyClient.cpp)

target_link_libraries (Exe Lib)

target_compile_definitions (Lib PRIVATE DYNAMICLIB_EXPORTS)
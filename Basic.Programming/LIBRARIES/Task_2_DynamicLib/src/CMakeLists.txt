cmake_minimum_required (VERSION 3.22.0)

project(LeaverApp VERSION 0.0.1)

add_library (LIB SHARED Leaver.h Leaver.cpp)
add_executable (CLIENT Client.cpp)

target_link_libraries (CLIENT LIB)
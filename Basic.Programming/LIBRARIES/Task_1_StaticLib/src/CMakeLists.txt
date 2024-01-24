cmake_minimum_required (VERSION 3.22.0)

project (Greeter_App VERSION 0.0.1)

add_library (Greeter_LIB STATIC Greeter.h Greeter.cpp)

add_executable (Greeter ClientGreeter.cpp)

target_link_libraries (Greeter Greeter_LIB)
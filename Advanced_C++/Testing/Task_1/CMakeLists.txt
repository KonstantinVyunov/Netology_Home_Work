cmake_minimum_required(VERSION 3.25)

project(My_Test)

find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
# add_executable(tests test.cpp)
# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# These tests need their own main
add_executable(MyTest main.cpp cpp.hint)
target_link_libraries(MyTest PRIVATE Catch2::Catch2)
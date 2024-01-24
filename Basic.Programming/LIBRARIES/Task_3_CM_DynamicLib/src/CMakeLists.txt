cmake_minimum_required (VERSION 3.22.0)

project(LeaverApp VERSION 0.0.1)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library (LIB SHARED Leaver.h Leaver.cpp)
add_executable (CLIENT Client.cpp)

target_link_libraries (CLIENT LIB)
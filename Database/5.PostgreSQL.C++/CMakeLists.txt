
cmake_minimum_required (VERSION 3.8)

project (Urok5)
add_executable (Urok5 "Urok5.cpp" )

add_subdirectory(libpqxx libpqxx-build) 
target_compile_features(Urok5 PRIVATE cxx_std_17) 
target_link_libraries(Urok5 pqxx)
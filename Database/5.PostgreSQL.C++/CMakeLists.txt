cmake_minimum_required (VERSION 3.8)

project (Task1)

add_executable (Task1 Task1.cpp)

#add_subdirectory(E:/libpqxx-7.8.1 libpqxx-build) 
add_subdirectory(-S/Users/castiel/libpqxx-7.8.1 libpqxx-build)

target_compile_features(Task1 PRIVATE cxx_std_17) 

target_link_libraries(Task1 pqxx)
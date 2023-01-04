cmake_minimum_required (VERSION 3.22.0)

project (Game_Race VERSION 0.0.1)

set (d_libraries 
		Race.h 
		Vehicle.cpp Vehicle.h 
		GroundVehicle.h GroundVehicle.cpp 
		Camel.h Camel.cpp 
		Horse.h Horse.cpp 
		Centaur.h Centaur.cpp 
		Boots.h Boots.cpp 
		AirVehicle.h AirVehicle.cpp 
		FlyingCarpet.h FlyingCarpet.cpp 
		Eagle.h Eagle.cpp 
		Broom.h Broom.cpp 
)
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library (DYNAMIC_LIB SHARED ${d_libraries})

add_library (STATIC_LIB STATIC Functions.cpp Functions.h)

add_executable (game GameClient.cpp )

target_link_libraries (game DYNAMIC_LIB STATIC_LIB)

target_compile_definitions (DYNAMIC_LIB PUBLIC DYNAMIC_LIB_EXPORT)
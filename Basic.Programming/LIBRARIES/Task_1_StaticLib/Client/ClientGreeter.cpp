#include "../StaticLibrary/Greeter.h"
#include "Leaver.h"

int main(int argc, char** argv) {
	Greeter hi;
	Leaver bye;
	std::string name = "John";
	std::cout << hi.greet(name);
	return EXIT_SUCCESS;
}
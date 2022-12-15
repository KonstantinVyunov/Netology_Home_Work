#include "Greeter.h"

int main(int argc, char** argv) {
	Greeter hi;
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << hi.greet(name);
	return EXIT_SUCCESS;
}
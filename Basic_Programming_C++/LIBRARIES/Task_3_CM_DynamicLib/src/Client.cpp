#include "Leaver.h"

int main(int argc, char** argv) {
	Leaver bye;
	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;
	std::cout << bye.leave(name) << std::endl;

	return EXIT_SUCCESS;
}
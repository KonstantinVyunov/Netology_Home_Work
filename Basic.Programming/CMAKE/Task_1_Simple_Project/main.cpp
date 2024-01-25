#include <iostream>

int main(int argc, char** argv) {
	std::string name = {};
	std::cout << "Type your first name: ";
	std::cin >> name;
	std::cout << "Hello " << name << '!' << std::endl;

	return EXIT_SUCCESS;
}
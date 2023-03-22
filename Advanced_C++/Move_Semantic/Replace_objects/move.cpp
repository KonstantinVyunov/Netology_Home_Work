#include <iostream>
#include <vector>
#include <string>

template<typename T>
void print(const T& obj) {
	for (auto itr = obj.begin(); itr != obj.end(); ++itr) {
		std::cout << *itr << ' ';
	}
}

template<typename T>
void moveVectors(std::vector<T>& one, std::vector<T>& two) noexcept {
	auto temp = std::move(one);
	one = std::move(two);
	two = std::move(temp);
}

int main(int argc, char** argv) {
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;

	std::cout << "BEFORE:" << std::endl;
	std::cout << "vector 1: ";
	print(one);

	std::cout << std::endl;

	std::cout << "vector 2: ";
	print(two);

	moveVectors(one, two);

	std::cout << "\nAFTER:" << std::endl;
	std::cout << "vector 1: ";
	print(one);

	std::cout << std::endl;

	std::cout << "vector 2: ";
	print(two);

	return EXIT_SUCCESS;
}
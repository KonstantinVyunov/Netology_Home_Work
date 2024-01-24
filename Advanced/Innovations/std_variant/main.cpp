#include <algorithm>
#include <iostream>
#include <variant>
#include <vector>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& vect) {
	std::for_each(vect.begin(), vect.end(), [&out](int elm) { out << elm << ' '; });
	return out;
}

std::variant<int, std::string, std::vector<int>> getVariant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;
	
	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable) {
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		std::cout << "Error: not int, string, or vector!" << std::endl;
		break;
	}
	return result;
}

void printVariant(std::variant<int, std::string, std::vector<int>> result) {

	if (std::holds_alternative<int>(result)) {
		std::cout << (std::get<int>(result) * 2) << std::endl;
	}
	else if (std::holds_alternative<std::string>(result)) {
		std::cout << *std::get_if<std::string>(&result) << std::endl;
	}
	else if (std::holds_alternative<std::vector<int>>(result)) {
		std::cout << *std::get_if<std::vector<int>>(&result) << std::endl;
	}
	else {
		std::cout << "Unclear behavior!" << std::endl;
	}
	return;
}

int main(int argc, char** argv) {

	auto result = getVariant();
	printVariant(result);

	return EXIT_SUCCESS;
}
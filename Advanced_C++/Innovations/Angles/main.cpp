#include <cmath>
#include <vector>
#include <iostream>
#include <functional>

const double Pi = 3.1415926;

void printInput(const std::vector<int>& angles) {
	for (const auto& angle : angles) {
		if (angle != angles.back()) {
			std::cout << angle << " deg (" << (angle * Pi / 180) << " rad); ";
		}
		else {
			std::cout << angle << " deg (" << (angle * Pi / 180) << " rad). ";
		}
	}
}

void printOutput(const std::vector<int>& angles) {

	std::function<double(int&)> coses = [](const int& angle) {
		std::cout << "cos ";
		return std::cos(angle);
	};
	std::function<double(int&)>  sins = [](const int& angle) {
		std::cout << "sin ";
		return std::sin(angle);
	};

	std::vector<std::function<double(int&)>> functions = { coses, sins };

	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions) {
			function(angle);
		}
		std::cout << std::endl;
	}
	};


int main(int argc, char** argv) {

	std::vector<int> angles = { 30, 60, 90 };

	std::cout << "Input: ";
	printInput(angles);

	std::cout << std::endl;

	std::cout << "Output:\n";
	printOutput(angles);

	return EXIT_SUCCESS;
}
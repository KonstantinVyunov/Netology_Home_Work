#include <iostream>
#include <string>
#include <cmath>

void printArr(int* arr, size_t length) {
	for (size_t i = 0; i < length; ++i) {
		std::cout << arr[i] << ' ';
	}
	return;
}

std::string printElement(int* arr, const int index) {
	if (index == 0) {
		return std::to_string((int)log2(index + 1)) + " root " + std::to_string(arr[index]);
	} else {
		return std::to_string((int)log2(index + 1)) + ' ' + ((index % 2 != 0) ? "left(" : "right(")
			 + std::to_string(arr[(index - 1) / 2]) + ") " + std::to_string(arr[index]);
	}
}

void printPyramid(int* arr, size_t length) {
	for (size_t i = 0; i < length; ++i) {
		if (i == 0) {
			std::cout << 0 << ' ' << "root " << arr[i] << std::endl;
		} else {
			std::cout << printElement(arr, i) << std::endl;
		}
	}
	return;
}

int main(int argc, char** argv) {

	//int arr[] = { 1, 3, 6, 5, 9, 8 };
	//int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
	int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

	const size_t length = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Initial array: ";
	printArr(arr, length);

	std::cout << std::endl;

	std::cout << "Pyramide:" << std::endl;
	printPyramid(arr, length);

	int index = NULL;
	std::cout << "Initial location: " << printElement(arr, index) << std::endl;
	std::string command = "start";
	while (command != "exit") {
		std::cout << "Input command: ";
		std::cin >> command;
		if (command == "up") {
			if (index == 0) {
				std::cout << "Error: no parrent." << std::endl;
			} else if ((index - 1) / 2 >= 0) {
				index = (index - 1) / 2;
				std::cout << "Ok\n" << "Current location: " << printElement(arr, index) << std::endl;
			}
		} else if (command == "left") {
			if ((2 * index + 1) < length) {
				index = (2 * index + 1);
				std::cout << "Ok\n" << "Current location: " << printElement(arr, index) << std::endl;
			} else {
				std::cout << "Error: no LEFT child." << std::endl;
			}
		} else if (command == "right") {
			if ((2 * index + 2) < length) {
				index = (2 * index + 2);
				std::cout << "Ok\n" << "Current location : " << printElement(arr, index) << std::endl;
			} else {
				std::cout << "Error: no RIGHT child." << std::endl;
			}
		} else {
			std::cout << "Error: wrong command." << std::endl;
		}
	}

	return EXIT_SUCCESS;
}
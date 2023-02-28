// Task #1 "Resizable dynamic array output"

#include <iostream>
#include <exception>

int* setDynamicArray(int logical_size, int actual_size) {
	int* arr = new int[actual_size];
	for (int i = 0; i < actual_size; ++i) {
		if (i < logical_size) {
			std::cout << "Enter arr[" << i << "]: ";
			std::cin >> arr[i];
		}
		else {
			arr[i] = 0;
		}
	}
	return arr;
}

void printDynamicArray(int* arr, int logical_size, int actual_size) {
	for (int i = 0; i < actual_size; ++i) {
		if (i < logical_size) {
			std::cout << arr[i] << ' ';
		}
		else {
			std::cout << "_ ";
		}
	}
	return;
}

int main(int argc, char** argv) {
	int actual_size = 0;
	int logical_size = 0;

	try {
		std::cout << "Enter the actual array's size: ";
		std::cin >> actual_size;
		if (actual_size == 0) {
			throw std::exception("Array's size must be greater then zero!");
		}

		std::cout << "Enter the logical array's size: ";
		std::cin >> logical_size;
		if (logical_size == 0) {
			throw std::exception("Logical size must be greater then zero!");
		}

		if (logical_size > actual_size) {
			throw std::exception("Actual size must be greater than the logical size!");
		}
	}
	catch (const std::exception& error) {
		std::cerr << "Error: " << error.what();
		return EXIT_FAILURE;
	}

	int* arr = setDynamicArray(logical_size, actual_size);
	std::cout << "Initial array: ";
	printDynamicArray(arr, logical_size, actual_size);

	delete[] arr;

	return EXIT_SUCCESS;
}
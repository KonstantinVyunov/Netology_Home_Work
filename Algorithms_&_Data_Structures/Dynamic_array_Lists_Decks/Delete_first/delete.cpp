// Task #3 "Удаление первого элемента из изменяемого динамического массива"

#include <iostream>
#include <exception>
#include <string>

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

int* removeFirstElementDynamicArray(int* arr, int& logical_size, int& actual_size) {
	if (logical_size == 1 && actual_size == 1) {
		--logical_size;
	} else if ((logical_size - 1) > (actual_size / 3)) {
		for (int i = 1; i < logical_size; ++i) {
			arr[i - 1] = arr[i];
		}
		--logical_size;
	} else {
		actual_size /= 3;
		int* new_arr = new int[actual_size];
		for (int i = 1; i < actual_size + 1; ++i) {
			new_arr[i - 1] = arr[i];
		}
		--logical_size;
		delete[] arr;
		return new_arr;
	}
	return arr;
}

void printDynamicArray(int* arr, const int logical_size, const int actual_size) {
	for (int i = 0; i < actual_size; ++i) {
		if (i < logical_size) {
			std::cout << arr[i] << ' ';
		}
		else {
			std::cout << "_ ";
		}
	}
	std::cout << std::endl;
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
			throw std::exception("Logical size must be equal or less than the actual size!");
		}
	}
	catch (const std::exception& error) {
		std::cerr << "Error: " << error.what();
		return EXIT_FAILURE;
	}

	int* arr = setDynamicArray(logical_size, actual_size);
	std::cout << "Initial array: ";
	printDynamicArray(arr, logical_size, actual_size);

	std::string question;

	do {
		std::cout << "Remove the first element? ";
		std::cin >> question;
		if (question == "yes") {
			if (logical_size > 0) {
				std::cout << "New array: ";
				arr = removeFirstElementDynamicArray(arr, logical_size, actual_size);
			} else {
				std::cout << "There is no first element to delete. The array is empty." << std::endl;
				break;
			}
		} else if (question == "no") {
			std::cout << "Final array: ";
		}
		printDynamicArray(arr, logical_size, actual_size);
	} while (question == "yes");

	delete[] arr;

	return EXIT_SUCCESS;
}
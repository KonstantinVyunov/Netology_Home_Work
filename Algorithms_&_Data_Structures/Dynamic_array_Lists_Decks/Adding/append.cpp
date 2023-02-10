// Task #2 "ƒобавление в измен€емый динамический массив"

#include <iostream>
#include <exception>

int* setDynamicArray(int logical_size, int actual_size) {
	int* arr = new int[actual_size];
	for (int i = 0; i < actual_size; ++i) {
		if (i < logical_size) {
			std::cout << "Enter arr[" << i << "]: ";
			std::cin >> arr[i];
		} else {
			arr[i] = 0;
		}
	}
	return arr;
}

int* appendDynamicArray(int* arr, int& logical_size, int& actual_size, int num) {
	if (logical_size < actual_size) {
		arr[logical_size] = num;
		++logical_size;
	} else {
		actual_size *= 2;
		int* new_arr = new int[actual_size];
		for (int i = 0; i < actual_size; ++i) {
			if (i < logical_size) {
				new_arr[i] = arr[i];
			} else if (i == logical_size) {
				new_arr[i] = num;
			} else {
				new_arr[i] = 0;
			}
		}
		++logical_size;
		delete[] arr;
		return new_arr;
	}
	return arr;
}

void printDynamicArray(int* arr,const int logical_size, const int actual_size) {
	for (int i = 0; i < actual_size; ++i) {
		if (i < logical_size) {
			std::cout << arr[i] << ' ';
		} else {
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

	int num = NULL;

	do {
		std::cout << "Enter the num to append: ";
		std::cin >> num;
		if (num == 0) {
			std::cout << "Final array: ";
		} else {
			std::cout << "Current array: ";
			arr = appendDynamicArray(arr, logical_size, actual_size, num);
		}
		printDynamicArray(arr, logical_size, actual_size);
	} while (num != 0);

	delete[] arr;

	return EXIT_SUCCESS;
}
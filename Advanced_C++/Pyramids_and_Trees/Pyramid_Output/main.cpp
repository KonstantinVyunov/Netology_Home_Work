#include <iostream>
#include <cmath>

void printArr(int* arr, size_t length) {
	for (size_t i = 0; i < length; ++i) {
		std::cout << arr[i] << ' ';
	}
	return;
}

void printLine(int* arr, int i) {
	std::cout << (int)log2(i + 1) << ' '
		<< ((i % 2 != 0) ? "left (" : "right (")
		<< arr[(i - 1) / 2] << ") "
		<< arr[i];
	return;
}

void printPyramid(int* arr, size_t length) {
	for (size_t i = 0; i < length; ++i) {
		if (i == 0) {
			std::cout << 0 << ' ' << "root " << arr[i] << std::endl;
		}
		else {
			printLine(arr, i);
			std::cout << std::endl;
		}
	}
	return;
}

int main(int argc, char** argv) {

	int arr[] = { 1, 3, 6, 5, 9, 8 };
	//int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
	//int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

	const size_t length = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Initial array: ";
	printArr(arr, length);

	std::cout << std::endl;

	std::cout << "Pyramide:" << std::endl;
	printPyramid(arr, length);

	return EXIT_SUCCESS;
}
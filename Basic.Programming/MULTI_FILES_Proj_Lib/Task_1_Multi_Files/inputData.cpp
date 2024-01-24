// GETTING DATA

#include <iostream>

void inputData(double* num_1, double* num_2, int* instruction) {
	std::cout << "Enter the 1st number: ";
	std::cin >> *num_1;
	std::cout << "Enter the 2nd number: ";
	std::cin >> *num_2;
	std::cout << "Choose the operator (addition - 1, subtraction - 2, multiplication - 3, division - 4, exponentiation - 5): ";
	std::cin >> *instruction;
	return;
}
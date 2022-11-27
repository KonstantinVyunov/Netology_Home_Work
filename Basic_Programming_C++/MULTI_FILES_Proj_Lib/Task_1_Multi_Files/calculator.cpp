// CALCULATION LOGIC

#include <iostream>
#include <cmath>

enum Operator {
	addition,
	subtraction,
	multiplication,
	division,
	exponentiation
};

double calculation(double num_1, double num_2, int instruction, double* result) {
	switch (static_cast<Operator>(instruction)) {
	case(1):
		*result = num_1 + num_2;
		break;
	case(2):
		*result = num_1 - num_2;
		break;
	case(3):
		*result = num_1 * num_2;
		break;
	case(4):
		*result = num_1 / num_2;
		break;
	case(5):
		*result = pow(num_1, num_2);
		break;
	default:
		std::cout << "Wrong operator. Calculation is impossible!" << std::endl;
	}
	return *result;
}
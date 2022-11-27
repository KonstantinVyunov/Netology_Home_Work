// EXECUTIVE FILE

#include "calculator.h"
#include <iostream>

int main(int argc, char** argv) {
	int instruction = 0;
	double num_1 = 0, num_2 = 0, result = 0;

	inputData(&num_1, &num_2, &instruction);
	calculation(num_1, num_2, instruction, &result);
	
	std::cout << "Result: " << result << std::endl;
	return 0;
}
#include <iostream>
#define MODE (1)
#define ADD(num_1, num_2) ((num_1) + (num_2))


int main() {

	#ifndef MODE
		#error Error! MODE undefined!
	#endif

	#if MODE == (0)
		std::cout << "Weather is good!" << std::endl;
	#elif MODE == (1)
		std::cout << "Weather is bad!" << std::endl;
		int num_1 = 0, num_2 = 0;
		std::cout << "Enter num 1: ";
		std::cin >> num_1;
		std::cout << "Enter num 2: ";
		std::cin >> num_2;
		std::cout << "Sum: " << ADD(num_1, num_2) << std::endl;
	#else
		std::cout << "Weather is unknown ..." << std::endl;
	#endif

	return 0;
}
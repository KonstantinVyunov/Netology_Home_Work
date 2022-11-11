// CALCULATOR.  Program asks the user input two figures,  
//              makes simple calculations and then outputs it on the screen.

#include <iostream>

class Calculator {
	public:
		void getNums() {
			std::cout << "Enter the 1st number: ";
			while (std::cin >> num_1 && set_num1(num_1)) {
				std::cout << "The number must distinguish from \"0\"!" << std::endl;
				std::cout << "Enter the 1st number again: ";
			}
			
			std::cout << "Enter the 2nd number: ";
			while (std::cin >> num_2 && set_num1(num_2)) {
				std::cout << "The number must distinguish from \"0\"!" << std::endl;
				std::cout << "Enter the 2nd number again: ";
			}

			return;
		}

		void outputCalculations() {
			std::cout.width(3);
			std::cout << num_1 << " + " << num_2 << " = " << add() << std::endl;
			std::cout.width(3);
			std::cout << num_1 << " - " << num_2 << " = " << subtract_1_2() << std::endl;
			std::cout.width(3);
			std::cout << num_2 << " + " << num_1 << " = " << subtract_2_1() << std::endl;
			std::cout.width(3);
			std::cout << num_1 << " * " << num_2 << " = " << multiply() << std::endl;
			std::cout.width(3);
			std::cout << num_1 << " / " << num_2 << " = " << divide_1_2() << std::endl;
			std::cout.width(3);
			std::cout << num_2 << " / " << num_1 << " = " << divide_2_1() << std::endl;

			return;
		}

	private:
		double num_1 = 0;
		double num_2 = 0;

		double add() {
			return (num_1 + num_2);
		}

		double multiply() {
			return (num_1 * num_2);
		}

		double subtract_1_2() {
			return (num_1 - num_2);
		}

		double subtract_2_1() {
			return (num_2 - num_1);
		}

		double divide_1_2() {
			return (num_1 / num_2);
		}

		double divide_2_1() {
			return (num_2 / num_1);
		}

		bool set_num1(double num_1) {
			return (num_1 != 0 ? false : true);
		}

		bool set_num2(double num_2) {
			return (num_2 != 0 ? false : true);
		}
};

int main(int argc, char** argv) {

	Calculator calculator;

	while (true) {
		calculator.getNums();
		std::cout << std::endl << "There is a list of all math manipulations:" << std::endl;
		calculator.outputCalculations();
		std::cout << std::endl;
	}

	return 0;
}
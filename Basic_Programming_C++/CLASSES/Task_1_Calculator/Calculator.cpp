// CALCULATOR.  Program asks the user input two figures,  
//              makes simple calculations and then outputs it on the screen.

#include <iostream>

class Calculator {
	private:
		double num_1;
		double num_2;
	public:
		Calculator(double num_1, double num_2) {
			this->num_1 = num_1;
			this->num_2 = num_2;
		}

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

		bool set_num1(double user_num_1) {
			if (user_num_1 != 0) {
				this->num_1 = user_num_1;
				return false;
			}
			return true;
		}

		bool set_num2(double user_num_2) {
			if (user_num_2 != 0) {
				this->num_2 = user_num_2;
				return false;
			}
			return true;
		}

		double get_num1() {
			return this->num_1;
		}

		double get_num2() {
			return this->num_2;
		}
};

void setNums(Calculator &calculator) {
	std::cout << "Enter the 1st number: ";
	double user_num_1 = 0.0;
	while (std::cin >> user_num_1 && calculator.set_num1(user_num_1)) {
		std::cout << "The number must distinguish from \"0\"!" << std::endl;
		std::cout << "Enter the 1st number again: ";
	}

	std::cout << "Enter the 2nd number: ";
	double user_num_2 = 0.0;
	while (std::cin >> user_num_2 && calculator.set_num2(user_num_2)) {
		std::cout << "The number must distinguish from \"0\"!" << std::endl;
		std::cout << "Enter the 2nd number again: ";
	}
	return;
}

void getCalculations(Calculator &calculator) {
	std::cout.width(3);
	std::cout << calculator.get_num1() << " + " << calculator.get_num2() << " = " << calculator.add() << std::endl;
	std::cout.width(3);
	std::cout << calculator.get_num1() << " - " << calculator.get_num2() << " = " << calculator.subtract_1_2() << std::endl;
	std::cout.width(3);
	std::cout << calculator.get_num2() << " + " << calculator.get_num1() << " = " << calculator.subtract_2_1() << std::endl;
	std::cout.width(3);
	std::cout << calculator.get_num1() << " * " << calculator.get_num2() << " = " << calculator.multiply() << std::endl;
	std::cout.width(3);
	std::cout << calculator.get_num1() << " / " << calculator.get_num2() << " = " << calculator.divide_1_2() << std::endl;
	std::cout.width(3);
	std::cout << calculator.get_num2() << " / " << calculator.get_num1() << " = " << calculator.divide_2_1() << std::endl;
	return;
}

int main(int argc, char** argv) {

	Calculator calculator = {0, 0};

	while (true) {
		setNums(calculator);
		std::cout << std::endl << "There is a list of all math manipulations:" << std::endl;
		getCalculations(calculator);
		std::cout << std::endl;
	}

	return 0;
}
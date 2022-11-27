// SUPPLEMENTAL FUNCTIONS TO  Class COUNTER

#include "counter.h"
#include <iostream>
#include <string>

std::string toLowerCase(std::string& answer) {
	for (char& chr : answer) {
		if (chr >= 'A' && chr <= 'Z') {
			chr = 'a' + (chr - 'A');
		}
	}
	return answer;
}

std::string getAnswer() {
	std::cout << "Want to set up the the counter's initial point? Yes/No: ";
	std::string answer;
	while (std::getline(std::cin, answer), toLowerCase(answer), ((answer != "yes") || (answer != "no"))) {
		if (answer == "yes") {
			return "yes";
		}
		else if (answer == "no") {
			return "no";
		}
		else {
			std::cout << "\n*** The answer must be \"Yes\" or \"No\": ";
		}
	}
}

void setScore(Counter& counter, std::string& answer) {
	if (answer == "yes") {
		std::cout << "Enter the initial point: ";
		int n = 0;
		std::cin >> n;
		counter = { n };
	}
	else {
		std::cout << "The initial point was set at 1." << std::endl;
		counter;
	}
	return;
}

enum class Operator {
	plus = '+',
	minus = '-',
	equal = '=',
	over = 'x'
};

void manageScore(Counter* counter) {
	char operator_symbol = NULL;
	while (static_cast<Operator>(operator_symbol) != Operator::over) {
		std::cout << "Enter the operator ('+', '-', '=' or 'x' to exit the program): ";
		std::cin >> operator_symbol;
		std::string duplication_check;
		std::getline(std::cin, duplication_check, '\n');
		if (empty(duplication_check)) {
			switch (static_cast<Operator>(operator_symbol)) {
			case Operator::plus:
				counter->increasScore();
				break;
			case Operator::minus:
				counter->decreasScore();
				break;
			case Operator::equal:
				std::cout << "Counter: " << counter->getScore() << std::endl;
				break;
			case Operator::over:
				break;
			default:
				std::cout << "\n*** WRONG INPUT! Use only '+', '-', '=' or 'x' operators. ***\n\n";
				break;
			}
		}
		else if (!empty(duplication_check) && operator_symbol == 'x') {
			break;
		}
		else {
			std::cout << "\n*** OPERATOR DUPLICATION! Only one operator is allowed at a time! ***\n\n";
		}
	}
	return;
}
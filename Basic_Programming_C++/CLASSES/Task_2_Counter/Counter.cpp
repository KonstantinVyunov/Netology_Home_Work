//COUNTER. Program increases/decreases/outputs counter by request.

#include <iostream>
#include <string>

class Counter {
	public:
		void setStartPoint() {
			std::cout << "Want to set up the the counter's initial point? Yes/No: ";
			std::string answer;
			while (std::getline(std::cin, answer), toLowerCase(answer), ((answer != "yes") || (answer != "no"))) {
				if (answer == "yes") {
					std::cout << "Enter the initial point: ";
					std::cin >> start_point;
					break;
				}
				else if (answer == "no") {
					std::cout << "The initial point was set at 0." << std::endl;
					break;
				}
				else {
					std::cout << "\n=== The answer must be \"Yes\" or \"No\"! ===\n=== Please, try again. Yes / No: ";
				}
			}
			return;
		}

		void operateCounter() {
			char operator_symbol = NULL;

			while (static_cast<Operator>(operator_symbol) != Operator::over) {
				std::cout << "Enter the operator ('+', '-', '=' or 'x' to exit the program): ";
				std::cin >> operator_symbol;
				std::string duplication_check;
				std::getline(std::cin, duplication_check,'\n');
				if (empty(duplication_check)) {
					switch (static_cast<Operator>(operator_symbol)) {
						case Operator::plus:
							++start_point;
							break;
						case Operator::minus:
							--start_point;
							break;
						case Operator::equal:
							std::cout << "Counter: " << start_point << std::endl;
							break;
						case Operator::over:
							break;
						default:
							std::cout << "\n=== WRONG INPUT! Use only '+', '-', '=' or 'x' operators. ===\n\n";
							break;
					}
				}
				else if (!empty(duplication_check) && operator_symbol == 'x') {
					break;
				} else {
					std::cout << "\n=== OPERATOR DUPLICATION! Only one operator allowed at a time! ===\n\n";
				}
			}
			return;
		}

	private:
		int start_point = 0;
		
		enum class Operator {
			plus	= '+',
			minus	= '-',
			equal	= '=',
			over	= 'x'
		};
		
		std::string toLowerCase(std::string &answer) {
			for (char &chr : answer) {
				if (chr >= 'A' && chr <= 'Z') {
					chr = 'a' + (chr - 'A');
				}
			}
			return answer;
		}
};

int main(int argc, char** argv) {

	Counter counter;
	counter.setStartPoint();
	counter.operateCounter();

	std::cout << "\n=== PROGRAM CLOSED ===\n";

	return 0;
}
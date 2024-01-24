//MONTHS. Program asks the user to input month's sequence and outputs the month's name.

#include <iostream>

enum class Months { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

int main(int argc, char** argv) {
	int month = 0;
	std::cout << "To exit the program enter \"0\"." << std::endl;
	while (std::cout << "Enter the month's number: " && std::cin >> month) {
		switch (month) {
		case (0):
			std::cout << "Exit the program!" << std::endl;
			exit(0);
		case (static_cast<int>(Months::Jan)):
			std::cout << "Jan" << std::endl;
			break;
		case (static_cast<int>(Months::Feb)):
			std::cout << "Feb" << std::endl;
			break;
		case (static_cast<int>(Months::Mar)):
			std::cout << "Mar" << std::endl;
			break;
		case (static_cast<int>(Months::Apr)):
			std::cout << "Apr" << std::endl;
			break;
		case (static_cast<int>(Months::May)):
			std::cout << "May" << std::endl;
			break;
		case (static_cast<int>(Months::Jun)):
			std::cout << "Jun" << std::endl;
			break;
		case (static_cast<int>(Months::Jul)):
			std::cout << "Jul" << std::endl;
			break;
		case (static_cast<int>(Months::Aug)):
			std::cout << "Aug" << std::endl;
			break;
		case (static_cast<int>(Months::Sep)):
			std::cout << "Sep" << std::endl;
			break;
		case (static_cast<int>(Months::Oct)):
			std::cout << "Oct" << std::endl;
			break;
		case (static_cast<int>(Months::Nov)):
			std::cout << "Nov" << std::endl;
			break;
		case (static_cast<int>(Months::Dec)):
			std::cout << "Dec" << std::endl;
			break;
		default:
			std::cout << "Number must be in range 1 to 12, re-enter the figure!" << std::endl;
			break;
		}
	}
	return 0;
}
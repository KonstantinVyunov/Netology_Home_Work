#include <exception>
#include <iostream>

class ForbiddenLength : public std::exception {
public:
	const char* what() const override {
		return error;
	}
private:
	const char* error = "bad_length";
};

class LessOrEqualZero : public std::exception {
public:
	const char* what() const override {
		return error;
	}
private:
	const char* error = "length less than or equal to 0!";
};

const int setForbiddenLength() {
	int forbidden_length = 0;
	std::cin >> forbidden_length;
	return (forbidden_length <= 0 ? throw LessOrEqualZero() : forbidden_length);
}

const size_t function(const std::string &str, int forbidden_length) {
	return (str.length() == forbidden_length ? throw ForbiddenLength() : str.length());
}

int main() {
	std::cout << "Enter the forbidden length for a word: ";
	try {
		const int forbidden_length = setForbiddenLength();
		std::string user_word;
		while (std::cout << "Enter a word: ", std::cin >> user_word) {
			std::cout << "The length of the word \""<< user_word << "\" is " <<
			function(user_word, forbidden_length) << '.' << std::endl;
		}
	}
	catch (const ForbiddenLength& error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}
	catch (const LessOrEqualZero &error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}
	return 0;
}
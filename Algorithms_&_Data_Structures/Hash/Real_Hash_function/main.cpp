#include <iostream>
#include <string>
#include <cmath>

int realStringHash(const std::string& word, const int& p, const int& n) {
	uint64_t sum = 0;
	if (!word.empty()) {
		size_t range = word.size();
		for (size_t i = 0; i < range; ++i) {
			sum += (static_cast<uint64_t>(pow(p, i)) * word[i]);
		}
	} else {
		std::cout << "Empty input!";
	}
	int hash = sum % n;
	return hash;
}

int main(int argc, char** argv) {
	
	int p = 0; // simple number
	std::cout << "Enter p: ";
	std::cin >> p;
	int n = 0; // capacity
	std::cout << "Enter n: ";
	std::cin >> n;

	std::string word = { "hello" };
	do {
		std::cout << "Enter the word: ";
		std::cin >> word;
		std::cout << "The hash of word \"" << word << "\" = ";
		std::cout << realStringHash(word, p, n) << std::endl;
	} while (word != "exit");

	return EXIT_SUCCESS;
}
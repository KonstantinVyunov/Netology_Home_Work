#include <iostream>
#include <string>

int simplStringHash(const std::string& word) {
	int hash = 0;
	if (!word.empty()) {
		for (const auto& chr : word) {
			hash += chr;
		}
	} else {
		std::cout << "Empty input!";
	}
	return hash;
}

int main(int argc, char** argv) {
	std::string word;
	do {
		std::cout << "Enter the word: ";
		std::cin >> word;
		std::cout << "The naive hash of word \"" << word << "\" = ";
		std::cout << simplStringHash(word) << std::endl;
	} while (word != "exit");

	return EXIT_SUCCESS;
}